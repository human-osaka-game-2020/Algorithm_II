
#include "Method.h"

Block Method::maze[MAZE_HEIGHT][MAZE_WIDTH] = {};

Method::Method() {

}

Method::~Method() {

}

void Method::PrintMaze(){
	for ( int y = 0; y < MAZE_HEIGHT; y++ ){
		for ( int x = 0; x < MAZE_WIDTH; x++ ){
			switch( maze[y][x] ){
			case Block::Wall: printf( "■" ); break;
			case Block::Empty: printf( "　" ); break;
			case Block::Route: printf( "・" ); break;
			default: break;
			}
		}
		printf( "\n" );
	}
}

void Method::Execute() {

	int create = -1;
	int search = -1;

	std::cout << "迷路の生成方法" << std::endl;
	std::cout << ":0 = 穴掘り法 \n:1 = 壁伸ばし法 \n:2 = 棒倒し法" << std::endl;
	scanf_s( "%d", &create );

	std::cout << "迷路の探索方法" << std::endl;
	std::cout << ":0 = ベルマンフォード法 \n:1 = ダイクストラ法 \n:2 = A*法" << std::endl;
	scanf_s( "%d", &search );

	switch ( create )
	{
	case 0:
		HoleDigging::Execute();
		break;
	case 1:
		WallExtend::Execute();
		break;
	case 2:
	default:
		Domino::Execute();
		break;
	}

	switch ( search )
	{
	case 0:
		BellmanFord::Execute();
		break;
	case 1:
		Dijkstra::Execute();
		break;
	case 2:
	default:
		ASter::Execute();
		break;
	}

	PrintMaze();
}
