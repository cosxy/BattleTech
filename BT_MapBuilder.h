#ifndef BT_MAPBUILDER_H_INCLUDED
#define BT_MAPBUILDER_H_INCLUDED

#include "ScreenMgt.h"
#include "BattleMap.pb.h"
#include "GameType.h"
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
        RenderBox->y = 126;
        break;
        case 2:
        RenderBox->x = 48;
        RenderBox->y = 126;
        break;
        case 3:
        RenderBox->x = 96;
        RenderBox->y = 126;
        break;
        case 4:
        RenderBox->x = 144;
        RenderBox->y = 126;
        break;
        case 5:
        RenderBox->x = 192;
        RenderBox->y = 126;
        break;
        case 6:
        RenderBox->x = 240;
        RenderBox->y = 126;
        break;
        case 7:
        RenderBox->x = 0;
        RenderBox->y = 168;
        break;
        case 8:
        RenderBox->x = 48;
        RenderBox->y = 168;
        break;
        case 9:
        RenderBox->x = 96;
        RenderBox->y = 168;
        break;
        case 10:
        RenderBox->x = 144;
        RenderBox->y = 168;
        break;
        case 11:
        RenderBox->x = 192;
        RenderBox->y = 168;
        break;
        case 12:
        RenderBox->x = 240;
        RenderBox->y = 168;
        break;
        case 13:
        RenderBox->x = 0;
        RenderBox->y = 210;
        break;
        case 14:
        RenderBox->x = 48;
        RenderBox->y = 210;
        break;
        case 15:
        RenderBox->x = 96;
        RenderBox->y = 210;
        break;
        case 16:
        RenderBox->x = 144;
        RenderBox->y = 210;
        break;
        case 17:
        RenderBox->x = 192;
        RenderBox->y = 210;
        break;
		case 18:
        RenderBox->x = 240;
        RenderBox->y = 210;
        break;
		case 19:
        RenderBox->x = 0;
        RenderBox->y = 252;
        break;
		case 20:
        RenderBox->x = 48;
        RenderBox->y = 252;
        break;
		case 21:
        RenderBox->x = 96;
        RenderBox->y = 252;
        break;
		case 22:
        RenderBox->x = 144;
        RenderBox->y = 252;
        break;
		case 23:
        RenderBox->x = 192;
        RenderBox->y = 252;
        break;
        default:
        printf("SDL_Rect: error loading hex target portion. (Terrain)invalid input value.\n");
        RenderBox->x = 0;
        RenderBox->y = 0;
        break;
    }
}

void ObjectIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
    case 1:
    RenderBox->x = 0;
    RenderBox->y = 84;
    break;
    case 2:
    RenderBox->x = 48;
    RenderBox->y = 84;
    break;
    case 3:
    RenderBox->x = 96;
    RenderBox->y = 84;
    break;
    case 4:
    RenderBox->x = 144;
    RenderBox->y = 84;
    break;
    case 5:
    RenderBox->x = 192;
    RenderBox->y = 84;
    break;
    case 6:
    RenderBox->x = 240;
    RenderBox->y = 84;
    break;
    default:
    printf("SDL_Rect: error loading hex target portion. (object)invalid input value.\n");
    RenderBox->x = 0;
    RenderBox->y = 84;
    break;
    }
}

void BaseIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
    case 0:
    RenderBox->x = 0;
    RenderBox->y = 0;
    break;
    case 1:
    RenderBox->x = 48;
    RenderBox->y = 0;
    break;
    case 2:
    RenderBox->x = 96;
    RenderBox->y = 0;
    break;
    case 3:
    RenderBox->x = 144;
    RenderBox->y = 0;
    break;
    case 4:
    RenderBox->x = 192;
    RenderBox->y = 0;
    break;
    case 5:
    RenderBox->x = 240;
    RenderBox->y = 0;
    break;
	case 6:
    RenderBox->x = 0;
    RenderBox->y = 42;
    break;
    case 7:
    RenderBox->x = 48;
    RenderBox->y = 42;
    break;
    case 8:
    RenderBox->x = 96;
    RenderBox->y = 42;
    break;
    case 9:
    RenderBox->x = 144;
    RenderBox->y = 42;
    break;
    default:
    printf("SDL_Rect: error loading hex target portion. (base)invalid input value.\n");
    RenderBox->x = 0;
    RenderBox->y = 0;
    break;
    }
}

