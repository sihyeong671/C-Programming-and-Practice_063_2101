#include <iostream>
# include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;
const int width = 20;
const int height = 20;
bool gameOver;
int x,y,feedX,feedY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Logic()
{
	//더 쉬운 알고리즘 찾기 
	tailX[0]=x;
	tailY[0]=y;
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;
	
	for(int i=1;i<nTail;i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch(dir)
	{
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	default:
		break;
	}
	if(0>x||x>width||0>y||y>height)
	{
		gameOver = true;
	}
	for(int i=1;i<nTail;i++)
	{
		if(tailX[i]==x&&tailY[i]==y)
		{
			gameOver = true;
		}
	}
	if(x==feedX&&y==feedY)
	{
		score++;
		feedX = rand()%width;
		feedY = rand()%height;
		nTail++;
	}
}
void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}
}
void SetUp()
{
	nTail=1;
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	feedX = rand()%width;
	feedY = rand()%height;
	score = 0;
}

void Draw()
{
	system("cls");
	for(int i=0; i < width;i++)
	{
		cout << "#";
	}
	cout << endl;
	for(int i=0; i< height;i++)
	{
		for(int j=0; j<width;j++)
		{
			if(j==0 || j==width-1)
			{
				cout << "#";
			}
			else if(i==y&&j==x)
			{
				cout << "O";
			}
			else if(i==feedY&&j==feedX)
			{
				cout << "$"; 
			}
			else
			{	
				bool print = false;
				for(int k=1;k<nTail;k++)
				{
					
					if(tailX[k]==j&&tailY[k]==i)
					{
						cout<<"o";
						print = true;
					}
				}
				if(!print)
				{
					cout << " ";
				}			
			}
			
		}
		cout << endl;
	}
	
	for(int i=0; i < width;i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "score : " << score << endl;
}
int main()
{
	SetUp();
	while(!gameOver)
	{
		Draw();
		Logic();
		Input();
		Sleep(100);
	}
	return 0;
}
