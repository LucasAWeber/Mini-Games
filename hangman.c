#include "hangman.h"

int game_loop_hangman() {
    int game = 1;
    int error = 0;
    char word[MAX_CHARS];
    char guessed[MAX_CHARS];
    char letterBank[27] = "                          \0";
    char guess;

    strcpy(word,getpass("Word: "));
    upper_hangman(word);
    while (!valid_word_hangman(word)) {
        strcpy(word,getpass("Word: "));
        upper_hangman(word);
    }
    
    for (int i=0;i<=strlen(word);i++) {
        guessed[i] = '_';
        if (i==strlen(word)) guessed[i] = '\0';
    }

    while (game) {
        print_hangman(error, guessed);
        printf("Guess: ");
        fflush(stdin);
        scanf("%c", &guess);
        guess = toupper(guess);
        while (check_hangman(letterBank, guess) || !isalpha(guess)) {
            printf("Guess: ");
            fflush(stdin);
            scanf("%c", &guess);
            guess = toupper(guess);
        }

        error += logic_hangman(word, guessed, letterBank, guess);

        if (strcmp(word, guessed) == 0) {
            print_hangman(error, guessed);
            printf("You Won!\n");
            break;
        }

        if (error >= 6) {
            print_hangman(error, word);
            printf("You lost!\n");
            break;
        }
    }

    return 0;
}

void upper_hangman(char word[MAX_CHARS]) {
    for (int i=0;i<strlen(word);i++) {
        word[i] = toupper(word[i]);
    }
}

void print_hangman(int error, char guessed[MAX_CHARS]) {
    printf("  ___\n");
    printf(" |   |\n");
    printf(" |   ");
    if (error >= 1) printf("o");
    printf("\n |  ");
    if (error >= 5) printf("/|");
    if (error >= 2 && error <= 4) printf(" |");
    if (error >= 6) printf("\\");
    printf("\n |  ");
    if (error >= 3) printf("/");
    if (error >= 4) printf(" \\");
    printf("\n---\n");
    for (int i=0;i<strlen(guessed);i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n\n");
}

int logic_hangman(char word[MAX_CHARS], char guessed[MAX_CHARS], char letterBank[MAX_CHARS], char guess) {
    letterBank[guess-'A'] = guess;
    if (check_hangman(word, guess)) {
        for (int i=check_hangman(word, guess)-1;i<strlen(word);i++) {
            if (guess == word[i]) {
                guessed[i] = guess;
            }
        }
        return 0;
    }
    return 1;
}

int check_hangman(char word[MAX_CHARS], char guess) {
    for (int i=0;i<strlen(word);i++) {
        if (guess == word[i]) {
            return i+1;
        }
    }
    return 0;
}

int valid_word_hangman(char word[MAX_CHARS]) {
    for (int i=0;i<strlen(word);i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }
    return 1;
}
