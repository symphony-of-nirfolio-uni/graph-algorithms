#include "Graph_factory.h"


namespace algorithms_on_graphs
{
	Graph_factory::Graph_factory()
	{
		prefix = "Graph_data/";
	}

	Graph_factory::Graph_factory(string prefix) : prefix(prefix)
	{

	}


	Weighted_directed_graph_factory::Weighted_directed_graph_factory() : Graph_factory()
	{

	}
	
	Weighted_directed_graph_factory::Weighted_directed_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Graph Weighted_directed_graph_factory::make_graph()
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->add_weight()->build();
		return read_graph.get_graph(prefix);
	}


	Weighted_undirected_graph_factory::Weighted_undirected_graph_factory() : Graph_factory()
	{

	}

	Weighted_undirected_graph_factory::Weighted_undirected_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Graph Weighted_undirected_graph_factory::make_graph()
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->add_weight()->build();
		return read_graph.get_graph(prefix);
	}


	Unweighted_directed_graph_factory::Unweighted_directed_graph_factory() : Graph_factory()
	{

	}

	Unweighted_directed_graph_factory::Unweighted_directed_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Graph Unweighted_directed_graph_factory::make_graph()
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();
		return read_graph.get_graph(prefix);
	}


	Unweighted_undirected_graph_factory::Unweighted_undirected_graph_factory() : Graph_factory()
	{

	}

	Unweighted_undirected_graph_factory::Unweighted_undirected_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Graph Unweighted_undirected_graph_factory::make_graph()
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->build();
		return read_graph.get_graph(prefix);
	}
}

