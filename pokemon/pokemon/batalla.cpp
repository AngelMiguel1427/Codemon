#include "pokemon.h"

// Determina si tipoA tiene ventaja de tipo sobre tipoB.
bool tieneVentaja(string tipoA, string tipoB) {
    if (tipoA == "Fuego"     && tipoB == "Planta")    return true;
    if (tipoA == "Agua"      && tipoB == "Fuego")     return true;
    if (tipoA == "Planta"    && tipoB == "Agua")      return true;
    if (tipoA == "Electrico" && tipoB == "Agua")      return true;
    if (tipoA == "Tierra"    && tipoB == "Electrico") return true;
    return false;
}

int leerNumero(int minimo, int maximo) {
    string entrada;
    int valor;
    while (true) {
        cin >> entrada;
        if (entrada.empty()) {
            cout << "  No puedes dejar eso en blanco. Ingresa un numero entre "
                 << minimo << " y " << maximo << ": ";
            continue;
        }
        bool soloDigitos = true;
        for (int i = 0; i < (int)entrada.size(); i++) {
            if (entrada[i] < '0' || entrada[i] > '9') { soloDigitos = false; break; }
        }
        if (!soloDigitos) {
            cout << "  Solo se permiten numeros. Ingresa un numero entre "
                 << minimo << " y " << maximo << ": ";
            continue;
        }
        if (entrada.size() > 1 && entrada[0] == '0') {
            cout << "  Entrada invalida. Ingresa un numero entre "
                 << minimo << " y " << maximo << ": ";
            continue;
        }
        valor = 0;
        for (int i = 0; i < (int)entrada.size(); i++)
            valor = valor * 10 + (entrada[i] - '0');
        if (valor < minimo || valor > maximo) {
            cout << "  Numero fuera de rango. Ingresa un numero entre "
                 << minimo << " y " << maximo << ": ";
            continue;
        }
        break;
    }
    return valor;
}

