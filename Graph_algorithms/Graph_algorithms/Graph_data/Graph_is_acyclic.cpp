#include "Graph_is_acyclic.h"


namespace algorithms_on_graphs
{
	bool Graph_is_acyclic::dfs(vector<int> &visit, Graph &graph, int vertex, int parent, int stop_type, bool &can_move_on)
	{
		visit[vertex] = 1;

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
			if (graph.is_direct() && visit[new_vertex] == 1)
			{
				return false;
			}
			else if (!graph.is_direct() && visit[new_vertex] == 1 && new_vertex != parent)
			{
				return false;
			}
			else if (visit[new_vertex] == 0)
			{
				//GraphAPI part
				if (stop_type == 1)
				{
					GraphAPI::instance().set_used_mark(vertex);
				}

				if (!dfs(visit, graph, new_vertex, vertex, stop_type, can_move_on))
				{
					return false;
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

		visit[vertex] = 2;


		//GraphAPI part
		if (stop_type == 1)
		{
			GraphAPI::instance().set_black_mark(vertex);
		}

		return true;
	}


	void Graph_is_acyclic::work(Graph graph, int stop_type, bool &can_move_on)
	{
		vector<int> visit(graph.size(), 0);

		for (auto vertex : graph)
		{
			if (visit[vertex.id()] == 0 && !dfs(visit, graph, vertex.id(), -1, stop_type, can_move_on))
			{
				//GraphAPI part
				if (stop_type == 1)
				{
					if (GraphAPI::instance().algorithm_is_ended())
					{
						return;
					}

					GraphAPI::instance().set_result("Graph is not acyclic");
					GraphAPI::instance().end_of_the_algorithm();
				}

				return;
			}
		}

		//GraphAPI part
		if (stop_type == 1)
		{
			if (GraphAPI::instance().algorithm_is_ended())
			{
				return;
			}

			GraphAPI::instance().set_result("Graph is acyclic");
			GraphAPI::instance().end_of_the_algorithm();
		}
	}

}