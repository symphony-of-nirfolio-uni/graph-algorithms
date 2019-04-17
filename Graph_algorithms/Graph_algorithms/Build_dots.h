#pragma once
#include "Graph.h"
#include "math.h"
#include "cmath"

using algorithms_on_graphs::Graph;

namespace build_dots
{
	vector<pair<int, int> > get_coordinates_of_vertexes(const Graph &graph);
	vector<pair<int, int> > get_coordinates_of_edges(const Graph &graph);
}