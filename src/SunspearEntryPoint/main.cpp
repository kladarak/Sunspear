#include <iostream>

int main()
{
	using namespace std;

	cout << "Hello world" << endl;

	extern void DoRTTIUnitTests();
	void DoRTTIUnitTests();

	extern void DoEntityUnitTests();
	void DoEntityUnitTests();

	cout << "Completed unit tests." << endl;

	while (true);

	return 0;
}
