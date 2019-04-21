#include "GraphAPI.h"



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
    //TODO: make a real implementation

    return Graph({{},{{2,0}},{{1,0}},{{4,0}},{{3,0}}});
}

/*GraphAPI & GraphAPI::instance()
{
	static GraphAPI instance;
	return instance;
}*/





GraphAPI::~GraphAPI()
{

}
