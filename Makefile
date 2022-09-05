SRC := main.cpp Game.cpp nikees_headers/Size.cpp nikees_headers/Vector2.cpp
INCLUDE := 


all:
	g++ -LSDL2mingw/lib -ISDL2mingw/include -Inikees_headers/ -o build/game.exe $(SRC) -lmingw32 -lSDL2main -lSDL2
