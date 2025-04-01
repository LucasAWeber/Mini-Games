#include "2048.h"

int game_loop_2048 () {
    int board[LENGTH][LENGTH];
    int clone[LENGTH][LENGTH];
    int validBoard[LENGTH*LENGTH][2];
    int total = 0;
    int index = -1;
    int valid = 0;

    srand(time(NULL));
    fill_board_2048(board);
    index = check_valid_2048(board, validBoard);
    new_number_2048(board, validBoard, index);
    index = check_valid_2048(board, validBoard);
    new_number_2048(board, validBoard, index);
    index = check_valid_2048(board, validBoard);
    print_board_2048(board);
    while (1) {
        logic_2048(board);
        index = check_valid_2048(board, validBoard);
        new_number_2048(board, validBoard, index);
        print_board_2048(board);
        total = get_total_2048(board);
        clone_array_2048(board, clone);
        valid = 0;
        valid += up_arrow_2048(clone);
        clone_array_2048(board, clone);
        valid += down_arrow_2048(clone);
        clone_array_2048(board, clone);
        valid += left_arrow_2048(clone);
        clone_array_2048(board, clone);
        valid += right_arrow_2048(clone);
        if (!valid) {
            printf("Oh no you lost! You finished with a score of %d\n", total);
            break;
        }
    }
    return 0;
}

void print_board_2048(int board[LENGTH][LENGTH]) {
    int digits = 0;
    int temp = 0;
    int total = 7;
    printf("\n");
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            temp = board[i][j];
            digits = 1;
            while (temp >= 10) {
                temp /= 10;
                digits++;
            }
            total = 7;
            total -= digits;
            for (int k = 0; k < total/2; k++) {
                printf(" ");
            }
            printf("%d", board[i][j]);
            total -= total/2;
            for (int k = 0; k < total; k++) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void fill_board_2048(int board[LENGTH][LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            board[i][j] = 0;
        }
    }
}

void new_number_2048(int board[LENGTH][LENGTH], int validBoard[LENGTH*LENGTH][2], int index) {
    int x = rand() % (index+1);
    int y;
    if (rand() % 10 == 1) {
        y = 4;
    } else {
        y = 2;
    }
    board[validBoard[x][0]][validBoard[x][1]] = y;
}

int check_valid_2048(int board[LENGTH][LENGTH], int validBoard[LENGTH*LENGTH][2]) {
    int valid = -1;
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            if (board[i][j] == 0) {
                valid++;
                validBoard[valid][0] = i;
                validBoard[valid][1] = j;
            }
        }
    }
    return valid;
}

int get_total_2048(int board[LENGTH][LENGTH]) {
    int total = 0;
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            total += board[i][j];
        }
    }
    return total;
}

void logic_2048(int board[LENGTH][LENGTH]) {
    int input = 0;
    while (!input) {
        if (getchar() == '\033') {
            getchar();
            switch(getchar()) {
                case 'A':
                    // code for arrow up
                    if (up_arrow_2048(board)) {
                        input = 1;
                    }
                    break;
                case 'B':
                    // code for arrow down
                    if (down_arrow_2048(board)) {
                        input = 1;
                    }
                    break;
                case 'C':
                    // code for arrow right
                    if (right_arrow_2048(board)) {
                        input = 1;
                    }
                    break;
                case 'D':
                    // code for arrow left
                    if (left_arrow_2048(board)) {
                        input = 1;
                    }
                    break;
            }
        }
    }
}

int up_arrow_2048(int board[LENGTH][LENGTH]) {
    int change = 0;
    for (int j = 0; j < LENGTH; j++) {
        for (int k = 0; k < LENGTH; k++) {
            for (int i = LENGTH-1; i > 0; i--) {
                if (board[i-1][j] == 0 && board[i][j] != 0) {
                    change = 1;
                    board[i-1][j] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < LENGTH-1; i++) {
            if (board[i][j] != 0 && board[i][j] == board[i+1][j]) {
                change = 1;
                board[i][j] += board[i+1][j];
                board[i+1][j] = 0;
                for (int k = i+1; k < LENGTH-1; k++) {
                    board[k][j] = board[k+1][j];
                    board[k+1][j] = 0;
                }
            }
        }
    }
    return change;
}

int down_arrow_2048(int board[LENGTH][LENGTH]) {
    int change = 0;
    for (int j = 0; j < LENGTH; j++) {
        for (int k = 0; k < LENGTH; k++) {
            for (int i = 0; i < LENGTH-1; i++) {
                if (board[i+1][j] == 0 && board[i][j] != 0) {
                    change = 1;
                    board[i+1][j] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        for (int i = LENGTH-1; i > 0; i--) {
            if (board[i][j] != 0 && board[i][j] == board[i-1][j]) {
                change = 1;
                board[i][j] += board[i-1][j];
                board[i-1][j] = 0;
                for (int k = i-1; k > 1; k--) {
                    board[k][j] = board[k-1][j];
                    board[k-1][j] = 0;
                }
            }
        }
    }
    return change;
}

int left_arrow_2048(int board[LENGTH][LENGTH]) {
    int change = 0;
    for (int i = 0; i < LENGTH; i++) {
        for (int k = 0; k < LENGTH; k++) {
            for (int j = LENGTH-1; j > 0; j--) {
                if (board[i][j-1] == 0 && board[i][j] != 0) {
                    change = 1;
                    board[i][j-1] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < LENGTH-1; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j+1]) {
                change = 1;
                board[i][j] += board[i][j+1];
                board[i][j+1] = 0;
                for (int k = j+1; k < LENGTH-1; k++) {
                    board[i][k] = board[i][k+1];
                    board[i][k+1] = 0;
                }
            }
        }
    }
    return change;
}

int right_arrow_2048(int board[LENGTH][LENGTH]) {
    int change = 0;
    for (int i = 0; i < LENGTH; i++) {
        for (int k = 0; k < LENGTH; k++) {
            for (int j = 0; j < LENGTH-1; j++) {
                if (board[i][j+1] == 0 && board[i][j] != 0) {
                    change = 1;
                    board[i][j+1] = board[i][j];
                    board[i][j] = 0;
                }
            }
        }
        for (int j = LENGTH-1; j > 0; j--) {
            if (board[i][j] != 0 && board[i][j] == board[i][j-1]) {
                change = 1;
                board[i][j] += board[i][j-1];
                board[i][j-1] = 0;
                for (int k = j-1; k > 1; k--) {
                    board[i][k] = board[i][k-1];
                    board[i][k-1] = 0;
                }
            }
        }
    }
    return change;
}

void clone_array_2048(int board[LENGTH][LENGTH], int clone[LENGTH][LENGTH]) {
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < LENGTH; j++) {
            clone[i][j] = board[i][j];
        }
    }
}
