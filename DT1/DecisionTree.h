#pragma once
#include <map>

namespace DecisionTree {
	typedef int LabelId;
	typedef int SampleCount;
	typedef std::map<LabelId, SampleCount> LabelStatistics;
	class DecisionTreeNode {
		int GreaterValue, AttributeId;
		DecisionTreeNode *NodeSatisfied, *NodeUnsatisfied;
		bool IsLeaf;
		// Attributes will use when IsLeaf is TRUE
		SampleCount count;
		LabelStatistics Statistics;
		// Training Data should be released when never use
		
	};

}