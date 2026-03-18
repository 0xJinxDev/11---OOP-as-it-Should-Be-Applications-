#include <iostream>

using namespace std;

template <typename T> T MyMax(T Number1, T Number2) {
	return (Number1 > Number2) ? Number1 : Number2;
}

int main() {

	cout << MyMax<int>(1, 2) << endl;
	cout << MyMax<double>(1.5, 2.5) << endl;
	cout << MyMax<char>('a', 'b') << endl;
}