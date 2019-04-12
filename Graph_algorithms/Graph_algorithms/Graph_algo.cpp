#include "Graph_algo.h"


namespace algorithms_on_graphs
{
	Graph_algo::Graph_algo(shared_ptr<Algorithm> algorithm) : algorithm(algorithm)
	{

	}
	
	Graph_algo::~Graph_algo()
	{

	}


	bool Graph_algo::work(Graph graph)
	{
		return algorithm->work(graph, true);
	}

	bool Graph_algo::work_without_stops(Graph graph)
	{
		return algorithm->work(graph, false);
	}
}