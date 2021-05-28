#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

const char hideChar = '.';
const char bombChar = '*';
const char flagChar = '#';

int introduction();
int scoreCalculator(char**, char**, int);
void showMines(char**, char**, int, int, int);
int submit(char**, char**, int, int, int);
void undoFlag(char**, int, int, int);
void flagLocation(char**, int, int, int);
void foundZero(int, int, char**, char**, int);
int openLocation(char**, char**, int, int, int);
void displayAnyBoard(char**, int);
int countFlags(char**, int);
int countMines(char**, int);
void createDisplayBoard(char**, int);
void createHints(int, int, char**, int);
void createMines(char**, int, int);
void createLogicBoard(char**, int);
void initialBoard(char**, int);

void main(){
	clrscr();
	int n, mcount, fcount, choice, lost=0, gameover=0, score, moves=0;
	
	n = introduction();
	
	char** logicBoard = new char*[n];
	char** displayBoard = new char*[n];
	for(int i=0; i<n; i++){
		logicBoard[i] = new char[n];
		displayBoard[i] = new char[n];
	}
	
	initialBoard(logicBoard, n);
	initialBoard(displayBoard, n);
	
	createLogicBoard(logicBoard, n);
	createDisplayBoard(displayBoard, n);
	
	mcount = countMines(logicBoard, n);
	
	/*displayAnyBoard(logicBoard, n);
	cout<<"\n mines = "<<mcount<<"\n";
	cout<<"\n\tPress Enter to continue...";
	getch();*/
	
	while(!gameover && !lost){
		clrscr();
		fcount = countFlags(displayBoard, n);
	
		cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
		cout<<" Mines = "<<mcount<<"\t"<<" Flags = "<<fcount<<"\n";
		displayAnyBoard(displayBoard, n);
		cout<<"\n Press 1 to open a position\n Press 2 to Flag a position\n Press 3 to Undo Flag\n Press 4 to Submit\n\n CHOICE: ";
		cin>>choice;
		
		switch(choice){
			case 1:
				lost = openLocation(logicBoard, displayBoard, n, mcount, fcount);
				break;
			case 2:
				flagLocation(displayBoard, n, mcount, fcount);
				break;
			case 3:
				undoFlag(displayBoard, n, mcount, fcount);
				break;
			case 4:
				gameover = submit(logicBoard, displayBoard, n, mcount, fcount);
				if(gameover == -1){
					lost = 1;
				}
				moves--;
				break;
			default:
				cout<<"\n\t\tEnter a valid Choice!!\n\t\tPress Enter to continue...";
				getch();
				break;
		}
		moves++;
	}
	
	if(lost == 1){
		score = scoreCalculator(logicBoard, displayBoard, n);
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t  GAME OVER\n\n";
		cout<<"\t\t\tThank you for playing the game\n\t\t\t\t  Moves: "<<moves<<"\n\t\t\t\tYou scored: "<<score<<"\n\n\t\t\t    Press Enter to Exit...";
		getch();
	}
	if(gameover == 1){
		score = scoreCalculator(logicBoard, displayBoard, n);
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t  GAME OVER\n\n";
		cout<<"\t\t\tCongrtulations!! You won the game\n\t\t\t\t  Moves: "<<moves<<"\n\t\t\t\tYou scored: "<<score<<"\n\n\t\t\t    Press Enter to Exit...";
		getch();
	}
}

int introduction(){
	int n;
	cout<<"\n\n\n\n\n\n\n\t\t\t\tM I N E S W E E P E R\n";
	delay(1500);
	
	clrscr();
	cout<<"\n\t\t\t\tI N T R O D U C T I O N\n\nThis is the minesweeper game, in this game the mines are hidden at random       locations in the board and the player needs to find out these locations with thehelp of numbers hidden in the board and each number indicates the number of minepresent around them and flag all the locations of mines to win the game but, be aware if any mine explodes, it will genrate a chain reaction and explode all themines present in the board and you may lose the game.\nHope you enjoy playing this game..\n\n";
	cout<<"Enter Size of Board: ";
	cin>>n;
	clrscr();
	
	return n;
}

