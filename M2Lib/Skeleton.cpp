#include "Skeleton.h"
#include "DataBinary.h"
#include "Logger.h"

using namespace M2Lib;
using namespace M2Lib::SkeletonChunk;

EError Skeleton::Load(const Char16* FileName)
{
	// check path
	if (!FileName)
		return EError_FailedToLoadM2_NoFileSpecified;
	
	// open file stream
	std::fstream FileStream;
	FileStream.open(FileName, std::ios::in | std::ios::binary);
	if (FileStream.fail())
		return EError_FailedToLoadM2_CouldNotOpenFile;

	// find file size
	FileStream.seekg(0, std::ios::end);
	UInt32 FileSize = (UInt32)FileStream.tellg();
	FileStream.seekg(0, std::ios::beg);

	sLogger.Log("Loading skeleton chunks...");
	while (FileStream.tellg() < FileSize)
	{
		UInt32 ChunkId;
		UInt32 ChunkSize;

		FileStream.read((char*)&ChunkId, sizeof(ChunkId));
		FileStream.read((char*)&ChunkSize, sizeof(ChunkSize));

		ChunkBase* Chunk = NULL;
		auto eChunk = (SkeletonChunk::ESkeletonChunk)REVERSE_CC(ChunkId);
		switch (eChunk)
		{
			case ESkeletonChunk::SKL1: Chunk = new SKL1Chunk(); break;
			case ESkeletonChunk::SKA1: Chunk = new SKA1Chunk(); break;
			case ESkeletonChunk::SKB1: Chunk = new SKB1Chunk(); break;
			case ESkeletonChunk::SKS1: Chunk = new SKS1Chunk(); break;
			case ESkeletonChunk::SKPD: Chunk = new SKPDChunk(); break;
			case ESkeletonChunk::AFID: Chunk = new AFIDChunk(); break;
			case ESkeletonChunk::BFID: Chunk = new BFIDChunk(); break;
			default:
				Chunk = new RawChunk();
				break;
		}

		sLogger.Log("Loaded %s skeleton chunk, size %u", ChunkIdToStr(ChunkId, false).c_str(), ChunkSize);

		ChunkOrder.push_back((UInt32)eChunk);
		UInt32 savePos = FileStream.tellg();
		Chunk->Load(FileStream, ChunkSize);
		FileStream.seekg(savePos + ChunkSize, std::ios::beg);

		Chunks[eChunk] = Chunk;
	}
	sLogger.Log("Finished loading skeleton chunks");

	return EError::EError_OK;
}

EError Skeleton::Save(const Char16* FileName)
{
	// check path
	if (!FileName)
		return EError_FailedToSaveM2_NoFileSpecified;

	// open file stream
	std::fstream FileStream;
	FileStream.open(FileName, std::ios::out | std::ios::trunc | std::ios::binary);
	if (FileStream.fail())
		return EError_FailedToSaveM2;

	ChunkOrder.clear();
	ChunkOrder.push_back((UInt32)ESkeletonChunk::SKL1);
	ChunkOrder.push_back((UInt32)ESkeletonChunk::SKS1);
	for (auto chunk : Chunks)
	{
		if (chunk.first == ESkeletonChunk::SKL1 || chunk.first == ESkeletonChunk::SKS1)
			continue;

		ChunkOrder.push_back((UInt32)chunk.first);
	}

	for (auto chunkId : ChunkOrder)
	{
		auto chunk = GetChunk((ESkeletonChunk)chunkId);
		if (!chunk)
			continue;

		UInt32 ChunkId = REVERSE_CC((UInt32)chunkId);

		FileStream.write((char*)&ChunkId, 4);
		FileStream.seekp(4, std::ios::cur);		// reserve space for chunk size
		UInt32 savePos = (UInt32)FileStream.tellp();
		chunk->Save(FileStream);
		UInt32 ChunkSize = (UInt32)FileStream.tellp() - savePos;
		FileStream.seekp(savePos - 4, std::ios::beg);
		FileStream.write((char*)&ChunkSize, 4);
		FileStream.seekp(0, std::ios::end);
	}

	return EError::EError_OK;
}

ChunkBase* Skeleton::GetChunk(ESkeletonChunk ChunkId)
{
	auto chunkItr = Chunks.find(ChunkId);
	if (chunkItr == Chunks.end())
		return NULL;

	return chunkItr->second;
}
