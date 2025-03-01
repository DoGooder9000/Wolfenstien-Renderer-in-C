SDL2_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

all:
	gcc -o main main.c $(SDL2_FLAGS)

run:
	./main.exe

clean:
	rm -f *.exe