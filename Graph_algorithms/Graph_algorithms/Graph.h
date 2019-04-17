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
		bool weight;
		bool direct;

		vector<vector<pair<int, int> > > graph;


		Graph();
		Graph(vector<vector<pair<int, int> > > graph);
		Graph(vector<vector<pair<int, int> > > graph, bool weight, bool direct);

		~Graph();
	};
}