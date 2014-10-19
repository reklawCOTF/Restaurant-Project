//Trevor Walker, Tyler Thaxton
//10/8/14
//CS240, Bowe
//Group Project work

#include<windows.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>

#include "ClockTest.h"
#include "ErrorMessages.h"
#include "FileHandling.h"
#include "FileHandling.cpp"

using namespace std;

void intro();
void loginCheck();
void clockMenu();
void clockInEmployee();
void clockOutEmployee();
void addNewEmployee();
void addEmployee();
void addManager();
void employeeMenu();
void employeeLogin();
void managerLogin();
void employeeMainMenu();
void managerMainMenu();
void scheduleMenu();
void displaySchedule();
void cashierMenu();
void addMenuItem();
void displayCurrentFoodMenu();
void makeTransaction();
void inventoryControl();
void foodMenuControl();
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
                 intro();
        break;
        }
    }

void loginCheck()
    {
    system("CLS");
    //checks whether an employee is manager or standard, checks permissions, then opens either employee menu or manager menu
    //for now, it is set to choose 1 or 2 for testing purposes
    int employeeType = 0;
    cout << "Login to system as Employee, or Manager? Enter 1 for employee, 2 for manager." << endl << endl << "You can also enter 3 to clock in or out." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
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
        default: errorMessages(1); loginCheck();
        break;

        }

    }

void clockMenu()
    {
    system("CLS");
    int clockType = 0;
    cout << "Would you like to clock in or clock out?" << endl << endl << "Enter 1 to clock in, or 2 to clock out." << endl << endl;
    cin >> clockType;
    switch (clockType)
        {
        case 1: clockInEmployee();
        break;
        case 2: clockOutEmployee();
        break;
        case 9: employeeMainMenu();
        break;
        default: errorMessages(1); clockMenu();
        break;
        loginCheck();
        }

    }

void clockInEmployee()
    {
    system("CLS");
    string username = "";
    cout << "Clock In" << endl;
    cout << "Enter Username: ";
    cin >> username;
    string fileName = "Payroll/" + username + ".CLK";
    time_t timeIn = time(NULL);
    char mbstr[100];
    if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeIn)))
    {
        cout << mbstr << endl;;
    }
    string clockTimeIn = mbstr;
    filemng fileClock;
    fileClock.appin(fileName, "Clocked In");
    fileClock.appin(fileName, clockTimeIn);
    cout << username << ", you have successfully clocked in." << endl;
    loginCheck();
    }

void clockOutEmployee()
    {
    system("CLS");
    string username = "";
    cout << "Clock Out" << endl;
    cout << "Enter Username: ";
    cin >> username;
    string fileName ="Payroll/" + username + ".CLK";
    time_t timeOut = time(NULL);
    char mbstr[100];
    if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeOut)))
    {
        cout << mbstr << endl;;
    }
    string clockTimeOut = mbstr;
    filemng fileClock;
    fileClock.appin(fileName, "Clocked Out");
    fileClock.appin(fileName, clockTimeOut);
    loginCheck();
    }


void addNewEmployee()
    {
    system("CLS");
    int whichType = 0;
    cout << "Would you like to add a new standard employee to the system, or a new manager?" << endl << endl << "Enter 1 to add an employee, or enter 2 to add a manager." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> whichType;
    switch (whichType)
        {
        case 1: addEmployee();
        break;
        case 2: addManager();
        break;
        case 9: intro();
        break;
        default: errorMessages(1); addNewEmployee();
        break;
        }
    }

void addEmployee()
    {
    system("CLS");
    string username = "";
    string password = "";
    cout << "Enter Username: ";
    cin >> username;
    cout << endl << "Enter Password: ";
    cin >> password;
    string fileName = "Employees/" + username + ".EMP";
    filemng EmployeeFile;
    EmployeeFile.newfile(fileName, username, password);
    system("CLS");
    cout << endl << endl << "Employee added." << endl;
    Sleep(1400);
    intro();
    }

void addManager()
    {
    system("CLS");
    string username = "";
    string password = "";
    cout << "Enter Username: ";
    cin >> username;
    cout << endl << "Enter Password: ";
    cin >> password;
    string fileName = "Managers/" + username + ".MAN";
    filemng EmployeeFile;
    EmployeeFile.newfile(fileName, username, password);
    system("CLS");
    cout << "Manager added." << endl;
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
    cout << endl << "Enter Password: ";
    cin >> passWord;
    string fileName = "Employees/" + userName + ".EMP";
    filemng employeeInfo;
    string actualPassWord = employeeInfo.extractline(fileName,2);
    if (passWord == actualPassWord)
        {
        system("CLS");
        cout << "Logged in successfully." << endl << endl << "Welcome to RMS, " << userName << ".";
        Sleep(1500);
        employeeMainMenu();
        }
    else
        {
        system("CLS");
        cout << "Login failed. Please try again, " << userName << ".";
        Sleep(1500);
        loginCheck();
        }
    Sleep(1200);
    }

