#pragma once
#include <vector>
#include <string>
#include "../Graph_data/Graph.h"
#include "../Build_dots/Build_dots.h"

using std::vector;
using std::pair;
using std::string;
using algorithms_on_graphs::Graph;
using build_dots::Point;

class GraphAPI // singleton
{
private:

    GraphAPI() {}
    GraphAPI(const GraphAPI&) {}
    GraphAPI operator=(GraphAPI&);
public:
	void highlight_vertex(int vertex);
	void mark_vertex(int vertex);
	void result(bool result);
	void end_of_the_algorithm();
	bool can_move_on();
	bool ui_idle();
    vector<Point> get_vertices_coodrdinates(string graph_file_name);
    Graph get_graph(string graph_file_name);
	static GraphAPI& instance()
	{
		static GraphAPI instance;
		return instance;
    }
	
	~GraphAPI();
};

