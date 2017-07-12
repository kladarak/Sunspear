#include <iostream>

#include "Core/RTTI.h"

int main()
{
	using namespace std;
	using namespace Sunspear;

	cout << "Hello world" << endl;

	RTTI::StaticRunUnitTests();

	extern void DoEntityUnitTests();
	DoEntityUnitTests();

	while (true);

	return 0;
}
