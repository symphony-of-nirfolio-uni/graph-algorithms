#include "Read_graph.h"


namespace algorithms_on_graphs
{
	Read_graph::Read_graph(shared_ptr<Read_graph_builder> builder)
	{
		weight = builder->weight;
		direct = builder->direct;
	}

	Read_graph::~Read_graph()
	{

	}


	string Read_graph::get_file_name()
	{
		string name;

		if (weight)
		{
			name = "Weighted_";
		}
		else
		{
			name = "Unweighted_";
		}

		if (direct)
		{
			name += "directed_";
		}
		else
		{
			name += "undirected_";
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
		vector<vector<pair<int, int> > > graph;

		ifstream file_in(get_file_name(prefix));

		string number_str;
		file_in >> number_str;

		number_str.erase(0, 7);
		int number = atoi(number_str.c_str());

		graph.resize(number);

		file_in.ignore();
		file_in.ignore();

		for (int i = 0; i < number; ++i)
		{
			int countVertex;
			file_in >> countVertex;
			
			string separator;
			file_in >> separator;

			for (int j = 0; j < countVertex; ++j)
			{
				int vertex, vertexWeight = -1;
				file_in >> vertex;

				if (weight)
				{
					file_in >> vertexWeight;
				}

				graph[i].push_back({ vertex, vertexWeight });

				if (direct)
				{
					graph[vertex].push_back({ i, vertexWeight });
				}
			}
		}

		return Graph(graph);
	}


	Graph Read_graph::get_graph()
	{
		return build_graph("");
	}

	Graph Read_graph::get_graph(string prefix)
	{
		return build_graph(prefix);
	}


	bool Read_graph::get_weight()
	{
		return weight;
	}

	bool Read_graph::get_direct()
	{
		return direct;
	}
}