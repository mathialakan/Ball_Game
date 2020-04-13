#include <iostream>
#include "Ball.h"

Ball::Ball(Point p, velocity v)
{
	cur_p = p;
	cur_v = v;
	previous_p = cur_p;
	previous_v = cur_v;
};

Ball::Ball()
{
};
void Ball::set_velocity(velocity v)
{
	cur_v = v;
};
void Ball::set_position(Point p)
{
	cur_p = p;
};
void Ball::set_previous_velocity(velocity v)
{
	previous_v = v;
};
void Ball::set_previous_position(Point p)
{
	previous_p = p;
};
Point Ball::get_position()
{
	return cur_p;
};
velocity Ball::get_velocity()
{
	return cur_v;
};
Point Ball::get_previous_position()
{
	return previous_p;
};
velocity Ball::get_previous_velocity() 
{
	return previous_v;
};

