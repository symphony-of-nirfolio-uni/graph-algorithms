#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Graph_is_acyclic : public Algorithm
	{
		bool dfs(vector<int> &visit, Graph &graph, int vertex, int parent, bool need_to_stop);

	public:
		bool work(Graph graph, bool need_to_stop);
	};
}