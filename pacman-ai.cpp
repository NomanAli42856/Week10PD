#include<iostream>
#include<windows.h>
using namespace std;

void gotoxy(int , int);
void maze();
void tempmaze();
void printpacman();
void erase();
char Getch(short int x,short int y);
void ghostmove();
void playermove(int x, int y);
  int x = 20;
  int y = 8;
  int gxv = 6;
	int gyv = 6;

int score;
main()
{
system("cls");

  bool runningame = true; 
  tempmaze();
  gotoxy(x,y);
  printpacman();
  while(runningame)
  {
    if(GetAsyncKeyState(VK_LEFT))
     {  
        char backLocation = Getch(x-1,y);
        char nextLocation = Getch(x+1,y);
        char upLocation = Getch(x,y-1);
        char downLocation = Getch(x,y+1);
        if (nextLocation == ' ' && backLocation == ' ' && upLocation == ' ' && downLocation == ' ')
        {
          gotoxy(x,y);
          erase();
          x=x-1;
          gotoxy(x,y);
          printpacman();
        }
        if (nextLocation == '.')
        {
          gotoxy(x,y);
          erase();
          x=x-1;
          gotoxy(x,y);
          printpacman();
          score = score + 1;
        }
        if (nextLocation == 'G' || backLocation == 'G' || upLocation == 'G' || downLocation == 'G')
        {
          runningame = false;
          gotoxy(5,25);
          cout << "SCORE : " << score;
        }
     }
    if(GetAsyncKeyState(VK_RIGHT))
     {
        char backLocation = Getch(x-1,y);
        char nextLocation = Getch(x+1,y);
        char upLocation = Getch(x,y-1);
        char downLocation = Getch(x,y+1);
        if (nextLocation == ' ' && backLocation == ' ' && upLocation == ' ' && downLocation == ' ')
        {
          gotoxy(x,y);
          erase();
          x=x+1;
          gotoxy(x,y);
          printpacman();
        }
        if (nextLocation == '.')
        {
          gotoxy(x,y); 
          erase();
          x=x+1;
          gotoxy(x,y);
          printpacman();
          score = score + 1;
        }
        if (nextLocation == 'G' || backLocation == 'G' || upLocation == 'G' || downLocation == 'G')
        {
          runningame = false;
          gotoxy(5,25);
          cout << "SCORE : " << score;
        }
     }
    if(GetAsyncKeyState(VK_UP))
     {
        char backLocation = Getch(x-1,y);
        char nextLocation = Getch(x+1,y);
        char upLocation = Getch(x,y-1);
        char downLocation = Getch(x,y+1);
        if (nextLocation == ' ' && backLocation == ' ' && upLocation == ' ' && downLocation == ' ')
        {
          gotoxy(x,y);
          erase();
          y=y-1;
          gotoxy(x,y);
          printpacman();
        }
        if (nextLocation == 'G' || backLocation == 'G' || upLocation == 'G' || downLocation == 'G')
        {
          runningame = false;
          gotoxy(5,25);
          cout << "SCORE : " << score;
        }
     }
    if(GetAsyncKeyState(VK_DOWN))
     {
        char backLocation = Getch(x-1,y);
        char nextLocation = Getch(x+1,y);
        char upLocation = Getch(x,y-1);
        char downLocation = Getch(x,y+1);
        if (nextLocation == ' ' && backLocation == ' ' && upLocation == ' ' && downLocation == ' ')
        {
          gotoxy(x,y);
          erase();
          y=y+1;
          gotoxy(x,y);
          printpacman();
        }
        if (nextLocation == 'G' || backLocation == 'G' || upLocation == 'G' || downLocation == 'G')
        {
          runningame = false;
          gotoxy(5,25);
          cout << "SCORE : " << score;
        }
     }
     ghostmove();
     Sleep(500);
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

void printpacman()
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

void ghostmove()
{
  if(x < gxv)
  {
    gotoxy(gxv,gyv);
    cout << " ";
    gxv--;
    gotoxy(gxv,gyv);
    cout << "G";

  }
  if(x > gxv)
  {
    gotoxy(gxv,gyv);
    cout << " ";
    gxv++;
    gotoxy(gxv,gyv);
    cout << "G";

  }
  if(y > gyv)
  {
    gotoxy(gxv,gyv);
    cout << " ";
    gyv++;
    gotoxy(gxv,gyv);
    cout << "G";

  }
  if(y < gyv)
  {
    gotoxy(gxv,gyv);
    cout << " ";
    gyv--;
    gotoxy(gxv,gyv);
    cout << "G";

  }
}

void erase()
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