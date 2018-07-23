#pragma once
#include "Interval.h"

namespace Data {
	class Data {
		Interval::Interval *FeatureList;
		int FeatureNum;
		int Label;
	public:
		Data();

	};

	class DataList {
		Data *Value;
		DataList *Next;
	public:
		DataList();
		DataList *Append(Data *Value);
		Data *GetValue();
		Data *GetNext();
	};

}