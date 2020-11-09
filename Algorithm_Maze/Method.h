#ifndef METHOD_H
#define METHOD_H

class Method {
public:
	// インクリメント
	Method();
	// デクリメント
	~Method();
public:
	// 穴掘り法での生成
	void HoleDigging();

	// 壁伸ばし法での生成
	void WallExtend();

	// ベルマンフォード法での探索
	void BellmanFord();

	// ダイクストラ法での探索
	void Dijkstra();

	// A*法での探索
	void AStar();
};

// 処理の実行
void ProcessStart( int generationMethod, int explorationMethod );

#endif // !METHOD_H
