#include "Interval.h"
#include <cassert>

Interval::Interval::Interval() {

}

Interval::Interval::Interval(int _LeftBorder, int _RightBorder) {
	LeftBorder = _LeftBorder;
	RightBorder = _RightBorder;
}

bool Interval::Interval::operator == (Interval x) {
	return (LeftBorder == x.LeftBorder) && (RightBorder == x.RightBorder);
}

bool Interval::Interval::operator != (Interval x) {
	return !(*this == x);
}

int Interval::Interval::Length() {
	Check();
	return RightBorder - LeftBorder + 1;
}

int Interval::Interval::GetLeftBorder() {
	return LeftBorder;
}

int Interval::Interval::GetRightBorder() {
	return RightBorder;
}

void Interval::Interval::Check() {
	assert(RightBorder >= LeftBorder);
}
