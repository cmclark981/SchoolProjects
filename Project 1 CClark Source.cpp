/*CS 210 Project One
Christopher Clark
Sept 19, 2021 */

#include<iostream>

using namespace std;


/*This class resulted from failed efforts to declare the hours, minutes and seconds
variables in the clock classes independently. I could not get the variables to be 
recognized and had confiltcs. This public class is in place and shared with the 
classes used for each clock in order to declare the variables listed. I have cited information
gathered from thenewboston Youtube channel tutorial on classes and objects.*/

class clockVars {     //(thenewboston, 2011)

public:
	int hours;
	int minutes;
	int seconds;	
};

/*Class set up for the 12 hour clock and shared clockVars public class for access
to the declared variables for hours, minues and seconds.*/

class twelveHourClock : public clockVars {

/*Public methods, or functions, for menu choices given to user. The 12 hours clock function is
set up for hours, minutes and seconds. There is a function for adding an hour, adding a minute and 
adding a second. The functions are set up to respond to user input and increase hour, minute and seconds.
If minute or second is at 59, then the next upper level is also increased. Cited information gathered 
in ZyBooks and OneComplier.com. At first I did not have a function with parameters for hours, min, and seconds. I had to add the first 
method below to access the variables in the public class and assign values in the parameters for this function. */

public:
	twelveHourClock(int hrs, int mins, int secs) {    //(ZyBooks; Dickson, 2020)
		hours = hrs;
		minutes = mins;
		seconds = secs;
	}
	
	void addHour() {
		
		if (hours == 12) {
			hours = 1;
		}
		else {
			hours += 1;
		}
	}

	void addMinute() {
		if (minutes == 59) {
			minutes = 0;
			addHour();
		}
		else {
			minutes += 1;
		}
	}

	void addSecond() {
		if (seconds == 59) {
			seconds = 0;
			addMinute();
		}
		else {
			seconds += 1;
		}
	}
};

/*This class is similar to above accept it is set up for the 24 hour clock. The public class 
of clockVars is shared for access the the hours, minutes and seconds variables. */

class twentyFourHourClock : public clockVars {

/*Public methods, or functions, for operation of 24 hour clock. The 24 hour clock is set up
for hours, minutes and seconds. There are functions to correspond to user input for adding
an hour, adding a minute, and adding seconds. If Hours are at 23, adding one hour outputs 00.
If minutes are at 59, adding a minute also increases the hours. If seconds are at 59, adding a
second also increases the minutes. No citation as this code was built based on lessons learned 
in the 12 hour class. */

public:
	twentyFourHourClock(int hrs, int mins, int secs) {
		hours = hrs;
		minutes = mins;
		seconds = secs;
	}

	void addHour() {
		
		if (hours == 23) {
			hours = 0;
		}

		else {
			hours += 1;
		}
	}

	void addMinute()
	{
		if (minutes == 59) {
			minutes = 0;
			addHour();
		}
		else {
			minutes += 1;
		}
	}
	void addSecond()
	{
		if (seconds == 59) {
			seconds = 0;
			addMinute();
		}
		else {
			seconds += 1;
		}
	}
};

/*This function is in place to output the clock and menu for user input. The display time function is 
set up to pass the 12 hour and 24 hour clock classes by reference and points clock 1 and clock 2 variables
to those classes for access to the hours, minutes and seconds output by those functions. 
There are if statements to account for the output of 2 digits even if the clock value is below 10. The cout
commands also set up the display format for the two clocks and the menu. 
I had troule with this section. I could not get the function calls to work. I did not realize a designator
or pointer was needed in conjunction with a new variable. I sourced this information from thenewboston Youtube channel
tutorial on pass by reference with pointers and compared to OneCompier.com. I had to add the clock 1 and 2 variables 
to the if statemtns to get the correct time to output from the functions called in displayTime*/

