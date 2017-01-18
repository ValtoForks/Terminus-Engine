#include <Resource/material_cache.h>
#include <IO/filesystem.h>
#include <Resource/text_loader.h>
#include <iostream>
#include <rapidjson.h>

namespace terminus
{
	MaterialCache::MaterialCache()
	{
        filesystem::add_directory("assets/material");
	}

	MaterialCache::~MaterialCache()
	{

	}

    Material* MaterialCache::load(String key)
	{
		if (m_MaterialMap.find(key) == m_MaterialMap.end())
		{
			std::cout << "Asset not in Cache. Loading Asset." << std::endl;
			std::string extension = filesystem::get_file_extention(key);

            asset_common::TextLoadData* data = text_loader::load(key);
            
            Material* material = material_factory::create(data);
            m_MaterialMap[key] = material;
            return material;
		}
		else
		{
			std::cout << "Asset already in cache, returning reference.." << std::endl;
			return m_MaterialMap[key];
		}
	}

	void MaterialCache::unload(Material* material)
	{

	}
}
