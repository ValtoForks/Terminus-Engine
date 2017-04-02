#include <core/loading_thread.h>
#include <core/context.h>
#include <utility/profiler.h>
#include <core/sync.h>

namespace terminus
{
    LoadingThread::LoadingThread()
    {
        concurrent_queue::clear(_loading_queue);
    }
    
    LoadingThread::~LoadingThread()
    {
        
    }
    
    void LoadingThread::run()
    {
        _thread = std::thread(&LoadingThread::load_loop, this);
    }
    
    void LoadingThread::enqueue_load_task(Task& task)
    {
        concurrent_queue::push(_loading_queue, task);
		sync::notify_loader_wakeup();
    }
    
    void LoadingThread::shutdown()
    {
        
    }
    
    void LoadingThread::exit()
    {
        _thread.join();
    }
    
    void LoadingThread::load_loop()
    {
        Context& context = global::get_context();
        
		sync::wait_for_loader_wakeup();
        
        while (!context._shutdown)
        {
            while(!concurrent_queue::empty(_loading_queue))
            {
                TERMINUS_BEGIN_CPU_PROFILE(load_loop);
                
                Task load_task = concurrent_queue::pop(_loading_queue);
                load_task._function.Invoke(&load_task._data[0]);
                
                TERMINUS_END_CPU_PROFILE;
            }
            
			sync::wait_for_loader_wakeup();
        }
        
		sync::notify_loader_exit();
    }
}