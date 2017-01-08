#pragma once

#ifndef TSMLOADER_H
#define TSMLOADER_H

#include <Resource/asset_loader.h>

namespace terminus
{
	class TSMLoader : public IAssetLoader
	{
	public:
		TSMLoader();
		~TSMLoader();
		void* Load(std::string _id);
	};
}

#endif