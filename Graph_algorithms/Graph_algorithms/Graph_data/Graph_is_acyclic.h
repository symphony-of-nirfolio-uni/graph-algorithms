#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Graph_is_acyclic : public Algorithm
	{
		bool dfs(vector<int> &visit, Graph &graph, int vertex, int parent, int stop_type, bool &can_move_on);

	public:
		~Graph_is_acyclic() {}

		void work(Graph graph, int stop_type, bool &can_move_on);
	};
}