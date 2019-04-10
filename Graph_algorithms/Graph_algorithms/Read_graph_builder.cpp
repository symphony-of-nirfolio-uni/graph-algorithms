#include "Read_graph_builder.h"
#include "Read_graph.h"


namespace algorithms_on_graphs
{
	Read_graph_builder::Read_graph_builder()
	{
		weight = false;
		direct = false;
	}

	Read_graph_builder::~Read_graph_builder()
	{

	}

	shared_ptr<Read_graph_builder> Read_graph_builder::add_weight()
	{
		weight = true;
		return shared_from_this();
	}

	shared_ptr<Read_graph_builder> Read_graph_builder::add_direct()
	{
		direct = true;
		return shared_from_this();
	}

	Read_graph Read_graph_builder::build()
	{
		return Read_graph(shared_from_this());
	}
}