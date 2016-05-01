#include "ScreenMgt.h"
#include "BT_MapBuilder.h"
#include "BattleMap.pb.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int build_New_Map(BattleTech_GameBoard::BattleField *BaseTemplate,BattleTech_GameBoard::MapHex::HexType TileClass,int HexElevation)
{
	int ReturnValue = 0;
	if(BaseTemplate->columnlist_size() == 0)
	{
		int xAxis = 1;
		BattleTech_GameBoard::MapColumn *ColumnList;
		BattleTech_GameBoard::MapHex *MapTile;
		for(int col = 0;col < 24; col++)
		{
			//cout << " "<< xAxis << " check" << endl;
			//cout << "[" << col << "]\t";//current column number
			ColumnList = BaseTemplate->add_columnlist();
			for(int row = 0; row < xAxis; row++)
			{
				//cout << row << " ";//hexes assigned to this column
			
				MapTile = ColumnList->add_hexcolumn();
				//Build full Maps based on Prebuilt tile classes found in BT_MapBuilder.h <line 193>
				Pre_Built_Tile_Selector(MapTile,TileClass,HexElevation);	
			}
			cout << endl;//return character for row number output.
			if((xAxis < 15) && (col < 16))
			{
				xAxis+=2;
			}
			else if(col == 16)
			{
				xAxis--;
			}
			else if(col > 16)
			{
				xAxis-=2;
			}
		}
	}
	else
	{
		cout << "build_New_Map: ERROR:Map is already initialized" << endl;
		ReturnValue= -1;
	}
	return ReturnValue;
}

int MenuOptions(BattleTech_GameBoard::BattleField *BaseTemplate, SDL_Event *Event)
{
	string SavedMap = "../BuildObjects/MapFiles/SAVE01.BTM";
	int TaskComplete = 0;
	
	if(BaseTemplate->columnlist_size() == 0)
	{
		switch(Event->key.keysym.sym)
		{
			case SDLK_1:
			{
				// Read the pre-existing map file.
				fstream input(SavedMap.c_str(), ios::in | ios::binary);
				if (!BaseTemplate->ParseFromIstream(&input))
				{
					cerr << "Failed to read Map from disk." << endl;
					TaskComplete = -1;
				}
				TaskComplete = 1;
			}
			break;
			case SDLK_2:
			{
				//build a default clear map;
				build_New_Map(BaseTemplate,BattleTech_GameBoard::MapHex::EMPTY,0);
				TaskComplete = 1;
			}
			break;
			case SDLK_RETURN:
			TaskComplete = -1;
			break;
			default:
			//error handle on non-pushed Keys
			break;
		}
	}
	else
	{
		// Write the new map file back to disk.
		fstream output(SavedMap.c_str(), ios::out | ios::trunc | ios::binary);
		if (!BaseTemplate->SerializeToOstream(&output))
		{
			cerr << "Failed to write map file to disk." << endl;
			TaskComplete = -1;
		}
	}
	return TaskComplete;
}

int SaveMapFile(BattleTech_GameBoard::BattleField *BaseTemplate,string FILEPATH)
{
	string SavedMap = FILEPATH;
	int TaskComplete = 0;
	
	switch(Event->key.keysym.sym)
	{
		cout << "SaveMapFile: ERROR: Map not Initializied " << PATHFILE << endl;
/*
		// Read the pre-existing map file.
		fstream input(SavedMap.c_str(), ios::in | ios::binary);
		if (!BaseTemplate->ParseFromIstream(&input))
		{
			cerr << "Failed to read Map from disk." << endl;
			TaskComplete = -1;
		}
		TaskComplete = 1;
*/
	}
	else
	{
		// Write the new map file back to disk.
		fstream output(SavedMap.c_str(), ios::out | ios::trunc | ios::binary);
		if (!BaseTemplate->SerializeToOstream(&output))
		{
			cerr << "Failed to write map file to disk." << endl;
			TaskComplete = -1;
		}
	}
	return TaskComplete;
}

