#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

void maze();
void gotoxy(int x, int y);
void showpacman(int x, int y);
void clearpacman(int x, int y);
char GetCharAtxy(short int x, short int y);
void showghost(int x, int y);
void clearghost(int x, int y, char previous);
void start();
int operation;
void score(int sc);

void showghost(int x, int y);
char nextlocation;
int sc=0;

main()
{
	
	int gx = 15;
	int gy = 15;
	int gxv = 38;
	int gyv = 5; 
	int px = 8;
	int py = 3;
	string direction = "right";
	string direction2 = "down";
	char previouschar = ' ';
	char previouschar2 = ' ';
	system("cls");
	start();
	if(operation == 2)
	{
		return 0;
	}
	if(operation == 1)
	{
	system("cls");
	maze();
	showghost(gx,gy);	
	showpacman(px,py);
	

while(true)
{
	
	if(GetAsyncKeyState(VK_RIGHT))
	{
		nextlocation = GetCharAtxy(px+1 , py);
		
		if(nextlocation == ' ')
		{
			clearpacman(px,py);
			px = px+1;
			showpacman(px,py);
		}
		if(nextlocation == 'G')
		{
			clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
			
		}
		if(nextlocation == '.')
		{
			clearpacman(px,py);
			px = px + 1;
			showpacman(px,py);
			sc = sc + 1;	
			score(sc);				
		}		
	}

	if(GetAsyncKeyState(VK_LEFT))
	{
		nextlocation = GetCharAtxy (px-1,py);
		if(nextlocation == ' ')
		{
			clearpacman(px,py);
			px = px-1;
			showpacman(px,py);
		}
		if(nextlocation == 'G')
		{
			clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
			
		}
		if(nextlocation == '.')
		{
			clearpacman(px,py);
			px = px - 1;
			showpacman(px,py);
			sc = sc + 1;	
			score(sc);				
		}

		
	}

	if(GetAsyncKeyState(VK_UP))
	{
		nextlocation = GetCharAtxy(px,py-1);
		if(nextlocation == ' ')
		{
			clearpacman(px,py);
			py = py-1;
			showpacman(px,py);
		}
		if(nextlocation == 'G')
		{
			clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
			
		}
		if(nextlocation == '.')
		{
			clearpacman(px,py);
			py = py - 1;
			showpacman(px,py);
			sc = sc + 1;	
			score(sc);				
		}

	}
	if(GetAsyncKeyState(VK_DOWN))
	{
		nextlocation = GetCharAtxy(px,py+1);
		if(nextlocation == ' ')
		{
			clearpacman(px,py);
			py = py+1;
			showpacman(px,py);
		}
		if(nextlocation == 'G')
		{
			clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
			
		}
		if(nextlocation == '.')
		{
			clearpacman(px,py);
			py = py + 1;
			showpacman(px,py);
			sc = sc + 1;	
			score(sc);				
		}

	}

//ghost functionallity
//for horizontally
Sleep(100);
if(direction == "right")
{
	char nextlocation = GetCharAtxy(gx+1,gy);
	if((nextlocation == '%' || nextlocation == '|'))	
	{
		direction = "left";
	}
	
	else if(nextlocation == ' ' || nextlocation == '.')
	{
		clearghost(gx, gy, previouschar);
		gx = gx + 1;
		//previouschar = nextlocation;
		showghost(gx, gy);
	}
	else if (nextlocation == 'P')
	{
		clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
	}

}
if(direction == "left" )
{
	char nextlocation = GetCharAtxy(gx-1, gy);
	if((nextlocation == '%' || nextlocation == '|'))	
	{
		direction = "right";
	}
	else if(nextlocation == ' ' || nextlocation == '.')
	{
		clearghost(gx,gy,previouschar);
		gx = gx -1;
		//previouschar = nextlocation;
		showghost(gx,gy);
	}
	else if (nextlocation == 'P')
	{
		clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
	}
}
//for vertically

if(direction2 == "down")
{
	char nextlocation = GetCharAtxy(gxv, gyv + 1);
	if(nextlocation == '%' || nextlocation == '|' || nextlocation == '#' )
	{
		direction2 = "up";
	}
	else if(nextlocation == ' ' || nextlocation == '.')
	{
		clearghost(gxv,gyv,previouschar2);
		gyv = gyv + 1;
		showghost(gxv, gyv);
	}
	else if (nextlocation == 'P')
	{
		clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
	}
}
if(direction2 == "up")
{
	char nextlocation = GetCharAtxy(gxv, gyv - 1);
	if(nextlocation == '%' || nextlocation == '|' || nextlocation == '#')
	{
		direction2 = "down";
	}
	else if(nextlocation == ' ' || nextlocation == '.')
	{
		clearghost(gxv,gyv, previouschar2);
		gyv = gyv - 1;
		showghost(gxv, gyv);
	}
	else if (nextlocation == 'P')
	{
		clearpacman(px,py);
			sc = 0;
			score(sc);
			px = 8;
			py = 3;
			px = px + 1;
			showpacman(px,py);
	}

}	

}	

	



gotoxy(0,20);
}
}
void maze()
{
cout<<" ###############################################################################   "<<endl;
cout<<" ||.. ..............................................................   .....  ||   "<<endl;
cout<<" ||.. %%%%%%%%%%%%%%%%%          ...          %%%%%%%%%%%%%%%  |%|..    %%%   ||   "<<endl;
cout<<" ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|   ||   "<<endl;
cout<<" ||..       |%|     |%|       |%|...           |%|        |%|  |%|..    |%|   ||   "<<endl;
cout<<" ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%%%     ..    %%%.  ||   "<<endl;
cout<<" ||..       |%|           ..  |%|...           .............. |%| ..       .  ||   "<<endl;
cout<<" ||..       %%%%%%%%%%%   ..  |%|...           %%%%%%%%%%%%   |%| ..    %%%.  ||   "<<endl;
cout<<" ||..               |%|.  ..                   |%|......      |%| ..    |%|.  ||   "<<endl;
cout<<" ||..     ......... |%|.  ..                   |%|......|%|       ..    |%|.  ||   "<<endl;
cout<<" ||..|%|  |%|%%%|%|.|%|. |%|                      ......|%|       ..|%| |%|.  ||   "<<endl;
cout<<" ||..|%|  |%|   |%|..    %%%%%%%%%%%%             ......|%|        .|%|.      ||   "<<endl;
cout<<" ||..|%|  |%|   |%|..                                %%%%%%       . |%|.      ||   "<<endl;
cout<<" ||..|%|            .                                         |%| ..|%|.      ||   "<<endl;
cout<<" ||..|%|  %%%%%%%%%%%%%%                   %%%%%%%%%%%%%%     |%| ..|%|%%%%   ||   "<<endl;
cout<<" ||                                                           |%| ..........  ||   "<<endl;
cout<<" ||    ...................................................          ........  ||   "<<endl;
cout<<" ||..|%|  |%|  |%|..     %%%%%%%%%%%%%%      ..........|%|    |%| ..|%|.      ||   "<<endl;
cout<<" ||..|%|  |%|  |%|..             ...|%|           %%%%%%%%    |%| ..|%|.      ||   "<<endl;
cout<<" ||..|%|           .             ...|%|                       |%| ..|%|.      ||   "<<endl;
cout<<" ||..|%|  %%%%%%%%%%%%%%%        ...|%|%%%%%%%%%%%%%%%        |%| ..|%|%%%%   ||   "<<endl;
cout<<" ||.....................................................      |%| .........   ||   "<<endl;
cout<<" ||  ...................................................             ......   ||   "<<endl;
cout<<" ###############################################################################   "<<endl;

}

