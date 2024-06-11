#ifndef PLAYMUSIC_HPP
#define PLAYMUSIC_HPP
#include <iostream>
#include <windows.h>
#include "mmsystem.h"
using namespace std;


class PlayMusic
{
    const char* c;
    string location;
public:
    PlayMusic(string s_name, string s_language);

    void Play()
    {
        PlaySound(TEXT(c), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP); //SND_ASYNC ALLOWS TO DO OTHER THINGS INSTEAD OF WAITING FOR THE WHOLE SOUND TO FINISH, DONT USE SND_SYNC
    }
    friend void controlMusic(int input, PlayMusic music) //FRIEND FUNCTION USED
    {
        if(input == 2)
        {
            PlaySound(0, 0, 0);
        }
        else if(input == 1)
        {
            PlaySound(TEXT(music.c), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
        }
        else
        {
            return;
        }
    }
};

#endif // PLAYMUSIC_HPP
