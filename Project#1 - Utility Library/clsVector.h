#pragma once
#include <iostream>
#include <vector>

using namespace std;
class clsVector
{

public:

	static void PrintVector(const vector <string>& Vector) {

		for (const string& Record : Vector) {
			cout << Record << endl;
		}
	}
};

