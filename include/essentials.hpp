#ifndef ESSENTIALS_HPP_INCLUDED
#define ESSENTIALS_HPP_INCLUDED
#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <conio.h>
#define TAB "\t\t\t\t\t\t\t\t\t\t\t"
#define WELCOME cout << "----------------------------------------------------------------------------------------------WELCOME USER-------------------------------------------------------------------------------------------------------" << endl;
#define LOGIN_SEQUENCE {system("cls");\
            WELCOME\
            cout << endl;\
            cout << TAB << " ENTER YOUR INFORMATION" << setw(98) << right << "'ENTER'  : CONTINUE" << endl;\
            cout << TAB << " ----------------------" << setw(98) << right << "'ESC'  : RESTART" << endl;}

using namespace std;

string operator+ (string a, int t)
{
    string b;
    b = to_string(t);
    a = a + b;
    return a;
}

void file_read(FILE *fptr, string *s)
{
    char temp;
    string str;
    int i = 0;
    if(fptr == NULL)
    {
        cout << "\nThe file cannot be opened\n";
        exit(0);
    }
    else
    {
        while(!feof(fptr))
        {
            temp = fgetc(fptr);
            str.push_back(temp);
            if(temp == '\n')
            {
                str.pop_back();
                s[i] = str;
                i++;
                str.clear();
            }
        }
    }
    fclose(fptr);
}

template <class T> //TEMPLATE FUNCTION 1
void option(T a, string s[])
{
    string *ki;
    int n;
    n = a.getIndex();
    ki = a.getString();

    for(int i = 0; i < 30; i++)
    {
        s[i] = ki[i];
        if(ki[i] == "\0") s[i] = "(NO SONG)";
        cout << i + 1 << ". " << s[i] << endl;
    }
}

template <class T> //TEMPLATE FUNCTION 2
int moreitems(T &a, int limit)
{
    int EXISTING = a.getIndex();
    if(EXISTING == limit)
        return 0;
    else return (limit - EXISTING);
}

template <class T, class U, class V>
class myclass
{
public:
    T first;
    U second;
    V third;
    myclass(){}
    void set_value(T a, U b, V c)
    {
        first = a;
        second = b;
        third = c;
    }
    void display()
    {
        cout << this->first << ". " << this->second << " " << this->third << endl;
    }
};

void color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int menu(int element_num, int xpos, int ypos, string items[]) //FUNCTION OVERLOADING
{
    int x = xpos, y = ypos;
    int Set[element_num];
    for(int i = 0; i < element_num; i++)
    {
        Set[i] = 7;
    }
    Set[0] = 12;
    int counter = 1;
    char key;

    for(int i = 0; ; )
    {
        for(int j = 0; j < element_num; j++)
        {
            gotoxy(x, y++);
            color(Set[j]);
            cout << j + 1 << ". " << items[j];
        }
        cout << endl << endl;
        key = _getch();

        if(key == 72 && (counter >= 2 && counter <= element_num)) //72 = UP ARROW KEY
        {
            --counter;
        }

        if(key == 80 && (counter >= 1 && counter <= (element_num - 1))) //80 == DOWN ARROW KEY
        {
            ++counter;
        }

        if(key == 27)
            return 0;

        if(key == '\r') // r = CARRIAGE RETURN (ENTER)
            return counter;

        if(key == 32)
            return -1;
        y = ypos;

        for(int i = 0; i < element_num; i++)
        {
            Set[i] = 7;
        }

        Set[counter - 1] = 12;
    }
}

int menu(int element_num, int xpos, int ypos, string items[], int temp, int mode)
{
    int x = xpos, y = ypos;
    int Set[element_num];
    for(int i = 0; i < element_num; i++)
    {
        Set[i] = 7;
    }
    int counter = temp;
    Set[counter - 1] = mode;
    char key;

    for(int i = 0; ; )
    {
        for(int j = 0; j < element_num; j++)
        {
            gotoxy(x, y++);
            color(Set[j]);
            cout << j + 1 << ". " << items[j];
        }
        cout << endl << endl;
        key = _getch();

        if(key == 72 && (counter >= 2 && counter <= element_num)) //72 = UP ARROW KEY
        {
            --counter;
        }

        if(key == 80 && (counter >= 1 && counter <= (element_num - 1))) //80 == DOWN ARROW KEY
        {
            ++counter;
        }

        if(key == 27)
            return 0;

        if(key == '\r') // r = CARRIAGE RETURN (ENTER)
            return counter;
        if(key == 32)
            return -1;

        y = ypos;

        for(int i = 0; i < element_num; i++)
        {
            Set[i] = 7;
        }

        Set[counter - 1] = mode;
    }
}

#endif // ESSENTIALS_HPP_INCLUDED
