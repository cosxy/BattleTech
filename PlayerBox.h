#ifndef PLAYERBOX_H_INCLUDED
#define PLAYERBOX_H_INCLUDED

#include "Classic_BT.h"

enum TeamID
{
    Attackers,
    Defenders
};

class PlayerGameBox
{
    protected:
        map<string,MechWrapper> MechList;
        int TurnPriority();
        int UnitTotal;
        TeamID Alliance;
};

#endif // PLAYERBOX_H_INCLUDED
