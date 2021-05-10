#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;
//게임화면 크기 
const int width = 20; 
const int height = 20;
//게임 종료 확인 변수 
bool gameOver;
// 머리 위치, 먹이 위치, 점수
int x,y,feedX,feedY,score;
// 꼬리들 
int tailX[100],tailY[100]; 
// 꼬리 갯수
int nTail;
int level=80;
int bombX, bombY; 
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Logic()
{
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
	if(0>=x||x>=width||0>y||y>=height) 
	{
		gameOver = true;
	}
	if(x==bombX&&y==bombY)
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
		if (score%3==0)
		{
			if (level >0)
			{
				level -= 20;
			}
		}
		srand(time(NULL));
		feedX = 1 + rand()%(width-2);
		feedY = 1 + rand()%(height-2);
		srand(time(NULL)*2);
		bombX = 1 + rand()%(width-2);
		bombY = 1 + rand()%(height-2);
		
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
	srand(time(NULL));
	nTail=1;
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	feedX = 1 + rand()%(width-2);
	feedY = 1 + rand()%(height-2);
	srand(time(NULL)*3);
	bombX = rand()%(width-2);
	bombY = rand()%(height-2);
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
			else if(i==bombY&&j==bombX)
			{
				cout << "X";
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
	cout << "level : " << (90 - level)/10 << endl;
}
int main()
{
	SetUp();
	while(!gameOver)
	{
		Draw();
		Logic();
		Input();
		Sleep(level);
	}
	return 0;
}
