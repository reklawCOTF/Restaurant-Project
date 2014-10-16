#ifndef FILEHANDLING_H
#define FILEHANDLING_H
#include <string>
#include <iostream>
#include <fstream>
//using namespace std;
class filemng
{
    public:
    filemng();
    ~filemng();
    void defaultnewfile();
    void newfile();
    void newfile(std::string);
    void newfile(std::string, std::string);
    void newfile(std::string, std::string, std::string);
    void newfile(std::string, std::string, std::string, std::string);
    void editfile();
    void editfile(std::string);
    void editfile(std::string, std::string, int);
    void editfile(std::string, std::string, int, std::string, int);
    void clrfile();
    void clrfile(std::string);
    void delfile();
    void delfile(std::string);
    void repline(std::string,std::string, int);
    void appin();
    void appin(std::string, std::string);
    std::string filetostr(std::string);
    std::string getfileinfo();

    private:
};

#endif // FILEHANDLING_H
