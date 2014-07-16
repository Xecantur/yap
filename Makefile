OBJ = main.cpp
CFLAGS= -std=c++11 -Wall -Wextra -Isrc/ -Isrc/gfx/ -Isrc/gameplay
LFLAGS= -lSDL2_image -lBox2D
all:
	clang++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap
