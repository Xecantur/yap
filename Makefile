OBJ = main.cpp
CFLAGS = -Wall -std=c++11 -Isrc/
LFLAGS = -lSDL2_image -lfreetype -lSDL2_ttf -ltinyxml -lchipmunk -lstdc++
CC = clang++
all:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap

debug:
	${CC} src/${OBJ} ${CFLAGS} `sdl2-config --cflags --libs` ${LFLAGS} -o `pwd`/yap -g -DDEBUG -Wextra

release:
	${CC} src/${OBJ} ${CFLAGS} ${SDL_FLAGS} ${LFLAGS} -o yap -02 -DNO_WARNINGS
