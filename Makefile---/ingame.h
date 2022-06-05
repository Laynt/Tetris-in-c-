#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define COLS 15
#define ROWS 25

void AdjustGame (int board[ROWS][COLS]);
int testSky(int board[ROWS][COLS]);
int testBound(int board[ROWS][COLS]);
int testGround(int board[ROWS][COLS]);
void clearCompleteRow(int board[ROWS][COLS]);