int LoadMapFile(BattleTech_GameBoard::BattleField *BaseTemplate,string FILEPATH)
{
	string SavedMap = FILEPATH;
	int TaskComplete = 0;
	
	switch(Event->key.keysym.sym)
	{
		// Read the pre-existing map file.
		fstream input(SavedMap.c_str(), ios::in | ios::binary);
		if (!BaseTemplate->ParseFromIstream(&input))
		{
			cerr << "Failed to read Map from disk." << endl;
			TaskComplete = -1;
		}
		TaskComplete = 1;
	}
	else
	{
	        cout << "LoadMapFile: ERROR: Map already Initializied " << PATHFILE << endl;	
/*
		// Write the new map file back to disk.
		fstream output(SavedMap.c_str(), ios::out | ios::trunc | ios::binary);
		if (!BaseTemplate->SerializeToOstream(&output))
		{
			cerr << "Failed to write map file to disk." << endl;
			TaskComplete = -1;
		}
*/
	}
	return TaskComplete;
}

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

void HexRender(SDL_Point HexProperties, GraphicalEngine *GameGUI, string MapFileName, SDL_Point *RenderSpot,  const BattleTech_GameBoard::MapHex& HexPTR)
{
    SDL_Rect SourceIMG;
    SDL_Rect RenderLOC;
    //int DefaultHex_W = 50,DefaultHex_H = 50;

    SourceIMG.h = HexProperties.y;
    SourceIMG.w = HexProperties.x;
    RenderLOC.h = HexProperties.y;
    RenderLOC.w = HexProperties.x;
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
            if (imagebase > 9)
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
            if (TileItem > 6)
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
            if (TerrainObj > 23)
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

void MapSelector_KEY_Function(SelectorCursor *Cursor_OBJECT)
{
	switch(Cursor_OBJECT->PTR_Direction)
	{
		case 1:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::NONE);
			Cursor_OBJECT->Current_IMG = 1;
		}
		break;
		case 2:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::NONE);
			Cursor_OBJECT->Current_IMG = 2;
		}
		break;
		case 3:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::VIRTICAL);
			Cursor_OBJECT->Current_IMG = 2;
		}
		break;
		case 4:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::VIRTICAL);
			Cursor_OBJECT->Current_IMG = 1;
		}
		break;
		case 5:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::HOR_AND_VIR);
			Cursor_OBJECT->Current_IMG = 2;
		}
		break;
		case 6:
		{
			Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::HORIZONTAL);
			Cursor_OBJECT->Current_IMG = 2;
		}
		break;
		default:
		Cursor_OBJECT->PTR_Direction = 1;
		Cursor_OBJECT->Current_IMG = 1;
		Cursor_OBJECT->ObjectFlip = SetFlipType(BattleTech_GameBoard::MapHex::NONE);
		break;
	}
	
}
void MapSelector_MOVE_Function(SelectorCursor *Cursor_OBJECT,BattleTech_GameBoard::BattleField *BaseTemplate,int Array_Wrap_Point,int Shift)
{
	SDL_Point Temp_LOC;
	int increment = Shift;
	Temp_LOC.x = Cursor_OBJECT->Map_POS.x;
	Temp_LOC.y = Cursor_OBJECT->Map_POS.y;
	switch(Cursor_OBJECT->PTR_Direction)
	{
		case 1:
		Temp_LOC.y-=increment;
		break;
		case 2:
		Temp_LOC.x+=increment;
		break;
		case 3:
		Temp_LOC.y+=increment;
		Temp_LOC.x+=increment;
		break;
		case 4:
		Temp_LOC.y+=increment;
		break;
		case 5:
		Temp_LOC.x-=increment;
		break;
		case 6:
		Temp_LOC.y-=increment;
		Temp_LOC.x-=increment;
		break;
		default:
		cout <<  "Error: Moving Selector Direction PTR_Direction = INVALID" << endl;
		break;
	}
	
	if(Temp_LOC.y >= BaseTemplate->columnlist_size())
	{	
		Temp_LOC.y = (BaseTemplate->columnlist_size()-1);
	}
	else if(Temp_LOC.y < 0)
	{
		Temp_LOC.y = 0;
	}
	
	if(Temp_LOC.y >=(Array_Wrap_Point-1))
	{
		int wrap_around = BaseTemplate->columnlist(Cursor_OBJECT->Map_POS.y).hexcolumn_size() - BaseTemplate->columnlist(Temp_LOC.y).hexcolumn_size();
		Temp_LOC.x -= wrap_around;
	}
	
	if(Temp_LOC.x >= BaseTemplate->columnlist(Temp_LOC.y).hexcolumn_size())
	{
		Temp_LOC.x = (BaseTemplate->columnlist(Temp_LOC.y).hexcolumn_size()-1);
		Temp_LOC.y = Cursor_OBJECT->Map_POS.y;
	}
	else if(Temp_LOC.x < 0)
	{
		Temp_LOC.x = 0;
		Temp_LOC.y = Cursor_OBJECT->Map_POS.y;
	}
	
	Cursor_OBJECT->Map_POS.x = Temp_LOC.x;
	Cursor_OBJECT->Map_POS.y = Temp_LOC.y;
	
	//cout << "Selector Position\n" << "col: " << Cursor_OBJECT->Map_POS.y << "\tMax_col: " << BaseTemplate->columnlist_size() << endl;
	//cout << "row: " << Cursor_OBJECT->Map_POS.x << "\tMax_row: " << BaseTemplate->columnlist(Cursor_OBJECT->Map_POS.y).hexcolumn_size() << endl;
	
}

