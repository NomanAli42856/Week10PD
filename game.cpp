#include<iostream>
#include<windows.h>
using namespace std;

void topHeader();
void maze();
void gotoxy(int , int);
char Getch(short int x,short int y);
void printpacman(int x, int y);
void erase(int x, int y);
void square();
int score = 0;

main()
{

    system("cls");

    topHeader();
    maze();


    bool runningame = true;
    int x = 12;
    int y = 12;
    printpacman(x,y);
    while(runningame)
    {
        if(GetAsyncKeyState(VK_LEFT))
        {  
            char nextLocation = Getch(x-1,y);
            if (nextLocation == ' ')
            {
            erase(x,y);
            x=x-1;
            printpacman(x,y);
            }
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = Getch(x+1,y);
            if (nextLocation == ' ')
            {
            erase(x,y);
            x=x+1;
            printpacman(x,y);
            }
            if (nextLocation == '.')
            {
            erase(x,y);
            x=x+1;
            printpacman(x,y);
            score = score + 1;
            }
            if (nextLocation == 'G')
            {
            runningame = false;
            gotoxy(5,25);
            cout << "SCORE : " << score;
            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            char nextLocation = Getch(x,y-1);
            if (nextLocation == ' ')
            {
            erase(x,y);
            y=y-1;
            printpacman(x,y);
            }
            if (nextLocation == '.')
            {
            erase(x,y);
            y=y-1;
            printpacman(x,y);
            score = score + 1;
            }
            if (nextLocation == 'G')
            {
            runningame = false;
            gotoxy(5,25);
            cout << "SCORE : " << score;
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            char nextLocation = Getch(x,y+1);
            if (nextLocation == ' ')
            {
            erase(x,y);
            y=y+1;
            printpacman(x,y);
            }
            if (nextLocation == '.')
            {
            erase(x,y);
            y=y+1;
            printpacman(x,y);
            score = score + 1;
            }
            if (nextLocation == 'G')
            {
            runningame = false;
            gotoxy(5,25);
            cout << "SCORE : " << score;
            }
        }
        Sleep(150);
    }



}



void topHeader()
{
    cout << "\t\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    cout << "\t\t\t" << "&&&&               &&&&" << endl;
    cout << "\t\t\t" << "&&&&    TETRIS     &&&&" << endl;
    cout << "\t\t\t" << "&&&&               &&&&" << endl;
    cout << "\t\t\t" << "$$$$$$$$$$$$$$$$$$$$$$$" << endl;
}


char Getch(short int x,short int y)
{
  CHAR_INFO ci;
  COORD xy = {0,0};
  SMALL_RECT rect = {x,y,x,y};
  COORD coordBufSize;
  coordBufSize.X=1;
  coordBufSize.Y=1;  
  return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize,xy, &rect) ? ci.Char.AsciiChar : ' ';
}


void gotoxy(int x , int y)
{
COORD coordinates;
coordinates.X = x;
coordinates.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printpacman(int x, int y)
{
  gotoxy(x,y);
  square();
}

void erase(int x, int y)
{
  gotoxy(x,y);
  cout << " ";
}


void maze()
{
cout << "   ############################################################################## "<< endl; 
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ||                                                                          || "<< endl;
cout << "   ############################################################################## "<< endl;
}


void square()
{
    cout  << "----" << endl;
    cout  << "----" << endl;
}