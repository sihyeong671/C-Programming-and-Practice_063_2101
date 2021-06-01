#ifndef __SNAKE_GAME__
#define __SNAKE_GAME__

#include "board.h"
#include "display.h"
#include "snake.h"
#include <string>
#include "DataSave.h"

class SnakeGame
{
	private:
		Snake snake_; // �� ��ü ����  
		Position food_pos; // ���� ��ǥ ����ü  
		Position bomb_pos; // ��ź ��ǥ ����ü  
		Display display; // ȭ��  
		int score; // ����  
		int GAME_SPEED; // ���� �ӵ�  
		int level; // ���̵�  
		bool check; // ���̵� �ø��� ������� üũ �ϴ� �Լ�  
		string userID; // ���� �̸� 
	public:
		SnakeGame(string ID); // ������  
		
		void Initialize(); // �ʱ�ȭ  
		
		bool is_no_food(); // ���� �ִ��� Ȯ��  
		bool is_no_bomb(); // ��ź �ִ��� Ȯ��, ���� ���� �� ���� �ʱ�ȭ ��  
		bool is_vaild_food_position(int x, int y); // ���̰� ����� �� ��ġ�� �����Ǿ����� Ȯ��  
		bool is_vaild_bomb_position(int x, int y); // ��ź�� ����� �� ��ġ�� �����Ǿ����� Ȯ��  
		ReturnCode pause(); // ���� �Ͻ�����  
		ReturnCode start(); // ���� �ʱ�ȭ  
		ReturnCode play(); // ���� ����  
		ReturnCode stop(); // ���� ����  
		
		void make_food(); // ���� ����  
		void make_bomb(); // ��ź ����  

};

#endif
