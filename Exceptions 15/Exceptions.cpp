//Matthew Mondi
//CIS 1202
//12/4/23

#include<iostream>

using namespace std;

char character(char start, int offset);


// use start is not (A-z,a-z)
class invalidCharacterExcpeption
{

};

// used if if the target is not a letter
class invalidRangeException
{

};

// used if the target has invalid letter casing
class caseConversionException
{

};


char character(char start, int offset) {


	int StartingValue = int(start);
	int I = StartingValue + offset;

	try {

		if (StartingValue < 65 || (StartingValue > 90 && StartingValue < 97) || StartingValue > 122)
		{
			throw invalidCharacterExcpeption();
		}
		else if (I < 65 || (I > 90 && I < 97) || I>122) {
			throw invalidRangeException();
		}
		else if ((I >= 65 && I <= 90 && StartingValue >= 95 && StartingValue <= 122) || (I >= 95 && StartingValue <= 122 && StartingValue >= 65 && StartingValue <= 90)) {

			throw caseConversionException();
		}
	}

	catch (invalidCharacterExcpeption Exception1) {
		cout << "Invalid Character Exception" << endl;
		return ' ';
	}

	catch (invalidRangeException Exception2) {
		cout << "Invalid Range Exception" << endl;
		return ' ';
	}

	catch (caseConversionException Exception3) {
		cout << "Invalid Letter Casing" << endl;
		return ' ';
	}

	return char(I);

}

int main() {

	cout << character('c', 1) << endl;
	cout << character('R', 55) << endl;
	cout << character('v', 0) << endl;
	cout << character('h', -5) << endl;
	cout << character('A', 45) << endl;
}