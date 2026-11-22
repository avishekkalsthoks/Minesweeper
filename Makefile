CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SDL_FLAGS = $(shell pkg-config --cflags --libs sdl3)

TARGET = work
SOURCE = main.c games/mines.c 

all:
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(SDL_FLAGS)

clean:
	rm -f $(TARGET)
