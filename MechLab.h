#ifndef MECHLAB_H_INCLUDED
#define MECHLAB_H_INCLUDED

#include <vector>
#include <map>
#include <string>
#include "MechCore.h"

using namespace std;


enum PartArchitecture
{
    FIXED,
    LIMITED,
    SWAPABLE
};

class MechComponent
{
public:
    int Tonnage;
    int StorageSpace;
    int PartID;
    string PartName;
    PartArchitecture PartCharacteristic;
};

class MechSection
{
public:
    MechBodyPart SectionName;
    MechBodyPart NextSectionLoc;
    bool SectionDestroyed;
    bool CASEActive;
    int ComponentCount;
    int StructureTotal;
    int PrimaryArmorValue;
    int RearArmorValue;
    vector<MechComponent *> CriticalTable;
private:
    int MaxStorageSpace;
    int SectionTonnage;
};

class LabMech
{
    public:
        string CommonName;
        string ModelNumber;
        map<MechComponent,int> ComponentMap;
        MechSection CoreSection[8];
        int TotalTonnage,BattleValue,C_BillValue;
        int HeatSinkTotal,TotalDamage,TotalHeat;
        int JumpTotal,WalkTotal,EngineRating;
        bool ClanOMNIMECH;
};

#endif // MECHLAB_H_INCLUDED
