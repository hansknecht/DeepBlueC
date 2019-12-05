#ifndef TIC_TAC_TOE
#define TIC_TAC_TOE

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int answerToLife(void);
bool playSquare(char);
void printBoard(void);
bool checkWinner();
bool checkDraw();
void playGame(void);
void clrscr(void);
void resetBoard(void);

#endif