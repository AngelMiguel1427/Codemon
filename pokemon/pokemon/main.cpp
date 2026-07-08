#include "pokemon.h"

int main() {
    srand(time(0));

    char seguir = 's';

    while (seguir == 's' || seguir == 'S') {

        mostrarMenu();

        // Jugador 1 elige su nombre y pokemon
        string nomJ1;
        cout << "\nNombre del Jugador 1: ";
        cin >> nomJ1;

        cout << "\nElige tu Pokemon, " << nomJ1 << " (1-" << TOTAL << "): ";
        int pJ1 = leerNumero(1, TOTAL) - 1;

        cout << "\n>> " << nomJ1 << " eligio a " << nombres[pJ1] << "! <<";
        mostrarSpriteUno(pJ1);

        // Jugador 2 elige su nombre y pokemon
        string nomJ2;
        cout << "Nombre del Jugador 2: ";
        cin >> nomJ2;

        cout << "\nElige tu Pokemon, " << nomJ2 << " (1-" << TOTAL << "): ";
        int pJ2 = leerNumero(1, TOTAL) - 1;

        cout << "\n>> " << nomJ2 << " eligio a " << nombres[pJ2] << "! <<";
        mostrarSpriteUno(pJ2);

        ejecutarBatalla(pJ1, pJ2, nomJ1, nomJ2);

        cout << "\nQuieres volver a jugar? (s/n): ";
        cin >> seguir;
    }

    cout << "\nGracias Por Jugar!\n\n";
    return 0;
}
