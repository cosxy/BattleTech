#include "ScreenMgt.h"
#include "BT_MapBuilder-copy.h"
#include "BattleMap.pb.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

SDL_RendererFlip SetFlipType(BattleTech_GameBoard::MapHex::FlipType FlipPTR)
{
    SDL_RendererFlip FlipType = SDL_FLIP_NONE;
    int FlipTypeHolder;

    switch(FlipPTR)
    {
    case BattleTech_GameBoard::MapHex::NONE:
    FlipType = SDL_FLIP_NONE;
    break;
    case BattleTech_GameBoard::MapHex::HORIZONTAL:
    FlipType = SDL_FLIP_HORIZONTAL;
    break;
    case BattleTech_GameBoard::MapHex::VIRTICAL:
    FlipType = SDL_FLIP_VERTICAL;
    break;
    case BattleTech_GameBoard::MapHex::HOR_AND_VIR:
    FlipTypeHolder = SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL;
    FlipType = (SDL_RendererFlip)FlipTypeHolder;
    break;
    default:
    printf("SDL_error: Failed to define FlipType.");
    break;
    }
    return FlipType;
}

void HexRender(int HexSize, GraphicalEngine *GameGUI, string MapFileName, SDL_Point *RenderSpot,  const BattleTech_GameBoard::MapHex& HexPTR)
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

    BaseIMG(HexPTR.baseimage(),&SourceIMG);
    GameGUI->Render(MapFileName,&SourceIMG,&RenderLOC,0.0,SDL_FLIP_NONE);

    if(HexPTR.terraindetail() != 0)
    {
        TerrainIMG(HexPTR.terraindetail(),&SourceIMG);
        GameGUI->Render(MapFileName,&SourceIMG,&RenderLOC,0.0,SetFlipType(HexPTR.terrainflip()));
    }

    if(HexPTR.objectimage() != 0)
    {
        ObjectIMG(HexPTR.objectimage(),&SourceIMG);
    GameGUI->Render(MapFileName,&SourceIMG,&RenderLOC,0.0,SetFlipType(HexPTR.objectflip()));
    }
}

