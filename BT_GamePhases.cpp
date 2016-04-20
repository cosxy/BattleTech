#include "Classic_BT.h"
#include <vector>
#include <iostream>

using namespace std;

typedef int(*functionPtr) (MechWrapper*);

const float Run_Multiplier = 1.5;
const float MASC_Multiplier = 2.0;

void LoadMoveOptions(MechWrapper *SelectedUnit,vector<functionPtr> *Table)
{
    //Determines what options the mech has for movement.
    //builds vector based on movement variables in mechclass.
    functionPtr function_ref;
    Table->empty();

    if(SelectedUnit->can_walk == true)
    {
        function_ref = &WalkingMP;
        Table->push_back(function_ref);
    }
    if(SelectedUnit->can_run == true)
    {
        function_ref = &RunningMP;
        Table->push_back(function_ref);
    }
    if(SelectedUnit->can_jump == true)
    {
        function_ref = &JumpingMP;
        Table->push_back(function_ref);
    }
    if(SelectedUnit->has_MASC == true)
    {
        function_ref = &MASC_MP;
        Table->push_back(function_ref);
    }
}

int WalkingMP(MechWrapper *SelectedUnit)
{
    int result_MP = 0;
    result_MP = SelectedUnit->WalkTotal;
    return result_MP;
}
int RunningMP(MechWrapper *SelectedUnit)
{
    int result_MP = 0;
    float Calculator;
    Calculator = (float)SelectedUnit->WalkTotal;
    Calculator *= Run_Multiplier;
    result_MP = (int)Calculator;
    return result_MP;
}
int JumpingMP(MechWrapper *SelectedUnit)
{
    int result_MP = 0;
    result_MP = SelectedUnit->JumpTotal;
    return result_MP;
}
int MASC_MP(MechWrapper *SelectedUnit)
{
    int result_MP = 0;
    float Calculator;
    Calculator = (float)SelectedUnit->WalkTotal;
    Calculator *= MASC_Multiplier;
    result_MP = (int)Calculator;
    return result_MP;
}
void SetWalkMP(MechWrapper *SelectedUnit)
{
    int test;
    test = SelectedUnit->AssociatedUnit.Get_BaseMP();
    test = (test - MovementAdjustment);
    SelectedUnit->WalkTotal = test;
}
