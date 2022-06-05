#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "AdjustGame.h"

#define ROWS 25
#define COLS 15

const int Shape[7][4][4][4]={
     {{{0,0,0,0}, 
     {0,0,0,0},
     {0,0,1,0},
     {1,1,1,0}}, // L

     {{0,0,0,0},
     {1,1,0,0},
     {0,1,0,0},
     {0,1,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,1,0},
     {1,0,0,0}},
     
     {{0,0,0,0},
     {1,0,0,0},
     {1,0,0,0},
     {1,1,0,0}}},
     /////////////////////////////////
     {{{1,0,0,0}, 
     {1,0,0,0},
     {1,0,0,0},
     {1,0,0,0}}, // straight

     {{0,0,0,0},
     {0,0,0,0},
     {0,0,0,0},
     {1,1,1,1}},

     {{1,0,0,0},
     {1,0,0,0},
     {1,0,0,0},
     {1,0,0,0}},
     
     {{1,0,0,0},
     {1,0,0,0},
     {1,0,0,0},
     {1,0,0,0}}},
     /////////////////////////////////
     {{{0,0,0,0}, 
     {0,0,0,0},
     {1,1,0,0},
     {1,1,0,0}}, // square

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,0,0},
     {1,1,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,0,0},
     {1,1,0,0}},
     
     {{0,0,0,0},
     {0,0,0,0},
     {1,1,0,0},
     {1,1,0,0}}},
      /////////////////////////////////
     {{{0,0,0,0}, 
     {0,0,0,0},
     {1,0,0,0},
     {1,1,1,0}},    // reverse L

     {{0,0,0,0},
     {0,1,0,0},
     {0,1,0,0},
     {1,1,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,1,0},
     {0,0,1,0}},
    
     {{0,0,0,0},
     {1,1,0,0},
     {1,0,0,0},
     {1,0,0,0}}},
      /////////////////////////////////
     {{{0,0,0,0}, 
     {0,0,0,0},
     {0,1,0,0},
     {1,1,1,0}},    // T

     {{0,0,0,0},
     {0,1,0,0},
     {1,1,0,0},
     {0,1,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,1,0},
     {0,1,0,0}},
     
     {{0,0,0,0},
     {1,0,0,0},
     {1,1,0,0},
     {1,0,0,0}}},
      /////////////////////////////////
     {{{0,0,0,0}, 
     {0,0,0,0},
     {0,1,1,0},
     {1,1,0,0}},    // Z

     {{0,0,0,0},
     {1,0,0,0},
     {1,1,0,0},
     {0,1,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {0,1,1,0},
     {1,1,0,0}},
     
     {{0,0,0,0},
     {0,0,0,0},
     {0,1,1,0},
     {1,1,0,0}}},
      /////////////////////////////////
     {{{0,0,0,0}, 
     {0,0,0,0},
     {1,1,0,0},
     {0,1,1,0}},    // Reverse Z

     {{0,0,0,0},
     {0,1,0,0},
     {1,1,0,0},
     {1,0,0,0}},

     {{0,0,0,0},
     {0,0,0,0},
     {1,1,0,0},
     {0,1,1,0}},
     
     {{0,0,0,0},
     {0,0,0,0},
     {1,1,0,0},
     {0,1,1,0}}}};


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
     for(int i=0;i<4;i++){
        for(int j=1;j<COLS-2;j++){
            if(board[i][j] != 0)return 1;

        }
    }
}






void AdjustGame (int board[ROWS][COLS]){
int i,j,p,col,k, score=0;
int t = 0;

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
t++;
}while ((SkyMax(board) ==0) && (Bord(board) == 1));
if(SkyMax(board) == 1)printf(" You reached the sky ! Game Over !\n");
}



void CreateType(int play3){ 
int i,j;
int l;
printf ("Type 1 :   Type 2 :   Type 3 :   Type 4 :\n" );
for (j=0; j<4; j++){
	for (i=0; i<4;i++){
			
		for (l=0; l<4;l++){
		if (Shape[play3][i][j][l] == 1){
			printf(" #");
		}
		else{
			printf(" .");
		} 
	
		}printf("    ");
			
	}printf("\n");
	
                    }

}


  
  
  
      
void SetShape(int board[ROWS][COLS],int col,int type,int position){ //  Set the shape
 
    int align = 0;
    int k=0 ;
    int i, j, h;
    

    for(i = 4;i<ROWS;i++){   //collision
     for(h =4;h>0;h--){
      for(j = 0;j<4;j++){
       if((board[i][col+j]) == 1 && (Shape[type][position-1][h][j]) == 1 && (k == 0)){
         align = i-h+3;
         k =1;
        }
       }
      }
     }


    for(i = 0;i<4;i++){     // Set the Shape on the board
     for(j=0;j<4;j++){
       if(board[(align-4)+i][col+j] == 0){
        board[(align-4)+i][col+j] = Shape[type][position-1][i][j];
       }    
      }
     }


}
         





      
char pawn(int a){ // Display
if(a==0)
return ' ';
else if (a==1)
return '#';
}
void boardDisplay(int board[ROWS][COLS]){ 
int i,j,x;
	printf("\n");
	for(i=4;i<ROWS-1;i++){
		printf("           |");
	for(j=0;j<COLS;j++){
		x=board[i][j];
		
		printf(" %c",pawn(x));
	}
	printf("|\n");
	}
	printf("          1 2 3 4 5 6 7 8 9 10 11 12 13 14 15\n");
	printf("\n\n"); 
//printf("\n 1 2 3 4 5 6 7 8 9 10\n");
}

void ShowShape(int play){

int i,j,l,s;
printf("\n");
printf(" 						Shape : \n");
printf(" 			 			 _________\n						|         |\n");


	for (i=0; i<4;i++){
		printf("						|");
		for (l=0; l<4;l++){
		if (Shape[play][0][i][l] == 1){
			printf(" #");
		}
		else{
			printf("  ");
			
		} 
		
		}printf(" |");
		
		do{
		printf("\n");
		s++;
		}while(s<4);
			
	}printf("						|");
	printf("_________");
	printf("|");
	printf("\n");
      }

int main(){ 
int i,j,p,col;
int board[ROWS][COLS]={0};
for (int j=0;j<COLS;j++){
	board[ROWS-1][j]= 1 ; 
	}

AdjustGame(board);



    



return 0;
}