void sleep(unsigned int msecond)
{
	clock_t goal = msecond + clock();
	while (goal > clock());
}

int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;
/*
  if (argc != 2)
  {
    cerr << "Usage:  " << argv[0] << " MAP_FILE" << "  SAVE_FILE" << endl;
    return -1;
  }
  */
  string MapFileName = "../Graphics/MapTiles/MapbuilderTest.png";
  SDL_Point ScreenSize;
  ScreenSize.x = 800;
  ScreenSize.y = 600;
  GraphicalEngine MainGUI(ScreenSize.x,ScreenSize.y,50);
  SDL_Event e;
  bool quit = false, setup = false;
  clock_t goal = clock();
  unsigned int msecond = 200;

  MainGUI.SDLInit();
  MainGUI.LoadImageFromFile(MapFileName);

  BattleTech_GameBoard::BattleField MapFile;
  BattleTech_GameBoard::MapColumn EditorTemp;

  //int HexSize = (50-6);
  int Adjustment,WrapAdj,TileClass;
  float ThreeQuarterHex,HalfHex;
  float transfer;
  //int column = 0,row = 0;
  SDL_Point RenderLocation,HexProp;
  //SDL_Point MouseLoc;
  SelectorCursor NewSelector;

  HexProp.x = 48;
  HexProp.y = 42;

  ThreeQuarterHex = (float)HexProp.x*0.75;
  HalfHex = (float)HexProp.y*0.5;
  Adjustment = 0;
  RenderLocation.x = 0;
  RenderLocation.y = 0;
  WrapAdj = 17;
  TileClass = 0;

  while(!setup)
  {
	  while(SDL_PollEvent(&e) != 0)
	  {
		  MainGUI.RenderClear();
		  MainGUI.RenderPresent();
		  
		  TileClass = MenuOptions(&MapFile,&e);
		  if(TileClass < 0)
		  {
			  quit = true;
			  setup = true;
		  }
		  else if(TileClass > 0)
		  {
			  setup = true;
		  }
	  }
  }
  if(!quit)
  {
	EditorTemp.add_hexcolumn()->CopyFrom(MapFile.columnlist(NewSelector.Map_POS.y).hexcolumn(NewSelector.Map_POS.x));
  }
  while(!quit)
	{
	   while(SDL_PollEvent(&e) != 0)
	   {
	      if(e.type == SDL_QUIT)
	      {
		     quit = true;
	      }
		  /*
	      else if(e.type == SDL_MOUSEBUTTONUP)
          {
              MouseLoc.x = e.motion.x;
              MouseLoc.y = e.motion.y;

            column = (((MouseLoc.x)/ThreeQuarterHex)/2)+((MouseLoc.y/HexProp.y)+Adjustment);

            if(column == WrapAdj)
			{
				row = ((MouseLoc.x)/ThreeQuarterHex)-(column-WrapAdj);
			}
			else if(column > WrapAdj)
			{
				transfer=(float)column-(float)WrapAdj;
				row = ((MouseLoc.x)/ThreeQuarterHex)-((transfer*1.5)+0.5);
			}
			else
			{
				row = ((MouseLoc.x)/ThreeQuarterHex);
			}
			
			if(column%2 == 0)
            {
                row = (MouseLoc.y)/HexProp.y;
            }
            else
            {
                transfer = (float)MouseLoc.y;
                transfer =  (transfer-HalfHex)/(float)HexProp.y;
                row = (int)transfer;
            }
			
            cout << " column:\t" << column << "\trow:\t" << row << endl;
          }
		  */
		           
          else if((e.type == SDL_KEYDOWN)&&(goal<clock()))
          {
			if(e.key.keysym.sym == SDLK_UP)
			{
				MapFile.mutable_columnlist(NewSelector.Map_POS.y)->mutable_hexcolumn(NewSelector.Map_POS.x)->CopyFrom(EditorTemp.hexcolumn(0));
				MapSelector_MOVE_Function(&NewSelector,&MapFile,WrapAdj,1);
				EditorTemp.mutable_hexcolumn(0)->CopyFrom(MapFile.columnlist(NewSelector.Map_POS.y).hexcolumn(NewSelector.Map_POS.x));
			}
			if(e.key.keysym.sym == SDLK_DOWN)
			{
				MapFile.mutable_columnlist(NewSelector.Map_POS.y)->mutable_hexcolumn(NewSelector.Map_POS.x)->CopyFrom(EditorTemp.hexcolumn(0));
				MapSelector_MOVE_Function(&NewSelector,&MapFile,WrapAdj,(-1));
				EditorTemp.mutable_hexcolumn(0)->CopyFrom(MapFile.columnlist(NewSelector.Map_POS.y).hexcolumn(NewSelector.Map_POS.x));
			}
			else if(e.key.keysym.sym == SDLK_LEFT)
			{
					NewSelector.PTR_Direction--;
				  if(NewSelector.PTR_Direction < 1)
				  {
					  NewSelector.PTR_Direction = 6;
				  }
				  MapSelector_KEY_Function(&NewSelector);
			}
			else if(e.key.keysym.sym == SDLK_RIGHT)
			{
				NewSelector.PTR_Direction++;
				  if(NewSelector.PTR_Direction > 6)
				  {
					  NewSelector.PTR_Direction = 1;
				  }
				  MapSelector_KEY_Function(&NewSelector);
			}
			else if(e.key.keysym.sym == SDLK_PAGEUP)
			{
              Adjustment--;
			  if(Adjustment < 0){Adjustment=0;}
         	  //sleep(500);
			  //goal = msecond + clock();
			}
			else if(e.key.keysym.sym == SDLK_PAGEDOWN)
			{
              transfer = ((ScreenSize.y/(float)HexProp.y));
			  //transfer = 13;
              //cout << "Adjustment: " << (WrapAdj -(int)transfer) << endl;
              int MaxAdj = (WrapAdj-(int)transfer);
			  Adjustment++;
			  if(Adjustment > MaxAdj || Adjustment > MapFile.columnlist_size()){Adjustment=MaxAdj;}
			  //sleep(500);
			  //goal = msecond + clock();
			}
			else if(e.key.keysym.sym == SDLK_HOME)
			{
              Adjustment = 0;
			}
			else if(e.key.keysym.sym == SDLK_END)
			{
              transfer = ((ScreenSize.y/(float)HexProp.y));
			  //transfer = 13;
              //cout << "Adjustment: " << (WrapAdj -(int)transfer) << endl;
              Adjustment = (WrapAdj-(int)transfer);
			}
			else if(e.key.keysym.sym == SDLK_F2)
			{
				MenuOptions(&MapFile,&e);
				cout << "MapFile Saved." << endl;
			}
			else
			{
				if(NewSelector.Map_POS.y < MapFile.columnlist_size() && NewSelector.Map_POS.y >= 0)
				{	
					if(NewSelector.Map_POS.x < MapFile.columnlist(NewSelector.Map_POS.y).hexcolumn_size() && NewSelector.Map_POS.x >= 0)
					{
						//ChangeHex(MapFile.mutable_columnlist(NewSelector.Map_POS.y)->mutable_hexcolumn(NewSelector.Map_POS.x),&e);
						ChangeHex(EditorTemp.mutable_hexcolumn(0),&e);
					}
				}
			}
			goal = msecond + clock();
		  }

          MainGUI.RenderClear();

          for(int column=0; column<MapFile.columnlist_size(); column++)
          {
              for(int row=0; (row)<MapFile.columnlist(column).hexcolumn_size(); row++)
              {
				  
                if(column == WrapAdj)
                {
                    RenderLocation.x = ((int)ThreeQuarterHex)+(row*(int)ThreeQuarterHex);
					RenderLocation.y = (((WrapAdj-1)*HexProp.y)+HalfHex)-(row*(int)HalfHex)-(Adjustment*HexProp.y);
                }
				else if(column > WrapAdj)
				{
					int MathOp = (column - WrapAdj)*2;
                    RenderLocation.x = ((MathOp*(int)ThreeQuarterHex)+ThreeQuarterHex)+(row*(int)ThreeQuarterHex);
					RenderLocation.y = (((WrapAdj-1)*HexProp.y)+HalfHex)-(row*(int)HalfHex)-(Adjustment*HexProp.y);
				}
                else
                {
                    RenderLocation.x = (row*(int)ThreeQuarterHex);
					RenderLocation.y = (column*HexProp.y)-(row*(int)HalfHex)-(Adjustment*HexProp.y);
                }
				
                HexRender(HexProp,&MainGUI,MapFileName,&RenderLocation,MapFile.columnlist(column).hexcolumn(row));
              }
          }
		
		if(NewSelector.Map_POS.y == WrapAdj)
        {
            NewSelector.Screen_POS.x = ((int)ThreeQuarterHex)+(NewSelector.Map_POS.x*(int)ThreeQuarterHex);
			NewSelector.Screen_POS.y = (((WrapAdj-1)*HexProp.y)+HalfHex)-(NewSelector.Map_POS.x*(int)HalfHex)-(Adjustment*HexProp.y);
        }
		else if(NewSelector.Map_POS.y > WrapAdj)
		{
			int MathOp1 = (NewSelector.Map_POS.y - WrapAdj)*2;
			NewSelector.Screen_POS.x = ((MathOp1*(int)ThreeQuarterHex)+ThreeQuarterHex)+(NewSelector.Map_POS.x*(int)ThreeQuarterHex);
			NewSelector.Screen_POS.y = (((WrapAdj-1)*HexProp.y)+HalfHex)-(NewSelector.Map_POS.x*(int)HalfHex)-(Adjustment*HexProp.y);
		}
        else
        {
            NewSelector.Screen_POS.x = (NewSelector.Map_POS.x*(int)ThreeQuarterHex);
			NewSelector.Screen_POS.y = (NewSelector.Map_POS.y*HexProp.y)-(NewSelector.Map_POS.x*(int)HalfHex)-(Adjustment*HexProp.y);
        }
		HexRender(HexProp,&MainGUI,MapFileName,&NewSelector.Screen_POS,EditorTemp.hexcolumn(0));
		Tool_Render(HexProp,&MainGUI,MapFileName,NewSelector);
		
        MainGUI.RenderPresent();
      }
    }
	
    MainGUI.SDLShutdown();

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
