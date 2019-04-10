#pragma once


#include "Read_graph_builder.h"


namespace algorithms_on_graphs
{
	class Read_graph
	{
		bool weight;
		bool direct;

	public:
		Read_graph(shared_ptr<Read_graph_builder> builder);

		~Read_graph();

		bool get_Weight();
		bool get_Direct();
	};

}