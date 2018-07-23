#pragma once


namespace Interval {
	class Interval {
	private:
		int LeftBorder, RightBorder;
	public:
		Interval();
		Interval(int _LeftBorder, int _RightBorder);
		bool operator == (Interval x);
		bool operator != (Interval x);
		int Length();
		int GetLeftBorder();
		int GetRightBorder();
		void Check();
	}; 
}
