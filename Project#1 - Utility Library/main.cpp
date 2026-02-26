#include <iostream>
#include "clsUtil.h"
#include "clsVector.h"
using namespace std;



int main() {


	clsUtil::Srand();
	string Key = clsUtil::GenerateKey(clsUtil::CapitalLetter, 5, 5);
	cout << "The one generated key is:\n";
	cout << Key <<endl;
	
	vector <string> vKeys = clsUtil::GenerateKeys(5, clsUtil::CapitalLetter, 4, 5);
	cout << "The keys generated using GenerateKeys function:\n";
	clsVector::PrintVector(vKeys);


	
	return 0;
}