int scoreCalculator(char** lboard, char** dboard, int n){
	int counter=0;
	for(int p=0; p<n; p++){
		for(int q=0; q<n; q++){
			if(dboard[p][q] == flagChar && lboard[p][q] == bombChar){
				counter += 10;
			}
			if(dboard[p][q] != hideChar && lboard[p][q] != bombChar){
				counter++;
			}
		}
	 }
	return counter;
}
void showMines(char** lboard, char** dboard, int n, int mcount, int fcount){
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	
	for(int p=0; p<n; p++){
		for(int q=0; q<n; q++){
			if(lboard[p][q] == bombChar && dboard[p][q] != flagChar){
				dboard[p][q] = lboard[p][q];
			}
		}
	 }
	
	displayAnyBoard(dboard, n);
}

int submit(char** lboard, char** dboard, int n, int mcount, int fcount){
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	displayAnyBoard(dboard, n);
	
	if(fcount == mcount){
		int counter = 0;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(lboard[i][j] == bombChar && dboard[i][j] == flagChar){
					counter++;
				}
			}
		}
		if(fcount == counter){
			return 1;
		}
		else{
			return -1;
		}
	}
	else if(fcount < mcount){
		lable1:
		cout<<"\n\t\tYou Have not Flagged all mines!!\n\tPress y submit anyway n to continue game...";
		if(getch() == 'y' || getch() == 'Y'){
			return -1;
		}
		else if(getch() == 'n' || getch() == 'N'){
			return 0;
		}
		else{
			goto lable1;
		}
	}
	else{
		lable2:
		cout<<"\n\t\tYou Flaged more than number of mines!!\n\tPress y submit anyway n to continue game...";
		if(getch() == 'y' || getch() == 'Y'){
			return -1;
		}
		else if(getch() == 'n' || getch() == 'N'){
			return 0;
		}
		else{
			goto lable2;
		}
	}
}

void foundZero(int x, int y, char** lboard, char** dboard, int n){
	if(dboard[x][y] == hideChar && lboard[x][y] != bombChar && x >= 0 && x <= n-1 && y >= 0 && y <= n-1){
		dboard[x][y] = lboard[x][y];
		if(lboard[x][y] == '0'){
			foundZero(x, y-1, lboard, dboard, n);	   //left
			foundZero(x, y+1, lboard, dboard, n);          //right
			foundZero(x-1, y-1, lboard, dboard, n);	   //top left
			foundZero(x-1, y, lboard, dboard, n);          //top
			foundZero(x-1, y+1, lboard, dboard, n);        //top right
			foundZero(x+1, y-1, lboard, dboard, n);        //bottom left
			foundZero(x+1, y, lboard, dboard, n);          //bottom
			foundZero(x+1, y+1, lboard, dboard, n);        //bottom right
		}
	}
}

void undoFlag(char** dboard, int n, int mcount, int fcount){
	int ei, ej;
	
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	displayAnyBoard(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1){
		if(dboard[ei][ej] == flagChar){
			dboard[ei][ej] = hideChar;
		}
		else{
			if(dboard[ei][ej] == hideChar){
				cout<<"\n\t\tLocation not Flaaged!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				//goto label;
			}
		}
	}
	else{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		goto label;
	}
}

void flagLocation(char** dboard, int n, int mcount, int fcount){
	int ei, ej;
	
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	displayAnyBoard(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1){
		if(dboard[ei][ej] == hideChar){
			dboard[ei][ej] = flagChar;
		}
		else{
			if(dboard[ei][ej] == flagChar){
				cout<<"\n\t\tLocation alredy Flaaged!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				//goto label;
			}
		}
	}
	else{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		goto label;
	}
}

