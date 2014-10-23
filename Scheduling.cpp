#include "Scheduling.h"
#include <string>
#include <iostream>
#include "filehandling.h"
    void schedule::newschedule(){
    std::string inname;
    std::cout<<"What is the name of the user whose schedule you are creating?"<<std::endl;
    std::cin>>inname;
    return schedule::newschedule(inname);
    }
    void schedule::newschedule(std::string username){
      std::string temp;
      temp=workload(username);
      sch.newfile(temp);
    }
    void schedule::addworkday(){
    std::string inname;
    std::string workday;
    std::cout<<"What is the name of the user whose schedule you are editing?"<<std::endl;
    std::cin>>inname;
    std::cout<<"what day will they be working?"<<std::endl;
    std::cin>>workday;
    return schedule::addworkday(inname,workday);
    }
    void schedule::addworkday(std::string username, std::string work){///second one is for work day
        std::string temp;
        temp=workload(username);
        sch.appin(temp, work);
    }
    void schedule::clrschedule(){
    std::string inname;
    std::cout<<"What is the name of the user whose schedule you are clearing?"<<std::endl;
    std::cin>>inname;
    return schedule::clrschedule(inname);
    }
    void schedule::clrschedule(std::string username){
        std::string temp;
        temp=workload(username);
        sch.clrfile(temp);
    }
    void schedule::viewschedule(){
    std::string inname;
    std::cout<<"What is the name of the user whose schedule you want to view?"<<std::endl;
    std::cin>>inname;
    return schedule::viewschedule(inname);
    }
    void schedule::viewschedule(std::string username){
        std::string temp;
        std::string holdingvalue;
        temp=workload(username);
        holdingvalue=sch.filetostrlst(temp);
        std::cout<<username<<"will work"<<std::endl<<holdingvalue;
    }
    void schedule::delschedule(){
    std::string inname;
    std::cout<<"What is the name of the user whose schedule you are deleting?"<<std::endl;
    std::cin>>inname;
    return schedule::delschedule(inname);
    }
    void schedule::delschedule(std::string username){
        std::string temp;
        temp=workload(username);
        sch.delfile(temp);
    }
    std::string schedule::workload(std::string username){
        std::string temp;
        temp="schedules/";
        temp=temp+username;
        temp=temp+".sch";
        return temp;
    }
    std::string schedule::returnschedule(std::string username){
        std::string temp;
        std::string holdingvalue;
        temp=workload(username);
        holdingvalue=sch.filetostrlst(temp);
        return holdingvalue;
    }
