#------------------------------------
#|        BattleTech MakeFile       |
#------------------------------------

main.exe: main.cpp ScreenMgt.cpp
	g++ -Wall -g -o main.exe main.cpp ScreenMgt.cpp -lSDL2_image -lSDL2_ttf `sdl2-config --cflags --libs`

#main.o: main.cpp ScreenMgt.cpp
#	g++ -Wall -g -o main.o -c main.cpp `sdl2-config --libs`
#	g++ -Wall -g -o ScreenMgt.o -c ScreenMgt.cpp `sdl2-config --libs`
clean:
#	rm *.o
	rm *.exe
MapViewer.exe: MapVeiwer.cpp ScreenMgt.cpp BattleMap.pb.cc
	g++ -Wall -g MapVeiwer.cpp ScreenMgt.cpp BattleMap.pb.cc `pkg-config --cflags --libs protobuf` `sdl2-config --cflags --libs` -o MapViewer.exe -lSDL2_image -lSDL2_ttf

BT_MapBuilder.exe: BT_MapBuilder.cpp ScreenMgt.cpp BattleMap.pb.cc
	g++ -Wall -g BT_MapBuilder.cpp ScreenMgt.cpp BattleMap.pb.cc `pkg-config --cflags --libs protobuf` `sdl2-config --cflags --libs` -o BT_MapBuilder.exe -lSDL2_image -lSDL2_ttf
