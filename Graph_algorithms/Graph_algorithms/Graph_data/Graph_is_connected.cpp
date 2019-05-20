#include "Graph_is_connected.h"


namespace algorithms_on_graphs
{
	bool Graph_is_connected::dfs(vector<bool> &visit, Graph &graph, int vertex, int stop_type, int &can_move_on)
	{
		visit[vertex] = true;

		//GraphAPI part
		if (stop_type == 1)
		{
			GraphAPI::instance().set_highlighted(vertex);
            waiting_for_the_next_move();

			if (GraphAPI::instance().algorithm_is_ended())
			{
				return false;
			}
		}
		else if (stop_type == -1)
		{
			waiting_for_the_next_move(can_move_on);
		}


		for (auto new_vertex : graph.at(vertex))
		{
			if (visit[new_vertex] == false)
			{
				//GraphAPI part
				if (stop_type == 1)
				{
					GraphAPI::instance().set_used_mark(vertex);
				}

				dfs(visit, graph, new_vertex, stop_type, can_move_on);

				//GraphAPI part
				if (stop_type == 1)
				{
					if (GraphAPI::instance().algorithm_is_ended())
					{
						return false;
					}
				}

				//GraphAPI part
				if (stop_type == 1)
				{
					GraphAPI::instance().set_highlighted(vertex);
					waiting_for_the_next_move();

					if (GraphAPI::instance().algorithm_is_ended())
					{
						return false;
					}
				}
				else if (stop_type == -1)
				{
					waiting_for_the_next_move(can_move_on);
				}
			}
		}

		//GraphAPI part
		if (stop_type == 1)
		{
			GraphAPI::instance().set_black_mark(vertex);
		}

		return true;
	}


	void Graph_is_connected::work(Graph graph, int stop_type, int &can_move_on)
	{
		vector<bool> visit(graph.size(), false);

		dfs(visit, graph, 0, stop_type, can_move_on);

		//GraphAPI part
		if (stop_type == 1)
		{
			if (GraphAPI::instance().algorithm_is_ended())
			{
				return;
			}
		}

		for (auto vertex : graph)
		{
			if (visit[vertex.id()] == false)
			{
				//GraphAPI part
				if (stop_type == 1)
				{
					GraphAPI::instance().set_result("Graph is not connected");
					GraphAPI::instance().end_of_the_algorithm();
				}
				else if (stop_type == -1)
				{
					can_move_on = -1;
				}

				return;
			}
		}

		//GraphAPI part
		if (stop_type == 1)
		{
			GraphAPI::instance().set_result("Graph is connected");
			GraphAPI::instance().end_of_the_algorithm();
		}
		else if (stop_type == -1)
		{
			can_move_on = -1;
		}
	}

}
