#ifndef BT_MAPBUILDER_H_INCLUDED
#define BT_MAPBUILDER_H_INCLUDED

#include "ScreenMgt.h"
//#include "./ProtocolBuffers/BattleMap/BattleMap.pb.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

void TerrainIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
        case 1:
        RenderBox->x = 0;
        RenderBox->y = 0;
        break;
        case 2:
        RenderBox->x = 48;
        RenderBox->y = 0;
        break;
        case 3:
        RenderBox->x = 96;
        RenderBox->y = 0;
        break;
        case 4:
        RenderBox->x = 144;
        RenderBox->y = 0;
        break;
        case 5:
        RenderBox->x = 192;
        RenderBox->y = 0;
        break;
        case 6:
        RenderBox->x = 0;
        RenderBox->y = 48;
        break;
        case 7:
        RenderBox->x = 48;
        RenderBox->y = 48;
        break;
        case 8:
        RenderBox->x = 96;
        RenderBox->y = 48;
        break;
        case 9:
        RenderBox->x = 144;
        RenderBox->y = 48;
        break;
        case 10:
        RenderBox->x = 192;
        RenderBox->y = 48;
        break;
        case 11:
        RenderBox->x = 0;
        RenderBox->y = 96;
        break;
        case 12:
        RenderBox->x = 48;
        RenderBox->y = 96;
        break;
        case 13:
        RenderBox->x = 96;
        RenderBox->y = 96;
        break;
        case 14:
        RenderBox->x = 144;
        RenderBox->y = 96;
        break;
        case 15:
        RenderBox->x = 192;
        RenderBox->y = 96;
        break;
        case 16:
        RenderBox->x = 0;
        RenderBox->y = 144;
        break;
        default:
        printf("SDL_Rect: error loading hex target portion. (Terrain)invalid input value.\n");
	RenderBox->x = 0;
        RenderBox->y = 192;
        break;
    }
}

void ObjectIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
    case 1:
    RenderBox->x = 48;
    RenderBox->y = 144;
    break;
    case 2:
    RenderBox->x = 96;
    RenderBox->y = 144;
    break;
    case 3:
    RenderBox->x = 144;
    RenderBox->y = 144;
    break;
    case 4:
    RenderBox->x = 192;
    RenderBox->y = 144;
    break;
    default:
    printf("SDL_Rect: error loading hex target portion. (object)invalid input value.\n");
    RenderBox->x = 0;
    RenderBox->y = 192;
    break;
    }
}

void BaseIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
    case 0:
    RenderBox->x = 0;
    RenderBox->y = 192;
    break;
    case 1:
    RenderBox->x = 48;
    RenderBox->y = 192;
    break;
    case 2:
    RenderBox->x = 96;
    RenderBox->y = 192;
    break;
    case 3:
    RenderBox->x = 144;
    RenderBox->y = 192;
    break;
    case 4:
    RenderBox->x = 192;
    RenderBox->y = 192;
    break;
    default:
    printf("SDL_Rect: error loading hex target portion. (base)invalid input value.\n");
    RenderBox->x = 0;
    RenderBox->y = 192;
    break;
    }
}

void MapRender(int HexSize, GraphicalEngine *GameGUI,string MapFileName, SDL_Point *RenderSpot)
{
    SDL_Rect SourceIMG;
    SDL_Rect RenderLOC;
    int DefaultHexSize = 48;

    SourceIMG.h = DefaultHexSize;
    SourceIMG.w = DefaultHexSize;
    RenderLOC.h = HexSize;
    RenderLOC.w = HexSize;
    RenderLOC.x = RenderSpot->x;
    RenderLOC.y = RenderSpot->y;

    BaseIMG(0,&SourceIMG);

    GameGUI->Render(MapFileName,&SourceIMG,&RenderLOC,0.0,SDL_FLIP_NONE);
}

#endif // BT_MAPBUILDER_H_INCLUDED
