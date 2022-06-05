#include"display.h"
#include"shape.h"
const int Shape[7][4][4][4];

char pawn(int a){ // Display
if(a==0)
return ' ';
else if (a==1)
return '#';
}




void boardDisplay(int board[ROWS][COLS]){
int i,j,x;
	printf("\n");
	for(i=0;i<ROWS-1;i++){
		printf("           |");
	for(j=0;j<COLS;j++){
		x=board[i][j];
		
		printf(" %c",pawn(x));
	}
	printf("|\n");
	}
	printf("           1 2 3 4 5 6 7 8 9 10 11 12\n");
	printf("\n\n"); 
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
void menu(){
int play;
	printf("\n\x1b[33;5;202m        tttt                                       tttt                              iiii                   \x1b[0m	\n\x1b[36;5;202m      ttt:::t                                    ttt:::t                             i::::i                  \x1b[0m\n\x1b[35;5;202m      t:::::t                                    t:::::t                              iiii                   \x1b[0m\n\x1b[32;5;202m      t:::::t                                    t:::::t                                                      \x1b[0m\n\x1b[31;5;202mttttttt:::::ttttttt        eeeeeeeeeeee    ttttttt:::::ttttttt   rrrrr   rrrrrrrrr  iiiiiii     ssssssssss   \x1b[0m\n\x1b[33;5;202mt:::::::::::::::::t      ee::::::::::::ee  t:::::::::::::::::t   r::::rrr:::::::::r i:::::i   ss::::::::::s  \x1b[0m\n\x1b[36;5;202mt:::::::::::::::::t     e::::::eeeee:::::eet:::::::::::::::::t   r:::::::::::::::::r i::::i ss:::::::::::::s \x1b[0m\n\x1b[35;5;202mtttttt:::::::tttttt    e::::::e     e:::::etttttt:::::::tttttt   rr::::::rrrrr::::::ri::::i s::::::ssss:::::s\x1b[0m\n\x1b[32;5;202m      t:::::t          e:::::::eeeee::::::e      t:::::t          r:::::r     r:::::ri::::i  s:::::s  ssssss \x1b[0m\n\x1b[31;5;202m      t:::::t          e:::::::::::::::::e       t:::::t          r:::::r     rrrrrrri::::i    s::::::s     \x1b[0m \n\x1b[33;5;202m      t:::::t          e::::::eeeeeeeeeee        t:::::t          r:::::r            i::::i       s::::::s  \x1b[0m \n \x1b[36;5;202m     t:::::t    tttttte:::::::e                 t:::::t    ttttttr:::::r            i::::i ssssss   s:::::s \x1b[0m\n \x1b[35;5;202m     t::::::tttt:::::te::::::::e                t::::::tttt:::::tr:::::r           i::::::is:::::ssss::::::s\x1b[0m\n  \x1b[32;5;202m    tt::::::::::::::t e::::::::eeeeeeee        tt::::::::::::::tr:::::r           i::::::is::::::::::::::s \x1b[0m\n\x1b[31;5;202m \x1b[33;5;202m       tt:::::::::::tt  ee:::::::::::::e          tt:::::::::::ttr:::::r           i::::::i s:::::::::::ss  \x1b[0m\n\x1b[36;5;202m          ttttttttttt      eeeeeeeeeeeeee            ttttttttttt  rrrrrrr           iiiiiiii  sssssssssss         \x1b[0m\n" );
printf("\n\x1b[38;5;202m 		***************************************************************************\n 		*                                ___                                      *\n		*     ___  ___  ___  ___  ___   |_  |    | |_  ___    ___ | | ___  _ _    *\n 		*    | . ||  _|| -_||_ -||_ -|   _| |_   |  _|| . |  | . || || .'|| | |   *\n 		*    |  _||_|  |___||___||___|  |_____|  |_|  |___|  |  _||_||__,||_  |   *\n 		*    |_|                                             |_|          |___|   *\n		*                                                                         *\n 		***************************************************************************\n\x1b[0m");
 
scanf("%d",&play);
do{
scanf("%d",&play);
}while(play!=1);
AdjustGame(board);
}

