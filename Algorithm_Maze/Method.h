#ifndef METHOD_H
#define METHOD_H

const int MAZE_X = 15;	// 迷路の横幅
const int MAZE_Y = 11;	// 迷路の縦幅

// マスの状態
enum Block {
	Empty,	// 何もない
	Wall	// 壁
};

class Method {
public:
	// インクリメント
	Method();
	// デクリメント
	~Method();
private:
	// 穴掘り法での生成
	static void HoleDigging();

	// 壁伸ばし法での生成
	static void WallExtend();

	// ベルマンフォード法での探索
	static void BellmanFord();

	// ダイクストラ法での探索
	static void Dijkstra();

	// A*法での探索
	static void AStar();

	// 迷路の表示
	static void PrintMaze();

public:
	// 処理の実行
	static void Execute( int generationMethod, int explorationMethod );

private:
	static int maze[MAZE_X][MAZE_Y];	// 迷路に使う2次元配列
};

#endif // !METHOD_H
