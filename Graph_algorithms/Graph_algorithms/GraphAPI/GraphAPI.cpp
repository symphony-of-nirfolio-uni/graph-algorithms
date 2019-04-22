#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"

#include <cmath>


vector<pair<double, double> > GraphAPI::get_vertices_coodrdinates(std::string graph_file_name)
{
	algorithms_on_graphs::Graph graph = get_graph(graph_file_name);

	vector<pair<double, double> > position;

	for (int i = 0; i < graph.get_size(); ++i)
	{
		position.push_back({ double(rand() % 100), double(rand() % 100) });
	}

	return position;
}

algorithms_on_graphs::Graph GraphAPI::get_graph(std::string graph_file_name)
{

    string file_name = "../Graph_data/Data/" + graph_file_name;

#ifdef QT_DEPRECATED_WARNINGS
    file_name = "../Graph_algorithms/Graph_data/Data/" + graph_file_name;
#endif

	return algorithms_on_graphs::Read_graph::get_graph_from_file(file_name);
}

/*GraphAPI & GraphAPI::instance()
{
	static GraphAPI instance;
	return instance;
}*/





GraphAPI::~GraphAPI()
{

}
