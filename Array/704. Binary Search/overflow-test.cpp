#include <iostream>

using namespace std;

int main(void) {
	int a = 1;
	int b = INT_MAX;

	int result = (a + b) / 2;
	cout << "(a + b) / 2: " << result << endl;

	result = a + (b - a) / 2;
	cout << "a + (b - a) / 2: " << result << endl;

	result = (unsigned int)(a + b) >> 1;
	cout << "(a + b) >> 1: " << result << endl;

	return 0;
}
