#ifndef __SNAKE__
#define __SNAKE__

#include "board.h"
#include <list>

using namespace std;

class Snake
{
	private:
		int direction; // ����  
		list<Position> body_; // �� list ��ü  
		
	public:
		Snake(); // ������  
		
		void Initialize(); // ����, ��ġ �ʱ�ȭ  
		void SetDirection(Key key); // ���� ����  
		void Move(); // ������  
		bool is_bitten(); // �Ӹ��� �� �κп� ��Ҵ��� Ȯ��  
		
		list<Position>& body(); // �� ��ü ��ȯ  

		const Position head() const; // �� �Ӹ� ��ǥ ��ȯ  
		const Position tail() const; // �� ���� ��ǥ ��ȯ  
		
		void move_up(); // ���� �̵�  
		void move_down(); // �Ʒ��� �̵�  
		void move_right(); // ���������� �̵�  
		void move_left(); // �������� �̵�  
		const int get_direction() const; // ���� ��ȯ  

};

#endif
