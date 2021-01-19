
#include "Method.h"

Position goal = { MAZE_WIDTH - 2, MAZE_HEIGHT - 2 };

std::vector<std::vector<Position>> Dijkstra::movingLog;

Dijkstra::Dijkstra(){

}

Dijkstra::~Dijkstra(){

}

void Dijkstra::Execute(){
	// 上下左右の行けるマスを調べる
	// 2マス先を調べて通路である限り探索を進める
	// 行き止まりである場合はその経路の探索をやめる

	movingLog.resize( 1, std::vector<Position>(1) );
	movingLog.back().back() = { 1,1 };

	int ans = Search();

	int counter = 0;

	while( true ){
		int tempX = movingLog.at( ans ).at( counter ).x;
		int tempY = movingLog.at( ans ).at( counter ).y;

		maze[tempY][tempX] = Block::Route;

		if( movingLog.at( ans ).at( counter ) == goal ) break;

		counter++;
	}
}

int Dijkstra::Search(){
	bool up = false;
	bool left = false;
	bool right = false;
	bool down = false;

	while( true )
	{
		// ケースの数だけループする
		int logSize = movingLog.size();

		for( int i = 0; i < logSize; i++ ){
			Position pos_ = movingLog.at( i ).back();

			// 上に進めることを確認
			if( maze[pos_.y - 1][pos_.x] == Block::Empty &&
				pos_.y - 1 > 0 &&
				pos_.from != Direction::Up ){
				// 移動して探索フラグを立てる
				movingLog.at( i ).push_back( { pos_.x, pos_.y - 1, Direction::Down } );
				up = true;
			}

			// 左
			if( maze[pos_.y][pos_.x - 1] == Block::Empty &&
				pos_.x - 1 > 0 &&
				pos_.from != Direction::Left){
				// 分かれ道の場合はケースを増やす
				if( up == true ){
					movingLog.push_back( std::vector<Position>() );
					movingLog.back() = movingLog.at( i );
					movingLog.back().pop_back();
					movingLog.back().push_back( { pos_.x - 1, pos_.y, Direction::Right } );
				}
				else{
					movingLog.at( i ).push_back( { pos_.x - 1, pos_.y, Direction::Right } );
				}

				left = true;
			}

			// 右
			if( maze[pos_.y][pos_.x + 1] == Block::Empty &&
				pos_.x + 1 > 0 &&
				pos_.from != Direction::Right ){
				// 分かれ道の場合はケースを増やす
				if( up == true || left == true ){
					movingLog.push_back( std::vector<Position>() );
					movingLog.back() = movingLog.at( i );
					movingLog.back().pop_back();
					movingLog.back().push_back( { pos_.x + 1, pos_.y, Direction::Left } );
				}
				else{
					movingLog.at( i ).push_back( { pos_.x + 1, pos_.y, Direction::Left } );
				}

				right = true;
			}

			// 下
			if( maze[pos_.y + 1][pos_.x] == Block::Empty &&
				pos_.y + 1 > 0 &&
				pos_.from != Direction::Down){
				// 分かれ道の場合はケースを増やす
				if( up == true || left == true || right == true ){
					movingLog.push_back( std::vector<Position>() );
					movingLog.back() = movingLog.at( i );
					movingLog.back().pop_back();
					movingLog.back().push_back( { pos_.x, pos_.y + 1, Direction::Up } );
				}
				else{
					movingLog.at( i ).push_back( { pos_.x, pos_.y + 1, Direction::Up } );
				}

				down = true;
			}

			if( movingLog.at( i ).back() == goal ) return i;

			up = false;
			left = false;
			right = false;
			down = false;
		}
	}

}
