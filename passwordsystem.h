#ifndef PASSWORDSYSTEM_H
#define PASSWORDSYSTEM_H
#include <string>
#include "filehandling.h"
#include "Encryption.h"
class loginsys{
    public:
    bool chkusrpasword(std::string, std::string);
    void chngpassword(std::string, std::string);
    void addnewemp();
    void addnewemp(std::string, std::string);
    void delusr(std::string);
    private:
     filemng filein;
     crypto cryp;

};
#endif // PASSWORDSYSTEM_H
