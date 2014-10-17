#include "filehandling.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
   filemng we;
std::string wer;
   we.newfile("hi.txt");
   we.newfile("hw.txt","hi");
   we.newfile("hq.txt","hi", "duck","potato");
   we.repline("hq.txt","ok",1);
   we.appin("hq.txt","okqwerty");
   wer=we.filetostrlst("hq.txt");
   std::cout<<wer;
    wer=we.extractline("hq.txt", 3);
   std::cout<<wer<<std::endl;
}
