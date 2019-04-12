#include "Graph_is_acyclic.h"


namespace algorithms_on_graphs
{
	bool Graph_is_acyclic::dfs(vector<int> &visit, Graph &graph, int vertex, int parent, bool need_to_stop)
	{
		visit[vertex] = 1;

		//GraphAPI part
		//GraphAPI::instance.highlight_vertex();
		if (need_to_stop)
		{
			//GraphAPI::instance.can_move_on();
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
				dfs(visit, graph, new_vertex, vertex, need_to_stop);
			}
		}

		visit[vertex] = 2;

		//GraphAPI part
		//GraphAPI::instance.mark_vertex();
		if (need_to_stop)
		{
			//GraphAPI::instance.can_move_on();
		}
		//

		return true;
	}


	bool Graph_is_acyclic::work(Graph graph, bool need_to_stop)
	{
		vector<int> visit(graph.graph.size(), 0);

		for (int i = 0; i < int(graph.graph.size()); ++i)
		{
			if (visit[i] == 0 && !dfs(visit, graph, i, -1, need_to_stop))
			{
				return false;
			}
		}

		return true;
	}

}