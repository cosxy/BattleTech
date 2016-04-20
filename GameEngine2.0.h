#ifndef GAMEENGINE2_0_H_INCLUDED
#define GAMEENGINE2_0_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameType.h"
#include "ScreenMgt.h"

enum PrebuiltGameTypes
{
    Nothing,
    QuickStart,
    ClassicBattleTech,
    BattleForce,
    MechBuilder,
    MapBuilder,
    Survival,
    MechWarrior
};

using namespace std;

class BattleTechCore
{
    protected:
        int TurnCount;
        time_t StopWatch;
        bool HaltEngine;
        GamePhase CurrentPhase;
        void CallPhaseFunction(GamePhase GamePOS);

    public:
        BattleTechCore()
        {
            TurnCount = 0;
            time(&StopWatch);
            HaltEngine = false;
            CurrentPhase = Setup;
        }
        void MainGameEngine();
};

#endif // GAMEENGINE2_0_H_INCLUDED
