#ifndef GAMETYPE_H_INCLUDED
#define GAMETYPE_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

enum GamePhase
{
    Setup,
    InitPhase,
    MovePhase,
    AttackPhase,
    EndPhase,
    Cleanup
};

class GameType
{
protected:
    int SeededDice;
    void DiceInit()
        {
            if(SeededDice == 0)
            {
                time_t now;
                time(&now);
                srand(now);
                SeededDice++;
            }
        }
    int SixSidedDice()
        {
            int OneDSix;
            DiceInit();
            OneDSix = ((rand() % 6)+1);
            return OneDSix;
        }
public:
    GameType()
    {
        SeededDice = 0;
		DiceInit();
    }
    int GetDiceRoll()
    {
        int RollResult = SixSidedDice();
        return RollResult;
    }
	int DiceRoll(int DiceSize)
    {
        int result;
        DiceInit();
        result = ((rand() % DiceSize)+1);
        return result;
    }
		
};

#endif // GAMETYPE_H_INCLUDED
