#include "Library.hpp"

Library::Library()
{
    //ctor
}

Library::Library(string l)
    {
        int i = 0;
        string location;
        libraryname = l;
        location = libraryname;

        ifstream inf(location);
        while(getline(inf, s[i], '\n'))
        {
            i++;
        }
        index = i;
        inf.close();
    }

Library::~Library()
{
    //dtor
}
