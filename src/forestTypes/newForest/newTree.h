#ifndef treeStruct_h
#define treeStruct_h
#include "../../baseFunctions/fpBaseNode.h"
#include "obsIndexAndClassVec.h"
#include "zipClassAndValue.h"
#include <vector>

namespace fp{

	template <typename T, typename Q>
		class treeStruct
		{
			protected:
				float OOBAccuracy;
				float correctOOB;
				float totalOOB;
				std::vector< fpBaseNode<T,Q> > tree;
				std::vector<processingNode<T,Q> > nodeQueue;


//obsIndexAndClassVec indexHolder(numClasses);
//std::vector<zipClassAndValue<int, float> > zipVec(testSize);

			public:
				treeStruct(obsIndexAndClassVec& indices, std::vector<zipClassAndValue<int, T> >& zip) : OOBAccuracy(-1.0),correctOOB(0),totalOOB(0){
			loadFirstNode(indices, zip);	
				}

				void loadFirstNode(obsIndexAndClassVec& indicesHolder, std::vector<zipClassAndValue<int, T> >& zipper){
					nodeQueue.emplace_back(0,0);
					//task location
nodeQueue.back().setupRoot(indicesHolder, zipper);
nodeQueue.back().calcBestSplit();
				}

				inline bool shouldProcessNode(){
					return !nodeQueue.back().isLeafNode();
				}

				inline void copyProcessedNodeToTree(){


				}

				inline void processNode(){
					
if(shouldProcessNode()){

}

				}
				/*
				inline float returnOOB(){
					return correctOOB/totalOOB;
				}

				inline int returnLastNodeID(){
					return tree.size()-1;
				}

				inline void linkParentToChild(){
					if(nodeQueue.back().returnIsLeftNode()){
						tree[nodeQueue.back().returnParentID()].setLeftValue(returnLastNodeID());
					}else{
						tree[nodeQueue.back().returnParentID()].setRightValue(returnLastNodeID());
					}
				}


				inline int returnMaxDepth(){
					int maxDepth=0;
					for(auto nodes : tree){
						if(maxDepth < nodes.returnDepth()){
							maxDepth = nodes.returnDepth();
						}
					}
					return maxDepth;
				}


				inline int returnNumLeafNodes(){
					int numLeafNodes=0;
					for(auto nodes : tree){
						if(!nodes.isInternalNode()){
							++numLeafNodes;
						}
					}
					return numLeafNodes;
				}


				inline int returnLeafDepthSum(){
					int leafDepthSums=0;
					for(auto nodes : tree){
						if(!nodes.isInternalNode()){
							leafDepthSums += nodes.returnDepth();
						}
					}
					return leafDepthSums;
				}


				inline void setAsLeaf(){
					tree.back().setClass(nodeQueue.back().returnMaxClass());
					tree.back().setDepth(nodeQueue.back().returnDepth());
				}


				inline void checkOOB(){
					totalOOB += nodeQueue.back().returnOutSampleSize();
					correctOOB += nodeQueue.back().returnOutSampleError(tree.back().returnClass());
				}


				inline void makeWholeNodeALeaf(){
					tree.emplace_back();
					linkParentToChild();
					setAsLeaf();
					checkOOB();
					nodeQueue.pop_back();
				}

				void printTree(){
					for(auto nd : tree){
						nd.printNode();
					}
				}

				inline void createNodeInTree(){
					tree.emplace_back();
					linkParentToChild();
					tree.back().setCutValue(nodeQueue.back().returnBestCutValue());
					tree.back().setFeatureValue(nodeQueue.back().returnBestFeature());
					tree.back().setDepth(nodeQueue.back().returnDepth());
				}


				inline void makeNodeInternal(){
					createNodeInTree();
					createChildren();
				}


				inline void createChildren(){
					bool isLeftNode = true;

					nodeQueue.back().moveDataLeftOrRight();

					stratifiedInNodeClassIndices* leftIndices = nodeQueue.back().returnLeftIndices();
					stratifiedInNodeClassIndices* rightIndices = nodeQueue.back().returnRightIndices();

					int childDepth = nodeQueue.back().returnDepth()+1;

					nodeQueue.pop_back();

					nodeQueue.emplace_back(returnLastNodeID(),childDepth, isLeftNode);
					nodeQueue.back().loadIndices(leftIndices);

					nodeQueue.emplace_back(returnLastNodeID(),childDepth, !isLeftNode);
					nodeQueue.back().loadIndices(rightIndices);
				}


				inline void findTheBestSplit(){
					nodeQueue.back().findBestSplit();
				}


				inline bool noGoodSplitFound(){
					return nodeQueue.back().returnBestFeature().empty();
				}


				inline void processANode(){
					//	timeLogger logTime;
					//	logTime.startSortTimer();
					nodeQueue.back().setupNode();
					//	logTime.stopSortTimer();
					//	logTime.startGiniTimer();
					if(shouldProcessNode()){
						findTheBestSplit();
						if(noGoodSplitFound()){
							makeWholeNodeALeaf();
						}else{
							makeNodeInternal();
						}
					}else{
						makeWholeNodeALeaf();
					}
					//	logTime.stopGiniTimer();
				}


				void processNodes(){
					while(!nodeQueue.empty()){
						processANode();
					}
				}


				void growTree(){
					loadFirstNode();
					processNodes();
				}


				inline int predictObservation(int observationNum){
					int currNode = 0;
					T featureVal = 0;
					while(tree[currNode].isInternalNode()){
						featureVal = 0;
					for(auto featureNumber : tree[currNode].returnFeatureNumber()){
							featureVal += fpSingleton::getSingleton().returnTestFeatureVal(featureNumber,observationNum);
						}
						currNode = tree[currNode].fpBaseNode<T, std::vector<int> >::nextNode(featureVal);
					}
					return tree[currNode].returnClass();
				}


				inline int predictObservation(std::vector<T>& observation){
					int currNode = 0;
					while(tree[currNode].isInternalNode()){
						currNode = tree[currNode].nextNode(observation);
					}
					return tree[currNode].returnClass();
				}
				*/
		};

}//fp
#endif //treeStruct_h
