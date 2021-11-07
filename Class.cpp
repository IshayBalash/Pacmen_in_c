
#include "functions.h"
#include "Classes.h"


using namespace std;


	object::object(char indexator, short Sx, short Sy)
	{
		this->corse_for_Board = GetStdHandle(STD_OUTPUT_HANDLE);
		this->StartXcor = Sx;
		this->xcord=Sx;
		this->ycord =Sy;
		this->StartYcord = Sy;
		this->indicator = indexator;
	}
	/*
	object::object(const object& old)
	{
		this->indicator = old.indicator;
		this->StartXcor = old.StartXcor;
		this->xcord = old.StartXcor;
		this->StartYcord = old.StartYcord;
		this->ycord = old.StartYcord;
		this->corse_for_Board = old.corse_for_Board;
	}
	*/


	void object::move_Left(int x)
	{
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << this->indicator << endl;
		Sleep(x);
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << " " << endl;
		--this->xcord;
		if (this->xcord < TOPLEFT.X + 1)
		{
			this->xcord = TOPRIGHT.X - 1;
		}
	}
	void object::move_Right(int x)
	{
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << this->indicator << endl;
		Sleep(x);
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << " " << endl;
		++this->xcord;
		if (this->xcord > TOPRIGHT.X - 1)
		{
			this->xcord = TOPLEFT.X + 1;
		}
	}
	void object::move_Down(int x)
	{
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << this->indicator << endl;
		Sleep(x);
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << " " << endl;
		++this->ycord;
		if (this->ycord > BOTTOMLEFT.Y - 1)
		{
			this->ycord = TOPLEFT.Y + 1;
		}
	}
	void object::move_Up(int x)
	{
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << this->indicator << endl;
		Sleep(x);
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << " " << endl;
		--this->ycord;
		if (this->ycord < TOPRIGHT.Y + 1)
		{
			this->ycord = BOTTOMLEFT.Y - 1;
		}
	}
	void object::stayFoot(int x)
	{
		gotoxy(this->corse_for_Board, this->xcord, this->ycord);
		cout << this->indicator << endl;
		Sleep(x);
	}
	int object::GetXcord()
	{
		return this->xcord;
	}
	int object::GetYcord()
	{
		return this->ycord;
	}
	
	void object::ResetStartLocation(HANDLE corsor_for_Board)
	{
		COORD dwCursorPosition;
		dwCursorPosition = {this->xcord,this->ycord};
		//dwCursorPosition = { this->StartXcor,this->StartYcord};
		SetConsoleCursorPosition(corsor_for_Board, dwCursorPosition);
		cout <<" ";
		//cout << this->indicator;
		


		short x = this->StartXcor;
		this->xcord = x;
		short y = this->StartYcord;
		this->ycord = y;
	}



	Packmen::Packmen(char indexator, short Sx, short Sy, short score, short lives) :object(indexator, Sx, Sy)
	{
		this->set_Lives(lives);
		this->set_Score(score);
	}
	
	/*
	Packmen::Packmen(const Packmen& old): object(old)
	{
		cout << "in copy!!!!!";
		this->Lives = old.Lives;
		this->Score = old.Score;
	}
	*/


	void Packmen::set_Score(short i)
	{
		this->Score = i;
	}
	short Packmen::get_Score()
	{
		return this->Score;
	}
	void Packmen::set_Lives(short i)
	{
		this->Lives = i;
	}
	short Packmen::get_Lives()
	{
		return this->Lives;
	}
	void Packmen::move(int dir)
	{
		bool IsInSecretDoor = checkIfPackmenInSecredDoor(*this, dir);
		if (dir == 0)
		{
			object::stayFoot(200);
		}
		else if (dir == 1)
		{
			if(this->GetXcord()==TOPLEFT.X+1 && !IsInSecretDoor)
			{
				object::stayFoot(5);
			}
			else
			{
				object::move_Left(200);
			}
			
		}
		else if (dir == 2)
		{
			if(this->GetXcord()==TOPRIGHT.X-1 && !IsInSecretDoor)
			{
				object::stayFoot(5);
			}
			else
			{
				object::move_Right(200);
			}
		}
		else if (dir == 3)
		{
			if(this->GetYcord()==TOPRIGHT.Y+1 && !IsInSecretDoor)
			{
				object::stayFoot(5);
			}
			else
			{
				object::move_Up(200);
			}
		}
		else if (dir == 4)
		{
			if(this->GetYcord()==BOTTOMRIGHT.Y-1 && !IsInSecretDoor)
			{
				object::stayFoot(5);
			}
			else
			{
				object::move_Down(200);
			}
		}
		else if (dir == 5)
		{
			object::stayFoot(200);
		}
		object::stayFoot(5);
	}
	
	

	Gost::Gost(char indexator, short Sx, short Sy) :object(indexator, Sx, Sy) {};
	int Gost::setRandDir()
	{
		int arr[] = { 1, 2, 3, 4 };
		int x = rand() % 4;	// Generating random index 
		return x;

	}
	void Gost::move()
	{
		int dir = setRandDir();
		if (dir == 1)
		{
			if(this->GetXcord() == TOPLEFT.X + 1)
			{
				object::move_Right(200);
			}
			else
			{
				object::move_Left(200);
			}
		}
		else if (dir == 2)
		{

			if (this->GetXcord() == TOPRIGHT.X - 1)
			{
				object::move_Left(200);
			}
			else
			{
				object::move_Right(200);
			}
		}
		else if (dir == 3)
		{
			if (this->GetYcord() == TOPRIGHT.Y + 1)
			{
				object::move_Down(200);
			}
			else
			{
				object::move_Up(200);
			}
		}
		else if (dir == 4)
		{
			if (this->GetYcord() == BOTTOMRIGHT.Y - 1)
			{
				object::move_Up(200);
			}
			else
			{
				object::move_Down(200);
			}
		}
		object::stayFoot(10);
	}


