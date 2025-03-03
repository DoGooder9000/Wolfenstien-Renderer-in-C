SDL2_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

C_SRCS = $(wildcard src/*.c)

all:
	gcc -o main main.c $(C_SRCS) $(SDL2_FLAGS)

run: all
	./main.exe

clean:
	rm -f *.exe