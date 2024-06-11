//LAB PROJECT BY MD. ZUNAIED NUDAR

/*


CONCEPTS USED IN THIS PROJECT-
1. BASIC INHERITANCE
2. BASIC POLYMORPHISM(FUNCTION OVERLOADING, OPERATOR OVERLOADING & BASIC FUNCTION OVERRIDING)
3. FILE MANAGEMENT
4. TEMPLATE FUNCTIONS & TEMPLATE CLASS
5. BASIC CONSTRUCTOR, DESTRUCTOR, ABSTRACT CLASS


*/
#include "essentials.hpp"
#include "language.hpp"
#include "Library.hpp"
#include "Sources.hpp"
#include "PlayMusic.hpp"
#define TAB "\t\t\t\t\t\t\t\t\t\t\t"
#define TAB2 "\t\t\t\t\t\t\t\t\t\t"
#define WELCOME cout << "----------------------------------------------------------------------------------------------WELCOME USER-------------------------------------------------------------------------------------------------------" << endl;
#define MAINMENU cout << "------------------------------------------------------------------------------------------------MAIN MENU--------------------------------------------------------------------------------------------------------" << endl;
#define PLAYLIST cout << "------------------------------------------------------------------------------------------------PLAYLIST---------------------------------------------------------------------------------------------------------" << endl;
#define ADMIN cout << "----------------------------------------------------------------------------------------------ADMIN SECTION------------------------------------------------------------------------------------------------------" << endl;

#define ENTER cout << setw(200) << right << "'ENTER'  : CONTINUE" << endl;
#define ESC cout << setw(200) << right << "'ESC'  : RESTART" << endl;
#define LOGIN_SEQUENCE {system("cls");\
            WELCOME\
            cout << endl;\
            cout << TAB << " ENTER YOUR INFORMATION" << setw(98) << right << "'ENTER'  : CONTINUE" << endl;\
            cout << TAB << " ----------------------" << endl;}
#define LOGIN_SEQUENCE_BASIC {system("cls");\
            WELCOME}
//width 209
using namespace std;

string songName, songLanguage, history[30];
int flag, flag2, n, choice, check, decision;
string st, str, concat;
string *la, *s, *temp;
list <int> :: iterator pi;
list <int> choiceList;
list <string> li, lan;
list <string> :: iterator itr;
map <string, int> check_details;
list <string> vn;
list <int> vp;
list <string>::iterator in;
list <int>::iterator ip;
const char* m;


class login
{
protected:
    string username, check_username[30];
    int pin, check_pin[30];
    bool isOk, isDuplicate;
public:
    login() {}
    login(string name, int p)
    {
        username = name;
        pin = p;
        isOk = 0;
        isDuplicate = 0;
    }

    void check()
    {
        int i = 0;
        ifstream inf;
        inf.open("Record.txt");
        while(inf)
        {
            inf >> str >> n;
            check_username[i] = str;
            check_pin[i] = n;
            i++;
        }

        for(i = 0; i < 30; i++)
        {
            if(username == check_username[i] && pin == check_pin[i])
            {
                isOk = 1;
            }
            if(username == check_username[i])
            {
                isDuplicate = 1;
            }
        }
        inf.close();
    }

    void create()
    {
        const char* c;
        concat = username + pin;
        c = concat.c_str();
        ofstream outf;
        outf.open(c);
        outf.close();

        concat = concat + 100;
        c = concat.c_str();
        outf.open(c);
        outf.close();

        outf.open("Record.txt", ios :: app);
        outf << username << "\n";
        outf << pin << "\n";
        outf.close();
    }

    bool permit()
    {
        return isOk;
    }
    bool duplicate()
    {
        return isDuplicate;
    }
};

class admin
{
private:
    static int pin; //PIN CODE: 2107041
    int COUNT;
    int user_count;
    myclass <int, string, int> m[30]; //TEMPLATE CLASS USED
public:
    admin()
    {
        int i = 0;
        string temp;
        int num;
        //cout << "ENTER ADMIN INFORMATION:" << endl;
        ifstream inf;
        inf.open("Record.txt");
        while(getline(inf, temp, '\n'))
        {
            stringstream ss; //STRINGSTREAM MUST BE RENEWED OR REDECLARED AT THE START OF THE LOOP, OTHERWISE THE VALUES WILL STOP REGISTERING AFTER ONE LOOP
            m[i].first = i + 1;
            m[i].second = temp;
            getline(inf, temp, '\n');
            ss << temp;
            ss >> num;
            m[i].third = num;
            i++;
        }
        COUNT = i;
        inf.close();
    }
    void adduser();

