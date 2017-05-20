// CIT237-C1
// Homework
// Chapter, Question.
// Project 1: Automobile Simulator
// Ximing He
// Jun. 11, 2015
//
///////////////////////////

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void displayMenu();
void displayStatus(string);
void calculation(string);

string currentState = "Stopped", command = "(Blank)";

double averageSpeed = 0.0, previousSpeed = 0.0, currentSpeed = 0.0,
averageSpeed_FeetPerSecond = 0.0,
intervalFeetTraveled = 0.0, totalFeetTraveled = 0.0, totalTraveled = 0.0,
timeInterval = 1.0,
delta = 5.0;

int quit = 0;


int main()
{
	char choice;
	do
	{
		cout << "command: ";
		cin.get(choice);
		cin.ignore(20, '\n');

		switch (choice)
		{
		case 'a':
		case 'A':
			calculation("Accelerate");
			break;
		case 'b':
		case 'B':
			calculation("Brake");
			break;
		case 'c':
		case 'C':
			calculation("Cruise");
			break;
		case 'd':
		case 'D':
			cout << "All data will be reset. Press any key to continue." << endl;
			system("pause");
			currentState = "Stopped"; command = "(Blank)"; // reset data
			averageSpeed = 0.0; previousSpeed = 0.0; currentSpeed = 0.0; // reset data
			averageSpeed_FeetPerSecond = 0.0; intervalFeetTraveled = 0.0; // reset data
			totalFeetTraveled = 0.0; totalTraveled = 0.0; // reset data
			calculation("Cruise");
			calculation("Cruise");
			calculation("Cruise");
			calculation("Accelerate");
			calculation("Accelerate");
			calculation("Accelerate");
			calculation("Accelerate");
			calculation("Accelerate");
			calculation("Cruise");
			calculation("Cruise");
			calculation("Cruise");
			calculation("Cruise");
			calculation("Cruise");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			calculation("Brake");
			currentState = "Stopped"; command = "(Blank)"; // reset data
			averageSpeed = 0.0; previousSpeed = 0.0; currentSpeed = 0.0; // reset data
			averageSpeed_FeetPerSecond = 0.0; intervalFeetTraveled = 0.0; // reset data
			totalFeetTraveled = 0.0; totalTraveled = 0.0; // reset data
			cout << "All data have been reset. Press any key to continue." << endl;
			system("pause");
			break;
		case 'e':
		case 'E':
			cout << "Enter a number for \"delta\" (with decimal point): ";
			cin >> delta;
			cin.ignore(20, '\n');
			if (cin.fail()) // no extraction took place
			{
				cin.clear(); // reset the state bits back to goodbit so we can use ignore()
				cin.ignore(1000, '\n'); // clear out the bad input from the stream
				delta = 0; // make the delta "wrong" so that user has to enter again
			}
			while (delta <= 0)
			{
				cout << "Please enter a valid number larger than zero: ";
				cin >> delta;
				cin.ignore(20, '\n');
				if (cin.fail()) // no extraction took place
				{
					cin.clear(); // reset the state bits back to goodbit so we can use ignore()
					cin.ignore(1000, '\n'); // clear out the bad input from the stream
					continue; // try again
				}
			}
			cout << "Done. \"Delta\" is set to " << delta << endl << endl;
			break;
		case 'i':
		case 'I':
			cout << "Enter a number for Time Interval (with decimal point): ";
			cin >> timeInterval;
			cin.ignore(20, '\n');
			if (cin.fail()) // no extraction took place
			{
				cin.clear(); // reset the state bits back to goodbit so we can use ignore()
				cin.ignore(1000, '\n'); // clear out the bad input from the stream
				timeInterval = 0; // make the Time Interval "wrong" so that user has to enter again
			}
			while (timeInterval <= 0)
			{
				if (cin.fail()) // no extraction took place
				{
					cin.clear(); // reset the state bits back to goodbit so we can use ignore()
					cin.ignore(1000, '\n'); // clear out the bad input from the stream
					continue; // try again
				}
				cout << "Please enter a valid number larger than zero: ";
				cin >> timeInterval;
				cin.ignore(20, '\n');
			}
			cout << "Done. Time Interval is set to " << timeInterval << endl << endl;
			break;
		case 'h':
		case 'H':
			displayMenu();
			break;
		case 'q':
		case 'Q':
			quit = -1;
			break;
		default:
			cout << "Please enter a valid command!!!" << endl;
			break;
		} // end of switch
	} while (quit != -1); // end of do loop

	system("pause");
	return 0;
}

void displayMenu()
{
	cout << "---------------------------------------------------------------" << endl;
	cout << "Suppoted commands: " << endl;
	cout << "\t\ta\t\t accelerate." << endl;
	cout << "\t\tb\t\t brake." << endl;
	cout << "\t\tc\t\t cruise." << endl;
	cout << "\t\td\t\t demo." << endl;
	cout << "\t\te\t\t change the \"delta\"." << endl;
	cout << "\t\ti\t\t change the time interval." << endl;
	cout << "\t\th\t\t print this help text." << endl;
	cout << "\t\tq\t\t quit the program." << endl;
	cout << "---------------------------------------------------------------" << endl;
}

void displayStatus(string command)
{
	cout << setw(10) << "Function"
		<< setw(15) << "Current State"
		<< setw(15) << "Current Speed"
		<< setw(19) << "Interval Distance"
		<< setw(20) << "Total Traveled"
		<< endl;
	cout << setprecision(0) << fixed << noshowpoint
		<< setw(10) << command
		<< setw(15) << currentState
		<< setw(15) << currentSpeed
		<< setw(19) << setprecision(1) << showpoint << intervalFeetTraveled
		<< setw(13) << totalFeetTraveled << "(" << setprecision(3) << totalTraveled << ")"
		<< endl;
}

void calculation(string command)
{
	previousSpeed = currentSpeed;

	if (command == "Accelerate")
	{
		command = "Accelerate";
		currentSpeed += delta;
		currentState = "Accelerating";
	}
	else if (command == "Brake")
	{
		command = "Brake";
		currentSpeed -= delta;
		currentState = "Braking";
	}
	else if (command == "Cruise")
	{
		command = "Cruise";
		currentState = "Cruising";
	}
	else
	{
		cout << "Error!! Check the code!!" << endl;
		system("pause");
		exit(0);
	}
	
	if (currentSpeed <= 0)
	{
		currentSpeed = 0.0;
		currentState = "Stopped";
	}
	averageSpeed = (previousSpeed + currentSpeed) / 2.0;
	averageSpeed_FeetPerSecond = averageSpeed * 5280.0 / 3600.0;
	intervalFeetTraveled = averageSpeed_FeetPerSecond * timeInterval;
	totalFeetTraveled += intervalFeetTraveled;
	totalTraveled = totalFeetTraveled / 5280.0;
	displayStatus(command);
}
