
#include <iostream>
#include <time.h>

#include "Method.h"

int main() {

	srand( ( unsigned ) time( NULL ) );

	Method::Execute();

	system( "pause" );
	return 0;
}
