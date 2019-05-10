#include "Algorithm.h"
//#include "../GraphUI/messagedialog.h"

#include <exception>
#include <thread>

namespace algorithms_on_graphs
{
    bool Algorithm::waiting_for_the_next_move()
	{

        while (!GraphAPI::instance().can_move_on() && !GraphAPI::instance().algorithm_is_ended())
		{

		}
        if (GraphAPI::instance().algorithm_is_ended())
        {
           return true;

        }
        return false;
	}

}
