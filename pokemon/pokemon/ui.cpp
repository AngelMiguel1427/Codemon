#include "pokemon.h"

void mostrarMenu() {
    cout << "\n==============================\n";
    cout << "       BATALLA POKEMON        \n";
    cout << "==============================\n";
    cout << "\nPokemon disponibles:\n";
    cout << "----------------------------\n";
    for (int i = 0; i < TOTAL; i++) {
        cout << "  " << (i + 1) << ". " << left << setw(12) << nombres[i]
             << " | HP: " << setw(4) << hp_base[i]
             << " | Tipo: " << tipos[i] << "\n";
    }
    cout << "----------------------------\n";
}

void mostrarSpriteUno(int idx) {
    cout << "\n";
    for (int i = 0; i < SPRITE_H; i++)
        cout << "  " << sprites[idx][i] << "\n";
    cout << "\n";
}

void mostrarSpritesLadoALado(int idxJ1, int idxJ2) {
    cout << "\n  "
         << left << setw(SPRITE_W + 4) << ("[ " + nombres[idxJ1] + " ]")
         << "[ " << nombres[idxJ2] << " ]\n";

    for (int i = 0; i < SPRITE_H; i++) {
        cout << "  " << left << setw(SPRITE_W + 4) << sprites[idxJ1][i]
             << sprites[idxJ2][i] << "\n";
    }
    cout << "\n";
}

void mostrarBarraHP(string nombre, int hp, int hpMax) {
    int llenas = (hp * 12) / hpMax;
    if (llenas < 0) llenas = 0;
    if (llenas > 12) llenas = 12;
    int vacias = 12 - llenas;

    cout << "  " << left << setw(13) << nombre << " HP: [";
    for (int i = 0; i < llenas; i++)  cout << "#";
    for (int i = 0; i < vacias; i++) cout << "-";
    cout << "] " << hp << "/" << hpMax << "\n";
}
