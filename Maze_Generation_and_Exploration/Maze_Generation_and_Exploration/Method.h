#ifndef METHOD_H
#define METHOD_H

class Method {
public:
	// �C���N�������g
	Method();
	// �f�N�������g
	~Method();
public:
	// ���@��@�ł̐���
	void HoleDigging();

	// �ǐL�΂��@�ł̐���
	void WallExtend();

	// �x���}���t�H�[�h�@�ł̒T��
	void BellmanFord();

	// �_�C�N�X�g���@�ł̒T��
	void Dijkstra();

	// A*�@�ł̒T��
	void AStar();
};

// �����̎��s
void ProcessStart( int generationMethod, int explorationMethod );

#endif // !METHOD_H
