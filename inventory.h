#ifndef INVENTORY_H
#define INVENTORY_H
#include "filehandling.h"
class inventory
{
public:
    void newinvitem(std::string, std::string);
    std::string returnvalue(std::string);
    void subvalue(std::string,int);
    void addvalue(std::string, int);
    void changevalue(std::string, std::string);
    void delitem(std::string);
    void showinv();
private:
    filemng invent;
};
#endif // INVENTORY_H
