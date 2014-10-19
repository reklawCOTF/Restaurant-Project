#include "inventory.h"
#include "filehandling.h"
#include <string>
#include <sstream>
#include <iostream>

void inventory::newinvitem(std::string item, std::string number){
        std::string temp;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        invent.appin("invdata/invtorylst.inv", item);
        invent.newfile(temp, item, number);
    }
std::string inventory::returnvalue(std::string item){
        std::string temp;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        return invent.extractline(temp, 2);
    }
void inventory::subvalue(std::string item, int subber){
        std::string temp;
        std::string number;
        std::string result;
        int num;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        number=invent.extractline(temp, 2);
        std::istringstream convert(number);
        convert>>num;
        num=num-subber;
        std::ostringstream switchcon;
        switchcon<<num;
        result=switchcon.str();
        invent.repline(temp,result,2);

}
void inventory::addvalue(std::string item, int adder){
        std::string temp;
        std::string number;
        std::string result;
        int num;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        number=invent.extractline(temp, 2);
        std::istringstream convert(number);
        convert>>num;
        num=num-adder;
        std::ostringstream switchcon;
        switchcon<<num;
        result=switchcon.str();
        invent.repline(temp,result,2);

}
void inventory::changevalue(std::string item, std::string number){
        std::string temp;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        return invent.repline(temp, number, 2);
}
void inventory::delitem(std::string item){
        std::string temp;
        temp= "invdata/";
        temp=temp+item;
        temp=temp+".inv";
        return invent.delfile(temp);
}
void inventory::showinv(){
    int invsize;
    int x;
    std::string temp;
    std::string file;
    std::string hold;
    x=0;
    invsize=invent.filesize("invdata/invtorylst.inv");
    for (x=0; x<=invsize; x++){
        file="invdata/";
        temp=invent.extractline("invdata/invtorylst.inv",x);
        file=file+temp;
        file=file+".inv";
        hold.append(invent.extractline(file, 1));
        hold.append("  : ");
        hold.append(invent.extractline(file, 2));
        hold.append(" | ");
        if (x%3==0){
            hold.append("\n");
        }
        else{}
    }
    std::cout<<hold<<std::endl;
}



