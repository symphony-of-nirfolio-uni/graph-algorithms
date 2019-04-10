#include "Read_graph.h"


namespace algorithms_on_graphs
{
	Read_graph::Read_graph(shared_ptr<Read_graph_builder> builder)
	{
		weight = builder->weight;
		direct = builder->direct;
	}

	Read_graph::~Read_graph()
	{

	}

	bool Read_graph::get_Weight()
	{
		return weight;
	}

	bool Read_graph::get_Direct()
	{
		return direct;
	}
}