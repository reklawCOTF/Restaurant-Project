#ifndef SCHEDULING_H
#define SCHEDULING_H
#include <string>
#include <iostream>
#include "filehandling.h"
class schedule
{
public:///these require a username
    void newschedule();
    void newschedule(std::string);
    void addworkday();
    void addworkday(std::string, std::string);
    void clrschedule();
    void clrschedule(std::string);
    void viewschedule();
    void viewschedule(std::string);
    void delschedule();
    void delschedule(std::string);
    std::string returnschedule(std::string);
private:
    filemng sch;
    std::string workload(std::string);
};
#endif // SCHEDULING_H
