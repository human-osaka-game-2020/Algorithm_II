
#include <iostream>
#include "Method.h"

int main() {

	int generationMethod = -1;
	int explorationMethod = -1;

	std::cout << "迷路の生成方法" << std::endl;
	std::cout << ":0 = 穴掘り法 \n:1 = 壁伸ばし法" << std::endl;
	scanf_s( "%d", &generationMethod );

	std::cout << "迷路の探索方法" << std::endl;
	std::cout << ":0 = ベルマンフォード法 \n:1 = ダイクストラ法 \n:2 = A*法" << std::endl;
	scanf_s( "%d", &explorationMethod );

	ProcessStart( generationMethod, explorationMethod);

	system( "pause" );
	return 0;
}
