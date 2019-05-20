#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Graph_is_connected : public Algorithm
	{
		bool dfs(vector<bool> &visit, Graph &graph, int vertex, int stop_type, int &can_move_on);

	public:
		~Graph_is_connected() {}

		void work(Graph graph, int stop_type, int &can_move_on);
	};
}