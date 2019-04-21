#include "Graph_is_acyclic.h"


namespace algorithms_on_graphs
{
	bool Graph_is_acyclic::dfs(vector<int> &visit, Graph &graph, int vertex, int parent, bool need_to_stop)
	{
		visit[vertex] = 1;

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI::getInstance().highlight_vertex(vertex);
			//TempAPI::getInstance().highlight_vertex();
			//waiting_for_the_next_move();
		}
		//

		for (int i = 0; i < int(graph.graph[vertex].size()); ++i)
		{
			int new_vertex = graph.graph[vertex][i].first;

			if (graph.direct && visit[new_vertex] == 1)
			{
				return false;
			}
			else if (!graph.direct && visit[new_vertex] == 1 && new_vertex != parent)
			{
				return false;
			}
			else if (visit[new_vertex] == 0)
			{
				if (!dfs(visit, graph, new_vertex, vertex, need_to_stop))
				{
					return false;
				}
			}
		}

		visit[vertex] = 2;

		//GraphAPI part
		if (need_to_stop)
		{
			//GraphAPI:::getInstance().mark_vertex(vertex);
			//waiting_for_the_next_move();
		}
		//

		return true;
	}


	void Graph_is_acyclic::work(Graph graph, bool need_to_stop)
	{
		vector<int> visit(graph.graph.size(), 0);

		for (int i = 0; i < int(graph.graph.size()); ++i)
		{
			if (visit[i] == 0 && !dfs(visit, graph, i, -1, need_to_stop))
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