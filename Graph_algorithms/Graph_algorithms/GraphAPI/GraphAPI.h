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

    unsigned current_highlighted;
    vector<unsigned> black_marked;
    vector<unsigned> use_marked;
    string result;

    atomic<bool> can_move;
    atomic<bool> algo_ended;

public:
	enum Algorithm
	{
		Graph_is_acyclic,
		Graph_is_connected,
		Finding_shortest_path
	};


    void set_highlighted(unsigned vertex);
    void set_black_mark(unsigned vertex);
    void set_used_mark(unsigned vertex);

    unsigned get_current_highlighted();
    vector<unsigned> get_black_marked();
    vector<unsigned> get_used_marked();


    void set_result(string result);
	void end_of_the_algorithm();
    bool can_move_on();

    void continue_algo();
    bool algorithm_is_ended();
    string get_result();


	void start_algorithm(Algorithm algorithm_name, Graph graph);
	void start_algorithm(Algorithm algorithm_name, Graph graph, bool &can_move_on);
	void start_algorithm_without_stops(Algorithm algorithm_name, Graph graph);

    vector<Point> get_vertices_coordinates(string graph_file_name);
    Graph get_graph(string graph_file_name);
	static GraphAPI& instance()
	{
		static GraphAPI instance;
		return instance;
    }
	
	~GraphAPI();
};

