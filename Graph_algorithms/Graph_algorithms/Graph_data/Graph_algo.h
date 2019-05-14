#pragma once


#include "Algorithm_factory.h"


namespace algorithms_on_graphs
{
	class Graph_algo
	{
		shared_ptr<Algorithm> algorithm;

		void run_work(Graph &graph, bool need_to_stop);

	public:
		Graph_algo(shared_ptr<Algorithm> algorithm);

		~Graph_algo();

		void work(Graph graph);
		void work(Graph graph, bool &can_move_on);
		void work_without_stops(Graph graph);
	};
}
