#ifndef METHOD_H
#define METHOD_H

#include <iostream>

const int MAZE_WIDTH = 15;	// 迷路の横幅
const int MAZE_HEIGHT = 11;	// 迷路の縦幅

// マスの状態
enum Block {
	Empty,	// 何もない
	Wall	// 壁
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
