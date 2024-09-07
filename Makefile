all: build run

build:
	gcc -I src/include -L src/lib -o main main.c graph.c text.c stats.c -lmingw32 -lSDL2main -lSDL2 -lpdh

run:
	./main.exe
