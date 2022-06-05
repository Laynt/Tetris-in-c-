#include"display.h"
#include"shape.h"
#include"ingame.h"


int main(){ 
int i,j,p,col;
menu();
int board[ROWS][COLS]={0};
for (int j=0;j<COLS;j++){
	board[ROWS-1][j]= 1 ; 
}
menu();
AdjustGame(board);

return 0;
}
