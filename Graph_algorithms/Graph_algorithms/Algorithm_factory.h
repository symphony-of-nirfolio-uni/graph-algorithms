#pragma once


#include "Algorithm.h"
#include "Graph_is_acyclic.h"
#include "Graph_is_connected.h"
#include "Read_graph.h"


namespace algorithms_on_graphs
{
	class Algorithm_factory
	{

	public:
		virtual shared_ptr<Algorithm> get_algorithm() = 0;

		virtual Graph get_graph(string prefix) = 0;
	};


	class Graph_is_acyclic_factory : public Algorithm_factory
	{

	public:
		static shared_ptr<Algorithm> get_algorithm();

		static Graph get_graph(string prefix, bool need_direct = true);
	};

	class Graph_is_connected_factory : public Algorithm_factory
	{

	public:
		static shared_ptr<Algorithm> get_algorithm();

		static Graph get_graph(string prefix, bool need_direct = true);
	};
}