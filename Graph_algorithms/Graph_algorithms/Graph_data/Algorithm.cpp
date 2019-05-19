#include "Algorithm.h"


namespace algorithms_on_graphs
{
    void Algorithm::waiting_for_the_next_move()
	{
        while (!GraphAPI::instance().can_move_on() && !GraphAPI::instance().algorithm_is_ended())
		{

        }
	}

    void Algorithm::waiting_for_the_next_move(bool &can_move_on)
	{
        while (!get_can_move_on(can_move_on))
		{

        }
	}


	bool Algorithm::get_can_move_on(bool &can_move_on)
	{
		if (can_move_on)
		{
			can_move_on = false;
			return true;
		}
		return false;
	}


	void Algorithm::work(Graph graph, int stop_type)
	{
		bool can_move_on = true;
		work(graph, stop_type, can_move_on);
	}

	void Algorithm::work(Graph graph, int start, int finish, int stop_type)
	{
		bool can_move_on = true;
		work(graph, start, finish, stop_type, can_move_on);
	}
}
