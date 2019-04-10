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

	
	Graph::~Graph()
	{
		graph.clear();
	}
}