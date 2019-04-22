#include "Read_graph.h"


namespace algorithms_on_graphs
{
	Read_graph::Read_graph(shared_ptr<Read_graph_builder> builder)
	{
		direct = builder->direct;
	}

	Read_graph::~Read_graph()
	{

	}


	string Read_graph::get_file_name()
	{
		string name;

		if (direct)
		{
			name += "Directed_";
		}
		else
		{
			name += "Undirected_";
		}

		name += "graph.dat";

		return name;
	}

	string Read_graph::get_file_name(string prefix)
	{
		return prefix + get_file_name();
	}


	Graph Read_graph::build_graph(string prefix)
	{
		return Read_graph::get_graph_from_file(get_file_name(prefix), direct);
	}


	Graph Read_graph::get_graph()
	{
		return build_graph("");
	}

	Graph Read_graph::get_graph(string prefix)
	{
		return build_graph(prefix);
	}


	Graph Read_graph::get_graph_from_file(string file_name, bool direct)
	{
		vector<vector<int> > graph;

		ifstream file_in(file_name);

		string number_str;
		file_in >> number_str;

		number_str.erase(0, 7);
		int number = atoi(number_str.c_str());

		graph.resize(number);

		string typeGraph;
		file_in >> typeGraph;

		for (int i = 0; i < number; ++i)
		{
			int countVertex;
			file_in >> countVertex;

			string separator;
			file_in >> separator;

			for (int j = 0; j < countVertex; ++j)
			{
				int vertex;
				file_in >> vertex;

				graph[i].push_back(vertex);

				if (!direct)
				{
					graph[vertex].push_back(i);
				}
			}
		}

		return Graph(graph, direct);
	}


	bool Read_graph::get_direct()
	{
		return direct;
	}
}