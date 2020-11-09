
#include "Method.h"

Method::Method() {

}

Method::~Method() {

}

void Method::HoleDigging() {

}

void Method::WallExtend() {

}

void Method::BellmanFord() {

}

void Method::Dijkstra() {

}

void Method::AStar() {

}

void ProcessStart( int generationMethod, int explorationMethod ) {
	switch ( generationMethod )
	{
	case 0:
		Method* HoleDigging();
		break;
	case 1:
		Method* WallExtend();
		break;
	default:
		return;
		break;
	}

	switch ( explorationMethod )
	{
	case 0:
		Method * BellmanFord();
		break;
	case 1:
		Method * Dijkstra();
		break;
	case 2:
		Method * AStar();
		break;
	default:
		return;
		break;
	}
}
