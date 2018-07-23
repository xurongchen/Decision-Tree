#pragma once
#include <map>
#include "Data.h"

namespace DecisionTree {
	typedef int LabelId;
	typedef int SampleCount;
	typedef std::map<LabelId, SampleCount> LabelStatistics;
	class DecisionTreeNode {
	private:
		int GreaterValue, AttributeId;
		DecisionTreeNode *NodeSatisfied, *NodeUnsatisfied;// > and <=
		double Threshold;// Divide when addition is greater than the threshold. Used in pre-cut, default 0(No pre-cut).
		bool IsLeaf;
		// Attributes following will use when IsLeaf is TRUE
		SampleCount count;
		LabelStatistics Statistics;
		// Training Data should be released when never use
		Data::DataList *DataInfomation;// Linked Table, copy straight
		//int DataInfomationLength;
	public:
		DecisionTreeNode();
		//DecisionTreeNode

		void DataInfomationInsert(Data::DataList *_DataInfomation);// copy straight

		void SetThreshold(double _Threshold);
		double GetThreshold();

		void PushDown();
	};
	typedef DecisionTreeNode DecisionTree;
	DecisionTree* NewDecisionTree(Data::DataList *DataInfomation);// copy straight
	//void DecisionTree()
}