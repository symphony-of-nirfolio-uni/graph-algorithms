#pragma once


#include "Read_graph.h"


namespace algorithms_on_graphs
{
	class Graph_factory
	{

	protected:
		string prefix;

	public:
		Graph_factory();
		Graph_factory(string prefix);

		virtual Graph make_graph() = 0;
	};


	class Weighted_directed_graph_factory : public Graph_factory
	{

	public:
		Weighted_directed_graph_factory();
		Weighted_directed_graph_factory(string prefix);

		Graph make_graph();
	};

	class Weighted_undirected_graph_factory : public Graph_factory
	{

	public:
		Weighted_undirected_graph_factory();
		Weighted_undirected_graph_factory(string prefix);

		Graph make_graph();
	};

	class Unweighted_directed_graph_factory : public Graph_factory
	{

	public:
		Unweighted_directed_graph_factory();
		Unweighted_directed_graph_factory(string prefix);

		Graph make_graph();
	};

	class Unweighted_undirected_graph_factory : public Graph_factory
	{

	public:
		Unweighted_undirected_graph_factory();
		Unweighted_undirected_graph_factory(string prefix);

		Graph make_graph();
	};
}