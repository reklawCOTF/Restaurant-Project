#include <ctime>
#include <iostream>

using namespace std;

class TimeClock
{
public:

    TimeClock()
    {

    }
    void clockIn()
    {
        time_t timeIn = time(NULL); // http://en.cppreference.com/w/cpp/chrono/c/strftime02
        intTimeIn = timeIn;
        char mbstr[100];
        if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeIn)))
        {
            cout << mbstr << endl;;
        }

    }

    void clockOut()
    {
        time_t timeOut = time(NULL); // http://en.cppreference.com/w/cpp/chrono/c/strftime02
        intTimeOut = timeOut;
        char mbstr[100];
        if (strftime(mbstr, sizeof(mbstr), "%A %c", localtime(&timeOut)))
        {
            cout << mbstr << endl;
        }
        timeWorked = intTimeOut - intTimeIn;
        cout << timeWorked << endl;


    }


private:
time_t timeIn;
int intTimeIn;
time_t timeOut;
int intTimeOut;
int timeWorked;

};
int main()
{
    int pause;
    TimeClock Test;
    Test.clockIn();
    cin >> pause;
    Test.clockOut();

}
