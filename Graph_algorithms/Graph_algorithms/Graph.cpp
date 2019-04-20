#include "Graph.h"


namespace algorithms_on_graphs
{
	Graph::Graph()
	{
		graph.clear();
	}

	Graph::Graph(vector<vector<pair<int, int> > > graph) : graph(graph)
	{

	}

	Graph::Graph(vector<vector<pair<int, int> > > graph, bool weight, bool direct) : graph(graph), weight(weight), direct(direct)
	{

	}

	
	Graph::~Graph()
	{
		graph.clear();
	}
}