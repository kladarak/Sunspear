#include <iostream>

#include "Core/RTTI.h"

int main()
{
	using namespace std;
	using namespace Sunspear;

	cout << "Hello world" << endl;

	RTTI::StaticRunUnitTests();

	return 0;
}
