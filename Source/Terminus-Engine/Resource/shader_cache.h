#pragma once

#ifndef SHADERCACHE_H
#define SHADERCACHE_H

#include <Resource/asset_cache.h>
#include <Resource/asset_loader.h>
#include <Resource/shader_factory.h>
#include <Resource/shader_key.h>
#include <types.h>

#include <unordered_map>

#define SHADER_DEF_NORMAL_MAP		  "USE_NORMAL_MAP"
#define SHADER_DEF_DIFFUSE_MAP		  "USE_DIFFUSE_MAP"
#define SHADER_DEF_ROUGHNESS_MAP	  "USE_ROUGHNESS_MAP"
#define SHADER_DEF_METALNESS_MAP	  "USE_METALNESS_MAP"
#define SHADER_DEF_PARALLAX_OCCLUSION "USE_PARALLAX_OCCLUSION"
#define SHADER_DEF_APPLE			  "APPLE"
#define SHADER_DEF_SKELETAL_MESH	  "SKELETAL_VERTEX"

namespace terminus
{
	class ShaderCache : public IAssetCache<ShaderFactory>
	{
	private:
		std::unordered_map<std::string, Shader*> m_ShaderMap;
		std::unordered_map<Shader*, ShaderProgram*> m_ShaderProgramMap;
        std::unordered_map<uint64, ShaderProgram*> m_ShaderProgramKeyMap;

	public:
		ShaderCache();
		~ShaderCache();
		void Initialize();

		ShaderProgram* Load(const char* _vertexID,
									  const char* _pixelID,
									  const char* _geometryID = nullptr,
									  const char* _tessevalID = nullptr,
									  const char* _tesscontrolID = nullptr);
		ShaderProgram* Load(ShaderKey key);
		void Unload(ShaderProgram* program);
	};
}

#endif