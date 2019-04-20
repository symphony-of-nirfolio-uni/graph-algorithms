#pragma once


#include "Graph.h"
#include <memory>


using std::shared_ptr;
using std::make_shared;
using std::enable_shared_from_this;


namespace algorithms_on_graphs
{
	class Read_graph;
	class Read_graph_builder;


	class Read_graph_builder : public enable_shared_from_this<Read_graph_builder>
	{

	public:
		bool weight;
		bool direct;

		Read_graph_builder();

		~Read_graph_builder();


		shared_ptr<Read_graph_builder> add_weight();

		shared_ptr<Read_graph_builder> add_direct();

		Read_graph build();
	};
}