#pragma once


namespace Interval {
	class Interval {
	private:
		int LeftBorder, RightBorder;
	public:
		Interval();
		Interval(int _LeftBorder, int _RightBorder);
		int Length();
		void Check();
	}; 
}
