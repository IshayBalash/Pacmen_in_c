#pragma once
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Classes.h"


const COORD TOPLEFT = { 5,3 };
const COORD TOPRIGHT = { 60,3 };
const COORD BOTTOMLEFT = { 5,25 };
const COORD BOTTOMRIGHT = { 60,25 };


const COORD SecterDoorsArry[12] = {{10,3},{20,3},{40,3},{10,25},{20,25},{40,25},{5,7},{60,7},{5,15},{60,15},{5,22},{60,22}};
const COORD PackmenStartLocation{15,7};
const COORD Gost1StartLocation{12,10};
const COORD Gost2StartLocation{40,19};















void gotoxy(HANDLE hConsoleOutput, short x, short y);
void print_game_Board(HANDLE corsor_for_Board,Packmen A);
void PrintPackmenStat(HANDLE corsor_for_Board, Packmen A);



bool checkIfPackmenInSecredDoor(Packmen A,int dir);
bool IsPacmenInGhostLocation(Packmen Pc, Gost G);
void ResetGame(Packmen* Pc, Gost* GA, Gost* GB, HANDLE corsor_for_Board);
