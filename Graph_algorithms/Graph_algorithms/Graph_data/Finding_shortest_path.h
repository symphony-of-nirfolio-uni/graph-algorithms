#pragma once


#include "Algorithm.h"


namespace algorithms_on_graphs
{
	class Finding_shortest_path : public Algorithm
	{
		
	public:
		void work(Graph graph, int start, int finish, bool need_to_stop);
	};
}