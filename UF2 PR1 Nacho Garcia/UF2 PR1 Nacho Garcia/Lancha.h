#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class Lancha
{
private:
    int Vel;
    int DisRec;
    int Nitro;
    string Name;
    bool nitroUsed;

public:
    void getParameters();
    void useNitro();
    int getVelocidad();
    int getDisRec();
    Lancha();
    Lancha(int pVel, int pDisRec, int pNitro, string pName);
};
