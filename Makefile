OBJ = main.cpp
CFLAGS = -Wall -std=c++11 -Isrc/
LFLAGS = -lSDL2_image -ltinyxml -lBox2D

all:
	clang++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap

debug:
	clang++ src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap -g -DDEBUG -Wextra

release:
	${CC} src/${OBJ} ${CFLAGS} ${SDL_FLAGS} ${LFLAGS} -o yap -02 -DNO_WARNINGS
