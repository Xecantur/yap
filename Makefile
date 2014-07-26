OBJ = main.cpp
CFLAGS = -Wall -Wextra -std=c++11 -Isrc/
LFLAGS = -lSDL2_image -lBox2D -ltinyxml

all:
	clang++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap

debug:
	clang++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap -g -DDEBUG
