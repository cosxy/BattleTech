#ifndef BT_HEXMAP_H_INCLUDED
#define BT_HEXMAP_H_INCLUDED

#include <iostream>
#include "BattleMap.pb.h"

using namespace std;

enum MapBuildOrder
{
    VIRTICAL_LINE,
    HORIZONTAL_LINE,
    SQUARED_BOX,
    VIRTICAL_BOX,
    HORIZONTAL_BOX
};

class BattleMap
{
protected:
    BattleTech_GameBoard::BattleField GameBoard;
    int ColumnTotal;
    int RowTotal;
    int MapTotal;
    MapBuildOrder MapConfig;
public:
    BattleMap()
    {
        ColumnTotal = 0;
        RowTotal = 0;
        MapTotal = 0;
        MapConfig = HORIZONTAL_LINE;
    }
    bool AddMap(BattleTech_GameBoard::BattleField BTGameMap);
    bool SetBuildOrder(MapBuildOrder BuildOrder)
    {
        bool Success = false;
        if(BuildOrder >= VIRTICAL_LINE && BuildOrder <= HORIZONTAL_BOX )
        {
            MapConfig = BuildOrder;
            Success = true;
        }
        return Success;
    }
    MapHex* RetrieveHex(int RowNumber,ColumnNumber);
};


#endif // BT_HEXMAP_H_INCLUDED
