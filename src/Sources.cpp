#include "Sources.hpp"
#include "Library.hpp"

English::English() : Library("English.txt") {}

string* English:: getString()
{
    return s;
}

int English:: getIndex()
{
    return index;
}



Bangla::Bangla() : Library("Bangla.txt") {}

string* Bangla:: getString()
{
    return s;
}

int Bangla:: getIndex()
{
    return index;
}



Hindi::Hindi() : Library("Hindi.txt") {}

string* Hindi:: getString()
{
    return s;
}

int Hindi:: getIndex()
{
    return index;
}



Japanese::Japanese() : Library("Japanese.txt") {}

string* Japanese:: getString()
{
    return s;
}

int Japanese:: getIndex()
{
    return index;
}



Others::Others() : Library("Others.txt") {}

string* Others:: getString()
{
    return s;
}

int Others:: getIndex()
{
    return index;
}



languageSeq::languageSeq(string t) : Library(t) {}

string* languageSeq:: getString()
{
    return s;
}

int languageSeq:: getIndex()
{
    return index;
}

