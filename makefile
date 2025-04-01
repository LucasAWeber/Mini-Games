CC = gcc
CFLAGS = -Wall -std=c99

minigames: main.o hangman.o 2048.o wordle.o
	$(CC) $(CFLAGS) main.o hangman.o 2048.o wordle.o -o minigames

main.o: main.c hangman.h 2048.h wordle.h
	$(CC) $(CFLAGS) -c main.c

hangman.o: hangman.c hangman.h
	$(CC) $(CFLAGS) -c hangman.c

2048.o: 2048.c 2048.h
	$(CC) $(CFLAGS) -c 2048.c

wordle.o: wordle.c wordle.h
	$(CC) $(CFLAGS) -c wordle.c

clean:
	rm *.o minigames
