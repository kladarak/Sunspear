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

	cout << "Completed unit tests." << endl;

	while (true);

	return 0;
}
