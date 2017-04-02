#pragma once

#include <core/types.h>
#include <graphics/render_device.h>

// Material Key Options

// Normal Mapping
// Parallax Occlusion
// Diffuse Maps or Constant color
// Roughness Maps or value
// Metalness Maps or value

namespace terminus
{
	// Forward Declaration
	struct Texture2D;

	enum TexureMap
	{
		DIFFUSE = 0,
		NORMAL = 1,
		ROUGHNESS = 2,
		METALNESS = 3,
		DISPLACEMENT = 4
	};
    
    enum class TessellationType
    {
        OFF = 0,
        PN_TRIANGLES
    };

	struct Material
	{
		Texture2D*       texture_maps[5];
        SamplerState*    sampler;
		bool             backface_cull;
        bool             alpha_discard;
        TessellationType tessellation;
		Vector4          diffuse_value;
		float            roughness_value;
		float            metalness_value;
	};
} // namespace terminus