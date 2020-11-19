#ifndef METHOD_H
#define METHOD_H

#include <iostream>

const int MAZE_X = 15;	// 迷路の横幅
const int MAZE_Y = 11;	// 迷路の縦幅

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

class Method {
public:

	/// @brief インクリメント
	Method();

	/// @brief デクリメント
	~Method();

protected:

	/// @brief 迷路の表示
	static void PrintMaze();

public:

	/// @brief 実行
	static void Execute();

protected:
	static int maze[MAZE_X][MAZE_Y];	// 迷路に使う2次元配列

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

};

class WallExtend : public Method{
public:

	/// @brief コンストラクタ
	WallExtend();

	/// @brief デストラクタ
	~WallExtend();

	/// @brief 実行
	static void Execute();

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
