
// Decalre the object ball with attributes current position and previous position and current and previous velocity
// I want to have the current and previous status of the ball to make it easily trackable

#ifndef BALL_H
#define BALL_H

#include "Point.h"

struct velocity
{
	float x;
	float y;
};

class Ball
{
public:

	Ball(Point p, velocity v);
	Ball();
	//~Ball();

	void set_velocity(velocity v);
	void set_position(Point p);
	void set_previous_velocity(velocity v);
	void set_previous_position(Point p);
	Point get_position();
	velocity get_velocity();
	Point get_previous_position();
	velocity get_previous_velocity();


private:
	Point cur_p, previous_p;
	velocity cur_v, previous_v;
};

#endif
