#include "Build_dots.h"

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
	
	Point::~Point() {}
	
	Point getDot(double angle, int i, double radius)
	{
        double radAngle = 2 * pi * double(i)*angle / 360.0;
		Point resPoint(radius * sin(radAngle), radius * cos(radAngle));
		return resPoint;
	}
}
