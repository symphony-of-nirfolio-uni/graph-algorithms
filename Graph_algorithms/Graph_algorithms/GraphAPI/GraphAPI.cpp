#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"
#include "../Graph_data/Graph_algo.h"


#include <cmath>


GraphAPI::GraphAPI()
{
    can_move = false;
    algo_ended = false;
    current_highlighted = 0;
}

void GraphAPI::set_highlighted(unsigned vertex)
{
    current_highlighted = vertex;
}

void GraphAPI::set_black_mark(unsigned vertex)
{
    black_marked.push_back(vertex);
}

void GraphAPI::set_used_mark(unsigned vertex)
{
    use_marked.push_back(vertex);
}

unsigned GraphAPI::get_current_highlighted()
{
    return current_highlighted;
}

vector<unsigned> GraphAPI::get_black_marked()
{
    return black_marked;
}

vector<unsigned> GraphAPI::get_used_marked()
{
    return use_marked;
}

void GraphAPI::set_result(std::string result)
{
    this->result = result;
}

void GraphAPI::end_of_the_algorithm()
{
    algo_ended = true;
}

bool GraphAPI::can_move_on()
{
    if(can_move)
    {
        can_move = false;
        return true;
    }
    else
    {
        return false;
    }

}

void GraphAPI::continue_algo()
{
    can_move = true;
}

bool GraphAPI::algorithm_is_ended()
{
    return algo_ended;
}

std::string GraphAPI::get_result()
{
    return result;
}


void GraphAPI::start_algorithm(Algorithm algorithm_name, Graph graph)
{
	shared_ptr<algorithms_on_graphs::Algorithm> algorithm;

	if (algorithm_name == Algorithm::Graph_is_acyclic)
	{
		algorithm = algorithms_on_graphs::Graph_is_acyclic_factory::get_algorithm();
	}
	else if (algorithm_name == Algorithm::Graph_is_connected)
	{
		algorithm = algorithms_on_graphs::Graph_is_connected_factory::get_algorithm();
	}
	else if (algorithm_name == Algorithm::Finding_shortest_path)
	{
		algorithm = algorithms_on_graphs::Finding_shortest_path_factory::get_algorithm();
	}

	algorithms_on_graphs::Graph_algo graph_algo(algorithm);

	graph_algo.work(graph);
}


vector<Point> GraphAPI::get_vertices_coordinates(std::string graph_file_name)
{
	algorithms_on_graphs::Graph graph = get_graph(graph_file_name);
    return build_dots::getAllDots(graph);
}

algorithms_on_graphs::Graph GraphAPI::get_graph(std::string graph_file_name)
{

    string file_name = "../Graph_data/Data/" + graph_file_name;

#ifdef QT_GRAPH_API
    file_name = "../Graph_algorithms/Graph_data/Data/" + graph_file_name;
#endif

	return algorithms_on_graphs::Read_graph::get_graph_from_file(file_name);
}






GraphAPI::~GraphAPI()
{

}