int openLocation(char** lboard, char** dboard, int n, int mcount, int fcount){
	int ei, ej;
	
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flags = "<<fcount<<"\n";
	displayAnyBoard(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1){
		if(dboard[ei][ej] == hideChar && lboard[ei][ej] != '0' && lboard[ei][ej] != bombChar){
			dboard[ei][ej] = lboard[ei][ej];
		}
		else{
			if(dboard[ei][ej] == hideChar && lboard[ei][ej] == '0'){
				foundZero(ei, ej, lboard, dboard, n);
			}
			else if(dboard[ei][ej] == hideChar && lboard[ei][ej] == bombChar){
				showMines(lboard, dboard, n, mcount, fcount);
				cout<<"\n\t\tYou Hit a Mine!!\n\t\tPress Enter to view results...";
				getch();
				return 1;
			}
			else if(dboard[ei][ej] == flagChar){
				cout<<"\n\t\tCannot open Flaged Location!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
		}
	}
	else{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		//goto label;
	}
	return 0;
}

void displayAnyBoard(char** board, int n){
	cout<<"\n       ";
	for(int k=0; k<n; k++){
		if(k<10){
			cout<<" "<<k<<" ";
		}
		else{
			cout<<k<<" ";

		}
	}
	cout<<"\n     __";
	for(k=0; k<n; k++){
		cout<<"___";
	}
	cout<<"__\n    |";
	for(k=0; k<n; k++){
		cout<<"   ";
	}
	cout<<"    |\n";
	for(int i=0; i<n; i++){
		if(i<10){
			cout<<" "<<i<<"  |  ";
		}
		else{
			cout<<i<<"  |  ";
		}
		for(int j=0; j<n; j++){
			cout<<" "<<board[i][j]<<" ";
		}
		cout<<"  |  \n";
	}
	cout<<"    |";
	for(k=0; k<n; k++){
		cout<<"___";
	}
	cout<<"____|\n";
}

int countFlags(char** board, int n){
	int counter=0;
	for(int p=0; p<n; p++){
		for(int q=0; q<n; q++){
			if(board[p][q] == '#'){
				counter++;
			}
		}
	 }
	return counter;
}

int countMines(char** board, int n){
	int counter=0;
	for(int p=0; p<n; p++){
		for(int q=0; q<n; q++){
			if(board[p][q] == bombChar){
				counter++;
			}
		}
	 }
	return counter;
}

void createDisplayBoard(char** board, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j] = hideChar;
		}
	}
}

void initialBoard(char** board, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			board[i][j] = '0';
		}
	}
}

void createHints(int x, int y, char** board, int n){
	if(board[x][y] != bombChar && x >= 0 && x <= n-1 && y >= 0 && y <= n-1){
		board[x][y] = board[x][y] + 1;
	}
}

void createMines(char** board, int m, int n){
	srand(time(0));
	int ri, rj;
	
	for(int i=0; i<m+1; i++){
		ri = rand()%n;
		rj = rand()%n;
		if(board[ri][rj] == bombChar){ 	//to check if postion alredy filled
		    i--;
		    continue;
		}
		board[ri][rj] = bombChar;
		for(int x=ri-1; x<=ri+1; x++){
			for(int y=rj-1; y<=rj+1; y++){
				if(!(board[x][y] == board[ri][rj])){
					createHints(x, y, board, n);
				}
			}
		}
		/*createHints(ri, rj-1, board, n);	   //left
		createHints(ri, rj+1, board, n);          //right
		createHints(ri-1, rj-1, board, n);	   //top left
		createHints(ri-1, rj, board, n);          //top
		createHints(ri-1, rj+1, board, n);        //top right
		createHints(ri+1, rj-1, board, n);        //bottom left
		createHints(ri+1, rj, board, n);          //bottom
		createHints(ri+1, rj+1, board, n);        //bottom right*/
	}
}

void createLogicBoard(char** board, int n){
	int m;
	m = n * n * 0.2;
	createMines(board, m, n);
}
