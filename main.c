#include "hangman.h"
#include "2048.h"
#include "wordle.h"

int main() {
    int game = -1;
    while (game < 0 || game > 2) {
        printf("Choose a game!\n\n")
        printf("************\n");
        printf("Hangman: 0\n")
        printf("2048: 1\n")
        printf("Wordle: 2\n")
        printf("************\n");
        scanf("%d", &game);
    }
    
    switch (game) {
        case 0:
            game_loop_hangman();
            break;
        case 1:
            game_loop_2048();
            break;
        case 2:
            game_loop_wordle();
            break;
    }
    
    return 0;
}