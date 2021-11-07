#define _CRT_SECURE_NO_WARNINGS
#include "functions.h";


using namespace std;




void gotoxy(HANDLE hConsoleOutput, short x, short y)
{
	COORD dwCursorPosition = { x, y };
	cout.flush();
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}

void PrintPackmenStat(HANDLE corsor_for_Board, Packmen A)
{
	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition = {0,0};
	SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);

	
	cout << "\r";
	cout << "                              ";
	cout << "\r";
	cout << "Game Status:"<<endl;

	cout << "\r";
	cout << "                              ";
	cout << "\r";
	cout << "lives:" << A.get_Lives() << endl;

	cout << "\r";
	cout << "                              ";
	cout << "\r";
	cout << "score:" << A.get_Score() << endl;
}


void print_game_Board(HANDLE corsor_for_Board, Packmen A)
{

	PrintPackmenStat(corsor_for_Board,A);
	COORD dwCursorPosition;
	short i;
	for (i = TOPLEFT.X; i <= TOPRIGHT.X; i++)
	{
		cout.flush();
		dwCursorPosition = { i,TOPLEFT.Y };
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout << "- ";
	}

	for (i = BOTTOMLEFT.X; i <= BOTTOMRIGHT.X; i++)
	{
		cout.flush();
		dwCursorPosition = { i,BOTTOMLEFT.Y };
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout << "- ";
	}

	for (i = TOPLEFT.Y; i <= BOTTOMLEFT.Y; i++)
	{
		cout.flush();
		dwCursorPosition = { TOPLEFT.X,i };
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout << "|";
	}

	for (i = TOPLEFT.Y; i <= BOTTOMLEFT.Y; i++)
	{
		cout.flush();
		dwCursorPosition = { TOPRIGHT.X,i };
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout << "|";
	}
	for (auto i : SecterDoorsArry)
	{
		cout.flush();
		dwCursorPosition = {i.X,i.Y};
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout << " ";

	}




}


bool checkIfPackmenInSecredDoor(Packmen A,int dir)
{
	int Xcord = A.GetXcord();
	int Ycord = A.GetYcord();
	for (auto i : SecterDoorsArry)
	{

		if(dir==1)
		{
			if (Xcord == i.X+1 && Ycord == i.Y)
			{
				return true;
			}	
		}
		if(dir==2)
		{
			if(Xcord ==i.X-1 && Ycord ==i.Y)
			{
				return true;
			}
		}
		else if(dir==3)
		{
			if (Xcord == i.X && Ycord == i.Y + 1)
			{
				return true;
			}
		}
		else if(dir==4)
		{
			if (Xcord == i.X && Ycord == i.Y-1)
			{
				return true;
			}	
		}
	}
	return false;
}

bool IsPacmenInGhostLocation(Packmen Pc, Gost G)
{
	if(Pc.GetXcord()==G.GetXcord() && Pc.GetYcord()==G.GetYcord())
	{
		return true;
	}
	return false;

}

void ResetGame(Packmen* Pc,Gost* GA,Gost* GB, HANDLE corsor_for_Board)
{
	short lives = Pc->get_Lives() - 1;
	Pc->set_Lives(lives);
	if (Pc->get_Lives() == 0)
	{
		system("CLS");
		cout << "Good-Bye" << endl;
		exit(0);
		return;
	}

	COORD dwCursorPosition;
	cout.flush();
	dwCursorPosition = {0,0};
	SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
	cout << "\r";
	cout << "                              ";
	cout << "\r";
	cout << "-----You Lost a life------" << endl;

	cout << "\r";
	cout << "                              ";
	cout << "\r";
	cout << "------be beteer-----------";
	Sleep(1500);
	Pc->ResetStartLocation(corsor_for_Board);
	GA->ResetStartLocation(corsor_for_Board);
	GB->ResetStartLocation(corsor_for_Board);
	PrintPackmenStat(corsor_for_Board,*Pc);
	
	
}




	






