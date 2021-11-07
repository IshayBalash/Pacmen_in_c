#pragma once
#include "functions.h"



class object
{
private:
	char indicator;
	short xcord;
	short ycord;
	short StartXcor;
	short StartYcord;
public:
	object(char indexator, short Sx, short Sy);
	//object(const object& old);
	HANDLE corse_for_Board;
	void move_Left(int x);
	void move_Right(int x);
	void move_Down(int x);
	void move_Up(int x);
	void stayFoot(int x);
	int GetXcord();
	int GetYcord();
	void ResetStartLocation(HANDLE corsor_for_Board);
	
};




class Packmen : public object
{
private:
	short Lives;
	short Score;
public:
	Packmen(char indexator, short Sx, short Sy, short score, short lives);
	//Packmen(const Packmen& old);
	void set_Score(short i);
	short get_Score();
	void set_Lives(short i);
	short get_Lives();
	void move(int dir);
};



class Gost :public object
{
public:
	Gost(char indexator, short Sx, short Sy);
	int setRandDir();
	void move();
};