void managerLogin()
    {
    system("CLS");
    string userName = "";
    string passWord = "";
    cout << "Enter UserName: ";
    cin >> userName;
    cout << endl << "Enter Password: ";
    cin >> passWord;
    string fileName = "Managers/" + userName + ".MAN";
    filemng managerInfo;
    string actualPassWord = managerInfo.extractline(fileName,2);
    if (passWord == actualPassWord)
        {
        system("CLS");
        cout << "Logged in successfully." << endl << endl << "Welcome to RMS, " << userName << ".";
        Sleep(1500);
        managerMainMenu();
        }
    else
        {
        system("CLS");
        cout << "Login failed. Please try again, " << userName << ".";
        Sleep(1500);
        loginCheck();
        }
    cout << endl;

    Sleep(1200);
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
        default: errorMessages(1); Sleep(1300); employeeMainMenu();
        break;
        }
    }

void managerMainMenu()
    {
    system("CLS");
    int scheduleOrCashier = 0;
    cout << "Enter 1 to access the cashier menu, enter 2 to view scheduling options, " << endl << endl << "Enter 3 to access inventory controls, or enter 4 to access food menu controls." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> scheduleOrCashier;
    switch (scheduleOrCashier)
        {
        case 1: cashierMenu();
        break;
        case 2: scheduleMenu();
        break;
        case 3: inventoryControl();
        break;
        case 4: foodMenuControl();
        break;
        case 9: intro();
        break;
        default: errorMessages(1); Sleep(1300); managerMainMenu();
        break;
        }
    }

void scheduleMenu()
    {
    cout << "Error. Returning to previous menu....";
    Sleep(1500);
    }

void displaySchedule()
    {
    intro();
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

void inventoryControl()
    {
    //inventory stuffs
    }

void makeTransaction()
    {
    system("CLS");
    float cashGiven = 0.0;
    float totalPrice = 0.0;
    float changeToGive = 0.0;
    cout << "Subtotal is: -subtotal here-" << endl << endl;
    cout << "Enter cash given: ";
    cin >> cashGiven;
    changeToGive = cashGiven - totalPrice;

    cout << endl << endl << "Change owed to customer: " << changeToGive << endl << endl;
    Sleep(2500);

    cashierMenu();
    }

void addMenuItem()
    {
    system("CLS");
    string itemName = "";
    cout << "This utility is used to add new items to the restaurant's menu." << endl << endl << "Enter Item Name: ";
    cin >> itemName;
    string fileName = "Menu/" + itemName + ".MNU";
    filemng menuFile;
    menuFile.appin("Menu/MasterMenu.MNU", itemName);
    menuFile.newfile(fileName, "");

    cout << endl << endl << "Please enter the ingredients the menu item contains, one at a time, with no spaces in the item name." << endl << endl << "Enter 'stop' after all ingredients have been added. Remember not to use spaces in any of your entries, please." << endl << endl;
    while (1)
    {
        string ingredient = "";
        string amount = "";
        cout<< "Enter Ingredient: ";
        cin >> ingredient;
        if (ingredient == "stop" || ingredient == "'stop'")
        {
            foodMenuControl();
        }
        cout << endl << "Enter Amount: ";
        cin >> amount;
        cout << endl << endl;
        menuFile.appin(fileName, ingredient);
        menuFile.appin(fileName, amount);
    }

    }

void foodMenuControl()
    {
    system("CLS");
    int controlMenu = 0;
    cout << "Enter 1 to display the current menu, or enter 2 to add an item to the menu." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> controlMenu;
    switch (controlMenu)
        {
        case 1: displayCurrentFoodMenu();
        break;
        case 2: addMenuItem();
        break;
        default: managerMainMenu();
        }
    }

void displayCurrentFoodMenu()
    {
    system("CLS");
    filemng MenuFile;
    int itemNumber = 1;
    cout << "Current Menu" << endl;
    while (1)
    {
        string item = MenuFile.extractline("Menu/MasterMenu.MNU",itemNumber);
        if (item == "")
        {
            break;
        }
        ostringstream convert;
        convert << itemNumber;
        string itemNumberString = convert.str();
        item = itemNumberString + "-" + item;
        cout << item << endl;
        itemNumber ++;
    }
    Sleep(1300);
    cin >> itemNumber;
    foodMenuControl();
    }


int main()
    {
    intro();
    return 0;
    }
