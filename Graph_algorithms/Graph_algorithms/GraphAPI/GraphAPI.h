#pragma once
#include <vector>
#include <string>
#include <atomic>
#include "../Graph_data/Graph.h"
#include "../Build_dots/Build_dots.h"

using std::vector;
using std::pair;
using std::string;
using algorithms_on_graphs::Graph;
using build_dots::Point;
using std::atomic;

class GraphAPI // singleton
{
private:

    GraphAPI() {}
    GraphAPI(const GraphAPI&) {}
    GraphAPI operator=(GraphAPI&);

    atomic<int> current_highlighted;
    vector<atomic<int> > marked;

public:
	void highlight_vertex(int vertex);
    void black_mark_vertex(int vertex);
    void used_mark_vertex(int vertex);
	void result(bool result);
	void end_of_the_algorithm();
	bool can_move_on();
	bool ui_idle();
    vector<Point> get_vertices_coordinates(string graph_file_name);
    Graph get_graph(string graph_file_name);
	static GraphAPI& instance()
	{
		static GraphAPI instance;
		return instance;
    }
	
	~GraphAPI();
};

