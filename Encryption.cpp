#include "Encryption.h"
#include <iostream>
#include <string>
std::string crypto::encrypt(){
std::string input;
std::cout<<"what do you want to encrypt?"<<std::endl;
std::cin>>input;
return crypto::encrypt(input);
}
std::string crypto::encrypt(std::string input){
    int convert;
    convert=25;
    return crypto::encrypt(input, convert);
}
std::string crypto::encrypt(std::string input, int convert){
    int x;
    int lines;
    char tempe;
    std::string temp;
    std::string result;
    x=0;
    lines=input.size();
    for(x=0; x<lines; x++){
        tempe=input.at(x);
        tempe=tempe+convert;
        temp=tempe;
        result.append(temp);
    }
    return result;

}
std::string crypto::decrypt(){
std::string input;
std::cout<<"what do you want to decrypt?"<<std::endl;
std::cin>>input;
return crypto::decrypt(input);
}
std::string crypto::decrypt(std::string input){
    int convert;
    convert=25;
    return crypto::decrypt(input,convert);
}
std::string crypto::decrypt(std::string input, int convert){
    int x;
    int lines;
    char tempe;
    std::string temp;
    std::string result;
    x=0;
    lines=input.size();
    for(x=0; x<lines; x++){
        tempe=input.at(x);
        tempe=tempe-convert;
        temp=tempe;
        result.append(temp);
        temp=" ";
    }
    return result;
}
