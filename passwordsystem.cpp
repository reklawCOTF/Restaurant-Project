#include "passwordsystem.h"
#include "filehandling.h"
#include "Encryption.h"
#include <iostream>
#include <fstream>
#include <string>
void loginsys::addnewemp(){
    std::string username;
    std::string password;
    std::cout<<"what is your name?"<<std::endl;
    std::cin>>username;
    std::cout<<"what is your password?"<<std::endl;
    std::cin>>password;
    return loginsys::addnewemp(username, password);
}
void loginsys::addnewemp(std::string username, std::string password){
    std::string temp;
    std::string propassword;
    temp="Users/";
    temp=temp+username;
    temp=temp+".emp";
    propassword=cryp.encrypt(password);
    filein.newfile(temp, username, propassword);
}
void loginsys::chngpassword(std::string username, std::string password){
    std::string temp;
    std::string propassword;
    temp="Users/";
    temp=temp+username;
    temp=temp+".emp";
    propassword=cryp.encrypt(password);
    filein.repline(temp, propassword, 2);
}
void loginsys::delusr(std::string username){
    std::string temp;
    temp="Users/";
    temp=temp+username;
    temp=temp+".emp";
    filein.delfile(temp);
}
bool loginsys::chkusrpasword(std::string username, std::string password){
    std::string temp;
    std::string passwordcheck;
    std::string hold;
    temp="Users/";
    temp=temp+username;
    temp=temp+".emp";
    hold=filein.extractline(temp, 2);
    passwordcheck=cryp.decrypt(hold);
    if(password==passwordcheck){
        return true;
    }
    else{
        return false;
    }
}




