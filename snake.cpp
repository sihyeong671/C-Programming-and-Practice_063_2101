#include <iostream>
# include <cstdlib>
#include <conio.h>

using namespace std;
const int width = 20;
const int height = 20;
bool gameOver;
int x,y,feedX,feedY,score;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Logic()
{
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
	if(x==feedX&&y==feedY)
	{
		score++;
		feedX = rand()%width;
		feedY = rand()%height;
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
				cout << " ";
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
	}
	return 0;
}
