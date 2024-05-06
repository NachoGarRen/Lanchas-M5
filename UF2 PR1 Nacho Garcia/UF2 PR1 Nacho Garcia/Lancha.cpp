#include "Lancha.h"
#include <ctime>

void Lancha::getParameters()
{
    cout 
        << "Velocidad actual: " << Vel
        << "\nDistancia Recorrida: " << DisRec
        << "\nNitro: " << Nitro << "\n";
}

void Lancha::useNitro(){
    srand((unsigned)time(NULL));
    if (Nitro == 1) {
        char respuesta;
        cout << "Deseas usar la nitro? (s/n): ";
        cin >> respuesta;
        if (respuesta == 's' || respuesta == 'S') {
            int random = rand() % 2;
            if (random == 0) {
                Vel /= 2;
                cout << "La velocidad se ha dividido por 2!\n";
                cout << "La nueva velocidad es de: " << Vel << "\n";
            }
            else {
                Vel *= 2;
                cout << "La velocidad se ha multiplicado por 2!\n";
                cout << "La nueva velocidad es de: " << Vel << "\n";
            }
        }
    }
    else{
        cout << "La nitro ya se ha usado en esta carrera!\n";
    }
}

int Lancha::getVelocidad(){
    return Vel;
}

int Lancha::getDisRec(){
    return DisRec;
}

Lancha::Lancha(){
    Vel = 0;
    DisRec = 0;
    Nitro = 1;
    Name = "?";
}

Lancha::Lancha(int pVel, int pDisRec, int pNitro, string pName)
{
    Vel = pVel;
    DisRec = pDisRec;
    Nitro = pNitro;
    Name = pName;
    nitroUsed = false;
}
