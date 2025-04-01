#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 4

int game_loop_2048 ();
void printBoard(int [LENGTH][LENGTH]);
void fillBoard(int [LENGTH][LENGTH]);
void newNumber(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2], int);
int checkValid(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2]);
int getTotal(int [LENGTH][LENGTH]);
void logic(int [LENGTH][LENGTH]);
int upArrow(int [LENGTH][LENGTH]);
int downArrow(int [LENGTH][LENGTH]);
int leftArrow(int [LENGTH][LENGTH]);
int rightArrow(int [LENGTH][LENGTH]);
void cloneArray(int [LENGTH][LENGTH], int [LENGTH][LENGTH]);