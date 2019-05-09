#pragma once


#include "../GraphAPI/GraphAPI.h"


namespace algorithms_on_graphs
{
	class Algorithm
	{

	protected:
		void waiting_for_the_next_move();

	public:
		virtual ~Algorithm() {}

		virtual void work(Graph, bool) {}
		virtual void work(Graph, int, int, bool) {}
	};
}