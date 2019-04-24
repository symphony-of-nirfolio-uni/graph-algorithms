#pragma once
#include "../Graph_data/Graph.h"

namespace build_dots
{
	using algorithms_on_graphs::Graph;
	const double pi = 3.14159265358979;

	class Point
	{
	public:
		double x, y;
		Point();
		Point(double x, double y);
		~Point();
	};

	Point getDot(double angle, int i, double radius);
	vector<Point> getAllDots(Graph graph);
}
