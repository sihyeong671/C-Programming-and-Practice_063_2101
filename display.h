#ifndef __SCREEN__
#define __SCREEN__

#include "board.h"
#include "snake.h"


class Display
{
	private:
		const int width; // 가로 
		const int height; // 세로 
	public:
		Display(); // 생성자 
		
		void draw_option(); // 키 옵션 그리기  
		void draw_wall(); // 벽 그리기  
		void draw_food(Position pos); // 먹이 그리기  
		void draw_snake(Snake snake); // 뱀 그리기  
		void draw_msg(const char * msg); // 메시지 생성  
		void clear(); // 화면 지우기  
		void draw_bomb(Position pos); // 폭탄 생성  
		
		const int get_width() const; // 가로 반환  
		const int get_height() const; // 세로 반환  
		
};

#endif
