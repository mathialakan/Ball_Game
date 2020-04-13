// Declare game with objects, now it uses rectangular box and ball

#include <iostream>
#include "Game.h"
#include "Ball.h"
#include<string>


Game::Game(Box box_t, Ball ball_t)
{
	box = box_t;
	ball = ball_t;
};
Game::Game()
{

};

void Game::setup(Box box_t, Ball ball_t)
{
	box = box_t;
	ball = ball_t;
};

void Game::set_box(Box box_t)
{
	box = box_t;
};
void Game::set_ball(Ball ball_t)
{
	ball = ball_t;
};
Box Game::get_box()
{
	return box;
};
Ball Game::get_ball()
{
	return ball;
};

bool Game::hit_wall()
{
	Point cur_pos = ball.get_position();
	for (Wall w : box.get_walls())
	{
		Point hit_at = w.hit_point(ball.get_previous_position(), cur_pos);
		if (!((100.0f -hit_at.x )  < 0.000001 && (100 -hit_at.y) < 0.000001))
		{
			direction wall_normal = w.get_normaldir();
			velocity ball_dir = ball.get_velocity();
			velocity new_dir{ ball_dir.x*wall_normal.x, ball_dir.y*wall_normal.y };
			ball.set_previous_velocity(ball_dir);
			ball.set_velocity(new_dir);
			ball.set_previous_position(ball.get_position());
			ball.set_position(hit_at);
			return true;
		}
	}
	return false;
};

void Game::move(float t)
{
	//move the ball
	//update the position
	velocity cur_v = ball.get_velocity();
	Point cur_p = ball.get_position();
	Point new_pos{ (cur_p.x + cur_v.x*t), (cur_p.y + cur_v.y*t) };
	//delta correction at the border - shift the ball's previous position little towards the moving direction
	// in order to take off from the boundary
	float delta_x = 0;
	float delta_y = 0;
	if (is_hit)
	{
		delta_x = cur_v.x*t*0.1f;
		delta_y = cur_v.y*t*0.1f;
	}
	Point pos_delta{ (cur_p.x + delta_x), (cur_p.y + delta_y) };
	ball.set_previous_position(pos_delta);
	ball.set_position(new_pos);
	is_hit = false;
	if (hit_wall())
	{
		//change the velocity direction
		std::cout << " o---> ball hits a wall at the point ( " << ball.get_position().x << " , " 
			<< ball.get_position().y  << " )  and bounced off  <---o" << std::endl << std::endl;
		is_hit = true;
	}
	
};
void Game::pause()
{
	std::cout << "pause to play the game ..." << std::endl;
};

void Game::start()
{
	std::cout << "statr to play the game ..." << std::endl;
};
void Game::stop()
{
	std::cout << "stop to play the game ..." << std::endl;
};

std::string Game::get_track()
{
	Point cur_pos = ball.get_position();
	velocity cur_v = ball.get_velocity();
	std::string status = "Ball at ( " + std::to_string(cur_pos.x) + " , " + std::to_string(cur_pos.y)
						+ " ) with velocity ( " + std::to_string(cur_v.x) + " , " + std::to_string(cur_v.y) + " ) ";
	return status;
}
