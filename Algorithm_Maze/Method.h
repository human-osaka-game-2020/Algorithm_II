#ifndef METHOD_H
#define METHOD_H

#include <iostream>
#include <vector>

const int MAZE_WIDTH = 31;	// 迷路の横幅
const int MAZE_HEIGHT = 31;	// 迷路の縦幅

// マスの状態
enum Block {
	Empty,	// 何もない
	Wall,	// 壁
	Route	// 経路
};

// 方向
enum Direction{
	Up,
	Left,
	Right,
	Down
};

struct Position{
	int x;
	int y;
	Direction from;

	bool operator == ( Position pos_ ){
		return ( x == pos_.x && y == pos_.y );
	}
};

class Method {
public:

	Method();

	~Method();

protected:

	/// @brief 迷路の表示
	static void PrintMaze();

public:

	/// @brief 実行
	static void Execute();

protected:
	static Block maze[MAZE_HEIGHT][MAZE_WIDTH];	// 迷路に使う2次元配列

};

/// @brief 穴掘り法での生成
class HoleDigging : public Method{
public:

	/// @brief コンストラクタ
	HoleDigging();

	/// @brief デストラクタ
	~HoleDigging();

	/// @brief 実行
	static void Execute();

private:
	static void Dig( Position pos_ );

};

class WallExtend : public Method{
public:

	/// @brief コンストラクタ
	WallExtend();

	/// @brief デストラクタ
	~WallExtend();

	/// @brief 実行
	static void Execute();

private:
	static void Build( Position pos_ );
	static Position Lottery();

	static std::vector<Position> start;
};

class Domino : public Method{
public:

	/// @brief コンストラクタ
	Domino();

	/// @brief デストラクタ
	~Domino();

	/// @brief 実行
	static void Execute();

private:
	static void Build( int x, int y );
};

class BellmanFord : public Method{
public:

	/// @brief コンストラクタ
	BellmanFord();

	/// @brief デストラクタ
	~BellmanFord();

	/// @brief 実行
	static void Execute();

};

class Dijkstra : public Method{
public:

	/// @brief コンストラクタ
	Dijkstra();

	/// @brief デストラクタ
	~Dijkstra();

	/// @brief 実行
	static void Execute();

private:
	// return 正解のケース
	static int Search();

	// ケース<回数<x,y>>
	static std::vector<std::vector<Position>> movingLog;

};

class ASter : public Method{
public:

	/// @brief コンストラクタ
	ASter();

	/// @brief デストラクタ
	~ASter();

	/// @brief 実行
	static void Execute();
};

#endif // !METHOD_H
