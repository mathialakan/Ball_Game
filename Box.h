//Decalre a box with four walls -- can be extended to multi wall box

#ifndef BOX_H
#define BOX_H

#include "Wall.h"
#include<vector>

class Box
{
public:

	Box(std::vector<Wall> walls);
	Box();
	//~Box();

	void set_walls(std::vector<Wall> walls);
	void set_wall(Wall wall, int k);
	std::vector<Wall> get_walls();
	Wall get_wall(int k);
	std::string to_string();

private:
	std::vector<Wall> walls;
};

#endif