#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"

#include <cmath>


vector<Point> GraphAPI::get_vertices_coordinates(std::string graph_file_name)
{
	algorithms_on_graphs::Graph graph = get_graph(graph_file_name);

	vector<Point> positions;
	if (graph.get_size() == 0)
		return positions;

	double cell_count = graph.get_size();
	double angle = 360.0 / cell_count;
	double radius = 49.0 - 49.0 / cell_count;
	Point mainDot(0.0, radius);
	for (int i = 0; i < graph.get_size()/2 + graph.get_size()%2; ++i)
		positions.push_back(build_dots::getDot(mainDot, angle, i, radius));

	Point tempDot;
	if (graph.get_size() % 2 == 1)
	{
		for (int i = int(positions.size() - 1); i >= graph.get_size() % 2; --i)
		{
			tempDot = positions[unsigned int(i)];
			tempDot.x = -tempDot.x;
			positions.push_back(tempDot);
		}
	}
	else
	{
		for (int i = int(positions.size() - 1); i >= 0; --i)
		{
			tempDot = positions[unsigned int(i)];
			tempDot.x = -tempDot.x;
			tempDot.y = -tempDot.y;
			positions.push_back(tempDot);
		}
	}

	for (unsigned int i = 0; i < positions.size(); ++i)
	{
		positions[i].x += 50;
		positions[i].y += 50;
	}
	return positions;
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
