#pragma once

#include "BaseTypes.h"
#include "M2Types.h"

namespace M2Lib
{
	std::string ChunkIdToStr(UInt32 ChunkId, bool Reverse);

	class ChunkBase
	{
	public:
		virtual ~ChunkBase() {}

		virtual void Load(std::fstream& FileStream, UInt32 Size) = 0;
		virtual void Save(std::fstream& FileStream) = 0;
	};

	class RawChunk : public ChunkBase
	{
	public:
		void Load(std::fstream& FileStream, UInt32 Size) override;
		void Save(std::fstream& FileStream) override;

		std::vector<UInt8> RawData;
	};
}