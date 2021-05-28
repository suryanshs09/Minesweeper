#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>

int introduction();
int score_calculator(char[50][50], char[50][50], int);
void show_mines(char[50][50], char[50][50], int, int, int);
int submit(char[50][50], char[50][50], int, int, int);
void undo_flag(char[50][50], int, int, int);
void flag_location(char[50][50], int, int, int);
void found_0(int, int, char[50][50], char[50][50], int);
int open_location(char[50][50], char[50][50], int, int, int);
void display_any_board(char[50][50], int);
int count_flags(char[50][50], int);
int count_mines(char[50][50], int);
void create_display_board(char[50][50], int);
void create_hints(int, int, char[50][50], int);
void create_mines(char[50][50], int, int);
void create_logic_board(char[50][50], int);
void initial_board(char[50][50], int);

void main()
{
 clrscr();
 char logic_board[50][50];
 char display_board[50][50];
 int n, mcount, fcount, choice, lost=0, gameover=0, score, moves=0;
 n = introduction();
 initial_board(logic_board, n);
 initial_board(display_board, n);
 create_logic_board(logic_board, n);
 create_display_board(display_board, n);
 mcount = count_mines(logic_board, n);
 display_any_board(logic_board, n);
 cout<<"\n mines = "<<mcount<<"\n";
 cout<<"\n\tPress Enter to continue...";
 getch();
 while(!gameover && !lost)
 {
	clrscr();
	fcount = count_flags(display_board, n);
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flags = "<<fcount<<"\n";
	display_any_board(display_board, n);
	cout<<"\n Press 1 to open a position\n Press 2 to Flag a position\n Press 3 to Undo Flag\n Press 4 to Submit\n\n CHOICE: ";
	cin>>choice;
	switch(choice)
	{
		case 1: lost = open_location(logic_board, display_board, n, mcount, fcount);
			break;
		case 2:	flag_location(display_board, n, mcount, fcount);
			break;
		case 3: undo_flag(display_board, n, mcount, fcount);
			break;
		case 4: gameover = submit(logic_board, display_board, n, mcount, fcount);
			if(gameover == -1)
			{
				lost = 1;
			}
			moves--;
			break;
	       default: cout<<"\n\t\tEnter a valid Choice!!\n\t\tPress Enter to continue...";
			getch();
			break;
	 }
	 moves++;

 }
 if(lost == 1)
 {
	score = score_calculator(logic_board, display_board, n);
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\t  GAME OVER\n\n";
	cout<<"\t\t\tThank you for playing the game\n\t\t\t\t  Moves: "<<moves<<"\n\t\t\t\tYou scored: "<<score<<"\n\n\t\t\t    Press Enter to Exit...";
	getch();
 }
 if(gameover == 1)
 {
	score = score_calculator(logic_board, display_board, n);
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\t  GAME OVER\n\n";
	cout<<"\t\t\tCongrtulations!! You won the game\n\t\t\t\t  Moves: "<<moves<<"\n\t\t\t\tYou scored: "<<score<<"\n\n\t\t\t    Press Enter to Exit...";
	getch();
 }
}
int introduction()
{
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
int score_calculator(char lboard[50][50], char dboard[50][50], int n)
{
	int counter=0;
	for(int p=0; p<n; p++)
	{
		for(int q=0; q<n; q++)
		{
			if(dboard[p][q] == '#' && lboard[p][q] == '*')
			{
				counter += 10;
			}
			if(dboard[p][q] != '?' && lboard[p][q] != '*')
			{
				counter++;
			}
		}
	 }
	 return counter;
}
void show_mines(char lboard[50][50], char dboard[50][50], int n, int mcount, int fcount)
{
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	for(int p=0; p<n; p++)
	{
		for(int q=0; q<n; q++)
		{
			if(lboard[p][q] == '*' && dboard[p][q] != '#')
			{
				dboard[p][q] = lboard[p][q];
			}
		}
	 }
	 display_any_board(dboard, n);
}

int submit(char lboard[50][50], char dboard[50][50], int n, int mcount, int fcount)
{
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	display_any_board(dboard, n);
	if(fcount == mcount)
	{
		int counter = 0;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(lboard[i][j] == '*' && dboard[i][j] == '#')
				{
					counter++;
				}
			}
		}
		if(fcount == counter)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else if(fcount < mcount)
	{
		lable1:
		cout<<"\n\t\tYou Have not Flagged all mines!!\n\tPress y submit anyway n to continue game...";
		if(getch() == 'y' || getch() == 'Y')
		{
			return -1;
		}
		else if(getch() == 'n' || getch() == 'N')
		{
			return 0;
		}
		else
		{
			goto lable1;
		}
	}
	else
	{
		lable2:
		cout<<"\n\t\tYou Flaged more than number of mines!!\n\tPress y submit anyway n to continue game...";
		if(getch() == 'y' || getch() == 'Y')
		{
			return -1;
		}
		else if(getch() == 'n' || getch() == 'N')
		{
			return 0;
		}
		else
		{
			goto lable2;
		}
	}

}

