#include "MechCore.h"

void BattleMech::SetCoreVar()
{
    ActionDone = false;
    PoweredOff = false;
    OutOfPlay = false;
    Prone = false;
    AMSActive = false;
    SearchLightsActive = false;
    Hidden = false;
    ClanOMNIMECH = false;

    BattleValue = 0;
    C_BillValue = 0;
    TurnHeat = 0;
    OverHeatTotal = 0;
    HeatSinkTotal = 10;
    JumpTotal = 0;
    WalkTotal = 0;
    EngineRating = 0;
    Tonnage = 0;
    MovementAdjustment = 0;
    ShootingAdjustment = 0;
    MapLocX = 0;
    MapLocY = 0;
    Facing = 0;

    IMGRotation = 0.0;

    CurrentPosse = Moving;
    SelectedMode = Standing;
}
void BattleMech::ClearAction()
{
    ActionDone = false;
}
void BattleMech::SetAction()
{
    ActionDone = true;
}
void BattleMech::UnitOutofPlay()
{
    OutOfPlay = true;
}
void BattleMech::TurnHeatReset()
{
    TurnHeat = 0;
}
void BattleMech::AddTurnHeat(int Heat2Add)
{
    TurnHeat += Heat2Add;
}
int BattleMech::GetCurrentHeatLevel()
{
    OverHeatTotal += (TurnHeat - HeatSinkTotal);

    TurnHeatReset();

    if(OverHeatTotal < 0)
    {
        OverHeatTotal = 0;
    }

    return OverHeatTotal;
}
