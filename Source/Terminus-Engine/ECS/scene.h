#pragma once

#include <ECS/system.h>
#include <Graphics/render_device.h>
#include <types.h>
#include <ECS/component_pool.h>
#include <ECS/transform_system.h>
#include <ECS/render_system.h>
#include <ECS/camera_component.h>
#include <ECS/mesh_component.h>
#include <ECS/script_component.h>
#include <vector>
#include <iostream>

namespace terminus
{
	using SystemList				   = std::vector<ISystem*>;
	using EntityList					   = std::vector<Entity>;
	using ComponentPoolMap = std::unordered_map<ComponentID, IComponentPool*>;
    using EntityNameIDMap = std::unordered_map<std::string, Entity>;
    using EntityIDNameMap = std::unordered_map<Entity,std::string>;
    
	struct Scene
	{
		Entity			 m_last_entity_id;
		SystemList		 m_systems;
        
        // Systems
        TransformSystem  m_transform_system;
        RenderSystem     m_render_system;
        
        // Component Pool
        ComponentPool<TransformComponent> m_transform_component_pool;
        ComponentPool<CameraComponent>    m_camera_component_pool;
        ComponentPool<MeshComponent>      m_mesh_component_pool;
        
		EntityList		 m_entities;
		ComponentPoolMap m_component_pools;
        String           m_name;
        EntityNameIDMap  m_entity_name_id_map;
        EntityIDNameMap  m_entity_id_name_map;

		Scene();
		~Scene();
		Entity CreateEntity(String name);
        Entity GetEntityByName(String name);
        String GetNameByEntity(Entity entity);
		void DestroyEntity(Entity entity);
		void Initialize();
		void Update(double delta);
		IComponent* AttachComponent(Entity entity, ComponentID id);
		IComponent* GetComponent(Entity entity, ComponentID id);
		bool HasComponent(Entity entity, ComponentID id);
		void RemoveComponent(Entity entity, ComponentID id);

		template<typename T>
		void RegisterComponentPool(ComponentPool<T>* pool)
		{
            m_component_pools[T::_id] = pool;
		}
        
        void RegisterSystem(ISystem* system)
        {
            system->SetScene(this);
            m_systems.push_back(system);
        }

		template<typename T>
		SlotMap<T, MAX_COMPONENTS>& GetComponentArray()
		{
			assert(m_component_pools.find(T::_id) != m_component_pools.end());
			ComponentPool<T>* pool = (ComponentPool<T>*)m_component_pools[T::_id];
			return pool->m_components;
		} 

	};
}