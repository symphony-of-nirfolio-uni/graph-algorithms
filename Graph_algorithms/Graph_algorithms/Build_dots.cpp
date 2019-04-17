#include "Build_dots.h"

namespace build_dots 
{
	vector<pair<int, int> > get_coordinates_of_vertexes(const Graph & g)
	{
		int n = g.graph.size();
		double radius = n * 25, angle = 360.0/n;
		vector<pair<int, int> > dots;
		for (int i = 0; i < n; ++i)
		{
			if (i == 0)
				dots.push_back({ 0, radius });
			else
			{

			}
		}
		return dots;
	}


	vector<pair<int, int> > get_coordinates_of_edges(const Graph & graph)
	{
		return pair<int, int>();
	}
}
