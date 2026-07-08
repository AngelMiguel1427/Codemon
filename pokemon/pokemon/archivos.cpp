#include "pokemon.h"

void guardarPartida(string nomJ1, string nomJ2, int pJ1, int pJ2, string ganador, int turnos) { 
    ofstream archivo("partida_guardada.txt");

    if (archivo.is_open()) {
        time_t ahora = time(0);
        char* fecha  = ctime(&ahora);

        archivo << "==============================\n";
        archivo << "  PARTIDA GUARDADA\n";
        archivo << "==============================\n";
        archivo << "Fecha: " << fecha;
        archivo << "Jugador 1: " << nomJ1 << "\n";
        archivo << "  Pokemon: " << nombres[pJ1] << "\n";
        archivo << "  Tipo:    " << tipos[pJ1] << "\n";
        archivo << "Jugador 2: " << nomJ2 << "\n";
        archivo << "  Pokemon: " << nombres[pJ2] << "\n";
        archivo << "  Tipo:    " << tipos[pJ2] << "\n";
        archivo << "------------------------------\n";
        archivo << "Ganador:  " << ganador << "\n";
        archivo << "Turnos:   " << turnos << "\n";
        archivo << "==============================\n";

        archivo.close();
        cout << "\n  >> Partida guardada en 'partida_guardada.txt'\n";
    } else {
        cout << "\n  >> No se pudo guardar la partida.\n";
    }
}

void guardarHistorial(string nomJ1, string nomJ2, string ganador, int turnos) {
    ofstream archivo("historial_batallas.txt", ios::app);

    if (archivo.is_open()) {
        time_t ahora = time(0);
        char* fecha  = ctime(&ahora);

        archivo << fecha;
        archivo << nomJ1 << " vs " << nomJ2
                << " | Ganador: " << ganador
                << " | Turnos: " << turnos << "\n";
        archivo << "------------------------------\n";

        archivo.close();
        cout << "  >> Batalla registrada en 'historial_batallas.txt'\n";
    } else {
        cout << "  >> No se pudo guardar el historial.\n";
    }
}
