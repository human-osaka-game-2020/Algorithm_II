
#ifndef DIFINITION_H
#define DIFINITION_H

static const int MaxWidth  = 15;
static const int MaxHeight = 15;

static const int UP		= 0;
static const int DOWN	= 1;
static const int LEFT	= 2;
static const int RIGHT	= 3;

enum class MazeType
{
	Path,
	Wall,
	Route
};

enum class Direction
{
	Up,
	Down,
	Left,
	Right
};

static MazeType Map[MaxHeight][MaxWidth];

#endif