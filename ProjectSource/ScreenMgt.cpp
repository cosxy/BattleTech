
#include "ScreenMgt.h"
#include <iostream>
#include <stdio.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

using namespace std;

const string BTVerInfo = "BattleTech Ver 1.0.0";

bool GraphicalEngine::SDLInit()
{
	//setup Check for SDL Init.
	bool success = true;

	//Initialize SDL.
	if(SDL_Init(SDL_INIT_VIDEO)<0)
	{
		printf("Error: SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//set texture filtering to linear
		if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//create Window
		MainWindow = SDL_CreateWindow(BTVerInfo.c_str(),SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,Window_W,Window_H, SDL_WINDOW_SHOWN);
		if(MainWindow == NULL)
		{
			printf("Error: Window could not be created! SDL_Error: %s\n",SDL_GetError());
			success = false;
		}
		else
		{
			//create vsynced renderer for window
			MainRenderer = SDL_CreateRenderer(MainWindow,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(MainRenderer == NULL)
			{
				printf("Error: Renderer could not be created! SDL_Error: %s\n",SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer colour
				SDL_SetRenderDrawColor(MainRenderer,0xFF,0xFF,0xFF,0xFF);

				//load support for the JPG and PNG image formats
				int IMGFlags = IMG_INIT_JPG|IMG_INIT_PNG;
				int IMGInitted = IMG_Init(IMGFlags);
				if(!IMGFlags &IMGInitted)//both ints equal the same. I guess just checking if they don't match?

				{
					printf("IMG_Init: Failed to init required jpg and png support!\n");
					printf("IMG_Init: %s\n", IMG_GetError());
					success = false;
				}

				//load Text rendering support.
				if(TTF_Init()==-1)
				{
					printf("TTF_Init: Failed to initialize True Type Font Support!\n");
					printf("TTF_Init: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}
	return success;
}
void GraphicalEngine::FreeTexture()
{
    if(LoadedImages.empty() == false)
    {
        map<string,SDL_Texture*>::iterator LoadedTexturePTR = LoadedImages.begin();
        while(LoadedTexturePTR != LoadedImages.end())
        {
                SDL_DestroyTexture(LoadedTexturePTR->second);
                LoadedTexturePTR->second = NULL;
                LoadedTexturePTR++;
        }
        LoadedImages.clear();
    }
}

bool GraphicalEngine::SetupTrueTypeFont(string FontName,int FontSize)
{
	bool success = true;
	if(!TTF_WasInit())
	{
		printf("TTF_Init: font rendering wasn't initialized.\n");
		printf("TTF_Init:%s\n",TTF_GetError());
		success = false;
	}
	else
	{
		screentext = TTF_OpenFont(FontName.c_str(),FontSize);
		if(!screentext)
		{
			printf("TTF_Font: Font failed to Load File.\n");
			printf("TTF_Font: %s\n",TTF_GetError());
			success = false;
		}
	}
	return success;
}

void GraphicalEngine::SDLShutdown()
{
	//destroy window and renderer
	SDL_DestroyRenderer(MainRenderer);
	SDL_DestroyWindow(MainWindow);
	MainRenderer = NULL;
	MainWindow = NULL;
	//Release and clear Textures
	FreeTexture();
	//Release and allocate stored fonts
	if(screentext != NULL)
    {
        TTF_CloseFont(screentext);
        screentext = NULL;
    }

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void GraphicalEngine::CreateTextureFromText(string text, SDL_Color TextColor, FontContainer* TempContainer)
{
	SDL_Surface *Text_Surface = NULL;
	SDL_Texture *Surface2Texture = NULL;

	TempContainer->StoredText = text;
	TempContainer->RenderedText = NULL;
	Text_Surface = TTF_RenderText_Solid(screentext,text.c_str(),TextColor);

	if(Text_Surface == NULL )
    {
        printf("Graphical Engine::CreateTextureFromText: Error Failed to create surface\n");
    }
    else
    {
        TempContainer->Text_W = Text_Surface->w;
        TempContainer->Text_H = Text_Surface->h;
        Surface2Texture = SDL_CreateTextureFromSurface(MainRenderer,Text_Surface);
        if(Surface2Texture == NULL)
        {
            printf("Graphical Engine::CreateTextureFromText: Error Failed to create texture\n");
        }
        else
        {
            LoadedImages[text] = Surface2Texture;
            TempContainer->RenderedText = Surface2Texture;
        }
    }
}

void GraphicalEngine::Render(FontContainer* Words)
{
    SDL_Rect Object,Target;
    Object.w = Words->Text_W;
    Object.h = Words->Text_H;
    Object.x = 0;
    Object.y = 0;
    Target = Object;
    RenderClear();
    SDL_RenderCopy(MainRenderer,Words->RenderedText,&Object,&Target);
    SDL_RenderPresent(MainRenderer);
}

void GraphicalEngine::Render(string RenderIMG, SDL_Rect *RenderObject, SDL_Rect *RenderTarget, float IMGRotation, SDL_RendererFlip FlipType)
{
  SDL_RenderCopyEx(MainRenderer,LoadedImages[RenderIMG],RenderObject,RenderTarget,IMGRotation,NULL,FlipType);
}

bool GraphicalEngine::LoadImageFromFile(string ImageName)
{
    //Function variables;
    SDL_Texture *LoadedIMG = NULL;
    bool Success = true;

    //load image at specified path
    SDL_Surface *Surface2Texture = IMG_Load(ImageName.c_str());
    if(Surface2Texture == NULL)
    {
        Success = false;
        printf("IMG_Error: failed to create Surface %s; SDL_Error: %s\n",ImageName.c_str(),IMG_GetError());
    }
    else
    {
        SDL_SetColorKey(Surface2Texture,SDL_TRUE,SDL_MapRGB(Surface2Texture->format,0xFF,0XFF,0xFF));
        LoadedIMG = SDL_CreateTextureFromSurface(MainRenderer,Surface2Texture);
        if(LoadedIMG == NULL)
        {
            Success = false;
            printf("IMG_Error: failed to create Texture %s; SDL_Error: %s\n",ImageName.c_str(),IMG_GetError());
        }
        else
        {
            LoadedImages[ImageName] = LoadedIMG;
        }
    }
    return Success;
}
