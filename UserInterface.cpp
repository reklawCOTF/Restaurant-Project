//Trevor Walker
//10/8/14
//CS240, Bowe
//Group Project work

#include<windows.h>
#include<stdlib.h>
#include <iostream>

#include "ClockTest.h"
#include "ErrorMessages.h"

using namespace std;

void intro();
void loginCheck();
void clockInEmployee();
void clockOutEmployee();
void addNewEmployee();
void addEmployee();
void addManager();
void employeeLogin();
void managerLogin();
void employeeMainMenu();
void managerMainMenu();
void scheduleMenu();
void displaySchedule();
void cashierMenu();
void displayCurrentFoodMenu();
void makeTransaction();

//written using restaurant flowchart as a guideline, JPEG is on github

void intro()
    {
    system("CLS");
    int addOrLogin = 0;
    cout << "*********************************************************" << endl;
    cout << "**----  Welcome to Restaurant Management System    ----**" << endl;
    cout << "******=========  Written by TT, RG, & TW  =========******" << endl;
    cout << "*********************************************************" << endl << endl;
    Sleep(2000);
    system("CLS");
    cout << "Would you like to add a new employee to the system, or proceed to login?" << endl << endl << "Enter 1 to add a new employee, or 2 to login." << endl;
    cin >> addOrLogin;
    switch (addOrLogin)
        {
        case 1: addNewEmployee();
        break;
        case 2: loginCheck();
        break;
        default: errorMessages(1);
        break;
        }
    }

void loginCheck()
    {
    system("CLS");
    //checks whether an employee is manager or standard, checks permissions, then opens either employee menu or manager menu
    //for now, it is set to choose 1 or 2 for testing purposes
    int employeeType = 0;
    cout << "Login to system as Employee, or Manager? Enter 1 for employee, 2 for manager." << endl << endl "You can also enter 3 to clock in or out." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> employeeType;
    switch(employeeType)
        {
        case 1: employeeLogin();
        break;
        case 2: managerLogin();
        break;
        case 3: clockMenu();
        break;
        case 9: intro();
        break;
        default: errorMessages(1);
        break;

        }

    }

void clockMenu()
    {
    system("CLS");
    int clockType = 0;
    cout << "Would you like to clock in or clock out?" << endl << endl << "Enter 1 to Clock in, or 2 to clock out." << endl << endl;
    cin >> clockType;
    switch (clockType)
        {
        case 1: clockInEmployee();
        break;
        case 2: clockOutEmployee();
        break;
        case 9: employeeMenu();
        break;
        default ErrorMessages(1);
        break;
    
        }
        
    }
    
void clockInEmployee()
    {
    
        
    }
    
void clockOutEmployee()
    {
        
    }
    
void addNewEmployee()
    {
    system("CLS");
    int whichType = 0;
    cout << "Would you like to add a new manager to the system, or a new standard employee?" << endl << endl << "Enter 1 to add a manager, or enter 2 to add an employee." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;

    cin >> whichType;
    switch (whichType)
        {
        case 1: addManager();
        break;
        case 2: addEmployee();
        break;
        case 9: intro();
        break;
        default: errorMessages(1);
                 addNewEmployee();
        break;
        }
    }

void addEmployee()
    {
    system("CLS");
    //function to add standard employee to system
    //return to main menu after adding new employee
    cout << "Employee added." << endl;
    Sleep(1400);
    intro();
    }

void addManager()
    {
    system("CLS");
    //function to add Manager to system
    //return to main menu after adding new manager
    cout << "Manager added. Permissions granted." << endl;
    Sleep(1400);
    intro();

    }

void employeeLogin()
    {
    system("CLS");
    string userName = "";
    string passWord = "";
    cout << "Enter UserName: ";
    cin >> userName;
    cout << endl << "Enter Password:  ";
    cin >> passWord;
    cout << endl;
    //needs to use Tyler's clock in class to clock in/out an employee and record the time in a text file, along with employee name. HELP ME TYLER
    cout << "Logged in successfully." << endl << endl << "Welcome to RMS, -Insert Username Here-";
    Sleep(1200);
    employeeMainMenu();
    }

void managerLogin()
    {
    system("CLS");
    string userName = "";
    string passWord = "";
    cout << "Enter UserName: ";
    cin >> userName;
    cout << endl << "Enter Password:  ";
    cin >> passWord;
    cout << endl;
    //needs to use Tyler's clock in class to clock in/out an employee and record the time in a text file, along with employee name. HELP ME TYLER
    //needs to use an actual stored password, this is here merely for testing/menu navigation purposes.
    cout << "Logged in successfully." << endl << endl << "Welcome to RMS, -Insert UserName Here-!";
    Sleep(1200);
    managerMainMenu();
    }

void employeeMainMenu()
    {
    system("CLS");
    int scheduleOrCashier = 0;
    cout << "Enter 1 to access the cashier menu, or enter 2 to view scheduling options." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> scheduleOrCashier;
    switch(scheduleOrCashier)
        {
        case 1: cashierMenu();
        break;
        case 2: scheduleMenu();
        break;
        case 9: intro();
        break;
        default: errorMessages(1);
        break;
        }
    }

void managerMainMenu()
    {
    system("CLS");

    }

void scheduleMenu()
    {
    //schedule menu must be here
    }

void displaySchedule()
    {
    //display schedule
    }

void cashierMenu()
    {
    system("CLS");
    int addThisItem = 0;
    //Cashier Menu - alot of work to do here
    cout << "Enter the corresponding number to add an item to the current total purchase." << endl << endl;
    displayCurrentFoodMenu();
    cin >> addThisItem;
    cout << endl << endl;
    //needs running sum that is always displayed with every new addition
    //needs option to void item with proper manager username and password
    cout << "Subtotal: DISPLAY SUBTOTAL HERE" << endl << endl;
    cout << "Items on order: DISPLAY CURRENTLY SELECTED PURCHASES HERE" << endl << endl;
    //make a while loop that goes as long as the user chooses to add more items to the order.
    // needs to encapsulate entire function, pretty much
    //while (userChoice != -done-)
    //  {
    //  enter another order
    //  add to subtotal
    //  ask if user wants another order
    //  change exit variable and exit loop if they don't
    //  keep loop going if not
    //  makeTransaction();
    //  }
    makeTransaction();
    }

void makeTransaction()
    {
    system("CLS");
    float cashAmount = 0.0;
    cout << "Subtotal is: -subtotal here-" << endl << endl;
    cout << "Enter cash given: ";
    cin >> cashAmount;
    cout << endl << endl << "Change owed to customer: -change amount here-" << endl << endl;
    cashierMenu();
    }

void displayCurrentFoodMenu()
    {
    //show the food menu that the user has compiled, next to a number for the user to specify. I guess it's a text file?
    cout << "FOOD MENU GRAPHIC HERE" << endl << endl;
    }


int main()
    {
    intro();
    return 0;
    }
