#pragma once
#include "Interval.h"
#include <iostream>

namespace Data {

	class Data {
	private:
		Interval::Interval *FeatureList;
		int FeatureNum;
		int DateSize;
		int Label;
	public:
		Data();
		Data(Interval::Interval *_FeatureList,int _FeatureNum,int _Label);
		int GetLabel();
		void CalculateSize();
		int GetSize();
		int GetFeatureNum();
		Interval::Interval GetInterval(int Sublabel);
		~Data();

	};

	typedef int FeatureChoosed;
	typedef double EntropyAddition;
	typedef std::pair<FeatureChoosed, EntropyAddition> FeatureAddition;
	typedef int* BoundaryPointer;
	typedef int ListSize;
	typedef std::pair<BoundaryPointer, ListSize> BoundaryList;
	class DataList {
	private:
		Data *Value;
		DataList *Next;
	protected:
		DataList();
	public:
		DataList *Append(Data *Value);// Copy Straight
		Data *GetValue();
		DataList *GetNext();
		int GetFeatureNum();
		BoundaryList GetBoundaryList(int FeatureSubLabel);
		EntropyAddition CalculateEntropyAddition(int FeatureSubLabel, int Boundary);
		FeatureAddition GetMaximumFeatureAddition();

		~DataList();
	};


}