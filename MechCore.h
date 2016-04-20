#ifndef MECHCORE_H_INCLUDED
#define MECHCORE_H_INCLUDED

#include <iostream>
#include <map>

using namespace std;

enum MechBodyPart
{
    CTORSO,
    RTORSO,
    LTORSO,
    RARM,
    LARM,
    RLEG,
    LLEG,
    HEAD
};

enum ArmorSection
{
    ExteriorArmor,
    Structure,
    RearArmor
};

class BattleMech
{
    public:

        int GetArmorValue(MechBodyPart LocLookup, ArmorSection ArmorType);
        bool FindComponent(string SearchTarget);
        int Get_BaseMP()
        {
            return EngineRating/Tonnage;
        }

    private:
        string CommonName;
        string ModelNumber;
        int Tonnage,BattleValue,C_BillValue;
        int HeatSinkTotal;
        int EngineRating;
        int ExternalArmor[8];
        int RearArmor[3];
        int StructureValues[8];
        bool ClanOMNIMECH;
        map<int,string> CriticalTable;

        //Setup Class
        void SetCoreVar()
        {
            ClanOMNIMECH = false;
            BattleValue = 0;
            C_BillValue = 0;
            HeatSinkTotal = 10;
            JumpTotal = 0;
            WalkTotal = 0;
            EngineRating = 0;
            Tonnage = 0;
        }
};

#endif // MECHCORE_H_INCLUDED
