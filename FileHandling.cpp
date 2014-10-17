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
    std::string inname;
    std::ofstream newfil;
    std::string temp;
    std::cout<<"What do you want to name your file?\n(include file extention)"<<std::endl;
    std::cin>>inname;
    temp=" ";
    newfil.open(inname.c_str());
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
    newfilr.open(inname.c_str());
    newfilr<<lineone;
    newfilr.close();
}
void filemng::newfile(std::string inname, std::string lineone, std::string linetwo){//adds two lines
    std::ofstream newfil;
    newfil.open(inname.c_str());
    newfil<<lineone;
    newfil<<std::endl;
    newfil<<linetwo;
    newfil.close();
}
void filemng::newfile(std::string inname, std::string lineone, std::string linetwo, std::string linethree){ //adds three lines
    std::ofstream newfil;
    newfil.open(inname.c_str());
    newfil<<lineone;
    newfil<<std::endl;
    newfil<<linetwo;
    newfil<<std::endl;
    newfil<<linethree;
    newfil.close();
}
void filemng::clrfile(){ //clears     a user inputed file
    std::ofstream file;
    std::string infile;
    std::cout<<"what is the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    file.open(infile.c_str());
    file<<" ";
    file.close();
}
void filemng::clrfile(std::string infile){
    std::ofstream file;
    file.open(infile.c_str());
    file<<" ";
    file.close();
}
void filemng::delfile(){ //deletes a user inputed file
     std::ofstream file;
    std::string infile;
    std::cout<<"what is the name of the file to be deleted?\n(include the file extension)\n";
    std::cin>>infile;
    file.open(infile.c_str());
    file.close();
    remove(infile.c_str());
}
void filemng::delfile(std::string infile){ //deletes a user defined file
    std::ofstream file;
    file.open(infile.c_str());
    file.close();
    remove(infile.c_str());
}
void filemng::repline(){
    std::ifstream outfile;
    std::ofstream inputfile;
    std::vector<std::string> hold;
    std::string temp;
    std::string tempstring;
    std::string replacement;
    std::string infile;
    int line;
    std::cout<<"what is the name of the file"<<std::endl<<"(include the file extension)";
    std::cin>>infile;
    std::cout<<"which line do you want to replace?"<<std::endl;
    std::cin>>line;
    std::cout<<"what do you want to put in the line"<<std::endl;
    std::cin>>replacement;
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
    std::cout<<"what is the name the file?\n(include the file extension)\n";
    std::cin>>infile;
    std::cout<<"what do you want to add at the end of the file"<<std::endl;
    std::cin>>input;
    file.open(infile.c_str(), std::ofstream::app);
    file<<input<<std::endl;
    file.close();
}
void filemng::appin(std::string infile, std::string input){
    std::ofstream file;
    file.open(infile.c_str(), std::ofstream::app);
    file<<input<<std::endl;
    file.close();
}
std::string filemng::filetostrlst(){
    std::ifstream file;
    std::string temp;
    std::string result;
    std::string infile;
    result="";
    std::cout<<"what is the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    file.open(infile.c_str());
    while(getline(file, temp)){
        result.append(temp);
        result.append("\n");
    }
    file.close();
    return result;
}
std::string filemng::filetostrlst(std::string infile){
    std::ifstream file;
    std::string temp;
    std::string result;
    result="";
    file.open(infile.c_str());
    while(getline(file, temp)){
        result.append(temp);
        result.append("\n");
    }
    file.close();
    return result;
}
std::string filemng::extractline(){
    std::ifstream file;
    std::string temp;
    std::string result;
    std::string infile;
    int line;
    int x;
    x=0;
    result="";
    std::cout<<"what is the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    std::cout<<"Which line do you want to extract?\n(use numerical value)"<<std::endl;
    std::cin>>line;
    file.open(infile.c_str());
    while(getline(file, temp)){
        x++;
        if (x==line){
        result=temp;
        }
        else{
        }
    }
    file.close();
    return result;
}
std::string filemng::extractline(std::string infile, int line){
    std::ifstream file;
    std::string temp;
    std::string result;
    int x;
    x=0;
    result="";
    file.open(infile.c_str());
    while(getline(file, temp)){
        x++;
        if (x==line){
        result=temp;
        }
        else{

        }

    }
    file.close();
    return result;
}
std::string filemng::extractmultilines(){
    std::ifstream file;
    std::string temp;
    std::string result;
    std::string infile;
    int startline;
    int endline;
    int x;
    x=0;
    result="";
    std::cout<<"what is the name of the file?\n(include the file extension)\n";
    std::cin>>infile;
    std::cout<<"Which line do you want to start extracting from?\n(use numerical value)"<<std::endl;
    std::cin>>startline;
    std::cout<<"Which line do you want to end extracting from?\n(use numerical value)"<<std::endl;
    std::cin>>endline;
    file.open(infile.c_str());
    while(getline(file, temp)){
        x++;
        if (x>=startline && x<=endline){
        result.append(temp);
        result.append("\n");
        }
        else{
        }
    }
    file.close();
    return result;
}
std::string filemng::extractmultilines(std::string infile, int startline, int endline){
    std::ifstream file;
    std::string temp;
    std::string result;
    int x;
    x=0;
    result="";
    file.open(infile.c_str());
    while(getline(file, temp)){
        x++;
        if (x>=startline && x<=endline){
        result.append(temp);
        result.append("\n");
        }
        else{
        }
    }
    file.close();
    return result;
}


