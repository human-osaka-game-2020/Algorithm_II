
#include <iostream>
#include "Method.h"

int main() {

	int generationMethod = -1;
	int explorationMethod = -1;

	std::cout << "���H�̐������@" << std::endl;
	std::cout << ":0 = ���@��@ \n:1 = �ǐL�΂��@" << std::endl;
	scanf_s( "%d", &generationMethod );

	std::cout << "���H�̒T�����@" << std::endl;
	std::cout << ":0 = �x���}���t�H�[�h�@ \n:1 = �_�C�N�X�g���@ \n:2 = A*�@" << std::endl;
	scanf_s( "%d", &explorationMethod );

	ProcessStart( generationMethod, explorationMethod);

	system( "pause" );
	return 0;
}
