#include "board.h"
#include "game.h"

int main()
{
	system("mode con cols=120 lines=31 | title snakegame");
	SnakeGame game("test");
	ReturnCode ret;
	
	while(true)
	{
		ret = game.start();
		if (ret != RETURN_SUCCESS)
		{
			return 0;
		}
		
		ret = game.play();
		if (ret == RETURN_NEWGAME)
			continue;
		else if (ret == RETURN_EXIT)
			return 0;
		else if ((ret != RETURN_STOP)&&(ret != RETURN_SUCCESS))
			return 0;
			
		game.stop();
		
		break;
	}
	
	return 0;}


