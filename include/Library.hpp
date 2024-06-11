#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include <iostream>
#include <fstream>
using namespace std;


class Library
{
protected:
    string s[50], libraryname;
    int index;
public:
    Library();
    Library(string l);
    virtual string* getString() = 0;
    virtual int getIndex() = 0;
    ~Library();
};

#endif // LIBRARY_HPP
