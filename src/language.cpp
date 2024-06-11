#include "language.hpp"

language::language()
{
    //ctor
}
void language::selectlanguage()

{
    switch(l_choice)
    {
    case 1:
    {
        l = "English";
        break;
    }
    case 2:
    {
        l = "Bangla";
        break;
    }
    case 3:
    {
        l = "Hindi";
        break;
    }
    case 4:
    {
        l = "Japanese";
        break;
    }
    case 5:
    {
        l = "Others";
        break;
    }
    default:
    {
        exit(0);
    }
    }
}

language::~language()
{
    //dtor
}
