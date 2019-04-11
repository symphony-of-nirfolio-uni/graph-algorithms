#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Graph_is_acyclic : public Algorithm
	{

	public:
		bool work(Graph graph, bool need_to_stop);
	};
}