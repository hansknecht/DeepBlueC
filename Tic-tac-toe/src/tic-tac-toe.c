#include "tic-tac-toe.h"

char board[10] = { 'X', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int wins[3] = { 0, 0, 0 };
int winners[8][3] = {
	{1, 2, 3},
	{4, 5, 6},
	{7, 8, 9},
	{1, 5, 9},
	{3, 5, 7},
	{1, 4, 7},
	{2, 5, 8},
	{3, 6, 9}
};

int answerToLife(void)
{
	return 42;
}
void resetBoard(void)
{
	for (int x = 1; x < 10; x++)
	{
		board[x] = x + '0';
	}
}
void clrscr(void)
{
	system("@cls||clear");
}

bool playSquare(char i)
{
	if (i < '1' || i > '9')
	{
		printf("That is not a valid square.");
		return false;
	}
	int x = i - '0';
	if (board[x] == 'X' || board[x] == 'O')
	{
		printf("That square is already selected. Try again");
		return false;
	}
	else
	{
		board[x] = board[0];
	}
	return true;
}

void printBoard(void)
{
	clrscr();
	printf("\n---------\n");
	for (int x = 1; x < 10; x++)
	{
		if (!(x % 3)) printf("%c\n---------\n", board[x]);
		else printf("%c | ", board[x]);
	}
	printf("\n");
}

bool checkWinner(void)
{
	for (int x = 0; x < 8; x++)
	{
		if ((board[winners[x][0]] == board[winners[x][1]]) && (board[winners[x][1]] == board[winners[x][2]]))
		{
			return true;
		}
	}
	return false;
}

bool checkDraw(void)
{
	for (int x = 1; x < 10; x++)
	{
		if (board[x] - '0' == x) return false;
	}
	return true;
}


void playGame(void)
{
	char c = '0';
	printf("Ready to play a game?\nHit 'Z' to get out\n");
	printBoard();
	while (c != 'Z')
	{
		printBoard();
		printf("Ready player %c to play? ", board[0]);
		c = getchar(), getchar();
		while (!playSquare(c))
		{
			printf("That didn't work, play again.\n");
			c = getchar(), getchar();
		}
		if (checkWinner())
		{
			printBoard();
			if (board[0] == 'X') wins[0]++;
			else wins[1]++;
			printf("Got a winner\nGreat Job %c\nIt is now X : %d\tO : %d\tDraws : %d\n",board[0], wins[0], wins[1], wins[2]);
			printf("Any key to play again:");
			getchar(), getchar();
			resetBoard();
		}
		if (checkDraw())
		{
			printBoard();
			wins[2]++;
			printf("Got a draw\nGreat Job:( you two\nIt is now X : %d\tO : %d\tDraws : %d\n", wins[0], wins[1], wins[2]);
			printf("Any key to play again:");
			getchar(), getchar();
			resetBoard();
		}
		board[0] = (board[0] != 'X') ? 'X' : 'O';
	}
}

