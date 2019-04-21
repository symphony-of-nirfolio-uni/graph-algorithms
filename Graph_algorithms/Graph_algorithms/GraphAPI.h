#pragma once
#include <vector>
#include <string>
#include "Graph.h"

using std::vector;
using std::pair;
using std::string;
using algorithms_on_graphs::Graph;

class GraphAPI // singleton
{
private:
public:
	static GraphAPI instance;
	void used_vertex(int v);
	bool can_move_on();
	bool ui_idle();
    vector<pair<double, double> > get_vertices_coodrdinates(string graph_file_name);
    Graph get_graph(string graph_file_name);
	
	GraphAPI();
	~GraphAPI();
};

