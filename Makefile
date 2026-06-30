CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/main.c src/operations.c src/ui.c
OUT = bin/habit_tracker

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
