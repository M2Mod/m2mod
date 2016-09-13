#pragma once

#include "BaseTypes.h"
#include "M2Types.h"
#include "M2Skin.h"
#include "M2I.h"
#include <vector>
#include <map>
#include <assert.h>

namespace M2Lib
{
	class M2I;		// forward declaration.
	class M2;		// forward declaration.
	class M2Skin;	// forward declaration.

	// does the main heavy lifting of building new .skins for the M2.
	class M2SkinBuilder
	{
	public:
		//
		class CBonePartition
		{
		public:
			// maximum number of bones allowed per partition.
			UInt32* pBoneLoD;
			// list of bones in this partition, indices into the global bone list. later gets consolidated into the global bone lookup list.
			std::vector< UInt16 > Bones;
			// here we keep a map of triangle index to triangle for all triangles that have successfully been added to this bone partition. this is result caching to speed up building of subset partitions when dealing out subset triangles between subset partitions.
			std::map< UInt32, CTriangle* > TrianglesMap;

			// offset from begining of skin's bone lookup list.
			UInt32 BoneStart;

		public:
			CBonePartition(UInt32* pBoneLoDIn)
				: pBoneLoD(pBoneLoDIn)
				, BoneStart(0)
			{
			}

			// attemts to add all of the bones used by input triangle. returns true if bones already exist or were added and triangle was added. returns false if there is not enough room for additional bones.
			bool AddTriangle(CVertex* GlobalVertexList, CTriangle* pTriangle);

			// returns true if bone is contained in this bone partition. if pTriangleIndexOut is supplied and function returns true, it will be set to index of where bone was found in this partition.
			bool HasBone(UInt16 Bone, UInt16* pIndexOut);

			// returns true if a triangle has been associated with this bone partition.
			bool HasTriangle(UInt32 TriangleIndex);
		};

		//
		class CSubMesh
		{
		public:
			class CSubsetPartition
			{
			public:
				// the bone partition used by this partitioned subset.
				CBonePartition* pBonePartition;

				// this subset partition's final index list. these are indices into the global vertex list. this gets consolidated into the single skin vertex list.
				//std::vector< UInt16 > Vertices;
				// this subset partition's final triangle list. these are indices into the above vertex index list. this gets consolidated into the single skin triangle listt
				std::vector< CTriangle* > Triangles;

				UInt32 VertexStart;
				UInt32 VertexCount;
				UInt32 TriangleIndexStart;
				UInt32 TriangleIndexCount;

				UInt32 Unknown1;	// aka max bones
				UInt32 Unknown2;	// aka category

				UInt32 HasFlags;
				UInt16 FlagsValue1;
				UInt16 FlagsValue2;
				UInt16 FlagsValue3;
				UInt16 FlagsValue4;
				UInt16 FlagsValue5;
				UInt16 FlagsValue6;

			public:
				CSubsetPartition(CBonePartition* pBonePartitionIn);

				// attempts to add a triangle to this subset partition.
				bool AddTriangle(CTriangle* pTriangle);

				// adds a vertex from the global vertex list to this subset's vertex list. returns index of existing or newly added vertex.
				//UInt32 AddVertex( UInt32 VertexIndex );
				//
				//void FixVertexOffsets( SInt32 Delta );

			};


		public:
			// this subset's ID within the model.
			UInt16 ID;
			UInt16 Level;
			//
			std::vector< CSubsetPartition* > SubsetPartitions;
			//
			//std::vector< M2Skin::CElement_Material* > pMaterials;

			SubmeshExtraData const* pExtraData;

		public:
			CSubMesh()
				: ID(0), pExtraData(NULL)
			{
			}

			~CSubMesh()
			{
				for (UInt32 i = 0; i < SubsetPartitions.size(); i++)
				{
					delete SubsetPartitions[i];
				}
			}

			// adds a subset partition to the list of subset partitions in this subset. this is done in preparation for when we deal out triangles and vertices to between the various subset partitions.
			void AddSubsetPartition(CBonePartition* pBonePartition);

			// attempts to add a triangle to this subset.
			bool AddTriangle(CTriangle* pTriangle);
		};

	public:
		// bone partition level of detail, this is the maximum number of bones allowed to be used per subset partition per draw call. it is a limitation imposed by the number of shader constant registers available on the GPU.
		// 256, 75, 53, 21
		UInt32 m_MaxBones;

		// each skin has it's own vertex list. common vertices accross subsets get duplicated (i think) so they appear as many times as they are used in multiple subsets. this is because each subset occupies a sub-range of this list.
		std::vector< UInt16 > m_Vertices;
		// bone lookup list used by this skin. the bone lookup lists from all the skins get consolidated into one big bone lookup list that is stored in the M2.
		std::vector< UInt16 > m_Bones;
		// indices to m_VertexLookupList.
		std::vector< UInt16 > m_Indices;

		// list of subsets that make up this skin.
		std::vector< CSubMesh* > m_SubMeshList;

		// list of bone partitions used within this skin.
		std::vector< CBonePartition* > m_BonePartitions;


	public:
		M2SkinBuilder()
			: m_MaxBones(256)
		{
		}

		~M2SkinBuilder()
		{
			for (UInt32 i = 0; i < m_SubMeshList.size(); i++)
			{
				delete m_SubMeshList[i];
			}

			for (UInt32 i = 0; i < m_BonePartitions.size(); i++)
			{
				delete m_BonePartitions[i];
			}
		}

	public:
		void Clear();

		// builds a skin from the supplied parameters.
		bool Build(M2Skin* pResult, UInt32 BoneLoD, M2I* pM2I, CVertex* pGlobalVertexList, UInt32 BoneStart);

		// returns true if the built skin with LoD is necessary to be exported, false if can be done without.
		// this is to check for LoD that has significant room for more bones than the skin actually uses, in such case, it would not be advisable to save.
	};
}
