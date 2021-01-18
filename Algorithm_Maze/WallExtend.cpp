
#include "Method.h"

WallExtend::WallExtend(){

}

WallExtend::~WallExtend(){

}

void WallExtend::Execute(){
	for( int y = 0; y < MAZE_HEIGHT; y++ ){
		for( int x = 0; x < MAZE_WIDTH; x++ ){
			if( y == 0 || y == MAZE_HEIGHT - 1 ||
				x == 0 || x == MAZE_WIDTH - 1){
				maze[y][x] = Block::Wall;
			}
			else{
				maze[y][x] = Block::Empty;
			}
		}
	}

	Position pos;

	while( true ){
		pos = { rand() % MAZE_WIDTH, rand() % MAZE_HEIGHT };
		if( pos.x % 2 == 1 ) pos.x++;

		if( pos.y % 2 == 1 ) pos.y++;

		if( pos.x != 0 && pos.x != MAZE_WIDTH - 1 ){
			if( pos.y == 0 || pos.y == MAZE_HEIGHT - 1 ) break;
		}
	}

	Build( pos );
}

void WallExtend::Build( Position pos_ ){

	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;

	while( up == false || left == false || right == false || down == false ){
		switch( rand() % 4 ){
			// 上
		case 0:
			if( maze[pos_.y - 2][pos_.x] != Block::Empty ||
				pos_.y - 2 <= 0 ||
				up == true ){
				up = true;
				break;
			}

			maze[pos_.y - 1][pos_.x] = Block::Wall;
			maze[pos_.y - 2][pos_.x] = Block::Wall;
			pos_.y -= 2;

			up = false;
			left = false;
			right = false;
			down = false;

			Build( pos_ );

			break;

			// 左
		case 1:
			if( maze[pos_.y][pos_.x - 2] != Block::Empty ||
				pos_.x - 2 <= 0 ||
				left == true ){
				left = true;
				break;
			}

			maze[pos_.y][pos_.x - 1] = Block::Wall;
			maze[pos_.y][pos_.x - 2] = Block::Wall;
			pos_.x -= 2;

			up = false;
			left = false;
			right = false;
			down = false;

			Build( pos_ );

			break;

			// 右
		case 2:
			if( maze[pos_.y][pos_.x + 2] != Block::Empty ||
				pos_.x + 2 >= MAZE_WIDTH ||
				right == true ){
				right = true;
				break;
			}

			maze[pos_.y][pos_.x + 1] = Block::Wall;
			maze[pos_.y][pos_.x + 2] = Block::Wall;
			pos_.x += 2;

			up = false;
			left = false;
			right = false;
			down = false;

			Build( pos_ );

			break;

			// 下
		case 3:
			if( maze[pos_.y + 2][pos_.x] != Block::Empty ||
				pos_.y + 2 >= MAZE_HEIGHT ||
				down == true ) {
				down = true;
				break;
			}

			maze[pos_.y + 1][pos_.x] = Block::Wall;
			maze[pos_.y + 2][pos_.x] = Block::Wall;
			pos_.y += 2;

			up = false;
			left = false;
			right = false;
			down = false;

			Build( pos_ );

			break;

		default: break;
		}
	}
}
