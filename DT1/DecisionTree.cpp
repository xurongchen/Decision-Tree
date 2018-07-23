#include "DecisionTree.h"
#include <cassert>
#define INITIAL_VALUE -1

DecisionTree::DecisionTreeNode::DecisionTreeNode() {
	AttributeId = INITIAL_VALUE;
	GreaterValue = INITIAL_VALUE;
	NodeSatisfied = nullptr;
	NodeUnsatisfied = nullptr;
	Threshold = 0;
	IsLeaf = true;// Todo: Consider the initial value
	count = 0;
	Statistics.clear();
	DataInfomation = nullptr;
}

void DecisionTree::DecisionTreeNode::SetThreshold(double _Threshold) {
	Threshold = _Threshold;
}

double DecisionTree::DecisionTreeNode::GetThreshold() {
	return Threshold;
}

void DecisionTree::DecisionTreeNode::DataInfomationInsert(Data::DataList *_DataInfomation) {
	DataInfomation = _DataInfomation;
}

void DecisionTree::DecisionTreeNode::PushDown() {
	if (DataInfomation == nullptr) { 
		assert(0);
		return;
	}
	// Check if labels are same
	Data::DataList *DataInfomationItem = DataInfomation;
	int Labelcheck = DataInfomationItem->GetValue()->GetLabel();
	bool LabelIsSame = true;
	while (DataInfomationItem != nullptr) {
		if (DataInfomationItem->GetValue()->GetLabel() == Labelcheck) {
			DataInfomationItem = DataInfomationItem->GetNext();
		}
		else {
			LabelIsSame = false;
			break;
		}
	}
	if (LabelIsSame) {
		IsLeaf = true;
		NodeSatisfied = nullptr;
		NodeUnsatisfied = nullptr;
		count = 0;
		Statistics.clear();
		Data::DataList *StatisticsItem = DataInfomation;
		while (StatisticsItem != nullptr) {
			count += StatisticsItem->GetValue()->GetSize();
			Statistics[StatisticsItem->GetValue()->GetLabel()] += 
				StatisticsItem->GetValue()->GetSize();
			StatisticsItem = StatisticsItem->GetNext();
		}
		// Release the DataInfo space
		delete[] DataInfomation;
		
		return;
	}
	
	// Check if features are same
	bool FeatureIsSame = true;
	Data::DataList *FeatureCmp = DataInfomation;
	Data::DataList *FeatureItem = FeatureCmp->GetNext();
	int FeatureSize = FeatureCmp->GetValue()->GetFeatureNum();
	while (FeatureItem != nullptr) {
		for (int i = 0; i < FeatureSize; i++) {
			if (FeatureCmp->GetValue()->GetInterval(i) != FeatureItem->GetValue()->GetInterval(i)) {
				FeatureIsSame = false;
				break;
			}
		}
		if (!FeatureIsSame) 
			break;
	}
	if (FeatureIsSame) {
		IsLeaf = true;
		NodeSatisfied = nullptr;
		NodeUnsatisfied = nullptr;
		count = 0;
		Statistics.clear();
		Data::DataList *StatisticsItem = DataInfomation;
		while (StatisticsItem != nullptr) {
			count += StatisticsItem->GetValue()->GetSize();
			Statistics[StatisticsItem->GetValue()->GetLabel()] +=
				StatisticsItem->GetValue()->GetSize();
			StatisticsItem = StatisticsItem->GetNext();
		}
		// Release the DataInfo space
		delete[] DataInfomation;

		return;
	}

	// Choose the maximun addition
	IsLeaf = false;




}


DecisionTree::DecisionTree* DecisionTree::NewDecisionTree(Data::DataList *DataInfomation) {
	DecisionTree *NewTree = new DecisionTreeNode();
	NewTree->DataInfomationInsert(DataInfomation);
	return NewTree;
}

