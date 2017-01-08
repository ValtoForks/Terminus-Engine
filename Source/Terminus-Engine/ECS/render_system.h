#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <ECS/system.h>
#include <ECS/mesh_component.h>
#include <ECS/transform_component.h>
#include <global.h>
#include <Graphics/rendering_path.h>
#include <Graphics/draw_item.h>
#include <Graphics/renderer.h>
#include <Resource/shader_cache.h>

#define MAX_DRAW_ITEMS 1024
#define MAX_VIEWS 10
#define MAX_RENDERABLES 1024

namespace terminus
{
    // Forward Declarations
    
    struct SceneView;
    struct Renderable;
    
    // Type Definitions
    
    using DrawItemArray   = std::array<DrawItem, MAX_DRAW_ITEMS>;
    using SceneViewArray  = std::array<SceneView, MAX_VIEWS>;
    using RenderableArray = std::array<Renderable, MAX_RENDERABLES>;
    
    struct RenderPrepareTaskData
    {
        int _scene_index;
    };
    
    struct Renderable
    {
        Mesh*                    _mesh;
        bool                     _sub_mesh_cull;
        float                    _radius;
        TransformComponent*      _transform;
        RenderableType _type;
        // TODO : Accomodate material overrides.
        // TODO : Union containing Renderable type (Mesh, Ocean, Terrain etc)
    };
    
    struct SceneView
    {
        DrawItemArray            _draw_items;
        int                      _num_items;
        Matrix4*                 _view_matrix;
        Matrix4*                 _projection_matrix;
        Matrix4*                 _view_projection_matrix;
        Vector4                  _screen_rect;
        bool                     _is_shadow;
        uint32                   _cmd_buf_idx;
        RenderingPath* _rendering_path;
    };
    
    class RenderSystem : public ISystem
    {
    private:
        SceneViewArray          m_views;
        uint16                  m_view_count;
        RenderableArray         m_renderables;
        uint16                  m_renderable_count;
        DefaultThreadPool*      m_thread_pool;
        Renderer*     m_renderer;
        ShaderCache*  m_shader_cache;
        
    public:
        RenderSystem();
        ~RenderSystem();
        void SetRenderDevice(Renderer* renderer);
        void SetShaderCache(ShaderCache* shaderCache);
        virtual void Initialize();
        virtual void Update(double delta);
        virtual void Shutdown();
        void OnEntityCreated(Entity entity);
        void OnEntityDestroyed(Entity entity);
        
    private:
        TASK_METHOD_DECLARATION(RenderPrepareTask);
    };
}

#endif