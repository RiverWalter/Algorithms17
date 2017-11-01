#include <iostream>
#include <functional>
#include <string>

void TestHash()
{
    char nts1[] = "Test";
    char nts2[] = "Test";
    std::string str1(nts1);
    std::string str2(nts2);

    std::hash<char*> ptr_hash;
    std::hash<std::string> str_hash;

    std::cout << "same hashes:\n" << std::boolalpha;

    std::cout << "sizeof(size_t):\n" << sizeof(size_t) << std::endl;
    auto hh = str_hash(str1);
    std::cout << "str_hash(str1):\n" << hh << std::endl;
    std::cout << "nts1 and nts2: " << (ptr_hash(nts1) == ptr_hash(nts2)) << '\n';
    std::cout << "str1 and str2: " << (str_hash(str1) == str_hash(str2)) << '\n';

}