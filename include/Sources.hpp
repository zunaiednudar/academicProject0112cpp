#ifndef SOURCES_HPP
#define SOURCES_HPP
#include "Library.hpp"


class English : virtual public Library
{
public:
    English();
    string* getString();
    int getIndex();
};

class Bangla : virtual public Library
{
public:
    Bangla();
    string* getString();
    int getIndex();
};

class Hindi : virtual public Library
{
public:
    Hindi();
    string* getString();
    int getIndex();
};

class Japanese : virtual public Library
{
public:
    Japanese();
    string* getString();
    int getIndex();
};

class Others : virtual public Library
{
public:
    Others();
    string* getString();
    int getIndex();
};

class languageSeq : virtual public Library
{
public:
    languageSeq(string t);
    string* getString();
    int getIndex();
};

#endif // SOURCES_HPP
