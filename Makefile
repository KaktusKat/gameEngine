
CPPFLAGS=-O3  -I/opt/homebrew/include
LDFLAGS=-L/opt/homebrew/lib -lsdl3

main: main.cpp gameEngine.h Animation.h Image.h Screen.h
	c++ $(CPPFLAGS) $(LDFLAGS) main.cpp -o main
