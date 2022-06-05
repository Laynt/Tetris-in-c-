int Ground(int board[ROWS][COLS]){       
   
    int count = 0,clear=0;
    for(int j=4;j<ROWS-1;j++){ // count all of the the Row for a clear
        for(int i=1;i<COLS-1;i++)if(board[j][i] == 1 )count++; 
        clear = j;
        if(count == 10)return clear;
        count = 0;
    }
    return 0;
}

void RowComplete(int board[ROWS][COLS]) // took of the complete row
	{                  
	for(int i = Ground(board); i>0;i--){             
		for(int j = 1;j<COLS-1;j++){                 
			board[i][j] = board[i-1][j];             
}         
}      
}

int Bord(int board[ROWS][COLS]){ // verify if the shape is out of the border or not
    for(int i =4;i<20;i++){
        if(board[i][0] == 1)return 0;
        else if(board[i][14] == 1)return 0;

    }
    return 1;
}

int SkyMax(int board[ROWS][COLS]){      //Check if the shape reach the sky
     for(int i=0;i<2;i++){
        for(int j=1;j<COLS-2;j++){
            if(board[i][j] != 0)return 1;

        }
    }
}






void AdjustGame(int board[ROWS][COLS]){
int i,j,p,col,k, score=0;

do {
	 for(int i = 0; i<4;i++){
            if(Ground(board) != 0){
                RowComplete(board);
                score = score + 100;                   //score 
            }
        }
	srand(time(NULL));
	k= rand () % 7;
	 printf("\n\nScore : %d\n",score);
	
	ShowShape(k);
	boardDisplay(board);
	CreateType(k);
	
	do{
            printf("Take your Type (1,2,3,4): "); 
            scanf("%d",&p);
        } while(p < 0 || p > 4);
        
        do{
            printf("\nChoose a column (0 to 14): ");    // ask Collumn 
            scanf("%d",&col);
        } while(col < 1 || col > 12);
       
	SetShape(board,col,k,p);
	
	printf(" ----------------------------------------------------------------------------------\n");
        //deleteRows(board);






	if (Bord(board) == 0)printf("You are out of bounds! Game Over !\n"); // Out of bounds left or right 

}while ((SkyMax(board) ==0) && (Bord(board) == 1));
if(SkyMax(board) == 1)printf(" You reached the sky ! Game Over !\n");
}
