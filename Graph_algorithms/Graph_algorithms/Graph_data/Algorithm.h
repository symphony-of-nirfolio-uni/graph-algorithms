#pragma once


#include "../GraphAPI/GraphAPI.h"


namespace algorithms_on_graphs
{
	class Algorithm
	{

	protected:
        void waiting_for_the_next_move();
        void waiting_for_the_next_move(bool &can_move_on);

		bool get_can_move_on(bool &can_move_on);

	public:
		virtual ~Algorithm() {}

		virtual void work(Graph, int, bool &) {}
		//stop_type:
		//0 - without stop
		//1 - stop for GraphAPI
		//-1 - stop for memory check
		void work(Graph graph, int stop_type);

		virtual void work(Graph, int, int, int, bool &) {}
		//stop_type:
		//0 - without stop
		//1 - stop for GraphAPI
		//-1 - stop for memory check
		void work(Graph graph, int start, int finish, int stop_type);
	};
}
