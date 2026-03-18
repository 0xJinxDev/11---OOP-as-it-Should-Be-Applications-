#include <iostream>

using namespace std;


template <class T>
class Calculator {

private:
	T _Number1, _Number2;

public:

	Calculator(T n1, T n2) : _Number1(n1), _Number2(n2) {

	}

	void PrintResults() {

		cout << "Add " << Add() << endl;
		cout << "Subtract " << Subtract() << endl;
		cout << "Multiply " << Multiply() << endl;
		cout << "Divide " << Divide() << endl;
	}
	T Add() {
		return _Number1 + _Number2;
	}

	T Subtract() {
		return _Number1 - _Number2;
	}

	T Multiply() {
		return _Number1 * _Number2;
	}

	T Divide() {
		return _Number1 / _Number2;
	}
};

int main() {

	Calculator <int> intCalc(100, 200);
	intCalc.PrintResults();

	Calculator <float> floatCalc(125.6, 123.8);
	floatCalc.PrintResults();

	return 0;
}