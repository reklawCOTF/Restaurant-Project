#ifndef SCHEDULING_H
#define SCHEDULING_H
#include <string>
#include <iostream>
#include "filehandling.h"
class schedule
{
public:///these require a username
    void newschedule(std::string);
    void addworkday(std::string, std::string);
    void clrschedule(std::string);
    void viewschedule(std::string);
    void delschedule(std::string);
    std::string returnschedule(std::string);
private:
    filemng sch;
    std::string workload(std::string);
};
#endif // SCHEDULING_H
