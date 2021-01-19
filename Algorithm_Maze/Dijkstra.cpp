
#include "Method.h"

Position goal = { MAZE_WIDTH - 2, MAZE_HEIGHT - 2 };

std::vector<std::vector<Position>> Dijkstra::movingLog;

Dijkstra::Dijkstra(){

}

Dijkstra::~Dijkstra(){

}

void Dijkstra::Execute(){
	// �㉺���E�̍s����}�X�𒲂ׂ�
	// 2�}�X��𒲂ׂĒʘH�ł������T����i�߂�
	// �s���~�܂�ł���ꍇ�͂��̌o�H�̒T������߂�

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
		// �P�[�X�̐��������[�v����
		int logSize = movingLog.size();

		for( int i = 0; i < logSize; i++ ){
			Position pos_ = movingLog.at( i ).back();

			// ��ɐi�߂邱�Ƃ��m�F
			if( maze[pos_.y - 1][pos_.x] == Block::Empty &&
				pos_.y - 1 > 0 &&
				pos_.from != Direction::Up ){
				// �ړ����ĒT���t���O�𗧂Ă�
				movingLog.at( i ).push_back( { pos_.x, pos_.y - 1, Direction::Down } );
				up = true;
			}

			// ��
			if( maze[pos_.y][pos_.x - 1] == Block::Empty &&
				pos_.x - 1 > 0 &&
				pos_.from != Direction::Left){
				// �����ꓹ�̏ꍇ�̓P�[�X�𑝂₷
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

			// �E
			if( maze[pos_.y][pos_.x + 1] == Block::Empty &&
				pos_.x + 1 > 0 &&
				pos_.from != Direction::Right ){
				// �����ꓹ�̏ꍇ�̓P�[�X�𑝂₷
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

			// ��
			if( maze[pos_.y + 1][pos_.x] == Block::Empty &&
				pos_.y + 1 > 0 &&
				pos_.from != Direction::Down){
				// �����ꓹ�̏ꍇ�̓P�[�X�𑝂₷
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