void ChangeHex(BattleTech_GameBoard::MapHex *Tile, SDL_Event *Trigger)
{
    int imagebase = Tile->baseimage(), TerrainObj = Tile->terraindetail(), TileItem = Tile->objectimage();
    //bool FunctionKill = false;

        if(Trigger->key.keysym.sym == SDLK_1)
        {
            imagebase++;
            if (imagebase > 4)
            {
                imagebase = 0;
                //cout << "baseIMG restart" << endl;
            }
            Tile->set_baseimage(imagebase);
            //cout << "Change tile base image" << endl;
		 }
		 if(Trigger->key.keysym.sym == SDLK_2)
         {
            TileItem++;
            if (TileItem > 3)
            {
                TileItem = 0;
                //cout << "baseIMG restart" << endl;
            }
            Tile->set_objectimage(TileItem);
            //cout << "Change tile base image" << endl;
		 }
         else if(Trigger->key.keysym.sym == SDLK_3)
         {
            TerrainObj++;
            if (TerrainObj > 16)
            {
                TerrainObj = 0;
                //cout << "Terrain boarder restart" << endl;
            }
            Tile->set_terraindetail(TerrainObj);
            //cout << "Change Tile Terrain" << endl;
         }
         else if(Trigger->key.keysym.sym == SDLK_4)
         {
            switch(Tile->terrainflip())
                {
                    case BattleTech_GameBoard::MapHex_FlipType_NONE:
                    Tile->set_terrainflip(BattleTech_GameBoard::MapHex_FlipType_HORIZONTAL);
                    break;
                    case BattleTech_GameBoard::MapHex_FlipType_HORIZONTAL:
                    Tile->set_terrainflip(BattleTech_GameBoard::MapHex_FlipType_VIRTICAL);
                    break;
                    case BattleTech_GameBoard::MapHex_FlipType_VIRTICAL:
                    Tile->set_terrainflip(BattleTech_GameBoard::MapHex_FlipType_HOR_AND_VIR);
                    break;
                    default:
                    Tile->set_terrainflip(BattleTech_GameBoard::MapHex_FlipType_NONE);
                    break;
                }
			//cout << "Flip Terrain detail" << endl;
        }
        else if(Trigger->key.keysym.sym == SDLK_5)
        {
            switch(Tile->objectflip())
                {
                    case BattleTech_GameBoard::MapHex_FlipType_NONE:
                    Tile->set_objectflip(BattleTech_GameBoard::MapHex_FlipType_HORIZONTAL);
                    break;
                    case BattleTech_GameBoard::MapHex_FlipType_HORIZONTAL:
                    Tile->set_objectflip(BattleTech_GameBoard::MapHex_FlipType_VIRTICAL);
                    break;
                    case BattleTech_GameBoard::MapHex_FlipType_VIRTICAL:
                    Tile->set_objectflip(BattleTech_GameBoard::MapHex_FlipType_HOR_AND_VIR);
                    break;
                    default:
                    Tile->set_objectflip(BattleTech_GameBoard::MapHex_FlipType_NONE);
                    break;
                }
            //cout << "Flip Object image" << endl;
        }
        else if(Trigger->key.keysym.sym == SDLK_p)
        {
            cout << "Tile Properties" << endl;
            cout << "Base: " << Tile->baseimage() << endl;
            cout << "Type: " << Tile->objectimage() << endl;
        }
        else if(Trigger->key.keysym.sym == SDLK_ESCAPE)
        {
            //FunctionKill = true;
        }
}

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  if (argc != 3)
  {
    cerr << "Usage:  " << argv[0] << " MAP_FILE" << "  SAVE_FILE" << endl;
    return -1;
  }
  string MapFileName = "../Graphics/MapTiles/HexPreset48.png";
  GraphicalEngine MainGUI(800,600,48);
  SDL_Event e;
  bool quit = false;

  MainGUI.SDLInit();
  MainGUI.LoadImageFromFile(MapFileName);

  BattleTech_GameBoard::BattleField MapFile;

  int HexSize = (48);
  int IndentAdj,Adjustment;
  float ThreeQuarterHex,HalfHex;
  float transfer;
  int column = 0,row = 0;
  SDL_Point RenderLocation,MouseLoc;

  ThreeQuarterHex = (float)HexSize*0.75;
  HalfHex = (float)HexSize*0.5;
  Adjustment = 0;
  RenderLocation.x = 0;
  RenderLocation.y = 0;
  IndentAdj = (int)HalfHex;

    // Read the existing address book.
  fstream input(argv[1], ios::in | ios::binary);
  if (!MapFile.ParseFromIstream(&input))
  {
    cerr << "Failed to parse address book." << endl;
    return -1;
  }

  while(!quit)
	{
	   while(SDL_PollEvent(&e) != 0)
	   {
	      if(e.type == SDL_QUIT)
	      {
		     quit = true;
	      }
	      else if(e.type == SDL_MOUSEBUTTONUP)
          {
              MouseLoc.x = e.motion.x;
              MouseLoc.y = e.motion.y;

            column = (MouseLoc.x)/ThreeQuarterHex;

            if(column%2 == 0)
            {
                row = (MouseLoc.y)/HexSize;
            }
            else
            {
                transfer = (float)MouseLoc.y;
                transfer =  (transfer-HalfHex)/(float)HexSize;
                row = (int)transfer;
            }
            //cout << " column:\t" << column << "\trow:\t" << row << endl;
          }
          else if(e.key.keysym.sym == SDLK_PAGEDOWN)
          {
              transfer = (600/(float)HexSize)+0.5;
              cout << "Adjustment: " << (MapFile.columnlist(0).hexcolumn_size() - (int)transfer) << endl;
              Adjustment = MapFile.columnlist(0).hexcolumn_size() - (int)transfer;
          }
          else if(e.key.keysym.sym == SDLK_PAGEUP)
          {
              Adjustment = 0;
          }
          else if(e.type == SDL_KEYDOWN)
          {
              ChangeHex(MapFile.mutable_columnlist(column)->mutable_hexcolumn(row+Adjustment),&e);
          }

          MainGUI.RenderClear();

          for(int column=0; column<MapFile.columnlist_size(); column++)
          {
              for(int row=0; (row)<MapFile.columnlist(column).hexcolumn_size(); row++)
              {
                if(MapFile.columnlist(column).columnindent() == true)
                {
                    RenderLocation.x = column*(int)ThreeQuarterHex;
                    RenderLocation.y = ((row*HexSize)+IndentAdj)+(Adjustment*HexSize);
                }
                else
                {
                    RenderLocation.x = column*(int)ThreeQuarterHex;
                    RenderLocation.y = (row*HexSize)+(Adjustment*HexSize);
                }
                HexRender((HexSize),&MainGUI,MapFileName,&RenderLocation,MapFile.columnlist(column).hexcolumn(row));
              }
          }
        MainGUI.RenderPresent();
      }
    }

    // Write the new address book back to disk.
    fstream output(argv[2], ios::out | ios::trunc | ios::binary);
    if (!MapFile.SerializeToOstream(&output))
    {
      cerr << "Failed to write address book." << endl;
      return -1;
    }

    MainGUI.SDLShutdown();

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