    void show_users()
    {
        system("cls");
        ADMIN
        for(int j = 0; j < COUNT; j++)
            m[j].display();
    }

    ~admin()
    {
        system("cls");
        ADMIN
        cout << "ADMIN LOGGED OUT" << endl;
        cout << "(PRESS ENTER)" << endl;
    }
};

int admin::pin = 2107041;

void admin::adduser()
{
    string username;
    int pin;
    system("cls");
    ADMIN
    cout << "ENTER THE INFORMATION OF THE NEW USER" << endl;
    cout << "USERNAME    :  ";
    cin >> username;
    cout << "PIN         :  ";
    cin >> pin;
    m[COUNT].first = COUNT + 1;
    m[COUNT].second = username;
    m[COUNT].third = pin;
    COUNT++;

    ofstream outf;
    outf.open("Record.txt", ios::app);
    outf << username << "\n";
    outf << pin << "\n";
    outf.close();
}


class formalities
{
protected:
    int state;
public:
    formalities() {}
    void askforInfo()
    {
        string items[] = {"TYPE THE URL OF THE SONG", "GO TO LOCAL LIBRARY"};
        state = menu(2, 0, 3, items);
    }

    int getState()
    {
        return state;
    }
};

class Playlist : virtual public Library, public language
{
protected:
    const char* playlist_name;
    const char* playlist_language;
public:
    Playlist(string d, string f);

    void set_value() {}

    void set_decision(int c)
    {
        l_choice = c;
    }

    int addSong(string history[]);

    void subtract(string history[]);

    string* getString()
    {
        return s;
    }

    int getIndex()
    {
        return index;
    }
};

Playlist::Playlist(string d, string f) : Library(d)
{
    string t;
    playlist_name = d.c_str();
    playlist_language = f.c_str();
}

