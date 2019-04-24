#include "Graph_is_connected.h"


namespace algorithms_on_graphs
{
	bool Graph_is_connected::dfs(vector<bool> &visit, Graph &graph, int vertex, bool need_to_stop)
	{
		visit[vertex] = true;

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI::instance.mark_vertex(vertex);
			//waiting_for_the_next_move();
		}
		//

		for (auto new_vertex : graph.at(vertex))
		{
			if (visit[new_vertex] == false)
			{
				dfs(visit, graph, new_vertex, need_to_stop);
			}
		}

		return true;
	}


	void Graph_is_connected::work(Graph graph, bool need_to_stop)
	{
		vector<bool> visit(graph.size(), false);

		dfs(visit, graph, 0, need_to_stop);

		for (auto vertex : graph)
		{
			if (visit[vertex.id()] == false)
			{
				//GraphAPI part
				if (need_to_stop)
				{
					//GraphAPI::instance.result(false);
					//GraphAPI::instance.end_of_the_algorithm();
				}
				//

				return;
			}
		}

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI::instance.result(true);
			//GraphAPI::instance.end_of_the_algorithm();
		}
		//
	}

}