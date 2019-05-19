#pragma once


#include "Algorithm.h"

#include <queue>


using std::queue;


namespace algorithms_on_graphs
{
	class Finding_shortest_path : public Algorithm
	{
		void bfs(Graph &graph, queue<int> &next_verteces, vector<int> &direction, int finish, int stop_type, bool &can_move_on);

		Graph create_route(Graph &graph, vector<int> &direction, int start, int finish);

	public:
		~Finding_shortest_path() {}

		void work(Graph graph, int start, int finish, int stop_type, bool &can_move_on);
	};
}