#ifndef CLASSIC_BT_H_INCLUDED
#define CLASSIC_BT_H_INCLUDED

#include "MechCore.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
//#include <SDL.h>
//#include <SDL_image.h>

using namespace std;

enum ClingONType
{
    FLAG,
    NARC,
    INFERNO,
    BATTLEARMOR,
    INFANTRY,
    BOMB
};

enum ActionIMG
{
    Moving,
    TorsoTurn,
    Falling,
    Climbing,
    JumpJet,
    Dead
};

enum MovementOption
{
    Standing,
    Walking,
    Running,
    Jumping
};

class MechWrapper
{
public:
    BattleMech AssociatedUnit;
    //Pilot AssociatedCharacter;

    MechWrapper();
    void ClearAction();
    void SetAction();
    void UnitOutofPlay();
    void TurnHeatReset();
    void AddTurnHeat(int Heat2Add);
    int GetCurrentHeatLevel();
    void DestroyPart(int SectionID);
    void DestroySection(MechBodyPart Section);

protected:
        int DamagedArmor[8];
        int DamagedRear[3];
        int DamagedStructure[8];
        int TurnHeat,OverHeatTotal;
        int JumpTotal,WalkTotal;
        int MovementAdjustment,ShootingAdjustment;
        int MapLocX,MapLocY,Facing;
        float IMGRotation;
        map<string,string> Weapon2Ammmo;
        map<string,int> AmmoStorage;
        map<string,int> DamagedComponentList;
        vector<ClingONType> CarryingObject;
        bool Prone,AMSActive,SearchLightsActive,Hidden;
        bool can_walk,can_run,can_jump,has_MASC;
        bool ActionDone,PoweredOff,OutOfPlay;
        ActionIMG CurrentPosse;
        MovementOption SelectedMode;
        //SDL_Texture *LoadedIMG;
        //SDL_RendererFlip IMGFLIP;
};

#endif // CLASSIC_BT_H_INCLUDED
