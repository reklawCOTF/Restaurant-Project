//Trevor Walker
//Error Messages

#ifndef ERRORMESSAGES_H


using namespace std;

void errorMessages(int messageNum);

void errorMessages(int messageNum)
    {
    switch (messageNum)
        {
    case 1: cout << "Invalid entry. Please try again." << endl;
        break;
    case 2: cout << "You do not have the necessary permissions to execute that command. Please try again." << endl;
        break;
    case 3: cout << "ERRORMESSAGE" << endl;
        break;
    case 4: cout << "ERRORMESSAGE" << endl;
        break;
    default: cout << "Unknown error has occured. Please try again." << endl;
        break;
        }
    }




#endif // ERRORMESSAGES_H
