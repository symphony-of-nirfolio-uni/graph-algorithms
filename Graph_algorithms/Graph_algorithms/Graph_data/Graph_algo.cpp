#include "Graph_algo.h"
#include <thread>
#include <chrono>


namespace algorithms_on_graphs
{
	Graph_algo::Graph_algo(shared_ptr<Algorithm> algorithm) : algorithm(algorithm)
	{

	}
	
	Graph_algo::~Graph_algo()
	{

	}


	void Graph_algo::run_work(Graph &graph, bool need_to_stop)
	{
		algorithm->work(graph, need_to_stop);
	}	


	void Graph_algo::work(Graph graph)
	{
		std::thread thread_algo(&Graph_algo::run_work, this, std::ref(graph), 1);
		
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		
		thread_algo.detach();
	}

	void Graph_algo::work(Graph graph, bool &can_move_on)
	{
		algorithm->work(graph, -1, can_move_on);
	}

	void Graph_algo::work_without_stops(Graph graph)
	{
		algorithm->work(graph, 0);
	}
}