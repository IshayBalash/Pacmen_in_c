#include "functions.h"
#include"Classes.h"

using namespace std;

int  main()
{
	static HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	Packmen packmen('@',PackmenStartLocation.X,PackmenStartLocation.Y,short(0),short(3));
	Gost go_1('$',Gost1StartLocation.X,Gost1StartLocation.Y);
	Gost go_2('$', Gost2StartLocation.X,Gost2StartLocation.Y);
	print_game_Board(hConsoleOutput,packmen);
	



	

	bool play = true;
	int dir = 0;
	while (play)
	{	
		packmen.move(dir);
		if (_kbhit())
		{
			char ch = _getch();

			if (ch == 97 || ch == 65)
			{
				dir = 1;
			}
			if (ch == 100 || ch == 68)
			{
				dir = 2;
			}
			if (ch == 119 || ch == 87)
			{
				dir = 3;
			}
			if (ch == 88 || ch == 120)
			{
				dir = 4;
			}
			if (ch == 115 || ch == 83)
			{
				dir = 5;
			}
		}

		if (IsPacmenInGhostLocation(packmen, go_1) || IsPacmenInGhostLocation(packmen, go_2))
		{
			ResetGame(&packmen, &go_1, &go_2, hConsoleOutput);
			Sleep(3000);
		}

		go_1.move();
		
		if (IsPacmenInGhostLocation(packmen,go_1) || IsPacmenInGhostLocation(packmen,go_2))
		{
			ResetGame(&packmen,&go_1,&go_2, hConsoleOutput);
			Sleep(3000);
		}

		packmen.move(dir);
		
		if (IsPacmenInGhostLocation(packmen, go_1) || IsPacmenInGhostLocation(packmen, go_2))
		{
			ResetGame(&packmen, &go_1, &go_2, hConsoleOutput);
			Sleep(3000);
		}
		
		go_2.move();
		if (IsPacmenInGhostLocation(packmen, go_1) || IsPacmenInGhostLocation(packmen, go_2))
		{
			ResetGame(&packmen, &go_1, &go_2, hConsoleOutput);
			Sleep(3000);
		}

		if (_kbhit())
		{
			char ch = _getch();
			
			if (ch == 97||ch==65)
			{
				dir = 1;
			}
			if (ch == 100 || ch==68)
			{
				dir = 2;
			}
			if(ch==119|| ch==87)
			{
				dir = 3;
			}
			if(ch==88 || ch==120 )
			{
				dir = 4;
			}
			if(ch==115 || ch==83)
			{
				dir = 5;
			}
		}

	}
	return 0;
}



