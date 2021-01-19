
#include "Method.h"

WallExtend::WallExtend(){

}

WallExtend::~WallExtend(){

}

void WallExtend::Execute(){
	for( int y = 0; y < MAZE_HEIGHT; y++ ){
		for( int x = 0; x < MAZE_WIDTH; x++ ){
			if( ( x % 2 == 0 && y % 2 == 0 ) ||
				y == 0 || y == MAZE_HEIGHT - 1 ||
				x == 0 || x == MAZE_WIDTH - 1){
				maze[y][x] = Block::Wall;
			}
			else{
				maze[y][x] = Block::Empty;
			}
		}
	}

	Build( { 2,2 } );
}

void WallExtend::Build( Position pos_ ){
	for( int y = 2; y < MAZE_HEIGHT - 1; y += 2 ){
		for( int x = 2; x < MAZE_WIDTH - 1; x += 2 ){
		}
	}
}
