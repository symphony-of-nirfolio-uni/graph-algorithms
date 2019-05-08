#include "Algorithm.h"

#include <exception>


namespace algorithms_on_graphs
{
	void Algorithm::waiting_for_the_next_move()
	{
		while (!GraphAPI::instance().can_move_on() || GraphAPI::instance().algorithm_is_ended())
		{

		}

		if (GraphAPI::instance().algorithm_is_ended())
		{
			std::terminate();
		}
	}
}