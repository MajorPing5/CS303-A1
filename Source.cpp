/*------------------------------------------------------------------------------------------
Author: Robert-Abel Porras

Program objectives:
1. A program that can read data (10 lines w/ 10 integers) from a .txt file into an array,
   performing the following functions:
	1) Check if a certain integer exists in the array. If the number is present, return the
	   index where the number is present
	
	2) Modify the value of an integer. When called with the index of the integer of the
	   array, return the new value and old value back to the user
	
	3) Adds a new integer to the end of the array
	
	4) Intakes an index of an array, and replaces the value with either 0 or removes the
	   integer altogether

2. A function that has try/catch blocks for user inputs to accomplish the following:
	a) Can modify the value of an integer when called with the index of the integer in the
	   array, and return both the new and old values back to the user
	
	b) Can add a new integer to the end of the array

Requirements for Submission:
	1. Require header file and .cpp file. Header should provide function declaration and
	   .cpp should have implementation details

	2. All functionality of program should be implemented as functions and methods
	
	3. Code should be well commented
	
	4. Create a report (readme file) that contains instructions on how to run the code and
	   screenshots of the outputs
	
	5. Upload report and code files to GitHub
	
	6. Submit GitHub link on Canvas by due date.

Known Bugs:
1. Any conflicting input after data has been processed (i.e. char input into int variable)
	does NOT have a way of killing the code and ending the loop. Currently unknown solution.
------------------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void addInteger(int list[], int newInt, int& length);
void changeInteger(int i, int oldInt, int list[], int& option);

int main()
{
	int i = 0;
	int k{};
	int list[200];
	int option{}, oldInt{}, newInt{}, pointer{}, searchQuery{};
	int length = 0;
	char confirm;

	ifstream inFile;
	ofstream outFile;

	inFile.open("dataFile.txt");
	outFile.open("dataOutput.txt");

	if (!inFile)
	{
		cout << "Data File not found. Please verify file name and location are correct for"
			 << " this program." << endl;
		system("pause");
		return -1;
	}

	for (i = 0; k != -858993460; i++)
	{
		inFile >> list[i];
		k = list[i];
		length++;
		cout << list[i] << " ";
	}
	
	cout << endl << endl;

	while (option == 0)
	{
		cout << "What would you like to do with this data?" << endl << endl
			<< "1. Search for an integer" << setw(17) << "(type 1)" << endl
			<< "2. Replace an Integer" << setw(20) << "(type 2)" << endl
			<< "3. Clear an Integer" << setw(22) << "(type 3)" << endl
			<< "4. Add a New Integer" << setw(21) << "(type 4)" << endl
			<< "5. Quit" << setw(34) << "(type 5)" << endl << endl;

		cin >> option;

		cout << endl;

		switch (option)
		{
		case 1:
		{
			cout << "What integer would you like to search for?" << endl << endl;
			cin >> searchQuery;

			bool found = false;

			pointer = 0;

			while (pointer < 200 && !found)
				if (list[pointer] == searchQuery)
					found = true;
				else
					pointer++;

			if (found)
			{
				cout << endl
					<< "Your integer was found! Integer " << searchQuery
					<< " was found at array[" << pointer << "]"
					<< endl << endl;
			}
			else
			{
				cout << endl
					<< "Sorry, your integer was not found."
					<< "Please try again with a different search, or"
					<< " try another menu." << endl << endl;
			}
			//O(n) for seqSearch Algorithm

			option = 0;
			break;
		}
		case 2: //Goal: Replace an Integer given an array index number
		{
			while (option == 2)
			{
				cout << "What is the array index number in question?" << endl << endl;
				cin >> i;

				cout << endl << "Is this index number correct Y/N? Array[" << i << "]" << endl << endl;
				cin >> confirm;
				
				changeInteger(i, oldInt, list, option);
			}
			break;
		}
		case 3: //Goal: Clear an Integer given an array index number
		{
			while (option == 3)
			{
				cout << "What is the array index number in question?" << endl << endl;
				cin >> i;

				cout << endl << "Is this index number correct Y/N? Array[" << i << "]" << endl << endl;
				cin >> confirm;

				switch (confirm)
				{
				case 'N':
				{
					cout << endl << "Sorry for the mix-up. Let's try this again." << endl << endl;
					confirm = ' ';
					break;
				}
				case 'Y':
				{
					oldInt = list[i];
					for (i; list[i + 1] != -858993460; ++i)
					{
						list[i - 1] = list[i];
					}
					cout << endl << "Great! At array[" << i << "], " << oldInt << " has been erased "
						"and all values have been moved up in the array index.";
					option = 0;

					//This specifically relies on list[i] being an INTEGER array. Anything else, and this WILL NOT WORK!
					//	Ideally, this is supposed to stop outputting any code that is not '\0', regardless of matrix size.

					for (i = 0; list[i] != -858993460; i++)
					{
						outFile << list[i] << " ";
					}

					break;
				}
				default:
				{
					cout << endl << "Input not recognize. Please try again." << endl << endl;
					i = 0;
					confirm = ' ';
					break;
				}
				}
			}
			option = 0;
			break;
		}
		case 4: //Goal: Input new integer at end of array
		{
			addInteger(list, newInt, length);
			option = 0;
			cout << "New Length: " << length << endl;
			break;
		}
		case 5://Goal: Kill Program Option for User
			break;

		default:
			cout << endl << "Input not recognize. Please review the options again." << endl << endl;
			option = 0;
			break;
		}
	}

//This specifically relies on list[i] being an INTEGER array. Anything else, and this WILL NOT WORK!
//	Ideally, this is supposed to stop outputting any code that is not '\0', regardless of matrix size.
	for (i = 0; list[i] != -858993460; i++)
	{
		outFile << list[i] << " ";
	}

	inFile.close();
	outFile.close();
	cout << "Thank you for using the Data Modifier Tool. Goodbye." << endl << endl;
	system("pause");
	return 0;
}

//Function with try/catch blocks for user to modify the value of an integer when called
//with the index of the integer in the array, and return both the new and
//old values back to the user
void changeInteger (int i, int oldInt, int list[], int& option)
{
	int newInt = 0;

	try
	{
		if (i < 0)
			throw string("Negative Index!");
		if (list[i] == -858993460)
			throw 0;
		else
			throw 1;
	}
	catch (string Negative_Index)
	{
		cout << endl << "Seems like you put in a negative index. The index cannot be negative."
			 << endl;
	}
	catch (int err)
	{
		if (err == 0)
		{
			cout << endl << "Oops! Seems like you entered an index that either doesn't exist in this"
				<< " array yet, or you are out of bounds in the current array." << endl << endl;
		}
		else
		{
			oldInt = list[i];
			cout << endl << "Great! What's the integer you want to use?" << endl << endl;
			cin >> newInt;
			list[i] = newInt;
			cout << endl << "At array[" << i << "], " << oldInt << " has now become " << newInt << "."
				<< endl << endl;
			option = 0;

			for (i = 0; list[i] != -858993460; i++)
			{
				cout << list[i] << " ";
			}
		}
	}
}

//Function with try/catch blocks for user inputs that can add a new integer to the end of the array
void addInteger (int list[], int newInt, int& length) 
{
	int i = --length;
	
	cout << "Array Insertion is currently at array[" << i << "]. What integer would you like to insert?" << endl;
	cout << "Inserting: ";
	cin >> newInt;

	list[i] = newInt;

	cout << "Success! Integer " << newInt << " has been added to array[" << i << "]." << endl << endl;
	length = length + 2;

	cout << "Array while in function: " << endl;
	for (i = 0; list[i] != -858993460; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl << endl;
}