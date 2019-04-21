#include "GraphAPI.h"
#include "../Graph_data/Read_graph.h"


vector<pair<double, double> > GraphAPI::get_vertices_coodrdinates(std::string graph_file_name)
{
    //TODO: make a real implementation

    return {{0, 6},
            {2, 4},
            {3, 8},
            {7, 4},
        {10, 5}};
}

algorithms_on_graphs::Graph GraphAPI::get_graph(std::string graph_file_name)
{
	string file_name = "../Graph_data/Data/" + graph_file_name + ".dat";

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
