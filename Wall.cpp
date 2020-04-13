

#include "Wall.h"
#include<cmath>
#include<iostream>

	Wall::Wall(Point start_t, Point end_t)
	{
		start = start_t;
		end = end_t;
	};
	Wall::Wall()
	{
	};

	void Wall::set_start_point(Point s)
	{
		start = s;
	};
	void Wall::set_end_point(Point s)
	{
		end = s;
	};
	Point Wall::get_start_point()
	{
		return start;
	};
	Point Wall::get_end_point()
	{
		return end;
	};
	float Wall::get_length(Point p1, Point p2)
	{
		return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
	};
	direction Wall::get_direction(Point p1, Point p2)
	{
		direction dir_line;
		float xdiff = p2.x - p1.x;
		float ydiff = p2.y - p1.y;
		dir_line.c = 0;
	
		if (xdiff == 0)
		{
			dir_line.x = -1; 
			dir_line.c = p2.x;
			dir_line.y = 0;
		}
		else
		{
			if (ydiff == 0)
			{
				dir_line.x = 0;
				dir_line.y = 1;
				dir_line.c = p2.y;
			}
			else
			{
				dir_line.y = 1;
				float m = ydiff / xdiff;
				dir_line.x = -m;
				dir_line.c = p2.y - m*p2.x;
			}
		}		
		return dir_line;
	};

	void Wall::set_normaldir(direction normaldir_t)
	{
		normaldir = normaldir_t;
	};

	direction Wall::get_normaldir()
	{
		return normaldir;
	};
	
	Point Wall::hit_point(Point p1, Point p2)
	{
		direction wall_dir = get_direction(start, end);
		direction ball_dir = get_direction(p1, p2);
		Point intersect{100,100};
		float det = wall_dir.x*ball_dir.y - wall_dir.y*ball_dir.x;
		
		if (abs(det) < 0.000001) return intersect;			//Parallel lines
		else
		{
			float x_i = (wall_dir.c*ball_dir.y - ball_dir.c*wall_dir.y) / det;
			float y_i = (wall_dir.x*ball_dir.c - ball_dir.x*wall_dir.c) / det;
			intersect.x = x_i;
			intersect.y = y_i;
		}

		if (get_length(p2, intersect) > get_length(p1, p2)) return { 100,100 }; //short segmnet 
		return intersect;
	};

	std::string Wall::to_string()
	{
		return " with vertices ( " + std::to_string(start.x )+ ", " + std::to_string(start.y) + ")" +
			" and ( " + std::to_string(end.x )+ ", " + std::to_string(end.y) + ")";
	};