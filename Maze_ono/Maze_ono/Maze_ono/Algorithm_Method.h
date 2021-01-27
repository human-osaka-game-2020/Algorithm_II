
#ifndef ALGORITHM_METHOD
#define ALGORITHM_METHOD

#include "Difinition.h"
#include <iostream>
#include <vector>

struct Position
{
	int x;
	int y;
	Direction direction;
	bool operator == (Position pos)
	{
		return (x == pos.x && y == pos.y);
	}
};

class Algorithm
{
public:
	Algorithm();
	~Algorithm();

	void Dijkstra();

private:
	int Explore();

private:
	static std::vector<std::vector<Position>> Trace;
};

#endif
