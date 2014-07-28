OBJ = main.cpp
CFLAGS = -Wall -std=c++11 -Isrc/
LFLAGS = -lSDL2_image -lBox2D -ltinyxml

all:
	g++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap

debug:
	g++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap -g -DDEBUG -Wextra
