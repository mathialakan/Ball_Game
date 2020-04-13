#ifndef GAME_H
#define GAME_H

#include "Box.h"
#include "Ball.h"

class Game
{
public:

	Game(Box box, Ball ball);
	Game();
	//~Game();

	void setup(Box box, Ball ball);
	bool hit_wall();
	void move( float t);
	void pause();
	void start();
	void stop();
	void set_box(Box box);
	void set_ball(Ball ball);
	Box get_box();
	Ball get_ball();
	std::string get_track();

private:
	Box box;
	Ball ball;
	bool is_hit;
	// ... here padel can be included in future....
};

#endif
