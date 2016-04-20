#include <iostream>
#include "GameEngine2.0.h"
#include "BT_MapBuilder.h"

using namespace std;

int main()
{
	//string str_holder = "Graphics/MenuItems/Fonts/calibri.ttf";
	string MapFile = "../Graphics/MapTiles/HexPreset48.png";
	//int int_holder = 12;

	GameType test;
	//SDL_Color FontColor = {0,0,0};
	//FontContainer ViewText;
	GraphicalEngine MainGUI(800,600,48);
	SDL_Event e;
	SDL_Point RenderLoc;

	MainGUI.SDLInit();
	//MainGUI.SetupTrueTypeFont(str_holder,int_holder);
	//MainGUI.CreateTextureFromText("Hello World",FontColor,&ViewText);
	MainGUI.LoadImageFromFile(MapFile);
	bool quit = false;

	while(!quit)
	{
	while(SDL_PollEvent(&e) != 0)
	{
	    if(e.type == SDL_QUIT)
	    {
		quit = true;
	    }

	    MainGUI.RenderClear();
	    RenderLoc.x = 0;
        RenderLoc.y = 0;
	    MapRender(48,&MainGUI,MapFile,&RenderLoc);
	    RenderLoc.x = 0;
        RenderLoc.y = 48;
        MapRender(48,&MainGUI,MapFile,&RenderLoc);
        RenderLoc.x = 36;
        RenderLoc.y = 24;
        MapRender(48,&MainGUI,MapFile,&RenderLoc);
	    MainGUI.RenderPresent();
	}
	}

	MainGUI.SDLShutdown();
/*
	cout  << "Dice Results: " << endl;
	for(int x=0;x<4;x++)
	{
		for(int y=5;y>0;y--)
		{
		cout << test.GetDiceRoll()<<" " ;
		}
		cout << endl;
	}
*/
    return 0;
}
