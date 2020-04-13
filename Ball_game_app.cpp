#include<iostream>
#include<ctime>
#include<vector>
#include<string>
#include "Box.h"
#include "Ball.h"
#include "Game.h"
#include "windows.h"


float random_range(float lower, float upper)
{
	return ((float)rand() / RAND_MAX)*(upper - lower) + lower;
};

int main()
{
	//setup the game
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); 
	SetConsoleTextAttribute(color, 15);

	std::cout << " ----------------------------------------------" << std::endl;
	std::cout << " -------------Ball bouncing game---------------" << std::endl;
	std::cout << " ----------------------------------------------" << std::endl;
	//time interval
	float cur_time = 0.0f;
	float time_tick = 0.1f;
	float end_time = 30.0f;

	//Built a box with 4 walls, bottom, right, top, and left.
	std::vector<Wall> walls; 
	Point const vertices[4] = { { -10.0f, -10.0f },{ 10.0f, -10.0f },{ 10.0f, 10.0f }, { -10.0f, 10.0f } };
	direction const normal[4] = { {1,-1}, {-1,1}, {1,-1}, {-1,1} };

	for (int i = 0; i < 4; i++)
	{
		Wall w(vertices[i], vertices[(i+1)%4]);
		w.set_normaldir(normal[i]);
		walls.push_back(w);
	}

	Box box(walls);

	//Take a ball with random position and velocity
	srand(unsigned int(time(NULL)));
	//pick a random position
	float x = random_range(0.0f, 5.0f);
	float y = random_range(0.0f, 5.0f);
	Point p{ x,y };
	//pick a random velocity
	float vx = random_range(0.0f, 3.0f);
	float vy = random_range(0.0f, 3.0f);
	velocity v{ vx, vy };
	
	Ball ball(p, v);
	//Construct a game with a box and a ball
	Game game(box, ball);
	std::cout << box.to_string();
	std::cout << "The initilal status of the ball \n";
	std::cout << game.get_track() << std::endl;
	std::cout << "Start time : " << cur_time << std::endl;
	std::cout << "End time : " << end_time << std::endl;
	std::cout << "Time step : " << time_tick << std::endl;
	std::cout << " ----------------------------------------------" << std::endl;
	//start the game 
	game.start();
	bool gameover = false;
	//play the game until its over, gameover
	//the gameover comes to true when the time reaches the end_time
	do{
		cur_time += time_tick;
		SetConsoleTextAttribute(color, 15);
		std::cout << "Just hit to move the ball ..." << std::endl;
		std::cin.ignore();
		SetConsoleTextAttribute(color, 10);
		game.move(time_tick);
		std::cout << "At time " << cur_time << std::endl;
		std::cout<< game.get_track() << std::endl;
		if ( fabs(end_time - cur_time) < end_time*0.1)
		{
			gameover = true;
			SetConsoleTextAttribute(color, 5);
			std::cout << "Game is over! your time is elapsed" << std::endl;
		}
	}while (!gameover);

	return 0;
}