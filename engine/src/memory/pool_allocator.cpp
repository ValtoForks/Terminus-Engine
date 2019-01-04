#include <memory/pool_allocator.hpp>
#include <memory/memory_common.hpp>
#include <assert.h>

TE_BEGIN_TERMINUS_NAMESPACE

PoolAllocator::PoolAllocator(void* memory, size_t max_size, size_t object_size, uint8_t alignment) : IAllocator()
{
	// Only init once.
	assert(m_memory == nullptr);
	assert(memory);
	assert(max_size > 0);

	m_size = max_size;
	m_memory = memory;

	m_object_size = object_size;
	m_object_alignment = alignment;

	assert(m_object_size >= sizeof(void*));
	uint8_t adjustment = memory::align_foward_adjustment(m_memory, m_object_alignment);
	m_freelist = (void**)memory::add(m_memory, adjustment);
	size_t num_objects = (m_size - adjustment) / m_object_size;

	void** p = m_freelist;

	for (int i = 0; i < num_objects - 1; i++)
	{
		*p = memory::add(p, m_object_size);
		p = (void**)*p;
	}

	*p = nullptr;
}

PoolAllocator::~PoolAllocator()
{

}

void* PoolAllocator::allocate(size_t size, size_t align)
{
    assert(size == m_object_size && align == m_object_alignment);
    
    if(m_freelist == nullptr)
        return nullptr;
    
    void* p = m_freelist;
    m_freelist = (void**)(*m_freelist);
    
    m_used_size += size;
    m_num_allocations++;
    
    return p;
}

void PoolAllocator::deallocate(void* ptr)
{
    *((void**)ptr) = m_freelist;
    m_freelist = (void**)ptr;
    m_used_size -= m_object_size;
    m_num_allocations--;
}

TE_END_TERMINUS_NAMESPACE
