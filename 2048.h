#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LENGTH 4

int game_loop_2048 ();
void print_board_2048(int [LENGTH][LENGTH]);
void fill_board_2048(int [LENGTH][LENGTH]);
void new_number_2048(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2], int);
int check_valid_2048(int [LENGTH][LENGTH], int [LENGTH*LENGTH][2]);
int get_total_2048(int [LENGTH][LENGTH]);
void logic_2048(int [LENGTH][LENGTH]);
int up_arrow_2048(int [LENGTH][LENGTH]);
int down_arrow_2048(int [LENGTH][LENGTH]);
int left_arrow_2048(int [LENGTH][LENGTH]);
int right_arrow_2048(int [LENGTH][LENGTH]);
void clone_array_2048(int [LENGTH][LENGTH], int [LENGTH][LENGTH]);
