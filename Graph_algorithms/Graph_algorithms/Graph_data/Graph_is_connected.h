#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Graph_is_connected : public Algorithm
	{
		bool dfs(vector<bool> &visit, Graph &graph, int vertex, bool need_to_stop);

	public:
		~Graph_is_connected() {}

		void work(Graph graph, bool need_to_stop);
	};
}