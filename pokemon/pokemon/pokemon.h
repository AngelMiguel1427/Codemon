#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

const int TOTAL       = 7;
const int NUM_ATAQUES = 3;
const int SPRITE_H    = 10;
const int SPRITE_W    = 20;

extern string nombres[TOTAL];
extern int    hp_base[TOTAL];
extern string tipos[TOTAL];
extern string nombre_ataque[TOTAL][NUM_ATAQUES];
extern int    poder_ataque[TOTAL][NUM_ATAQUES];
extern string sprites[TOTAL][SPRITE_H];

// ui.cpp
void mostrarMenu();
void mostrarSpriteUno(int idx);
void mostrarSpritesLadoALado(int idxJ1, int idxJ2);
void mostrarBarraHP(string nombre, int hp, int hpMax);

// batalla.cpp
bool tieneVentaja(string tipoA, string tipoB);
int  leerNumero(int minimo, int maximo);
void ejecutarBatalla(int pJ1, int pJ2, string nomJ1, string nomJ2);

// archivos.cpp
void guardarPartida(string nomJ1, string nomJ2, int pJ1, int pJ2, string ganador, int turnos);
void guardarHistorial(string nomJ1, string nomJ2, string ganador, int turnos);

#endif
