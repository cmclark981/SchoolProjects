/*
 * Calculator.cpp
 *
 *  Date: [9/12/21]
 *  Author: [Christopher Clark]
 */

#include <iostream>
#include <cmath>          //Added cmath library for fixed statement.
#include <iomanip>        //Added iomanip for the manipulatro library (setprecision).

using namespace std;

int main()          //Change void to int given main is to output an int type.
{
	char statement[100];
	double op1;          //Separated int type declarations for op1 adn op2 for best practices.
	double op2;
	char operation;
	char answer = 'Y';          //Replaced double quotes with single quotes for singe char type and added semicolon to end statement. Added whitespace for best practices.


	while (answer == 'y' || answer == 'Y') {          //Added OR statment to include both Y and y and added line spaces and whitespace for best practices.

		cout << "Enter expression" << endl;          //Added line spacing after while loop statement for best practices.
		cin >> op1 >> operation >> op2;          //Swapped locations of op1 and op2 for input order and correct calculations below.

		if (operation == '+') {          //Replaced double quotes with single quotes, removed semicolon and added braces. Added line spacing for all if statements
			cout << fixed << setprecision(2) << op1 << " + " << op2 << " = " << op1 + op2 << endl;          //Replaced >> operands with << after op2. Added braces for if statement. Added fixed << setpreceieion for 2 decimal output on all.
		}
		if (operation == '-') {          //Removed semicolon and added braces for is statement.
			cout << fixed << setprecision(2) << op1 << " - " << op2 << " = " << op1 - op2 << endl;          //Replaced >> operands with << after cout. Added setprecision for two decimal output.
		}	
		if (operation == '*') {           //Removed semicolon and added braces for is statement.
			cout << fixed << setprecision(2) << op1 << " * " << op2 << " = " << op1 * op2 << endl;          //Replaced / with * after op1 for correct calculation and added semicolon after endl. Added setprecision for 2 decimal output.
		}
		if (operation == '/') {          //Added brace for if statement.
			cout << fixed << setprecision(2) << op1 << " / " << op2 << " = " << op1 / op2 << endl;          //Replaced * with / after op1 for correct calculation. Added fixed << setprecision for 2 decimal output. 
		}
			cout << "Do you wish to evaluate another expression? Enter Y to continue or N to finish. " << endl;          //Statement to get user input for program continution. 
			cin >> answer;          //Get input from user and initialize "answer" for program continuation. 

		if (answer == 'N' || answer == 'n') {          //Added if statement to get user input for continuation and putput progam finsihed when n or N is input
			cout << "Program finished" << endl;         //Added print statement for progrma finsihed if uer input is N or n. 
		}
	}
	return 0;          //Added for main to retun an int when no output from program.
}
