#include "Graph_is_connected.h"


namespace algorithms_on_graphs
{
	bool Graph_is_connected::dfs(vector<bool> &visit, Graph &graph, int vertex, bool need_to_stop)
	{
		visit[vertex] = true;

		//GraphAPI part
		if (need_to_stop)
		{
			GraphAPI::instance().set_highlighted(vertex);
			waiting_for_the_next_move();

			if (GraphAPI::instance().algorithm_is_ended())
			{
				return false;
			}
		}

		for (auto new_vertex : graph.at(vertex))
		{
			if (visit[new_vertex] == false)
			{
				//GraphAPI part
				if (need_to_stop)
				{
					GraphAPI::instance().set_used_mark(vertex);
				}

				dfs(visit, graph, new_vertex, need_to_stop);

				//GraphAPI part
				if (need_to_stop)
				{
					if (GraphAPI::instance().algorithm_is_ended())
					{
						return false;
					}
				}

				//GraphAPI part
				if (need_to_stop)
				{
					GraphAPI::instance().set_highlighted(vertex);
					waiting_for_the_next_move();

					if (GraphAPI::instance().algorithm_is_ended())
					{
						return false;
					}
				}
			}
		}

		//GraphAPI part
		if (need_to_stop)
		{
			GraphAPI::instance().set_black_mark(vertex);
		}

		return true;
	}


	void Graph_is_connected::work(Graph graph, bool need_to_stop)
	{
		vector<bool> visit(graph.size(), false);

		dfs(visit, graph, 0, need_to_stop);

		//GraphAPI part
		if (need_to_stop)
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
				if (need_to_stop)
				{
					GraphAPI::instance().set_result("Graph is not connected");
					GraphAPI::instance().end_of_the_algorithm();
				}

				return;
			}
		}

		//GraphAPI part
		if (need_to_stop)
		{
			GraphAPI::instance().set_result("Graph is connected");
			GraphAPI::instance().end_of_the_algorithm();
		}
	}

}