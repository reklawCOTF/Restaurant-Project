
#include "filehandling.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
//using namespace std;
filemng::filemng(){}
filemng::~filemng(){}
void filemng::defaultnewfile(){ //creates a generic .txt file
    std::ofstream newfil;
    std::string temp;
    temp=" ";
    newfil.open("file.txt");
    newfil<<temp;
    newfil.close();
}
void filemng::newfile(){ //asks user for the file name to create
    std::ofstream newfil;
    std::string temp;
    std::string infile;
    temp=" ";
    std::cout<<"what do you want to name the file?\n(include the file extension)\n";
    std::cin>>infile;
    newfil.open(infile.c_str());
    newfil<<temp;
    newfil.close();
}
void filemng::newfile(std::string inname){ //creates an empty file with user inputed name and extension
    std::ofstream newfil;
    std::string temp;
    temp=" ";
    newfil.open(inname.c_str());
    newfil<<temp;
    newfil.close();
}
void filemng::newfile(std::string inname, std::string lineone){ //adds a line

    std::ofstream newfilr;
    std::string temp;
    temp=" ";
    newfilr.open(inname.c_str());
    newfilr<<temp;
    newfilr<<lineone;
    newfilr.close();
}
void filemng::newfile(std::string inname, std::string lineone, std::string linetwo){//adds two lines
    std::ofstream newfil;
    std::string temp;
    newfil.open(inname.c_str());
    newfil<<lineone;
    newfil<<std::endl;
    newfil<<linetwo;
    newfil.close();
}
void filemng::newfile(std::string inname, std::string lineone, std::string linetwo, std::string linethree){ //adds three lines
    std::ofstream newfil;
    std::string temp;
    newfil.open(inname.c_str());
    newfil<<lineone;
    newfil<<std::endl;
    newfil<<linetwo;
    newfil<<std::endl;
    newfil<<linethree;
    newfil.close();
}
void filemng::editfile(){
    std::ofstream edtfile;
    std::string infile;
    std::string temp;
    bool test;
    char choice;
    test=true;
    std::cout<<"what id the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    edtfile.open(infile.c_str());
    while(test==true){
        std::cout<<"type in the next line"<<std::endl;
        std::cin>>temp;
        edtfile<<temp;
        std::cout<<"do you want to add a new line? y/n";
        std::cin>>choice;
        if (choice=='y'){}
        else{test=false;}
    }
    edtfile.close();
}
void filemng::clrfile(){ //clears     a user inputed file
    std::ofstream file;
    std::string temp;
    std::string infile;
    temp=" ";
    std::cout<<"what is the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    file.open(infile.c_str());
    file<<temp;
    file.close();
}
void filemng::clrfile(std::string infile){
    std::ofstream file;
    std::string temp;
    temp=" ";
    file.open(infile.c_str());
    file<<temp;
    file.close();
}
void filemng::delfile(){ //deletes a user inputed file
     std::ofstream file;
    std::string temp;
    std::string infile;
    std::cout<<"what is the name of the file to be deleted?\n(include the file extension)\n";
    std::cin>>infile;
    file.open(infile.c_str());
    file.close();
    remove(infile.c_str());
}
void filemng::delfile(std::string infile){ //deletes a user defined file
    std::ofstream file;
    std::string temp;
    file.open(infile.c_str());
    file.close();
    remove(infile.c_str());
}
void filemng::repline(std::string infile, std::string replacement, int line){
    std::ifstream outfile;
    std::ofstream inputfile;
    std::vector<std::string> hold;
    std::string temp;
    std::string tempstring;
    bool endpoint;
    endpoint=true;
    int x;
    x=0;
    outfile.open(infile.c_str());
    while(getline(outfile, temp)){
    x++;
    if (x==line){
       hold.push_back(replacement);
       endpoint=false;
    }
    else
    {
    hold.push_back(temp);
    }
    }
    if (endpoint==true){
        hold.push_back(replacement);
    }
    outfile.close();
    inputfile.open(infile.c_str());
    x=0;
    for (x=0; x<hold.size(); x++){
        tempstring=hold.at(x);
        inputfile<<tempstring<<"\n";
    }
    inputfile.close();
}
void filemng::appin(){
    std::ofstream file;
    std::string input;
    std::string infile;
    std::cout<<"what do you want to name the file?\n(include the file extension)\n";
    std::cin>>infile;
    std::cout<<"what do you want to add at the end of the file"<<std::endl;
    std::cin>>input;
    file.open(infile.c_str(), std::ofstream::app);
    file<<input;
    file.close();
}
void filemng::appin(std::string infile, std::string input){
    std::ofstream file;
    file.open(infile.c_str(), std::ofstream::app);
    file<<input;
    file.close();
}

