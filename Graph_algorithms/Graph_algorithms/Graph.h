#pragma once


#include <vector>
#include <string>


using std::vector;
using std::pair;
using std::string;


namespace algorithms_on_graphs
{
	struct Graph
	{
		vector<vector<pair<int, int> > > graph;

		Graph();

		~Graph();
	};
}