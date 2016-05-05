#include "Classic_BT.h"
#include "MechCore.h"
#include <iostream>

using namespace std;

MechWrapper::MechWrapper()
{
    ActionDone = false;
    PoweredOff = false;
    OutOfPlay = false;
    Prone = false;
    AMSActive = false;
    SearchLightsActive = false;
    Hidden = false;
    TurnHeat = 0;
    OverHeatTotal = 0;
    MovementAdjustment = 0;
    ShootingAdjustment = 0;
    MapLocX = 0;
    MapLocY = 0;
    Facing = 0;

    IMGRotation = 0.0;

    CurrentPosse = Moving;
    SelectedMode = Standing;
}

void MechWrapper::ClearAction()
{
    ActionDone = false;
}
void MechWrapper::SetAction()
{
    ActionDone = true;
}
void MechWrapper::UnitOutofPlay()
{
    OutOfPlay = true;
}
void MechWrapper::TurnHeatReset()
{
    TurnHeat = 0;
}
void MechWrapper::AddTurnHeat(int Heat2Add)
{
    TurnHeat += Heat2Add;
}
int MechWrapper::GetCurrentHeatLevel()
{
    OverHeatTotal += (TurnHeat - AssociatedUnit.HeatSinkTotal);

    TurnHeatReset();

    if(OverHeatTotal < 0)
    {
        OverHeatTotal = 0;
    }

    return OverHeatTotal;
}
