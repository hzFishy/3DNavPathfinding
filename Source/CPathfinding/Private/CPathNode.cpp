// Copyright Dominik Trautman. Published in 2022. All Rights Reserved.

#include "CPathNode.h"

CPathAStarNode::CPathAStarNode()
{
	
}

CPathAStarNode::~CPathAStarNode()
{
	
}

FCPathNode::FCPathNode():
	WorldLocation(FVector::ZeroVector),
	Normal(FVector::ZeroVector)
{}

FCPathNode::FCPathNode(FVector Location):
	WorldLocation(Location),
	Normal(FVector::ZeroVector)
{}
