#pragma once


#include "Algorithm_factory.h"


namespace algorithms_on_graphs
{
	class Graph_algo
	{
		shared_ptr<Algorithm> algorithm;

	public:
		Graph_algo(shared_ptr<Algorithm> algorithm);

		~Graph_algo();

		void work(Graph graph);
		void work_without_stops(Graph graph);
	};
}