void SelectorIMG(int IMG_INDEX, SDL_Rect *RenderBox)
{
    switch(IMG_INDEX)
    {
    case 0:
    RenderBox->x = 240;
    RenderBox->y = 252;
    break;
    case 1:
    RenderBox->x = 192;
    RenderBox->y = 42;
    break;
    case 2:
    RenderBox->x = 240;
    RenderBox->y = 42;
    break;
    default:
    printf("SDL_Rect: error loading hex target portion. (Selector)invalid input value.\n");
    RenderBox->x = 0;
    RenderBox->y = 0;
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

class SelectorCursor
{
	public:
	SelectorCursor()
	{
		Screen_POS.x = 0;
		Screen_POS.y = 0;
		Map_POS.x = 0;
		Map_POS.y = 0;
		ObjectFlip = SDL_FLIP_NONE;
		Current_IMG = 1;
		PTR_Direction = 1;
	}
	SDL_Point Screen_POS;
	SDL_Point Map_POS;
	SDL_RendererFlip ObjectFlip;
	int Current_IMG;
	int PTR_Direction;
};

void Tool_Render(SDL_Point HexProperties, GraphicalEngine *GameGUI, string MapFileName,SelectorCursor Select_OBJ)
{
    SDL_Rect SourceIMG;
    SDL_Rect RenderLOC;
    //int DefaultHex_W = 50,DefaultHex_H = 50;

    SourceIMG.h = HexProperties.y;
    SourceIMG.w = HexProperties.x;
    RenderLOC.h = HexProperties.y;
    RenderLOC.w = HexProperties.x;
    RenderLOC.x = Select_OBJ.Screen_POS.x;
    RenderLOC.y = Select_OBJ.Screen_POS.y;

    SelectorIMG(Select_OBJ.Current_IMG,&SourceIMG);
    GameGUI->Render(MapFileName,&SourceIMG,&RenderLOC,0.0,Select_OBJ.ObjectFlip);
}

void Pre_Built_Tile_Selector(BattleTech_GameBoard::MapHex *MapTile,BattleTech_GameBoard::MapHex_HexType TileClass,int HexElevation)
{
	switch(TileClass)
	{
		case BattleTech_GameBoard::MapHex::EMPTY:
		{
			MapTile->set_baseimage(1);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case BattleTech_GameBoard::MapHex::WATER:
		{
			MapTile->set_baseimage(6);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::WATER);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case BattleTech_GameBoard::MapHex::LGTFOREST:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(3);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::LGTFOREST);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case BattleTech_GameBoard::MapHex::HVYFOREST:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(5);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::HVYFOREST);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case BattleTech_GameBoard::MapHex::ROUGH:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(1);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::ROUGH);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case BattleTech_GameBoard::MapHex::BUILDING:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::BUILDING);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		default:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
	}
}

