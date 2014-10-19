#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include<string>
class crypto
{
   public:
    std::string encrypt();
    std::string encrypt(std::string);
    std::string encrypt(std::string, int);
    std::string decrypt();
    std::string decrypt(std::string);
    std::string decrypt(std::string, int);
    private:
};
#endif // ENCRYPTION_H
