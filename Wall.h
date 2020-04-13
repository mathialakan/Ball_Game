
//Declare a wall with end vertices (start, end)
// direction is the coefficients of y, x, and c based the equation y -mx = c
// normaldir is the normal/orthoganal direction to the line
#ifndef WALL_H
#define WALL_H

#include "Point.h"
#include<string>

struct direction
{
	float x;
	float y;
	float c;
};

class Wall
{
public:

	Wall(Point start, Point end);
	Wall();
	//~Wall();

	void set_start_point(Point s);
	void set_end_point(Point s);
	Point get_start_point();
	Point get_end_point();
	float get_length(Point p1, Point p2);
	direction get_direction(Point p1, Point p2);
	direction get_normaldir();
	void set_normaldir(direction d);
	//float* get_orthoganal();
	Point hit_point(Point p1, Point p2);
	std::string to_string();

private:
	Point start, end;
	direction dir, normaldir;
	//float elasticity --- since its bounces off, fully elasticity
};

#endif