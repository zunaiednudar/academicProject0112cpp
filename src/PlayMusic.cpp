#include "PlayMusic.hpp"

PlayMusic::PlayMusic(string s_name, string s_language)
{
    location = "Musics/" + s_language + "/" + s_name + ".wav";
    c = location.c_str();
    cout << "\nNow Playing: " << endl;
    cout << s_name << endl;
}
