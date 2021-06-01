#ifndef __SNAKE__
#define __SNAKE__

#include "board.h"
#include <list>

using namespace std;

class Snake
{
	private:
		int direction; // 방향  
		list<Position> body_; // 뱀 list 객체  
		
	public:
		Snake(); // 생성자  
		
		void Initialize(); // 길이, 위치 초기화  
		void SetDirection(Key key); // 방향 설정  
		void Move(); // 움직임  
		bool is_bitten(); // 머리가 몸 부분에 닿았는지 확인  
		
		list<Position>& body(); // 뱀 객체 반환  

		const Position head() const; // 뱀 머리 좌표 반환  
		const Position tail() const; // 뱀 꼬리 좌표 반환  
		
		void move_up(); // 위로 이동  
		void move_down(); // 아래로 이동  
		void move_right(); // 오른쪽으로 이동  
		void move_left(); // 왼쪽으로 이동  
		const int get_direction() const; // 방향 반환  

};

#endif
