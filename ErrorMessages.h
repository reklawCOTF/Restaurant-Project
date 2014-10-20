//Trevor Walker
//Error Messages

#ifndef ERRORMESSAGES_H
#define ERRORMESSAGES_H
#include <iostream>
using namespace std;

void errorMessages(int messageNum);

void errorMessages(int messageNum)
    {
    switch (messageNum)
        {
    case 1: std::cout << "Invalid entry. Please try again." << std::endl;
        break;
    case 2: std::cout << "You do not have the necessary permissions to execute that command. Please try again." << std::endl;
        break;
    case 3: std::cout << "ERRORMESSAGE" << std::endl;
        break;
    case 4: std::cout << "ERRORMESSAGE" << std::endl;
        break;
    default: std::cout << "Unknown error has occured. Please try again." << std::endl;
        break;
        }
    }
#endif // ERRORMESSAGES_H
