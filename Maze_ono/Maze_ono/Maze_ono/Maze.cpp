
#include <stdlib.h>
#include <stdio.h>
#include "Maze.h"

Maze::Maze()
{
}

Maze::~Maze()
{
}

void Maze::CreateMap()
{
	for (int Height = 0; Height < MaxHeight; Height++)
	{
		for (int Width = 0; Width < MaxWidth; Width++)
		{
			Map[Height][Width] = MazeType::Wall;
		}
	}

	int RandWidth = 2 * (rand() % (MaxWidth / 2)) + 1;
	int RandHeight = 2 * (rand() % (MaxHeight / 2)) + 1;

	Map[RandHeight][RandWidth] = MazeType::Path;

	Dig(RandWidth, RandHeight);

}

void Maze::PrintMap()
{
	for (int Height = 0; Height < MaxHeight; Height++)
	{
		for (int Width = 0; Width < MaxWidth; Width++)
		{
			if (Map[Height][Width] == MazeType::Path)
			{
				printf("%2s", "");
			}
			else if (Map[Height][Width] == MazeType::Wall)
			{
				printf("%2s", "¡");
			}
			else if (Map[Height][Width] == MazeType::Route)
			{
				printf("%2s", "E");
			}
		}
		printf("\n");
	}
}

void Maze::Dig(int x_, int y_)
{
	int Direction;
	int Up = 0;
	int Down = 0;
	int Left = 0;
	int Right = 0;

	while (Up == 0 || Down == 0 || Left == 0 || Right == 0)
	{
		Direction = rand() % 4;

		switch (Direction)
		{
		case UP:
			if (y_ - 2 >= 0 && y_ - 2 < MaxHeight)
			{
				if (Map[y_ - 2][x_] == MazeType::Wall)
				{
					Map[y_ - 1][x_] = MazeType::Path;
					Map[y_ - 2][x_] = MazeType::Path;
					Dig(x_, y_ - 2);
				}
			}
			Up++;

			break;

		case DOWN:
			if (y_ + 2 >= 0 && y_ + 2 < MaxHeight)
			{
				if (Map[y_ + 2][x_] == MazeType::Wall)
				{
					Map[y_ + 1][x_] = MazeType::Path;
					Map[y_ + 2][x_] = MazeType::Path;
					Dig(x_, y_ + 2);
				}
			}
			Down++;

			break;

		case LEFT:
			if (x_ - 2 >= 0 && x_ - 2 < MaxWidth)
			{
				if (Map[y_][x_ - 2] == MazeType::Wall)
				{
					Map[y_][x_ - 1] = MazeType::Path;
					Map[y_][x_ - 2] = MazeType::Path;
					Dig(x_ - 2, y_);
				}
			}
			Left++;

			break;

		case RIGHT:
			if (x_ + 2 >= 0 && x_ + 2 < MaxWidth)
			{
				if (Map[y_][x_ + 2] == MazeType::Wall)
				{
					Map[y_][x_ + 1] = MazeType::Path;
					Map[y_][x_ + 2] = MazeType::Path;
					Dig(x_ + 2, y_);
				}
			}
			Right++;

			break;

		default:
			break;
		}
	}
}
