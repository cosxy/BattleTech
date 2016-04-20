#ifndef SCREENMGT_H_INCLUDED
#define SCREENMGT_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <map>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

const string RootImagePath = "Graphics/";

enum ScreenTypes
{
    MainMenu,
    InGameMenu,
    PopupWindow,
    PhaseWindow
};

class FontContainer
{
    public:
        SDL_Texture* RenderedText;
        string StoredText;
        int Text_W,Text_H;
};

class GraphicalEngine
{
    protected:
	int Window_W, Window_H, TileSize;
	SDL_Window *MainWindow = NULL;
	SDL_Renderer *MainRenderer = NULL;
	TTF_Font *screentext;
	map<string,SDL_Texture*> LoadedImages;

    public:
    GraphicalEngine(int ScreenWidth, int ScreenHeight, int HexSize)
	{
		Window_W = ScreenWidth;
		Window_H = ScreenHeight;
		TileSize = HexSize;
		screentext = NULL;
	}
    ~GraphicalEngine()
	{
        SDLShutdown();
	}
    void RenderClear()
    {
        SDL_SetRenderDrawColor(MainRenderer,0xFF,0xFF,0xFF,0xFF);
        SDL_RenderClear(MainRenderer);
    }
    void RenderPresent()
    {
        SDL_RenderPresent(MainRenderer);
    }
    void FreeTexture();
    void Render(FontContainer* Words);
    void Render(string RenderIMG, SDL_Rect *RenderObject, SDL_Rect *RenderTarget, float IMGRotation, SDL_RendererFlip FlipType);
	void SDLShutdown();
    void CreateTextureFromText(string text, SDL_Color TextColor,FontContainer* TempContainer);
	bool SDLInit();
	bool LoadImageFromFile(string ImageName);
	bool SetupTrueTypeFont(string FontName,int FontSize);

};
/*
bool KeyCapture(SDL_Event *E,string *text)
{
	bool Accept = false;
	switch(E->key.keysym.sym)
	{
		case SDLK_0:
		text->append("0");
		break;
		case SDLK_1:
		text->append("1");
		break;
		case SDLK_2:
		text->append("2");
		break;
		case SDLK_3:
		text->append("3");
		break;
		case SDLK_4:
		text->append("4");
		break;
		case SDLK_5:
		text->append("5");
		break;
		case SDLK_6:
		text->append("6");
		break;
		case SDLK_7:
		text->append("7");
		break;
		case SDLK_8:
		text->append("8");
		break;
		case SDLK_9:
		text->append("9");
		break;
		case SDLK_a:
		text->append("a");
		break;
		case SDLK_b:
		text->append("b");
		break;
		case SDLK_c:
		text->append("c");
		break;
		case SDLK_d:
		text->append("d");
		break;
		case SDLK_e:
		text->append("e");
		break;
		case SDLK_f:
		text->append("f");
		break;
		case SDLK_g:
		text->append("g");
		break;
		case SDLK_h:
		text->append("h");
		break;
		case SDLK_i:
		text->append("i");
		break;
		case SDLK_j:
		text->append("j");
		break;
		case SDLK_k:
		text->append("k");
		break;
		case SDLK_l:
		text->append("l");
		break;
		case SDLK_m:
		text->append("m");
		break;
		case SDLK_n:
		text->append("n");
		break;
		case SDLK_o:
		text->append("o");
		break;
		case SDLK_p:
		text->append("p");
		break;
		case SDLK_q:
		text->append("q");
		break;
		case SDLK_r:
		text->append("r");
		break;
		case SDLK_s:
		text->append("s");
		break;
		case SDLK_t:
		text->append("t");
		break;
		case SDLK_u:
		text->append("u");
		break;
		case SDLK_v:
		text->append("v");
		break;
		case SDLK_w:
		text->append("w");
		break;
		case SDLK_x:
		text->append("x");
		break;
		case SDLK_y:
		text->append("y");
		break;
		case SDLK_z:
		text->append("z");
		break;
		case SDLK_SPACE:
		text->append(" ");
		break;
		case SDLK_MINUS:
		text->append("-");
		break;
		case SDLK_UNDERSCORE:
		text->append("_");
		break;
		case SDLK_BACKSPACE:
		{
			if(text->empty() != true)
			{
				text->erase(text->end()-1);
			}
		}
		break;
		case SDLK_DELETE:
		text->empty();
		break;
		case SDLK_RETURN:
		Accept = true;
		break;
		default:
		cout << "invalid character pressed" << endl;
		break;
	}
	return Accept;
}
*/
#endif // SCREENMGT_H_INCLUDED