void found_0(int x, int y, char lboard[50][50], char dboard[50][50], int n)
{
	if(dboard[x][y] == '?' && lboard[x][y] != '*' && x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
	{
		dboard[x][y] = lboard[x][y];
		if(lboard[x][y] == '0')
		{
			found_0(x, y-1, lboard, dboard, n);	   //left
			found_0(x, y+1, lboard, dboard, n);          //right
			found_0(x-1, y-1, lboard, dboard, n);	   //top left
			found_0(x-1, y, lboard, dboard, n);          //top
			found_0(x-1, y+1, lboard, dboard, n);        //top right
			found_0(x+1, y-1, lboard, dboard, n);        //bottom left
			found_0(x+1, y, lboard, dboard, n);          //bottom
			found_0(x+1, y+1, lboard, dboard, n);        //bottom right
		}
	}
}

void undo_flag(char dboard[50][50], int n, int mcount, int fcount)
{
	int ei, ej;
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	display_any_board(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1)
	{
		if(dboard[ei][ej] == '#')
		{
			dboard[ei][ej] = '?';
		}
		else
		{
			if(dboard[ei][ej] == '?')
			{
				cout<<"\n\t\tLocation not Flaaged!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else
			{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				//goto label;
			}
		}
	}
	else
	{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		goto label;
	}
}

void flag_location(char dboard[50][50], int n, int mcount, int fcount)
{
	int ei, ej;
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flag = "<<fcount<<"\n";
	display_any_board(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1)
	{
		if(dboard[ei][ej] == '?')
		{
			dboard[ei][ej] = '#';
		}
		else
		{
			if(dboard[ei][ej] == '#')
			{
				cout<<"\n\t\tLocation alredy Flaaged!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else
			{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				//goto label;
			}
		}
	}
	else
	{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		goto label;
	}
}

int open_location(char lboard[50][50], char dboard[50][50], int n, int mcount, int fcount)
{
	int ei, ej;
	label:
	clrscr();
	cout<<"\t\t\t\tM I N E S W E E P E R\n\n";
	cout<<" Mines = "<<mcount<<"\t"<<" Flags = "<<fcount<<"\n";
	display_any_board(dboard, n);
	cout<<"\n   Enter Row:";
	cin>>ei;
	cout<<"Enter Column:";
	cin>>ej;
	if(ei >= 0 && ei <= n-1 && ej >= 0 && ej <= n-1)
	{
		if(dboard[ei][ej] == '?' && lboard[ei][ej] != '0' && lboard[ei][ej] != '*')
		{
			dboard[ei][ej] = lboard[ei][ej];
		}
		else
		{
			if(dboard[ei][ej] == '?' && lboard[ei][ej] == '0')
			{
				found_0(ei, ej, lboard, dboard, n);
			}
			else if(dboard[ei][ej] == '?' && lboard[ei][ej] == '*')
			{
				show_mines(lboard, dboard, n, mcount, fcount);
				cout<<"\n\t\tYou Hit a Mine!!\n\t\tPress Enter to view results...";
				getch();
				return 1;
			}
			else if(dboard[ei][ej] == '#')
			{
				cout<<"\n\t\tCannot open Flaged Location!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
			else
			{
				cout<<"\n\t\tLocation alredy opened!!\n\t\tPress Enter to Try Again...";
				getch();
				goto label;
			}
		}
	}
	else
	{
		cout<<"\n\t\tInvalid Location Entered!!\n\t\tPress Enter to Try Again...";
		getch();
		//goto label;
	}
	return 0;
}

void display_any_board(char board[50][50], int n)
{
	cout<<"\n       ";
	for(int k=0; k<n; k++)
	{
		if(k<10)
		{
			cout<<" "<<k<<" ";
		}
		else
		{
			cout<<k<<" ";

		}
	}
	cout<<"\n     __";
	for(k=0; k<n; k++)
	{
		cout<<"___";
	}
	cout<<"__\n    |";
	for(k=0; k<n; k++)
	{
		cout<<"   ";
	}
	cout<<"    |\n";
	for(int i=0; i<n; i++)
	{
		if(i<10)
		{
			cout<<" "<<i<<"  |  ";
		}
		else
		{
			cout<<i<<"  |  ";
		}
		for(int j=0; j<n; j++)
		{
			cout<<" "<<board[i][j]<<" ";
		}
		cout<<"  |  \n";
	}
	cout<<"    |";
	for(k=0; k<n; k++)
	{
		cout<<"___";
	}
	cout<<"____|\n";
}

int count_flags(char board[50][50], int n)
{
	int counter=0;
	for(int p=0; p<n; p++)
	{
		for(int q=0; q<n; q++)
		{
			if(board[p][q] == '#')
			{
				counter++;
			}
		}
	 }
	 return counter;
}

int count_mines(char board[50][50], int n)
{
	int counter=0;
	for(int p=0; p<n; p++)
	{
		for(int q=0; q<n; q++)
		{
			if(board[p][q] == '*')
			{
				counter++;
			}
		}
	 }
	 return counter;
}

void create_display_board(char board[50][50], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j] = '?';
		}
	}
}

void initial_board(char board[50][50], int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			board[i][j] = '0';
		}
	}

}

