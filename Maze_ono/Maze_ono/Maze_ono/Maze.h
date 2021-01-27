
#ifndef MAZE
#define MAZE

#include "Difinition.h"

class Maze 
{
public:
	Maze();
	~Maze();

	void CreateMap();
	void PrintMap();

private:
	void Dig(int x_, int y_);
};


#endif //! MAZE
