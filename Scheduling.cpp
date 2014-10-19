#include "Scheduling.h"
#include <string>
#include <iostream>
#include "filehandling.h"
    void schedule::newschedule(std::string username){
      std::string temp;
      temp=workload(username);
      sch.newfile(temp);
    }
    void schedule::addworkday(std::string username, std::string work){///second one is for work day
        std::string temp;
        temp=workload(username);
        sch.appin(temp, work);
    }
    void schedule::clrschedule(std::string username){
        std::string temp;
        temp=workload(username);
        sch.clrfile(temp);
    }
    void schedule::viewschedule(std::string username){
        std::string temp;
        std::string holdingvalue;
        temp=workload(username);
        holdingvalue=sch.filetostrlst(temp);
        std::cout<<username<<"will work"<<std::endl<<holdingvalue;
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

