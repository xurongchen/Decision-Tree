#include "Data.h"
#include "Interval.h"
#include <cassert>
#include <set>
#define INITIAL_VALUE -1

Data::Data::Data() {
	FeatureList = nullptr;
	FeatureNum = 0;
	Label = INITIAL_VALUE;
	DateSize = 0;
}

Data::Data::Data(Interval::Interval *_FeatureList, int _FeatureNum, int _Label) {
	FeatureList = _FeatureList;
	FeatureNum = _FeatureNum;
	Label = _Label;
	CalculateSize();
}

int Data::Data::GetLabel() {
	return Label;
}

void Data::Data::CalculateSize() {
	int Size = 1;
	assert(FeatureNum > 0);
	for (int i = 0; i < FeatureNum; i++) {
		(FeatureList + i)->Check();
		Size *= (FeatureList + i)->Length();
	}
	DateSize = Size;
}

int Data::Data::GetSize() {
	return DateSize;
}

int Data::Data::GetFeatureNum() {
	return FeatureNum;
}

Interval::Interval Data::Data::GetInterval(int Sublabel) {
	return *(FeatureList + Sublabel);
}

Data::Data::~Data() {
	if(FeatureList!=nullptr)
		delete[] FeatureList;
}

Data::DataList::DataList() {
	Value = nullptr;
	Next = nullptr;
}

Data::DataList *Data::DataList::Append(Data *Value) {
	DataList *NewData = new DataList();
	NewData->Value = Value;
	NewData->Next = this;
	return NewData;
}

Data::Data* Data::DataList::GetValue() {
	return Value;
}

Data::DataList* Data::DataList::GetNext() {
	return Next;
}

int Data::DataList::GetFeatureNum() {
	if (this == nullptr)
		assert(0);
	return GetValue()->GetFeatureNum();
}

Data::BoundaryList Data::DataList::GetBoundaryList(int FeatureSubLabel) {
	std::set<int> BoundarySet;
	DataList *DataInfomationItem = this;
	while (DataInfomationItem != nullptr) {
		BoundarySet.insert(DataInfomationItem->GetValue()
			->GetInterval(FeatureSubLabel).GetRightBorder());
		BoundarySet.insert(DataInfomationItem->GetValue()
			->GetInterval(FeatureSubLabel).GetLeftBorder()-1);
		DataInfomationItem = DataInfomationItem->GetNext();
	}
	int SetSize = BoundarySet.size();
	int *BoundaryList = new int[SetSize + 5];
	int ListSize = 0;
	for (std::set<int>::iterator it = BoundarySet.begin(); it != BoundarySet.end(); ++it) {
		*(BoundaryList + (ListSize++)) = *it;
	}
	return std::make_pair(BoundaryList, ListSize);
}

Data::EntropyAddition Data::DataList::CalculateEntropyAddition(int FeatureSubLabel, int Boundary) {

}

Data::FeatureAddition Data::DataList::GetMaximumFeatureAddition() {

}

Data::DataList::~DataList() {
	if (Value != nullptr)
		delete Value;
	if (Next != nullptr)
		delete Next;
}


