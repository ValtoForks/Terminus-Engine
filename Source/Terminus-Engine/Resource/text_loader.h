#pragma once

#ifndef TEXTLOADER_H
#define TEXTLOADER_H

#include <Resource/asset_loader.h>

namespace terminus
{
	class TextLoader : public IAssetLoader
	{
	public:
		TextLoader();
		~TextLoader();
		void* Load(std::string _id);
	};
}

#endif