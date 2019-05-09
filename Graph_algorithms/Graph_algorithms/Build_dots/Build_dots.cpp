#include "Build_dots.h"
#include <cmath>

namespace build_dots 
{
	Point::Point() 
	{
		x = 0;
		y = 0;
	}
	
	Point::Point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	
	Point getDot(double angle, int i, double radius)
	{
        double radAngle = 2 * pi * double(i)*angle / 360.0;
		Point resPoint(radius * sin(radAngle), radius * cos(radAngle));
		return resPoint;
	}

	vector<Point> getAllDots(Graph graph)
	{
		vector<Point> positions;
		if (graph.size() == 0)
			return positions;

		double cell_count = double(graph.size());
		double angle = 360.0 / cell_count;
		double radius = 50.0 - 50.0 / cell_count;

		for (int i = 0; i < int(graph.size()) / 2 + int(graph.size()) % 2; ++i)
			positions.push_back(build_dots::getDot(angle, i, radius));

		Point tempDot;
		if (graph.size() % 2 == 1)
		{
			for (int i = int(positions.size() - 1); i >= int(graph.size()) % 2; --i)
			{
				tempDot = positions[unsigned(i)];
				tempDot.x = -tempDot.x;
				positions.push_back(tempDot);
			}
		}
		else
		{
			int temp_size = int(positions.size());
			for (int i = 0; i < temp_size; ++i)
			{
				tempDot = positions[unsigned(i)];
				tempDot.x = -tempDot.x;
				tempDot.y = -tempDot.y;
				positions.push_back(tempDot);
			}
		}

		for (unsigned int i = 0; i < positions.size(); ++i)
		{
			positions[i].x += 50.0;
			positions[i].y += 50.0;
		}
		return positions;
	}


}
