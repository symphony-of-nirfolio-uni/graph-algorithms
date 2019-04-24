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

    GraphAPI();
    GraphAPI(const GraphAPI&) {}
    GraphAPI operator=(GraphAPI&);

    atomic<unsigned> current_highlighted;
    vector<atomic<unsigned>*> black_marked;
    vector<atomic<unsigned>*> use_marked;

public:
    void set_highlighted(unsigned vertex);
    void set_black_mark(unsigned vertex);
    void set_used_mark(unsigned vertex);

    unsigned get_current_highlighted();
    vector<unsigned> get_black_marked();
    vector<unsigned> get_used_marked();

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

