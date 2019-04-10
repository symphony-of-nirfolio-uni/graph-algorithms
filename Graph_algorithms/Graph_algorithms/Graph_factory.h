#pragma once


#include "Read_graph.h"


namespace algorithms_on_graphs
{
	class Graph_factory
	{

	protected:
		string prefix;

		virtual Read_graph get_read_graph() = 0;

	public:
		Graph_factory();
		Graph_factory(string prefix);

		Graph make_graph();
	};


	class Weighted_directed_graph_factory : public Graph_factory
	{
		Read_graph get_read_graph();

	public:
		Weighted_directed_graph_factory();
		Weighted_directed_graph_factory(string prefix);
	};

	class Weighted_undirected_graph_factory : public Graph_factory
	{
		Read_graph get_read_graph();

	public:
		Weighted_undirected_graph_factory();
		Weighted_undirected_graph_factory(string prefix);
	};

	class Unweighted_directed_graph_factory : public Graph_factory
	{
		Read_graph get_read_graph();

	public:
		Unweighted_directed_graph_factory();
		Unweighted_directed_graph_factory(string prefix);
	};

	class Unweighted_undirected_graph_factory : public Graph_factory
	{
		Read_graph get_read_graph();

	public:
		Unweighted_undirected_graph_factory();
		Unweighted_undirected_graph_factory(string prefix);
	};
}