
#include <iostream>

#include "Method.h"

int Method::maze[MAZE_X][MAZE_Y] = {};

Method::Method() {

}

Method::~Method() {

}

void Method::HoleDigging() {

	// 全て壁で埋める
	for ( int y = 0; y < MAZE_Y; y++ ) {
		for ( int x = 0; x < MAZE_X; x++ ) {
			maze[x][y] = Block::Wall;
		}
	}

	// 奇数の場所に起点となる穴を掘る
	{
		int randResult[2] = {};	// 生成された値を保存する用 (x, y)

		while ( true ){
			randResult[Pos::X] = rand() % MAZE_X;
			// 偶数になったら再抽選
			if ( randResult[Pos::X] % 2 == 1 ) break;
		}

		while ( true ){
			randResult[Pos::Y] = rand() % MAZE_Y;
			if ( randResult[Pos::Y] % 2 == 1 ) break;
		}

		maze[randResult[Pos::X]][randResult[Pos::Y]] = Block::Empty;
	}

	// 掘り堀り

	// 掘る方向を決める
	int digDirection = rand() % 4;

	switch ( digDirection )
	{
	case Direction::Up:
		break;
	case Direction::Left:
		break;
	case Direction::Right:
		break;
	case Direction::Down:
		break;
	default:
		break;
	}
}

void Method::WallExtend() {

}

void Method::BellmanFord() {

}

void Method::Dijkstra() {

}

void Method::AStar() {

}

void Method::PrintMaze(){
	for ( int y = 0; y < MAZE_Y; y++ ){
		for ( int x = 0; x < MAZE_X; x++ ){
			if ( maze[x][y] == Block::Wall ){
				printf( "■" );
			}
			else{
				printf( "　" );
			}
		}
		printf( "\n" );
	}
}

void Method::Execute( int generationMethod, int explorationMethod ) {
	switch ( generationMethod )
	{
	case 0:
		Method::HoleDigging();
		break;
	case 1:
		Method::WallExtend();
		break;
	default:
		return;
		break;
	}

	switch ( explorationMethod )
	{
	case 0:
		Method::BellmanFord();
		break;
	case 1:
		Method::Dijkstra();
		break;
	case 2:
		Method::AStar();
		break;
	default:
		return;
		break;
	}

	PrintMaze();
}
