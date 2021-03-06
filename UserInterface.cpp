//Trevor Walker, Tyler Thaxton
//10/8/14
//CS240, Bowe
//Group Project work

#include<windows.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>
#include <ctime>

#include "ErrorMessages.h"
#include "FileHandling.h"
#include "Scheduling.h"

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
    string passWord = "";
    cout << "Clock In" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << endl << "Enter Password: ";
    cin >> passWord;
    string fileNamePayroll = "Payroll/" + username + ".CLK";
    time_t timeIn = time(NULL);
    char mbstr[100];
    if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeIn)))
    {
        cout << mbstr << endl;
    }
    string clockTimeIn = mbstr;
    filemng fileClock;
    string fileNameEmployee = "Employees/" + username + ".EMP";
    string actualPassWord = fileClock.extractline(fileNameEmployee, 2);
    if (passWord == actualPassWord)
        {
        fileClock.appin(fileNamePayroll, "Clocked In");
        fileClock.appin(fileNamePayroll, clockTimeIn);
        cout << username << ", you have successfully clocked in.";
        Sleep(1500);
        loginCheck();
        }
    else
        {
            string fileNameManager = "Managers/" + username + ".MAN";
            string actualPassWord = fileClock.extractline(fileNameManager, 2);
        if (passWord == actualPassWord)
            {
            fileClock.appin(fileNamePayroll, "Clocked In");
            fileClock.appin(fileNamePayroll, clockTimeIn);
            cout << username << ", you have successfully clocked in.";
            Sleep(1500);
            loginCheck();
            }
        else
            {
            cout << "Clock In Failed. Please try again, " << username << ".";
            Sleep(1500);
            loginCheck();
            }
        }

    Sleep(1400);
    loginCheck();
    }

void clockOutEmployee()
    {
    system("CLS");
    string username = "";
    string passWord = "";
    cout << "Clock Out" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << endl << "Enter Password: ";
    cin >> passWord;
    string fileNamePayroll ="Payroll/" + username + ".CLK";
    time_t timeOut = time(NULL);
    char mbstr[100];
    if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeOut)))
    {
        cout << mbstr << endl;;
    }
    string clockTimeOut = mbstr;
        filemng fileClock;
    string fileNameEmployee = "Employees/" + username + ".EMP";
    string actualPassWord = fileClock.extractline(fileNameEmployee, 2);
    if (passWord == actualPassWord)
        {
        fileClock.appin(fileNamePayroll, "Clocked Out");
        fileClock.appin(fileNamePayroll, clockTimeOut);
        cout << username << ", you have successfully clocked out.";
        Sleep(1500);
        loginCheck();
        }
    else
        {
            string fileNameManager = "Managers/" + username + ".MAN";
            string actualPassWord = fileClock.extractline(fileNameManager, 2);
        if (passWord == actualPassWord)
            {
            fileClock.appin(fileNamePayroll, "Clocked Out");
            fileClock.appin(fileNamePayroll, clockTimeOut);
            cout << username << ", you have successfully clocked out.";
            Sleep(1500);
            loginCheck();
            }
        else
            {
            cout << "Clock Out Failed. Please try again, " << username << ".";
            Sleep(1500);
            loginCheck();
            }

        }

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
    Sleep(1200);
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
    int menuType = 0;
    cout << "Enter 1 to access the cashier menu, enter 2 to view scheduling options, " << endl << endl << "Enter 3 to access inventory controls, or enter 4 to access food menu controls." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> menuType;
    switch (menuType)
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
     int choice;
    schedule sch;
    cout<<"Enter 1 to create a new schedule"<<endl<<"Enter 2 to add a workday to a user"<<endl;
    cout<<"Enter 3 to clear a schedule"<<endl<<"Enter 4 to delete a schedule"<<"Enter 5 to view a schedule"<<endl;
    cin>>choice;
    switch (choice)
    {
        case 1:
        sch.newschedule();
        break;
        case 2:
        sch.addworkday();
        break;
        case 3:
        sch.clrschedule();
        break;
        case 4:
        sch.delschedule();
        break;
        case 5:
        sch.viewschedule();
        break;
        default:
        errorMessages(1);
    }
    managerMainMenu();
    }

void displaySchedule()
    {
    system("CLS");
    string userName = "";
    cout << "Enter your username to display current schedule." << endl << endl;
    cin >> userName;
    }

void cashierMenu()
    {
    system("CLS");
    int addThisItem = 0;
    float subTotal = 0.0;
    float temp = 0.0;
    float givenByCustomer = 0.0;
    float customerChange = 0.0;
    int ringComplete = 1;
    int leaveOrRepeat = 0;
    float getTax = 0.0;
    while (ringComplete == 1)
        {
        cout << "Current Subtotal: " << subTotal << endl << endl;
        displayCurrentFoodMenu();
        cout << endl << "Enter the corresponding number to add an item to the current total purchase: ";
        cin >> addThisItem;
        cout << endl << endl << "Enter item price: ";
        cin >> temp;
        subTotal = subTotal + temp;
        cout << endl << "New Subtotal: " << subTotal << endl << endl;
        cout << "Enter 1 to add another purchase to the current order, or enter 2 to complete transaction." << endl << endl;
        cin >> ringComplete;
        cout << endl << endl;
        temp = 0.0;
        system("CLS");
        }
    system("CLS");
    getTax = subTotal * 0.06;
    subTotal = subTotal + getTax;
    cout << "Post-tax Final Subtotal: " << subTotal << endl << endl;
    cout << "Enter cash amount given by customer: ";
    cin >> givenByCustomer;
    customerChange = givenByCustomer - subTotal;
    cout << endl << endl << "Change owed: " <<  customerChange;
    Sleep(1800);
    getTax = 0.0;
    subTotal = 0.0;

    cout << endl << endl << "Enter 1 to make another transaction, or enter any other number to return to the login menu: ";
    cin >> leaveOrRepeat;
    if (leaveOrRepeat == 1)
        {
        system("CLS");
        cashierMenu();
        }
    else
        {
        loginCheck();
        }
    }

void inventoryControl()
    {
    //inventory stuffs
    }



void addMenuItem()
    {
    system("CLS");
    string itemName = "";
    cout << "This utility is used to add new items to the restaurant's menu." << endl << endl << "Include no spaces in your entry name. Enter Item Name: ";
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
            cout << "Menu item added." << endl << endl;
            Sleep (1000);
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
    int menuReturn = 0;
    int controlMenu = 0;
    cout << "Enter 1 to display the current menu, or enter 2 to add an item to the menu." << endl << endl << "Remember, you can enter 9 on any menu to return to the main menu." << endl << endl;
    cin >> controlMenu;
    switch (controlMenu)
        {
        case 1: displayCurrentFoodMenu();
        cout << endl << endl << "Enter any number to return to the main menu." << endl;
        cin >> menuReturn;
        managerMainMenu();
        break;
        case 2: addMenuItem();
        break;
        default: managerMainMenu();
        }
    }

void displayCurrentFoodMenu()
    {
    filemng MenuFile;
    int itemNumber = 1;
    cout << endl << "Current Menu" << endl;
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
    }


int main()
    {
    intro();
    return 0;
    }
