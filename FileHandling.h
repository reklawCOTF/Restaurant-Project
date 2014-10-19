
#define FILEHANDLING_H
#include <string>
#include <iostream>
#include <fstream>
//using namespace t
class filemng
{
    public:
    filemng();
    ~filemng();
    void defaultnewfile();///uber default for the creation of a new file
    void newfile();///asks user for input information
    void newfile(std::string);///creates an empty file with a specified name
    void newfile(std::string, std::string);///creates a file with one line in it
    void newfile(std::string, std::string, std::string);///creates a file with two lines
    void newfile(std::string, std::string, std::string, std::string);///creates a file with three lines
    void clrfile();///needs user input clears the file of all data
    void clrfile(std::string);///clears file of all data
    void delfile();///delets a user specified file
    void delfile(std::string);///deletes a passes file
    void repline();///replaces a line needs users input
    void repline(std::string,std::string, int);/// replaces a line in a file
    void appin();///needs user input adds new info at th end of the file
    void appin(std::string, std::string); /// new data at the end of the file
    std::string filetostrlst();///returns the entire file as a string needs user input
    std::string filetostrlst(std::string);///returns the entire file as a string
    std::string extractline();///returns a line from the file user specified
    std::string extractline(std::string, int);///returns a line from the file
    std::string extractmultilines();///returns a set of lines needs user input
    std::string extractmultilines(std::string, int, int);///returns a set of lines
    int filesize();///returns the size of the file needs user input
    int filesize(std::string);///returns the size of the file
    private:
};

#endif // FILEHANDLING_H
