#include "wordle.h"

int game_loop_wordle()
{
    char validWordsArray[12973][STRINGLEN];
    char wordAnswersArray[2316][STRINGLEN];
    char wordGuess[STRINGLEN];
    char word[STRINGLEN];
    int guessArray[STRINGLEN-1];
    int guesses = GUESSES;

    srand(time(0));

    readWords(validWordsArray, "valid-wordle-words.txt");
    readWords(wordAnswersArray, "wordle-answers-alphabetical.txt");

    strcpy(word, wordAnswersArray[rand() % 2315]);
    //printf("%s\n", word);

    while (guesses > 0)
    {
        scanf("%s", wordGuess);
        for (int i = 0; i < STRINGLEN; i++)
        {
            wordGuess[i] = tolower(wordGuess[i]);
        }
        if (validWordCheck(validWordsArray, wordGuess))
        {
            if (checkWord(wordGuess, word, guessArray) == 1)
            {
                printGuesses(guessArray);
                printf("You got the word!\n");
                break;
            }
            else
            {
                printGuesses(guessArray);
                guesses--;
            }
        }
    }
    printf("The word was %s!\n", word);

    return 0;
}

void readWords(char array[][STRINGLEN], char ptr[])
{
    FILE * fptr = fopen(ptr, "r");
    int i = 0;

    while (!feof(fptr))
    {
        fscanf(fptr, "%s", array[i]);
        i++;
    }
    fclose(fptr);
}

int validWordCheck(char array[][STRINGLEN], char word[])
{
    if (strlen(word) != STRINGLEN - 1)
    {
        //printf("NOT LONG ENOUGH\n");
        return 0;
    }
    for (int i = 0; i < STRINGLEN-1; i++)
    {
        if (word[i] < 65 || (word[i] > 90 && word[i] < 97) || word[i] > 122)
        {
            //printf("NOT A VALID CHARACTER\n");
            return 0;
        }
    }
    for (int i = 0; i < 12972; i++)
    {
        if (strcmp(word, array[i]) == 0)
        {
            return 1;
        }
    }
    //printf("NOT A VALID WORD\n");
    return 0;
}

int checkWord(char guess[STRINGLEN], char word[STRINGLEN], int guessArray[STRINGLEN-1])
{
    int j;
    int visited[STRINGLEN-1] = {-1, -1, -1, -1, -1};
    for (int i = 0; i < STRINGLEN-1; i++)
    {
        guessArray[i] = 0;
    }
    if (strcmp(guess, word) == 0)
    {
        for (int i = 0; i < STRINGLEN-1; i++)
        {
            guessArray[i] = 2;
        }
        //printf("🟩🟩🟩🟩🟩\n");
        return 1;
    }
    for (int i = 0; i < STRINGLEN-1; i++)
    {
        for (j = 0; j < STRINGLEN-1; j++)
        {
            if (guess[i] == word[j])
            {
                if (i == j)
                {
                    //printf("🟩");
                    if (visited[j] != -1)
                    {
                        guessArray[visited[j]] = 0;
                    }
                    guessArray[i] = 2;
                    visited[j] = i;
                    break;
                }
                else if (visited[j] == -1)
                {
                    //printf("🟨");
                    guessArray[i] = 1;
                    visited[j] = i;
                    break;
                }
            }
        }
        if (j == STRINGLEN-1)
        {
            guessArray[i] = 0;
            //printf("⬛️");
        }
    }
    //printf("\n");
    return 0;
}

void printGuesses(int guess[STRINGLEN-1])
{
    for (int i = 0; i < STRINGLEN-1; i++)
    {
        if (guess[i] == 0)
        {
            printf("⬛️");
        }
        else if (guess[i] == 1)
        {
            printf("🟨");
        }
        else
        {
            printf("🟩");
        }
    }
    printf("\n");
}