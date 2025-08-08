#include <stdio.h>

void printboard(int board[9]){
	printf("\n ");
	for(int i = 0;i<9;i++){
		if(board[i] == 0) printf(" ");
		if(board[i] == 1) printf("O");
		if(board[i] == 2) printf("X");
		if((i+1)%3 == 0 && i != 8) printf("\n--- --- ---\n ");
		if((i+1)%3 != 0) printf(" | ");

	}
printf("\n\n");
}

void taketurn(int playerid, int board[9]){
		int spot;
		printf("Player %d's turn, choose your spot : ",playerid);
		scanf("%d", &spot);
		board[spot-1] = playerid;
		printboard(board);
}

int checkwin(int board[9]){
	if(board[0] == board[1] && board[0] == board[2] && board[0] != 0) return board[0];
	else if(board[3] == board[4] && board[3] == board[5] && board[3] != 0) return board[3];
	else if(board[6] == board[7] && board[6] == board[8] && board[6] != 0) return board[6];
	else if(board[0] == board[4] && board[0] == board[8] && board[0] != 0) return board[0];
	else if(board[2] == board[4] && board[2] == board[6] && board[2] != 0) return board[2];
	else if(board[0] == board[3] && board[0] == board[6] && board[0] != 0) return board[0];
	else if(board[1] == board[4] && board[1] == board[7] && board[1] != 0) return board[1];
	else if(board[2] == board[5] && board[2] == board[8] && board[2] != 0) return board[2];
	else return 0;
}	

void main(){
	int board[9] = {0,0,0,0,0,0,0,0,0};
	printboard(board);
	int turn = 1;
	while(checkwin(board)==0){
		taketurn(turn,board);
		if(turn == 1) turn = 2;
		else if(turn == 2) turn = 1;
	}
	printf("Player %d wins!\n", checkwin(board));
	
}
