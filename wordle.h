#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define STRINGLEN 6
#define GUESSES 6

int game_loop_wordle();
void read_words_wordle(char array[][STRINGLEN], char ptr[]);
int valid_word_check_wordle(char array[][STRINGLEN], char word[]);
int check_word_wordle(char guess[STRINGLEN], char word[STRINGLEN], int guessArray[STRINGLEN-1]);
void printGuesses(int guess[STRINGLEN-1]);