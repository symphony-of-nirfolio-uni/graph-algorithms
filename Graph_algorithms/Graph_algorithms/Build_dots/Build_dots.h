#pragma once
#include "../Graph_data/Graph.h"

using algorithms_on_graphs::Graph;

namespace build_dots
{
	const double pi = 3.14159265358979;

	class Point
	{
	public:
		double x, y;
		Point();
		Point(double x, double y);
		~Point();
	};

	Point getDot(Point mainDot, double angle, int i, double radius);
}