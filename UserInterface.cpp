//Trevor Walker
//10/8/14
//CS240, Bowe
//Group Project work

#include<windows.h>
#include<stdlib.h>
#include <iostream>

#include "ClockTest.h"

using namespace std;

void intro();
void loginCheck();
void addNewEmployee();
void addEmployee();
void addManager();

//written using restaurant flowchart as a guideline, JPEG is on github

void intro()
    {
    cout << "**----Welcome to Restaurant Management Program.----**" << endl;
    cout << "******=========Written by TT, RG, & TW=========******" << endl;
    cout << "*****************************************************" << endl << endl;
    Sleep(2000);
    system("CLS");
    loginCheck();
    }

void loginCheck()
    {
    //checks whether an employee is manager or standard, checks permissions, then opens either employee menu or manager menu
    //for now, it is set to choose 1 or 2 for testing purposes
    int employeeType = 0;
    cout << "Login as Employee, or Manager? Enter 1 for employee, 2 for manager." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl;
    if (employeeType != 1 && employeeType != 2)
        {

        }

    }



void addNewEmployee()
    {

    int whichType = 0;
    cout << "Would you like to add a new manager to the system, or a new standard employee? Enter 1 to add a manager, or enter 2 to add an employee." << endl;
    cin >> whichType;
    switch (whichType)
        {
        case 1: addManager();
        break;
        case 2: addEmployee();
        break;
        default:
            cout << "Error encountered. Not a valid option. Please try again.";
            system("CLS");
            addNewEmployee();
        break;
        }
    }

void addEmployee()
    {
    //function to add
    }

void addManager()
    {

    }

void clockInAndOut()
    {
    //needs to use Tyler's clock in class to clock in/out an employee and record the time in a text file, along with employee name. HELP ME TYLER
    }


void employeeMenu()
    {

    }

void managerMenu()
    {

    }



int main()
    {

    return 0;
    }
