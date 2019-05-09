#pragma once


#include "Algorithm.h"
#include "Graph_is_acyclic.h"
#include "Graph_is_connected.h"
#include "Finding_shortest_path.h"
#include "Read_graph.h"


namespace algorithms_on_graphs
{
	template<typename Factory>
	class Algorithm_factory
	{

	public:
		static shared_ptr<Algorithm> get_algorithm()
		{
			return Factory::get_algorithm_private();
		}

		static Graph get_graph(string prefix)
		{
			return Factory::get_graph_private(prefix);
		}
	};


	class Graph_is_acyclic_factory : public Algorithm_factory<Graph_is_acyclic_factory>
	{

	public:
		static shared_ptr<Algorithm> get_algorithm_private();

		static Graph get_graph_private(string prefix, bool need_direct = true);
	};

	class Graph_is_connected_factory : public Algorithm_factory<Graph_is_connected_factory>
	{

	public:
		static shared_ptr<Algorithm> get_algorithm_private();

		static Graph get_graph_private(string prefix, bool need_direct = true);
	};

	class Finding_shortest_path_factory : public Algorithm_factory<Finding_shortest_path_factory>
	{

	public:
		static shared_ptr<Algorithm> get_algorithm_private();

		static Graph get_graph_private(string prefix, bool need_direct = true);
	};
}