#pragma once


#include "Algorithm.h"
#include "Graph_factory.h"


namespace algorithms_on_graphs
{
	class Algorithm_factory
	{

	public:
		virtual shared_ptr<Algorithm> get_algorithm() = 0;

		virtual Graph get_graph() = 0;
	};


	class Graph_is_acyclic_factory : public Algorithm_factory
	{

	public:
		shared_ptr<Algorithm> get_algorithm();

		Graph get_graph();
	};

	class Graph_is_connected_factory : public Algorithm_factory
	{

	public:
		shared_ptr<Algorithm> get_algorithm();

		Graph get_graph();
	};
}