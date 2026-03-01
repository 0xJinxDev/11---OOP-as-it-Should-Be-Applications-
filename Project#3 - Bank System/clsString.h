#pragma once
#include <iostream>
#include <vector>
using namespace std;
class clsString
{

private:
	string _Value;

public:
	clsString() : _Value("") {

	}

	clsString(const string& Value) : _Value(Value) {

	}

	void setValue(const string& Value) { _Value = Value; }
	string getValue() const { return _Value; }

	static short CountWords(const string& Value, const string& Delim) {

		if (Value.empty() || Delim.empty())
			return 0;

		short Counter = 0;
		bool InsideWord = false;
		for (short i = 0; i < Value.length();) {

			if (Value.compare(i, Delim.length(), Delim) != 0) {
				if (!InsideWord) {
					InsideWord = true;
					Counter++;
				}
				i++;
			}
			else {
				InsideWord = false;
				i += Delim.length();
			}

		}
		return Counter;
	}

	short CountWords(const string& Delim = " ") const {
		return CountWords(_Value, Delim);
	}

	static vector<string> SeperateWords(const string& Value, const string& Delim) {
		vector<string> vWords;
		string Word;
		if (Value.empty() || Delim.empty()) {

			return {};
		}

		for (int i = 0; i < Value.length();) {

			if (Value.compare(i, Delim.length(), Delim) != 0) {
				Word += Value[i];
				i++;
			}
			else {
				if (!Word.empty()) {
					vWords.push_back(Word);
					Word.clear();
				}
				i += Delim.length();
			}


		}

		if (!Word.empty()) {
			vWords.push_back(Word);
		}
		return vWords;
	}
	vector<string> SeperateWords(const string& Delim) {
		return SeperateWords(_Value, Delim);
	}
};
