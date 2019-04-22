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
	
	Point getDot(Point mainDot, double angle, int i, double radius)
	{
		Point resPoint;
		double helpY = radius*cos(pi*double(i)*angle / 360.0);
		resPoint.y = mainDot.y - helpY;
		resPoint.x = sqrt(radius * radius - helpY * helpY);
		return resPoint;
	}
}
