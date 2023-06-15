all: Traverse part1
	./part1

Traverse:
	g++ traverse.cpp -o traverse.exe -lglu32 -lopengl32 -lfreeglut

part1:
	g++ part1a.cpp -o part1.exe -lglu32 -lopengl32 -lfreeglut

