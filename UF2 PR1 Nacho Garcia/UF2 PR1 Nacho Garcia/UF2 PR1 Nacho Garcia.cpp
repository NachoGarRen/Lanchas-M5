#include <iostream>
#include <thread>
#include <chrono>
#include "Lancha.h"
#include <ctime>

using namespace std;

void delay(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

int main()
{
    srand((unsigned)time(NULL));

    string jugador1;
    cout << "Escribe un nombre para la Lancha 1: ";
    cin >> jugador1;
    int vel1 = 0;
    int nitro1 = 1;
    Lancha Lancha1 = Lancha(vel1, 0, nitro1, jugador1);

    string jugador2;
    cout << "Escribe un nombre para la Lancha 2: ";
    cin >> jugador2;
    int vel2 = 0;
    int nitro2 = 1;
    Lancha Lancha2 = Lancha(vel2, 0, nitro2, jugador2);

    int contador = 0;
    int cambioVel;
    while (contador < 5){
        contador++;
        cout << "\nTurno " << contador << ":\n";

        //Lancha1
        int dado1 = 1 + rand() % 6;
        cout << jugador1 << " ha tirado un " << dado1 << "!\n";
        vel1 = Lancha1.getVelocidad() + dado1;
        Lancha1 = Lancha(vel1, vel1 * 100, nitro1, jugador1);
        Lancha1.getParameters();

        Lancha1.useNitro();
        cambioVel = Lancha1.getVelocidad();
        if (cambioVel != vel1) {
            nitro1 = 0;
            Lancha1 = Lancha(cambioVel, vel1 * 100, nitro1, jugador1);
        }
        //Lancha2
        int dado2 = 1 + rand() % 6;
        cout << "\n" << jugador2 << " ha tirado un " << dado2 << "!\n";
        vel2 = Lancha2.getVelocidad() + dado2;
        Lancha2 = Lancha(vel2, vel2 * 100, nitro2, jugador2);
        Lancha2.getParameters();

        Lancha2.useNitro();
        cambioVel = Lancha2.getVelocidad();
        if (cambioVel != vel2) {
            nitro2 = 0;
            Lancha2 = Lancha(cambioVel, vel2 * 100, nitro2, jugador2);
        }

        for (int i = 3; i > 0; i--){
            cout << "\nContinuamos en " << i;
            delay(1000);
        }
        cout << "\n";
    }

    int dist1 = Lancha1.getDisRec();
    int dist2 = Lancha2.getDisRec();
    cout << "\n" << jugador1 << " ha recorrido " << dist1 << "m, " << jugador2 << " ha recorrido " << dist2 << "m\n";
    if (dist1 > dist2)
    {
        cout << jugador1 << " ha ganado!";
    }
    else if (dist1 < dist2)
    {
        cout << jugador2 << " ha ganado!";
    }
    else
    {
        cout << "Empate!";
    }

    return 0;
}
