#pragma once

#ifndef  TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include <types.h>
#include <ECS/component.h>

namespace terminus
{
	struct TransformComponent : IComponent
	{
        static const ComponentID _id;
		Matrix4 global_transform;
		Vector3 position;
		Vector3 scale;
		Vector3 rotation;
        String parent_entity_name;
	};
}

#endif