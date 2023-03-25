#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int , int);
void maze();
void tempmaze();
void printpacman(int x, int y);
void erase(int x, int y);
char Getch(short int x,short int y);
void ghostmove(int x, int y);
void playermove(int x, int y);

int score;
main()
{
system("cls");

  bool runningame = true;
  int x = 8;
  int y = 8;
  int gxv = 6;
	int gyv = 6; 
  tempmaze();
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
        if (nextLocation == '.')
        {
          erase(x,y);
          x=x-1;
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
    playermove(gxv,gyv);
    if (gxv<24)
    {
      gxv=gxv+1;
    }
    if (gxv==24)
    {
      gotoxy(gxv-1,gyv);
      cout << " ";
      gxv=8;
    }
  }


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
  cout << "P";
}


void playermove(int x , int y)
{
  gotoxy(x-1,y);
  cout << " ";
  gotoxy(x,y);
  cout << "G";
  Sleep(200);
}

void ghostmove(int x, int y)
{
  gotoxy(x-1,y);
  cout << " ";
  gotoxy(x,y);
  cout << "G";
  Sleep(200);
  if (x<24)
  {
    x=x+4;
  }
  if (x==24)
  {
    gotoxy(x-1,y);
    cout << " ";
    x=8;
  }
}

void erase(int x, int y)
{
  gotoxy(x,y);
  cout << " ";
}


void maze()
{
cout << "   ############################################################################## "<< endl; 
cout << "   ||..    ....................................................    .........   || "<< endl;
cout << "   ||..    |%%%%%%%%|  ...     |%%%|    |%%|..    |%%%%%|   |%%%%%|  ......... ||"<< endl;
cout << "   ||..           |%|   |%|       |%|...     |%|    |%|   |%|..          |%|   ||"<< endl;
cout << "   ||..           |%|   |%|       |%|... G    |%|    |%|   |%|..          |%|  ||"<< endl;
cout << "   ||..    G       |%%%%%%%|     ..|%|...     |%%%%%%%%|     ........  %%%%%.  ||"<< endl;
cout << "   ||..           |%|           ..|%|...    ...........   |%|........       .  ||"<< endl;
cout << "   ||..           |%%%%%%%%|    ..|%|...    %%%%%%%%      |%|..        %%%%%.  ||"<< endl;
cout << "   ||..                  |%|.           |%|......         |%|..          |%|.  ||"<< endl;
cout << "   ||..         ........ |%|.           |%|....|%|           ..          |%|.  ||"<< endl;
cout << "   ||..|%| |%|%%|%|.|%|. |%|. |%|          ....|%|      G    ..|%|       |%|.  ||"<< endl;
cout << "   ||..|%| |%|  |%|.|%|..     %%%%%%%%%%   ....|%|           ..|%|       |%|.  ||"<< endl;
cout << "   ||..           %%%%%%%%%     ..|%|...     %%%%%%%%%%      ..        %%%%%.  ||"<< endl;
cout << "   ||..           |%|   |%|       |%|...     |%|    |%|   |%|.......     |%|   ||"<< endl;
cout << "   ||..           %%%%%%%%%     ..|%|...     %%%%%%%%%%      .......   %%%%%.  ||"<< endl;
cout << "   ||..         ........ |%|. G       |%|....|%|             .......     |%|.  ||"<< endl;
cout << "   ||..           %%%%%%%%%     ..|%|...     %%%%%%%%%%      .......   %%%%%.  ||"<< endl;
cout << "   ||..           |%|   |%|       |%|...     |%|    |%|   |%|..          |%|   ||"<< endl;
cout << "   ############################################################################## "<< endl;
}

void tempmaze()
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