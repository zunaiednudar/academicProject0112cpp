#ifndef LANGUAGE_HPP
#define LANGUAGE_HPP
#include <iostream>
using namespace std;


class language
{
protected:
    string l;
    int l_choice;
public:
    language();

    void selectlanguage();

    ~language();
};

#endif // LANGUAGE_HPP
