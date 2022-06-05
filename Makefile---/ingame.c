#include"ingame.h"

void AdjustGame (int board[ROWS][COLS]){
int i,j,p,col,k, score=0;
int t = 0;

do {
	 for(int i = 0; i<4;i++){
            if(testGround(board) != 0){
                clearCompleteRow(board);
                score = score + 100;                   //score calculation
            }
        }
	srand(time(NULL));
	k= rand () % 7;
	ShowShape(k);
	boardDisplay(board);
	CreateType(k);
	
	do{
            printf("Take your Type (1,2,3,4): "); 
            scanf("%d",&p);
        } while(p < 0 || p > 4);
        
        do{
            printf("\nChoose a column (1 to 10): ");    // ask Collumn 
            scanf("%d",&col);
        } while(col < 0 || col > 12);
       
	SetShape(board,col,k,p);
	
	printf(" ----------------------------------------------------------------------------------\n");
        //deleteRows(board);






	if (testBound(board) == 0)printf("Oops ! You are out of bounds! Game Over !\n"); // Out of bounds left or right 
t++;
}while ((testSky(board) ==0) && (testBound(board) == 1));
if(testSky(board) == 1)printf("Seems that you reached the sky ! Game Over !\n");
}

int testSky(int board[ROWS][COLS]){      // checks if the shape has reached top bound
     for(int i=0;i<4;i++){
        for(int j=1;j<COLS-2;j++){
            if(board[i][j] != 0)return 1;

        }
    }
}

int testBound(int board[ROWS][COLS]){// checks if the shape is out of bounds (left/right)
    for(int i =4;i<ROWS-1;i++){
        if(board[i][0] == 1)return 0;
        else if(board[i][COLS-1] == 1)return 0;

    }
    return 1;
}

int testGround(int board[ROWS][COLS]){       
        //compte le nombre de lignes à clear
    int count = 0,clear=0;
    for(int j=4;j<ROWS-1;j++){ 
        for(int i=1;i<COLS-1;i++)if(board[j][i] == 1 )count++; 
        clear = j;
        if(count == 9)return clear;
        count = 0;
    }
    return 0;
}

void clearCompleteRow(int board[ROWS][COLS])
	{                  
	for(int i = testGround(board); i>0;i--){             
		for(int j = 1;j<COLS-1;j++){                 
			board[i][j] = board[i-1][j];             
}         
}      
}

