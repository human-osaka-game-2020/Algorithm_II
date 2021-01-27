
#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>
#include <list>
#include "Algorithm_Method.h"

Position Goal = { MaxWidth - 2, MaxHeight - 2 };
std::vector<std::vector<Position>> Algorithm::Trace;

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

void Algorithm::Dijkstra()
{
	Trace.resize(1, std::vector<Position>(1));
	Trace.back().back() = { 1,1 };

	int Ans = Explore();

	int Counter = 0;

	while (true)
	{
		int TempX = Trace.at(Ans).at(Counter).x;
		int TempY = Trace.at(Ans).at(Counter).y;

		Map[TempY][TempX] = MazeType::Route;

		if (Trace.at(Ans).at(Counter) == Goal) break;

		Counter++;
	}
}

int Algorithm::Explore()
{
	bool Up = false;
	bool Down = false;
	bool Left = false;
	bool Right = false;

	while (true)
	{
		int NodeNum = Trace.size();

		for (int i = 0; i < NodeNum; i++)
		{
			Position pos = Trace.at(i).back();

			if (Map[pos.y - 1][pos.x] == MazeType::Path && pos.y - 1 > 0 && pos.direction != Direction::Up)
			{
				Trace.at(i).push_back({ pos.x, pos.y - 1, Direction::Down });
				Up = true;
			}

			if (Map[pos.y + 1][pos.x] == MazeType::Path && pos.y + 1 > 0 && pos.direction != Direction::Down)
			{
				if (Up == true || Left == true || Right == true) {
					Trace.push_back(std::vector<Position>());
					Trace.back() = Trace.at(i);
					Trace.back().pop_back();
					Trace.back().push_back({ pos.x, pos.y + 1, Direction::Up });
				}
				else {
					Trace.at(i).push_back({ pos.x, pos.y + 1, Direction::Up });
				}
				Down = true;
			}

			if (Map[pos.y][pos.x - 1] == MazeType::Path && pos.x - 1 > 0 && pos.direction != Direction::Left)
			{
				if (Up == true)
				{
					Trace.push_back(std::vector<Position>());
					Trace.back() = Trace.at(i);
					Trace.back().pop_back();
					Trace.back().push_back({ pos.x - 1, pos.y, Direction::Right });
				}
				else
				{
					Trace.at(i).push_back({ pos.x - 1, pos.y, Direction::Right });
				}
				Left = true;
			}

			if (Map[pos.y][pos.x + 1] == MazeType::Path && pos.x + 1 > 0 && pos.direction != Direction::Right)
			{
				if (Up == true || Left == true) {
					Trace.push_back(std::vector<Position>());
					Trace.back() = Trace.at(i);
					Trace.back().pop_back();
					Trace.back().push_back({ pos.x + 1, pos.y, Direction::Left });
				}
				else {
					Trace.at(i).push_back({ pos.x + 1, pos.y, Direction::Left });
				}
				Right = true;
			}

			if (Trace.at(i).back() == Goal) return i;

			Up		= false;
			Down	= false;
			Left	= false;
			Right	= false;
		}
	}

	return 0;
}
