//Trevor Walker
//10/8/14
//CS240, Bowe
//Group Project work

#include<windows.h>
#include<stdlib.h>
#include <iostream>

using namespace std;


//written using restaurant flowchart as a guideline
void introAndLogin()
    {
    cout << "**----Welcome to Restaurant Management Program.----**" << endl;
    cout << "******=========Written by TT, RG, & TW=========******" << endl;
    cout << "*****************************************************" << endl << endl;
    }

int addNewEmployee()
    {
    int whichType = 0;
    cout << "Would you like to add a new manager to the system, or a new standard employee? Enter 1 to add a manager, or enter 2 to add an employee." << endl;
    cin >> whichType;
    if (whichType != 1 && whichType != 2)
        {
        switch (whichType)
            {
            case 1: //logic to add new manager to roster
            break;
            case 2: //logic to add new std. employee to roster
            break;
            }
        }
    else
        {
        cout << "Error encountered. Not a valid option. Please try again. ";
        system("CLS");
        }
    }

int addEmployee()
    {

    }

int clockInAndOut()
    {

    }


int employeeMenu()
    {

    }

int managerMenu()
    {

    }



int main()
    {

    }
