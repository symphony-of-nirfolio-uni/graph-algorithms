#include "Finding_shortest_path.h"


namespace algorithms_on_graphs
{
	void Finding_shortest_path::bfs(Graph &graph, queue<int> &next_verteces, vector<int> &direction, int finish, bool need_to_stop)
	{
		while (!next_verteces.empty())
		{
			int vertex = next_verteces.front();
			next_verteces.pop();

			//GraphAPI part
			if (need_to_stop)
			{
				//GraphAPI::getInstance().highlight_vertex(vertex);
				//waiting_for_the_next_move();
			}
			//

			for (auto new_vertex : graph.at(vertex).adjacent())
			{
				if (direction[new_vertex] != -1)
				{
					next_verteces.push(new_vertex);
					direction[new_vertex] = vertex;

					if (new_vertex == finish)
					{
						return;
					}
				}
			}

			//GraphAPI part
			if (need_to_stop)
			{
				//GraphAPI:::getInstance().mark_vertex(vertex);
				//waiting_for_the_next_move();
			}
			//
		}
	}


	Graph Finding_shortest_path::create_route(Graph &graph, vector<int> &direction, int start, int finish)
	{
		vector<vector<int> > new_graph(graph.get_size());

		int index = finish;
		
		while (direction[index] != start)
		{
			new_graph[direction[index]].push_back(index);

			index = direction[index];
		}

		return Graph(new_graph, true);
	}


	void Finding_shortest_path::work(Graph graph, int start, int finish, bool need_to_stop)
	{
		vector<int> direction(graph.get_size(), -1);

		queue<int> next_verteces;
		next_verteces.push(start);
		direction[start] = start;

		bfs(graph, next_verteces, direction, finish, need_to_stop);


	}

}