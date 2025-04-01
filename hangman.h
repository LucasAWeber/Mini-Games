#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_CHARS 10

int game_loop_hangman();
void upper_hangman(char[MAX_CHARS]);
void print_hangman(int, char[MAX_CHARS]);
int logic_hangman(char[MAX_CHARS], char[MAX_CHARS], char[MAX_CHARS], char);
int check_hangman(char[MAX_CHARS], char);
int valid_word_hangman(char[MAX_CHARS]);
