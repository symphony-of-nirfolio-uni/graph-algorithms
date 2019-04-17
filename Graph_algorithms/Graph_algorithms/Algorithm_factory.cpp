#include "Algorithm_factory.h"


namespace algorithms_on_graphs
{
	shared_ptr<Algorithm> Graph_is_acyclic_factory::get_algorithm()
	{
		return make_shared<Graph_is_acyclic>();
	}

	Graph Graph_is_acyclic_factory::get_graph(string prefix, bool need_direct)
	{
		if (need_direct)
		{
			Read_graph read_graph = make_shared<Read_graph_builder>()->add_direct()->build();
			return read_graph.get_graph(prefix);
		}
		else
		{
			Read_graph read_graph = make_shared<Read_graph_builder>()->build();
			return read_graph.get_graph(prefix);
		}
	}


	shared_ptr<Algorithm> Graph_is_connected_factory::get_algorithm()
	{
		return make_shared<Graph_is_connected>();
	}

	Graph Graph_is_connected_factory::get_graph(string prefix, bool need_direct)
	{
		return Graph_is_acyclic_factory::get_graph(prefix, need_direct);
	}
}

