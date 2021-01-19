
#include "Method.h"

std::vector<Position> WallExtend::start;

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

	// 開始地点候補を詰める
	for( int y = 2; y < MAZE_HEIGHT - 1; y += 2 ){
		for( int x = 2; x < MAZE_WIDTH - 1; x += 2 ){
			start.push_back( { x, y } );
		}
	}

	while( !start.empty() ){
		Build( Lottery() );
	}

}

void WallExtend::Build( Position pos_ ){
	if( maze[pos_.y][pos_.x] != Block::Empty ) return;

	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;

	maze[pos_.y][pos_.x] = Block::Wall;

	while( up == false || left == false || right == false || down == false ){
		switch( rand() % 4 ){
		case 0:
			// 上
			if( maze[pos_.y - 1][pos_.x] == Block::Empty ){
				maze[pos_.y - 1][pos_.x] = Block::Wall;
				if( maze[pos_.y - 2][pos_.x] == Block::Empty ){
					maze[pos_.y - 2][pos_.x] = Block::Wall;
					pos_.y -= 2;

					left = false;
					right = false;
					down = false;
				}
				else{
					return;
				}
			}
			else{
				up = true;
			}

			break;
		case 1:
			// 左
			if( maze[pos_.y][pos_.x - 1] == Block::Empty ){
				maze[pos_.y][pos_.x - 1] = Block::Wall;
				if( maze[pos_.y][pos_.x - 2] == Block::Empty ){
					maze[pos_.y][pos_.x - 2] = Block::Wall;
					pos_.x -= 2;

					up = false;
					right = false;
					down = false;
				}
				else{
					return;
				}
			}
			else{
				left = true;
			}

			break;
		case 2:
			// 右
			if( maze[pos_.y][pos_.x + 1] == Block::Empty ){
				maze[pos_.y][pos_.x + 1] = Block::Wall;
				if( maze[pos_.y][pos_.x + 2] == Block::Empty ){
					maze[pos_.y][pos_.x + 2] = Block::Wall;
					pos_.x += 2;

					up = false;
					left = false;
					down = false;
				}
				else{
					return;
				}
			}
			else{
				right = true;
			}

			break;
		case 3:
			// 下
			if( maze[pos_.y + 1][pos_.x] == Block::Empty ){
				maze[pos_.y + 1][pos_.x] = Block::Wall;
				if( maze[pos_.y + 2][pos_.x] == Block::Empty ){
					maze[pos_.y + 2][pos_.x] = Block::Wall;
					pos_.y += 2;

					up = false;
					left = false;
					right = false;
				}
				else{
					return;
				}
			}
			else{
				down = true;
			}

			break;
		}
	}
}

Position WallExtend::Lottery(){
	int temp = rand() % start.size();
	Position pos = start.at( temp );
	std::swap( start.at( temp ), start.back() );
	start.pop_back();

	return pos;
}