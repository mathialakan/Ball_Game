
#include "Box.h"


Box::Box(std::vector<Wall> walls_t)
{
	walls = walls_t;
};
Box::Box()
{
};

void Box::set_walls(std::vector<Wall> walls_t)
{
	walls = walls_t;
};
void Box::set_wall(Wall wall, int k)
{
	walls.insert(walls.begin() + k, wall);
};
std::vector<Wall> Box::get_walls()
{
	return walls;
};
Wall Box::get_wall(int k)
{
	return walls[k];
};

std::string Box::to_string()
{
	std::string disc = "A box with 4 walls \n";
	for (int i = 0; i < 4; i++)
		disc += " wall " + std::to_string(i) + "\t" + walls[i].to_string() + " \n";
	return disc;
};