void clockOutput(const twelveHourClock& clock1, const twentyFourHourClock& clock2)     //(thenewboston, pass by reference with pointers, 2011; Dickson, 2020)
{
	cout << "*************************    **************************" << endl;
	cout << "*     12-Hour Clock     *    *      24-Hour Clock     *" << endl;
	cout << "*     "; 
	
	if (clock1.hours < 10) cout << "0";
		cout << clock1.hours << ":";
	
	if (clock1.minutes < 10) cout << "0";
		cout << clock1.minutes << ":";
	
	if (clock1.seconds < 10) cout << "0";
		cout << clock1.seconds;
	
	if (clock2.hours >= 12) cout << " P M";		//(cplusplus.com)
	
	else cout << " A M";
		 cout << "      *    *        ";
	
	if (clock2.hours < 10) cout << "0";
		cout << clock2.hours << ":";
	
	if (clock2.minutes < 10) cout << "0";
		cout << clock2.minutes << ":";
	
	if (clock2.seconds < 10) cout << "0";
		cout << clock2.seconds;
	
	cout << "        *"  << endl;
	cout << "*************************    **************************" << endl;
}

/*In main we set the clocks to the inital display values and assign them to the
output of the functions above. The while loop controls the user input menu. We
display a menu and obtain the user input value. We use if statements to 
call our functions and output the time based on user input selection.

Referenced ZyBooks, cplusplus.com and OneCompiler.com for examples of calling the
classes as seen below and initializing the functions with a value. */

int main() {

	twelveHourClock twelveHourOutput(03, 22, 01);		//(Dickson, 2020)
	twentyFourHourClock twentyFourHourOutput(15, 22, 01);
	clockOutput(twelveHourOutput, twentyFourHourOutput);

	while (true) {

		cout << endl;
		cout << "              *************************" << endl;
		cout << "              * 1 - Add One Hour      *" << endl;
		cout << "              * 2 - Add One Minute    *" << endl;
		cout << "              * 3 - Add One Second    *" << endl;
		cout << "              * 4 - Exit Program      *" << endl;
		cout << "              *************************" << endl;

		int userInput;
		cin >> userInput;

		/*For this section I could not get the if statemetnts to work properly. I used information gathered from 
		cplusplus.com as cited. I was not identifying the add....() function after identifying which clock function to call. 
		I then assigned the clock functions to the output function using "twelveHourOutPut.addHour()", etc. I also initially 
		tried to have separate if statments for	12 hours vs 24 hours clocks. However, I could not get the clockOutput call 
		to work. The system errored with too few parameters in the call. I ended up calling both the 12 and 24 hours 
		functions in the same if statement. */

		if (userInput == 1) {				//(cplusplus.com)
			twelveHourOutput.addHour();
			twentyFourHourOutput.addHour();
			clockOutput(twelveHourOutput, twentyFourHourOutput);
		}

		if (userInput == 2) {
			twelveHourOutput.addMinute();
			twentyFourHourOutput.addMinute();
			clockOutput(twelveHourOutput, twentyFourHourOutput);
		}

		if (userInput == 3) {
			twelveHourOutput.addSecond();
			twentyFourHourOutput.addSecond();
			clockOutput(twelveHourOutput, twentyFourHourOutput);
		}

		if (userInput == 4) {
			exit(1);
		}

		//Used code given in announcements.

		for (int i = 0; i < 40; ++i)		
			cout << endl;
	}
	
}



/*Citations

Declaring AM/PM as a string - C++ forum. cplusplus.com. (n.d.). Retrieved September 18, 2021, from http://www.cplusplus.com/forum/beginner/118181/. 

Dickson, W. (2020). OneCompiler. Retrieved September 18, 2021, from https://onecompiler.com/cpp/3xbpkvhuk

thenewboston. (2011, April 6). Buckys C++ programming tutorials - 12 - introduction to classes and objects. YouTube. Retrieved September 18, 2021, from https://www.youtube.com/watch?v=ABRP_5RYhqU.

thenewboston. (2011, April 10). Buckys C++ programming tutorials - 39 - pass by reference with pointers. YouTube. Retrieved September 18, 2021, from https://www.youtube.com/watch?v=_ja8iizm7nk.

User Defined Functions. Zybooks. (n.d.). Retrieved September 18, 2021, from https://learn.zybooks.com/zybook/SNHUCS210v2*/