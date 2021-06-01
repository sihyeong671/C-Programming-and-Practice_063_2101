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
		Snake snake_; // 뱀 객체 생성  
		Position food_pos; // 먹이 좌표 구조체  
		Position bomb_pos; // 폭탄 좌표 구조체  
		Display display; // 화면  
		int score; // 점수  
		int GAME_SPEED; // 게임 속도  
		int level; // 난이도  
		bool check; // 난이도 올리는 경우인지 체크 하는 함수  
		string userID; // 유저 이름 
	public:
		SnakeGame(string ID); // 생성자  
		
		void Initialize(); // 초기화  
		
		bool is_no_food(); // 먹이 있는지 확인  
		bool is_no_bomb(); // 폭탄 있는지 확인, 먹이 먹을 때 같이 초기화 됨  
		bool is_vaild_food_position(int x, int y); // 먹이가 제대로 된 위치에 생성되었는지 확인  
		bool is_vaild_bomb_position(int x, int y); // 폭탄이 제대로 된 위치에 생성되었는지 확인  
		ReturnCode pause(); // 게임 일시정지  
		ReturnCode start(); // 게임 초기화  
		ReturnCode play(); // 게임 시작  
		ReturnCode stop(); // 게임 종료  
		
		void make_food(); // 먹이 생성  
		void make_bomb(); // 폭탄 생성  

};

#endif
