#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void generateCode(int myArr[][4]); //Generate random 4 digit number
bool validateUserInput(string input); //Validates user input.  Only allow digits 1 - 6
int checkCode(string input, int counter, int myArr[][4]); //Check the users code againts random generated code

int main()
{
	string input;
	int myArr[4][4];

	generateCode(myArr);
	
	//uncomment below line to display code (for testing purposes)
	//cout << myArr[0][0] << myArr[0][1] << myArr[0][2] << myArr[0][3] << endl;

	for (int counter = 1; counter < 11; ++counter)
	{
		cout << "Enter a code: ";
		getline(cin, input);

		while(validateUserInput(input) == false)
		{
			cout << "Invalid entry, try again: ";
			getline(cin, input);
		}
		
		if(checkCode(input, counter, myArr) == 1)
			{
			counter = 11;
			cout << "You won!\n" << "The code was " << myArr[0][0] << myArr[0][1] << myArr[0][2] << myArr[0][3] << endl;
			}

		if(counter == 10)
			cout << "You lost!\n" << "The code was " << myArr[0][0] << myArr[0][1] << myArr[0][2] << myArr[0][3] << endl;

	}

//system("pause");

	return 0;
}

void generateCode(int myArr[][4])
{
	srand(time(NULL));
	
	for (int i = 0; i < 4; ++i)
	{
		myArr[0][i] = rand() % 6 + 1;
	}
}

int checkCode(string input, int counter, int myArr[][4])
{

	myArr[1][0] = myArr[0][0];
	myArr[1][1] = myArr[0][1];
	myArr[1][2] = myArr[0][2];
	myArr[1][3] = myArr[0][3];

	myArr[2][0] = atoi(input.substr(0,1).c_str());
	myArr[2][1] = atoi(input.substr(1,1).c_str());
	myArr[2][2] = atoi(input.substr(2,1).c_str());
	myArr[2][3] = atoi(input.substr(3,1).c_str());

	myArr[3][0] = 0;
	myArr[3][1] = 0;
	myArr[3][2] = 0;
	myArr[3][3] = 0;
	
	for(int i =0; i < 4; ++i)
	{
		if(myArr[2][i] == myArr[0][i])
			myArr[1][i] = 0;
	}

	for(int i =0; i < 4; ++i)
	{
		if(myArr[2][i] == myArr[1][0])
		{
			myArr[3][i] = 1;
			myArr[1][0] = 0;
		}
		else if (myArr[2][i] == myArr[1][1])
		{
			myArr[3][i] = 1;
			myArr[1][1] = 0;
		}
		else if (myArr[2][i] == myArr[1][2])
		{
			myArr[3][i] = 1;
			myArr[1][2] = 0;
		}
		else if (myArr[2][i] == myArr[1][3])
		{
			myArr[3][i] = 1;
			myArr[1][3] = 0;
		}
	}

	for(int i =0; i < 4; ++i)
	{
		if(myArr[2][i] == myArr[0][i])
		myArr[3][i] = 2;
	}

	string clue = "";

	for(int i = 0; i < 4; ++i)
	{
		if(myArr[3][i] == 1)
			clue = clue + ".";
		if(myArr[3][i] == 2)
			clue = clue + "O";
	}

	clue = clue + "    ";

	cout << "    -------------------------" << endl;
	if(counter < 10)
		cout << "#0";
	else
		cout << "#";

	cout << counter << "  ( " << myArr[2][0] << " ) ( " << myArr[2][1] << " ) ( " << myArr[2][2] << " ) ( " << myArr[2][3] << " )   [" << clue.substr(0,1) << clue.substr(1,1) << clue.substr(2,1) << clue.substr(3,1) << "]" << endl;
	cout << "    -------------------------" << endl;

	int x = 0;

	if(clue.substr(0,4) == "OOOO")
		x = 1;

	return x;
}

bool validateUserInput(string input)
{
			if (input.find_first_not_of("123456") != string::npos || input.length() < 4 || input.length() > 4)
				return false;
			else
				return true;
}