int Playlist::addSong(string history[])
{
    string s[30];
    int choice;
    if(l == "English")
    {
        English e;
        option(e, s);
    }
    else if(l == "Bangla")
    {
        Bangla b;
        option(b, s);
    }
    else if(l == "Hindi")
    {
        Hindi h;
        option(h, s);
    }
    else if(l == "Japanese")
    {
        Japanese j;
        option(j, s);
    }
    else if(l == "Others")
    {
        Others o;
        option(o, s);
    }


    system("cls");
    MAINMENU
    int type = 0, temp;
    cout << setw(209) << right << "ESC: GO BACK" << endl;

    int more;
    more = moreitems(*this, 30);
    if(!more)
    {
        system("cls");
        cout << "NO MORE SONGS CAN BE ADDED" << endl;
        cout << "PLEASE DELETE SOME SONGS TO CREATE SPACE" << endl;
        return -1;
    }

    choice = menu(30, 0, 1, s, 1, 5);
    temp = choice;

    while(choice)
    {
        flag = 1;
        for(pi = choiceList.begin(); pi != choiceList.end(); pi++)
        {
            if(*pi == choice)
            {
                type = 1;
                flag = 0;
                break;
            }
        }
        for(int i = 0; i < 30; i++)
        {
            if(flag == 0) break;
            if(history[i] == s[choice - 1])
            {
                type = 2;
                flag = 0;
                break;
            }
            else if(s[choice - 1] == "(NO SONG)")
            {
                type = 3;
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            more--;
            type = 4;
            choiceList.push_front(choice);
            songName = s[choice - 1];
            li.push_back(songName);
            lan.push_back(l);
        }

        system("cls");
        MAINMENU
        if(type == 1 || type == 2)
        {
            cout << setw(209) << right << "ESC: GO BACK" << endl;
            cout << setw(209) << right << "THE MUSIC ALREADY EXISTS IN YOUR PLAYLIST" << endl << endl;
        }
        else if(type == 3)
        {
            cout << setw(209) << right << "ESC: GO BACK" << endl;
            cout << setw(209) << right << "THIS SLOT IS EMPTY" << endl << endl;
        }
        else if(type == 4)
        {
            cout << setw(209) << right << "ESC: GO BACK" << endl;
            cout << setw(209) << right << "SONG ADDED TO YOUR LIST" << endl << endl;
        }
        if(!more)
        {
            system("cls");
            cout << "NO MORE SONGS CAN BE ADDED" << endl;
            cout << "PLEASE DELETE SOME SONGS TO CREATE SPACE" << endl;
            cout << "\n\n(PRESS ENTER TO GO BACK)" << endl;
            _getch();
            break;
        }
        choice = menu(30, 0, 1, s, temp, 5);
        temp = choice;
        type = 0;
    }

    ofstream outf;

    outf.open(playlist_name, ios::app);

    for(auto x : li)
    {
        outf << x << endl;
    }
    outf.close();

    outf.open(playlist_language, ios::app);

    for(auto x : lan)
    {
        outf << x << endl;
    }
    outf.close();

    li.clear();
    lan.clear();
    choiceList.clear();
}

void Playlist::subtract(string history[])
{
    system("cls");
    MAINMENU
    string s;
    ifstream inf;
    inf.open(playlist_name);

    int j = 0;
    while(getline(inf, s, '\n'))
    {
        li.push_back(s);
        j++;
    }
    inf.close();
    inf.open(playlist_language);
    while(getline(inf, s, '\n'))
    {
        lan.push_back(s);
    }

    inf.close();
    if(li.empty() == false)
    {
        int i = 0;
        int left, right;
        string items[] = {"INDIVIDUALLY", "GROUPWISE"};
        int option;
        cout << "HOW DO YOU WANT TO DELETE SONG/SONGS?" << endl;
        cout << "\n\n\nESC: GO BACK" << endl;
        option = menu(2, 0, 2, items);
        cout << "\nCHOOSE SONG/SONGS TO DELETE:\n" << endl;

        string elements[j];
        for(itr = li.begin(); itr != li.end(); itr++)
        {
            elements[i] = *itr;
            i++;
        }

        i = 0;
        int choice;
        if(option == 1)
        {
            for(; ;)
            {
                system("cls");
                MAINMENU
                cout << "ESC: STOP\n" << endl;
                choice = menu(j, 0, 3, elements);
                if(choice == 0) break;
                itr = li.begin();
                advance(itr, (choice - 1));
                li.erase(itr);
                itr = lan.begin();
                advance(itr, (choice - 1));
                lan.erase(itr);//
                j--;
                for(itr = li.begin(); itr != li.end(); itr++)
                {
                    elements[i] = *itr;
                    i++;
                }
                i = 0;
            }
        }
        else if(option == 2)
        {
            i = 0;
            system("cls");
            MAINMENU
            for(itr = li.begin(); itr != li.end(); itr++)
            {
                cout << i + 1 << ". " << *itr << endl;
                i++;
            }
            for(; ;)
            {
                cout << "'0 0': STOP" << endl;
                cout << "\nENTER THE RANGE: ";
                cin >> left >> right;
                if(left == 0) break;
                list <string> :: iterator i1, i2;
                i1 = i2 = li.begin();
                advance(i1, left - 1);
                advance(i2, right);
                li.erase(i1, i2);
                i1 = i2 = lan.begin();
                advance(i1, left - 1);
                advance(i2, right);
                lan.erase(i1, i2);
                system("cls");
                MAINMENU
                i = 0;
                for(itr = li.begin(); itr != li.end(); itr++)
                {
                    cout << i + 1 << ". " << *itr << endl;
                    i++;
                }
                i = 0;
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        cout << "PLAYLIST EMPTY..\n" << endl;
    }

    ofstream outf;
    outf.open(playlist_name);
    for(auto x : li)
    {
        outf << x << endl;
    }
    outf.close();
    outf.open(playlist_language);
    for(auto x : lan)
    {
        outf << x << endl;
    }
    outf.close();
    for(int i = 0; i < 30; i++)
    {
        history[i] = "___ADD SONG___";
    }
}


int main()
{
    string username;
    int pin, k, comeback = 0, comeback2 = 0;
    bool ok, logout;
    int admin_comeback;
B:
    logout = false;
    PlaySound(0, 0, 0);
    if(admin_comeback)
    {
        admin_comeback = 0;
        _getch();
        system("cls");
    }
    WELCOME
    string items[] = {"ACCESS EXISTING ACCOUNT", "CREATE NEW ACCOUNT", "ADMIN PRIVILAGE"};
    check = menu(3, 87, 3, items);
    system("cls");
    if(check == 0) goto B;
    WELCOME
    flag = 0;
    if(check == 1)
    {
        cout << endl;
        cout << TAB << " ENTER YOUR INFORMATION" << setw(98) << right << "'ENTER'  : CONTINUE" <<endl;
        cout << TAB << " ----------------------" << setw(98) << right << "'ESC'  : RESTART" <<endl;
        flag = 0;
        do
        {
            char key;
            key = _getch();

            if(key == 27)
            {
                flag = 1;
                system("cls");
                break;
            }

            LOGIN_SEQUENCE
            cout << endl;
            cout <<"USERNAME  :    ";
            cin >> username;

            LOGIN_SEQUENCE
            cout << endl;
            cout <<"USERNAME  :    " << username << endl;
            cout <<"PIN       :    ";
            cin >> pin;

            login log(username, pin);
            system("cls");
            WELCOME
            log.check();
            ok = log.permit();
            if(!ok)
            {
                cout << endl;
                cout << "THE USERNAME OR THE PIN IS INCORRECT!" << setw(172) << right << "'ENTER'  : CONTINUE" << endl;
                cout << "TRY AGAIN.." << setw(198) << right << "'ESC'  : RESTART" << endl;
            }
        }
        while(!ok);
    }
    else if(check == 2)
    {
        do
        {
            system("color 0F");
            flag2 = 0;
            cout << endl;
            cout <<"NEW USERNAME  :    ";
            cin >> username;
            LOGIN_SEQUENCE_BASIC
            cout << endl;
            cout <<"NEW USERNAME  :    " << username << endl;
            cout <<"CREATE A PIN  :    ";
            cin >> pin;
            login log(username, pin);
            log.check();
            ok = log.duplicate();
            if(ok)
            {
                system("cls");
                WELCOME
                cout << endl;
                cout <<"THIS USERNAME ALREADY EXISTS\nTRY AGAIN..\n" << endl;
                flag2 = 1;
            }
            else
                log.create();
        }
        while(flag2);
    }

    else
    {
        admin a;
        string items[] = {"SHOW USERS", "ADD USER", "EXIT"};
        int choice, temp;
        choice = menu(3, 0, 1, items, 1, 11);
        temp = choice;
        while(choice != 3)
        {
            if(choice == 1)
            {
                a.show_users();
                cout << endl;
                cout << "(PRESS ENTER TO PROCEED)" << endl;
                _getch();
            }
            else
            {
                a.adduser();
                cout << endl;
                cout << "USER SUCCESSFULLY ADDED" << endl;
                cout << "(PRESS ENTER TO PROCEED)" << endl;
                _getch();
            }
            system("cls");
            ADMIN
            choice = menu(3, 0, 1, items, temp, 11);
            temp = choice;
        }
        admin_comeback = 1;
    }

    if(flag == 1 || admin_comeback == 1) goto B;

    system("cls");
    WELCOME
    cout << "SUCCESSFULLY LOGGED IN\n" << endl;

    formalities f;
    f.askforInfo();
    k = f.getState();
    system("cls");
    WELCOME
    cout << "SUCCESSFULLY LOGGED IN\n" << endl;

C:

    while(k == 1)
    {
        string URL;
        cout << endl;
        cout << "ENTER THE URL: " << endl;
        cin >> URL;
        ShellExecute(NULL, "open", URL.c_str(), NULL, NULL, SW_SHOWNORMAL);
        if(comeback == 1)
        {
            comeback = 2;
            break;
        }
        LOGIN_SEQUENCE_BASIC
        string items[] = {"TYPE THE URL OF THE SONG AGAIN", "GO TO LOCAL LIBRARY"};
        k = menu(2, 0, 2, items);
    }
    system("color 0F");

    concat = username + pin;
    m = concat.c_str();
    st = concat + 100;

    for(int i = 0; i < 30; i++)
    {
        history[i] = "___ADD SONG___";
    }


A:
    comeback2 = 0;
    bool nothing = false;
    choice = 1;
    while(choice)
    {
        Playlist P(concat, st);
        Library *p;
        p = &P;
        temp = p->getString();
        n = p->getIndex();

        system("cls");

        for(int i = 0; i < n; i++)
        {
            history[i] = temp[i];
        }

        if(n == 0)
        {
            nothing =  true;
            choice = 2;
        }
        else
        {
            MAINMENU
            string items[] = {"MY PLAYLIST", "ADD SONGS", "DELETE SONGS", "SEARCH URL", "LOG OUT", "EXIT"};
            choice = menu(6, 0, 1, items);
            if(choice == 1)
            {
                Library *l;
                languageSeq L(st);
                l = &L;
                la = l->getString();
                break;
            }
            else if(choice == 4)
            {
                system("cls");
                MAINMENU
                system("color 0F");
                comeback = 1;
                k = 1;
                break;
            }
            else if(choice == 5)
            {
                logout = true;
                system("cls");
                break;
            }
            else if(choice == 6)
            {
                cout << "\n\n\nTHANK YOU" << endl;
                return 0;
            }
        }
        if(choice == 2)
        {
            system("cls");
            MAINMENU
            if(nothing == true)
            {
                cout << "YOUR CURRENT PLAYLIST IS EMPTY";
            }
            cout << endl;
            nothing = false;
            li.clear();
            lan.clear();
            cout << endl;
            cout << TAB << "   CHOOSE THE LIBRARY" << endl;
            cout << TAB << "   ------------------" << endl;
            string items[] = {"ENGLISH", "BANGLA", "HINDI", "JAPANESE", "OTHERS", "GO BACK", "LOG OUT", "EXIT"};
            decision = menu(8, 95, 6, items);
            system("cls");
            MAINMENU
            if(decision == 6)
            {
                comeback2 = 1;
                break;
            }
            else if(decision == 7)
            {
                logout = true;
                system("cls");
                break;
            }
            else if(decision == 8)
            {
                cout << "\n\n\nTHANK YOU" << endl;
                return 0;
            }
            P.set_decision(decision);
            P.selectlanguage();
            int more = P.addSong(history);
            if(more == -1)
            {
                cout << "\n\n(PRESS ENTER TO GO BACK)" << endl;
                _getch();
                comeback2 = 1;
                break;
            }
        }
        else if(choice == 3)
        {
            li.clear();
            lan.clear();
            P.subtract(history);
        }
        choice = 1;
    }
    if(comeback == 1) goto C;
    if(comeback2 == 1) goto A;

    if(logout) goto B;
    decision = 1;
    int temp = 1;
    system("cls");
    PLAYLIST
    while(decision == 1)
    {
        system("cls");
        PLAYLIST
        FILE *fp;
        fp = fopen(m, "r");

        Library *l;
        languageSeq L(st);
        l = &L;
        la = l->getString();

        string s[30];
        file_read(fp, s);

        cout << endl;
        cout << TAB << "    CHOOSE THE SONG" << endl;
        cout << TAB << "    ---------------" << endl;
        for(int i = 1; i <= 30; i++)
        {
            if(s[i - 1] == "\0")
                s[i - 1] = "___ADD SONG___";
        }

        cout << setw(209) << right << "ENTER: SELECT" << endl;
        cout << setw(209) << right << "SPACE: GO BACK" << endl;
        cout << setw(209) << right << "ESC: EXIT" << endl;
        choice = menu(30, 0, 4, s, temp, 5);

        temp = choice;
        if(choice == 0)
        {
            cout << "\n\n\nTHANK YOU" << endl;
            break;
        }
        else if(choice != -1)
        {
            int input;
            songName = s[choice - 1];
            if(songName == "___ADD SONG___")
            {
                string items2[] = {"SELECT", "GO BACK", "EXIT"};
                cout << "NO SONG FOUND" << endl;
                cout << "TRY AGAIN" << endl;
                decision = menu(3, 0, 40, items2, 1, 5);
                if(decision == 3)
                {
                    cout << "\n\n\nTHANK YOU" << endl;
                    return 0;
                }
                continue;
            }
            songLanguage = la[choice - 1];
            PlayMusic music(songName, songLanguage);
            music.Play();

            string elements[] = {"START", "STOP"};
            int temp2 = 1;
            while(temp2 != 0)
            {
                input = menu(2, 0, 40, elements, temp2, 11);
                temp2 = input;
                controlMusic(temp2, music);
            }
        }
        else
        {
            decision = 2;
        }
    }

    if(decision == 2) goto A;

    return 0;
}

