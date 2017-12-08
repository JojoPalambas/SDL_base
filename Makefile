CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -pedantic -g
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
OBJ = main.o game.o init.o load.o menu.o time.o display.o \
      inputs.o map.o texture.o update.o
EXEC = anticipation_fighter

VPATH = src/

.PHONY: all clean

all: $(EXEC)

$(EXEC): $(OBJ)

clean:
	${RM} $(OBJ)
	${RM} $(EXEC)