void Pre_Built_Tile_Selector(BattleTech_GameBoard::MapHex *MapTile,int HexElevation,int selection)
{
	GameType Dice;
	switch(selection)
	{
		case 1://empty grass
		{
			MapTile->set_baseimage(0+(Dice.DiceRoll(2)-1));
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 2://empty desert
		{
			MapTile->set_baseimage(4);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 3://empty cave
		{
			MapTile->set_baseimage(5);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 7://shallow water
		{
			MapTile->set_baseimage(6);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::WATER);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 8://deep water
		{
			MapTile->set_baseimage(8);
			MapTile->set_terraindetail(0);
			MapTile->set_objectimage(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::WATER);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 4://light forest
		{
			//MapTile->set_baseimage(0);
			//MapTile->set_terraindetail(0);
			MapTile->set_objectimage(2+Dice.DiceRoll(2));
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::LGTFOREST);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 5://heavy forest
		{
			//MapTile->set_baseimage(0);
			//MapTile->set_terraindetail(0);
			MapTile->set_objectimage(4+Dice.DiceRoll(2));
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::HVYFOREST);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		case 6://rocks & rough terrain
		{
			//MapTile->set_baseimage(0);
			//MapTile->set_terraindetail(0);
			MapTile->set_objectimage(Dice.DiceRoll(2));
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::ROUGH);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
		default:
		{
			MapTile->set_baseimage(0);
			MapTile->set_terraindetail(0);
			MapTile->set_terrain(BattleTech_GameBoard::MapHex::EMPTY);
			MapTile->set_hexelevation(HexElevation);
			MapTile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
			MapTile->set_objectflip(BattleTech_GameBoard::MapHex::NONE);
		}
		break;
	}
}

void SetElevation(BattleTech_GameBoard::MapHex *Tile,int BuildValue)
{
	switch(BuildValue)
	{
		case 0:
		Tile->set_terraindetail(0);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 1:
		Tile->set_terraindetail(1);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 2:
		Tile->set_terraindetail(2);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 3:
		Tile->set_terraindetail(3);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 4:
		Tile->set_terraindetail(1);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 5:
		Tile->set_terraindetail(8);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 6:
		Tile->set_terraindetail(4);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 7:
		Tile->set_terraindetail(9);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 8:
		Tile->set_terraindetail(1);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 9:
		Tile->set_terraindetail(6);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 10:
		Tile->set_terraindetail(8);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 11:
		Tile->set_terraindetail(12);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 12:
		Tile->set_terraindetail(3);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 13:
		Tile->set_terraindetail(12);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 14:
		Tile->set_terraindetail(9);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 15:
		Tile->set_terraindetail(20);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 16:
		Tile->set_terraindetail(2);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 17:
		Tile->set_terraindetail(8);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 18:
		Tile->set_terraindetail(7);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 19:
		Tile->set_terraindetail(11);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 20:
		Tile->set_terraindetail(5);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 21:
		Tile->set_terraindetail(14);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 22:
		Tile->set_terraindetail(13);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 23:
		Tile->set_terraindetail(16);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 24:
		Tile->set_terraindetail(3);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 25:
		Tile->set_terraindetail(12);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 26:
		Tile->set_terraindetail(11);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 27:
		Tile->set_terraindetail(18);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 28:
		Tile->set_terraindetail(10);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 29:
		Tile->set_terraindetail(15);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 30:
		Tile->set_terraindetail(19);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 31:
		Tile->set_terraindetail(21);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 32:
		Tile->set_terraindetail(2);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 33:
		Tile->set_terraindetail(3);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 34:
		Tile->set_terraindetail(5);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 35:
		Tile->set_terraindetail(10);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 36:
		Tile->set_terraindetail(7);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 37:
		Tile->set_terraindetail(11);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 38:
		Tile->set_terraindetail(13);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 39:
		Tile->set_terraindetail(19);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 40:
		Tile->set_terraindetail(8);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 41:
		Tile->set_terraindetail(12);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 42:
		Tile->set_terraindetail(14);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 43:
		Tile->set_terraindetail(15);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 44:
		Tile->set_terraindetail(11);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 45:
		Tile->set_terraindetail(18);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 46:
		Tile->set_terraindetail(16);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 47:
		Tile->set_terraindetail(21);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 48:
		Tile->set_terraindetail(4);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 49:
		Tile->set_terraindetail(9);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 50:
		Tile->set_terraindetail(13);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 51:
		Tile->set_terraindetail(19);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 52:
		Tile->set_terraindetail(13);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 53:
		Tile->set_terraindetail(16);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 54:
		Tile->set_terraindetail(17);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 55:
		Tile->set_terraindetail(22);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		case 56:
		Tile->set_terraindetail(9);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 57:
		Tile->set_terraindetail(19);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 58:
		Tile->set_terraindetail(16);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 59:
		Tile->set_terraindetail(21);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 60:
		Tile->set_terraindetail(19);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HORIZONTAL);
		break;
		case 61:
		Tile->set_terraindetail(21);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
		break;
		case 62:
		Tile->set_terraindetail(22);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::VIRTICAL);
		break;
		case 63:
		Tile->set_terraindetail(23);
		Tile->set_terrainflip(BattleTech_GameBoard::MapHex::NONE);
		break;
		default:
		cout<<"Error in elevation autobuild: invalid BuildValue" << endl;
		break;
	}
}

#endif // BT_MAPBUILDER_H_INCLUDED
