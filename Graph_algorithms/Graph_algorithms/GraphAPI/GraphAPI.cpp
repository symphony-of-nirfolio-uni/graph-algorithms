#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"

#include <cmath>


vector<Point> GraphAPI::get_vertices_coodrdinates(std::string graph_file_name)
{
	algorithms_on_graphs::Graph graph = get_graph(graph_file_name);

	vector<Point> position;

	int counter = 0;
	double cell_count = sqrt(graph.get_size()) + 1;
	double cell_size = 100.0 / cell_count;

	for (int i = 0; i < int(cell_count); ++i)
	{
		for (int j = 0; j < int(cell_count) && counter < graph.get_size(); ++j, ++counter)
		{
			Point tempX;
			tempX.x = double(i * cell_size + cell_size * (0.5 + 0.67 * double(rand() % 200 - 100) / 100.0));
			tempX.y = double(j * cell_size + cell_size * (0.5 + 0.67 * double(rand() % 200 - 100) / 100.0));
            position.push_back(tempX);
		}
	}

	return position;
}

algorithms_on_graphs::Graph GraphAPI::get_graph(std::string graph_file_name)
{

    string file_name = "../Graph_data/Data/" + graph_file_name;

#ifdef QT_GRAPH_API
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