void create_hints(int x, int y, char board[50][50], int n)
{
	if(board[x][y] != '*' && x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
	{
		board[x][y] = board[x][y] + 1;
	}
}

void create_mines(char board[50][50], int m, int n)
{
	srand(time(0));
	int ri, rj;
	for(int i=0; i<m+1; i++)
	{
		ri = rand()%n;
		rj = rand()%n;
		if(board[ri][rj] == '*') 	//to check if postion alredy filled
		{
		       i--;
		       continue;
		}
		board[ri][rj] = '*';
		for(int x=ri-1; x<=ri+1; x++)
		{
			for(int y=rj-1; y<=rj+1; y++)
			{
				if(!(board[x][y] == board[ri][rj]))
				{
					create_hints(x, y, board, n);
				}
			}
		}
		/*create_hints(ri, rj-1, board, n);	   //left
		create_hints(ri, rj+1, board, n);          //right
		create_hints(ri-1, rj-1, board, n);	   //top left
		create_hints(ri-1, rj, board, n);          //top
		create_hints(ri-1, rj+1, board, n);        //top right
		create_hints(ri+1, rj-1, board, n);        //bottom left
		create_hints(ri+1, rj, board, n);          //bottom
		create_hints(ri+1, rj+1, board, n);        //bottom right*/
	}

}

void create_logic_board(char board[50][50], int n)
{
	 int m;
	 m = n * n * 0.2;
	 create_mines(board, m, n);
}