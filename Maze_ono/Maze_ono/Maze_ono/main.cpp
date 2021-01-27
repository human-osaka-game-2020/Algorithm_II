
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Maze.h"
#include "Algorithm_Method.h"

Maze maze;
Algorithm algorithm;

int main()
{
	srand((unsigned)time(NULL));

	maze.CreateMap();
	maze.PrintMap();

//	algorithm.Dijkstra();

	system("pause");
	return 0;
}
