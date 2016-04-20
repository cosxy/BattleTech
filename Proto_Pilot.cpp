#include <iostream>
#include <vector>

using namespace std;

int checksum = 7;

class ProtoTypeObject
{
public:
    int Container;
    float Calculator;
};

void IntMod(ProtoTypeObject *test)
{
    test->Container = checksum;
    test->Calculator = ((float)checksum/3);
    checksum++;
}

void ReadOut(ProtoTypeObject *test)
{
    cout << test->Container << "\t" << test->Calculator << endl;
}

typedef void(*FunctionPtr) (ProtoTypeObject*);

int main()
{
    FunctionPtr address = &ReadOut;
    ProtoTypeObject expariment;

    vector<FunctionPtr> ObjectList;

    expariment.Container = 0;
    expariment.Calculator = 0;

    ObjectList.push_back(address);
    address = &IntMod;
    ObjectList.push_back(address);
    address = &ReadOut;
    ObjectList.push_back(address);

    for(int x=0;x<3;x++)
    {
        ObjectList[x](&expariment);
    }

    return 0;
}