void ejecutarBatalla(int pJ1, int pJ2, string nomJ1, string nomJ2) {
    // hpMax se guarda aparte de hp actual porque la barra de vida se dibuja en base a hpMax.
    int hpJ1   = hp_base[pJ1];
    int hpJ2   = hp_base[pJ2];
    int hpMaxJ1 = hpJ1;
    int hpMaxJ2 = hpJ2;
    int turno  = 1;

    cout << "\n==============================\n";
    cout << "      *** QUE EMPIECE ***     \n";
    cout << "==============================\n";

    while (hpJ1 > 0 && hpJ2 > 0) {

        cout << "\n============================\n";
        cout << "         TURNO " << turno << "\n";
        cout << "============================\n";

        mostrarBarraHP(nombres[pJ1], hpJ1, hpMaxJ1);
        mostrarBarraHP(nombres[pJ2], hpJ2, hpMaxJ2);
        mostrarSpritesLadoALado(pJ1, pJ2);

        // --- Turno del jugador 1 ---
        cout << "  [" << nomJ1 << "] elige ataque para " << nombres[pJ1] << ":\n";
        for (int i = 0; i < NUM_ATAQUES; i++) {
            cout << "    " << (i + 1) << ". " << left << setw(18)
                 << nombre_ataque[pJ1][i]
                 << "(poder: " << poder_ataque[pJ1][i] << ")\n";
        }
        cout << "\n  Elige ataque (1-" << NUM_ATAQUES << "): ";
        int ataqueJ1 = leerNumero(1, NUM_ATAQUES) - 1; // -1 porque el usuario ve 1-3, pero el arreglo usa 0-2

        int danioJ1 = poder_ataque[pJ1][ataqueJ1] + (rand() % 5);// Daño base + variación aleatoria
        bool criticoJ1 = (rand() % 10) == 0;// 10% de probabilidad de golpe crítico
        if (criticoJ1) danioJ1 = danioJ1 * 2;
        if (tieneVentaja(tipos[pJ1], tipos[pJ2])) danioJ1 = danioJ1 * 3 / 2;// 50% más de daño si tiene ventaja
        if (tieneVentaja(tipos[pJ2], tipos[pJ1])) danioJ1 = danioJ1 * 3 / 4;// 25% menos de daño si tiene desventaja
        if (danioJ1 < 1) danioJ1 = 1;

        hpJ2 = hpJ2 - danioJ1;
        if (hpJ2 < 0) hpJ2 = 0;

        cout << "\n  >> " << nombres[pJ1] << " usa "
             << nombre_ataque[pJ1][ataqueJ1]
             << " y causa " << danioJ1 << " de dano!\n";
        if (criticoJ1)
            cout << "  >> !Golpe critico!\n";
        if (tieneVentaja(tipos[pJ1], tipos[pJ2]))
            cout << "  >> !Es super efectivo!\n";
        if (tieneVentaja(tipos[pJ2], tipos[pJ1]))
            cout << "  >> No es muy efectivo...\n";

        if (hpJ2 <= 0) break;
        // Sin este break, un Pokémon con 0 HP podría seguir atacando.

        cout << "\n";

        // --- Turno del jugador 2 ---
        // (misma lógica que el jugador 1, con los roles invertidos)
        cout << "  [" << nomJ2 << "] elige ataque para " << nombres[pJ2] << ":\n";/
        for (int i = 0; i < NUM_ATAQUES; i++) {
            cout << "    " << (i + 1) << ". " << left << setw(18)
                 << nombre_ataque[pJ2][i]
                 << "(poder: " << poder_ataque[pJ2][i] << ")\n";
        }
        cout << "\n  Elige ataque (1-" << NUM_ATAQUES << "): ";
        int ataqueJ2 = leerNumero(1, NUM_ATAQUES) - 1; // -1 porque el usuario ve 1-3, pero el arreglo usa 0-2

        int danioJ2 = poder_ataque[pJ2][ataqueJ2] + (rand() % 5);// Daño base + variación aleatoria
        bool criticoJ2 = (rand() % 10) == 0;// 10% de probabilidad de golpe crítico
        if (criticoJ2) danioJ2 = danioJ2 * 2;
        if (tieneVentaja(tipos[pJ2], tipos[pJ1])) danioJ2 = danioJ2 * 3 / 2;// 50% más de daño si tiene ventaja
        if (tieneVentaja(tipos[pJ1], tipos[pJ2])) danioJ2 = danioJ2 * 3 / 4;// 25% menos de daño si tiene desventaja
        if (danioJ2 < 1) danioJ2 = 1;

        hpJ1 = hpJ1 - danioJ2;
        if (hpJ1 < 0) hpJ1 = 0;

        cout << "\n  >> " << nombres[pJ2] << " usa "
             << nombre_ataque[pJ2][ataqueJ2]
             << " y causa " << danioJ2 << " de dano!\n";
        if (criticoJ2)
            cout << "  >> !Golpe critico!\n";
        if (tieneVentaja(tipos[pJ2], tipos[pJ1]))
            cout << "  >> !Es super efectivo!\n";
        if (tieneVentaja(tipos[pJ1], tipos[pJ2]))
            cout << "  >> No es muy efectivo...\n";

        turno++;// solo se incrementa aquí, al final de la ronda completa
    }

    // Resultado
    string ganador;
    int    pokGanador;

    if (hpJ1 > 0) {
        ganador    = nomJ1;
        pokGanador = pJ1;
    } else {
        ganador    = nomJ2;
        pokGanador = pJ2;
    }

    cout << "\n==============================\n";
    cout << "       *** RESULTADO ***      \n";
    cout << "==============================\n";
    cout << "  " << ganador << " gano con " << nombres[pokGanador]
         << " en " << turno << " turnos.\n";
    mostrarSpriteUno(pokGanador);

    guardarPartida(nomJ1, nomJ2, pJ1, pJ2, ganador, turno);
    guardarHistorial(nomJ1, nomJ2, ganador, turno);
}
