#include "Interval.h"
#include <cassert>

Interval::Interval::Interval() {

}

Interval::Interval::Interval(int _LeftBorder, int _RightBorder) {
	LeftBorder = _LeftBorder;
	RightBorder = _RightBorder;
}

int Interval::Interval::Length() {
	return RightBorder - LeftBorder + 1;
}

void Interval::Interval::Check() {
	assert(RightBorder >= LeftBorder);
}
