/*
 *	OPCODE - Optimized Collision Detection
 * http://www.codercorner.com/Opcode.htm
 * 
 * Copyright (c) 2001-2008 Pierre Terdiman,  pierre@codercorner.com

This software is provided 'as-is', without any express or implied warranty.
In no event will the authors be held liable for any damages arising from the use of this software.
Permission is granted to anyone to use this software for any purpose, 
including commercial applications, and to alter it and redistribute it freely, 
subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.
2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.
3. This notice may not be removed or altered from any source distribution.
*/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 *	Contains base model interface.
 *	\file		OPC_BaseModel.h
 *	\author		Pierre Terdiman
 *	\date		May, 18, 2003
 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Include Guard
#ifndef __OPC_BASEMODEL_H__
#define __OPC_BASEMODEL_H__

	//! Model creation structure
	struct OPCODE_API OPCODECREATE
	{
		//! Constructor
								OPCODECREATE();

		MeshInterface*			mIMesh;			//!< Mesh interface (access to triangles & vertices) (*)
		BuildSettings			mSettings;		//!< Builder's settings
		bool					mNoLeaf;		//!< true => discard leaf nodes (else use a normal tree)
		bool					mQuantized;		//!< true => quantize the tree (else use a normal tree)
#ifdef __MESHMERIZER_H__
		bool					mCollisionHull;	//!< true => use convex hull + GJK
#endif // __MESHMERIZER_H__
		bool					mKeepOriginal;	//!< true => keep a copy of the original tree (debug purpose)
		bool					mCanRemap;		//!< true => allows OPCODE to reorganize client arrays

		// (*) This pointer is saved internally and used by OPCODE until collision structures are released,
		// so beware of the object's lifetime.
	};

	enum ModelFlag
	{
		OPC_QUANTIZED	= (1<<0),	//!< Compressed/uncompressed tree
		OPC_NO_LEAF		= (1<<1),	//!< Leaf/NoLeaf tree
		OPC_SINGLE_NODE	= (1<<2)	//!< Special case for 1-node models
	};

	class OPCODE_API BaseModel
	{
		public:
		// Constructor/Destructor
											BaseModel();
		virtual								~BaseModel();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Builds a collision model.
		 *	\param		create		[in] model creation structure
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool				Build(const OPCODECREATE& create)	= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the number of bytes used by the tree.
		 *	\return		amount of bytes used
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			udword				GetUsedBytes()		const			= 0;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Refits the collision model. This can be used to handle dynamic meshes. Usage is:
		 *	1. modify your mesh vertices (keep the topology constant!)
		 *	2. refit the tree (call this method)
		 *	\return		true if success
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		virtual			bool				Refit();

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the source tree.
		 *	\return		generic tree
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	const	AABBTree*			GetSourceTree()		const	{ return mSource;						}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the tree.
		 *	\return		the collision tree
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	const	AABBOptimizedTree*	GetTree()			const	{ return mTree;							}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the tree.
		 *	\return		the collision tree
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			AABBOptimizedTree*	GetTree()					{ return mTree;							}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the number of nodes in the tree.
		 *	Should be 2*N-1 for normal trees and N-1 for optimized ones.
		 *	\return		number of nodes
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			udword				GetNbNodes()		const	{ return mTree->GetNbNodes();			}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Checks whether the tree has leaf nodes or not.
		 *	\return		true if the tree has leaf nodes (normal tree), else false (optimized tree)
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			BOOL				HasLeafNodes()		const	{ return !(mModelCode & OPC_NO_LEAF);	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Checks whether the tree is quantized or not.
		 *	\return		true if the tree is quantized
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			BOOL				IsQuantized()		const	{ return mModelCode & OPC_QUANTIZED;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Checks whether the model has a single node or not. This special case must be handled separately.
		 *	\return		true if the model has only 1 node
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			BOOL				HasSingleNode()		const	{ return mModelCode & OPC_SINGLE_NODE;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the model's code.
		 *	\return		model's code
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			udword				GetModelCode()		const	{ return mModelCode;					}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Gets the mesh interface.
		 *	\return		mesh interface
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_	const	MeshInterface*		GetMeshInterface()	const						{ return mIMesh;	}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		 *	Sets the mesh interface.
		 *	\param		imesh		[in] mesh interface
		 */
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		inline_			void				SetMeshInterface(const MeshInterface* imesh)	{ mIMesh = imesh;	}

		protected:
				const	MeshInterface*		mIMesh;			//!< User-defined mesh interface
						udword				mModelCode;		//!< Model code = combination of ModelFlag(s)
						AABBTree*			mSource;		//!< Original source tree
						AABBOptimizedTree*	mTree;			//!< Optimized tree owned by the model
		// Internal methods
						void				ReleaseBase();
						bool				CreateTree(bool no_leaf, bool quantized);
	};

#endif //__OPC_BASEMODEL_H__