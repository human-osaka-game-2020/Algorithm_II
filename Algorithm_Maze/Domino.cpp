
#include "Method.h"

Domino::Domino(){

}

Domino::~Domino(){

}

void Domino::Execute(){
	for( int y = 0; y < MAZE_HEIGHT; y++ ){
		for( int x = 0; x < MAZE_WIDTH; x++ ){
			if( ( x % 2 == 0 && y % 2 == 0 ) ||
				y == 0 || y == MAZE_HEIGHT - 1 ||
				x == 0 || x == MAZE_WIDTH - 1 ){
				maze[y][x] = Block::Wall;
			}
			else{
				maze[y][x] = Block::Empty;
			}
		}
	}

	for( int y = 2; y < MAZE_HEIGHT - 1; y += 2 ){
		for( int x = 2; x < MAZE_WIDTH - 1; x += 2 ){
			Build( x, y );
		}
	}
}

void Domino::Build( int x, int y ){
	while( true ){
		switch( rand() % 4 ){
		case 0:
			// 上
			if( y == 2 && maze[y - 1][x] == Block::Empty ) {
				maze[y - 1][x] = Block::Wall;
				return;
			}

			break;
		case 1:
			// 左
			if( maze[y][x - 1] == Block::Empty ) {
				maze[y][x - 1] = Block::Wall;
				return;
			}

			break;
		case 2:
			// 右
			if( maze[y][x + 1] == Block::Empty ) {
				maze[y][x + 1] = Block::Wall;
				return;
			}

			break;
		case 3:
			// 下
			if( maze[y + 1][x] == Block::Empty ) {
				maze[y + 1][x] = Block::Wall;
				return;
			}

			break;
		default:
			break;
		}
	}
}
