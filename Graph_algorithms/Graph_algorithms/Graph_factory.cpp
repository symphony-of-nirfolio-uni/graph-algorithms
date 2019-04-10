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


	Graph Graph_factory::make_graph()
	{
		Read_graph read_graph = get_read_graph();

		return read_graph.get_graph(prefix);
	}


	Weighted_directed_graph_factory::Weighted_directed_graph_factory() : Graph_factory()
	{

	}
	
	Weighted_directed_graph_factory::Weighted_directed_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Read_graph Weighted_directed_graph_factory::get_read_graph()
	{
		return make_shared<Read_graph_builder>()->add_direct()->add_weight()->build();
	}


	Weighted_undirected_graph_factory::Weighted_undirected_graph_factory() : Graph_factory()
	{

	}

	Weighted_undirected_graph_factory::Weighted_undirected_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Read_graph Weighted_undirected_graph_factory::get_read_graph()
	{
		return make_shared<Read_graph_builder>()->add_weight()->build();
	}


	Unweighted_directed_graph_factory::Unweighted_directed_graph_factory() : Graph_factory()
	{

	}

	Unweighted_directed_graph_factory::Unweighted_directed_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Read_graph Unweighted_directed_graph_factory::get_read_graph()
	{
		return make_shared<Read_graph_builder>()->add_direct()->build();
	}


	Unweighted_undirected_graph_factory::Unweighted_undirected_graph_factory() : Graph_factory()
	{

	}

	Unweighted_undirected_graph_factory::Unweighted_undirected_graph_factory(string prefix) : Graph_factory(prefix)
	{

	}

	Read_graph Unweighted_undirected_graph_factory::get_read_graph()
	{
		return make_shared<Read_graph_builder>()->build();
	}
}

