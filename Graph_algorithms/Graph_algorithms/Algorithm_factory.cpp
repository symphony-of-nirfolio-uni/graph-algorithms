#include "Algorithm_factory.h"
#include "Graph_is_acyclic.h"
#include "Graph_is_connected.h"


namespace algorithms_on_graphs
{
	shared_ptr<Algorithm> Graph_is_acyclic_factory::get_algorithm()
	{
		return make_shared<Graph_is_acyclic>();
	}

	Graph Graph_is_acyclic_factory::get_graph(string prefix)
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();
		return read_graph.get_graph(prefix);
	}


	shared_ptr<Algorithm> Graph_is_connected_factory::get_algorithm()
	{
		return make_shared<Graph_is_connected>();
	}

	Graph Graph_is_connected_factory::get_graph(string prefix)
	{
		Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();
		return read_graph.get_graph(prefix);
	}
}