void gotoxy(int x, int y)
{
COORD coordinates;
 coordinates.X = x;
 coordinates.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void showpacman(int x, int y)
{
	gotoxy(x,y);
	cout<<"P";
	Sleep(50);	

}

void showghost(int x, int y)
{
	gotoxy(x,y);
	cout<<"G";
}

void clearghost(int x, int y, char previous)
{
	gotoxy(x,y);
	cout<< previous;
}




void clearpacman(int x , int y)
{
	gotoxy(x,y);
	cout<<" ";
}


void score(int sc)
{
	
	
	gotoxy(85,1);
	cout<<"Score:           ";
	gotoxy(85,1);
	cout<<"Score: "<<sc;
	

}





char GetCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}

void start()
{
cout<<"        ### ##       ##        ## ##    ##   ##    ##       ###  ## "<<endl;
cout<<"         ##  ##       ##      ##   ##    ## ##      ##        ## ##"<<endl;
cout<<"         ##  ##     ## ##     ##        # ### #    ## ##     # ## #"<<endl;
cout<<"         ##  ##     ##  ##    ##        ## # ##    ##  ##    ## ##"<<endl;
cout<<"         ## ##      ## ###    ##        ##   ##    ## ###    ##  ##"<<endl;
cout<<"         ##         ##  ##    ##        ##   ##    ##  ##    ##  ##"<<endl;
cout<<"         ##         ##  ##    ##   ##   ##   ##    ##  ##    ##  ##"<<endl;
cout<<"        ####       ###  ##     ## ##    ##   ##   ###  ##   ###  ##"<<endl;
cout<<"                                                                     "<<endl;
cout<<"                       1. Start Game                                 "<<endl;
cout<<"                       2. Exit Game                                  "<<endl;
cout<<"                 ____________________________                        "<<endl;
cout<<"                 Select your option...                                                "<<endl;
cin >> operation;
}

