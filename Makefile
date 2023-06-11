all: 
	g++ traverse.cpp -o traverse.exe -lglu32 -lopengl32 -lfreeglut
	g++ -o all.exe Frontpage.cpp -lglu32 -lopengl32 -lfreeglut
	./front
Frontpage:
	g++ Frontpage.cpp -o front.exe -lglu32 -lopengl32 -lfreeglut

Traverse:
	g++ traverse.cpp -o traverse.exe -lglu32 -lopengl32 -lfreeglut

