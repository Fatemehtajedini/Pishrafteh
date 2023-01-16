all: compile link

compile:
	g++ -Isfml/include -c src/main.cpp src/Extra_func.cpp src/Part.cpp src/Player.cpp

link:
	g++ main.o Extra_func.o Part.o Player.o -o Hospital -Lsfml/lib -lsfml-graphics -lsfml-window -lsfml-system