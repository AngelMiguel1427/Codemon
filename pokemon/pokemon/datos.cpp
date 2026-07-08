#include "pokemon.h"

string nombres[TOTAL] = {"Charmander","Squirtle","Bulbasaur","Pikachu","Geodude","Jynx","Eevee"};
int    hp_base[TOTAL] = {120, 120, 125, 110, 140, 105, 115};
string tipos[TOTAL]   = {"Fuego","Agua","Planta","Electrico","Tierra","Hielo","Normal"};

string nombre_ataque[TOTAL][NUM_ATAQUES] = {
    {"Llamarada",    "Garra",          "Ascuas"},
    {"BurbujaCid",   "Placaje",        "Pistola de Agua"},
    {"Latigo",       "Hoja Navaja",    "Hoja Afilada"},
    {"Impactrueno",  "Ataque Voltio",  "Rayo"},
    {"Avalancha",    "Explosion",      "Patada"},
    {"Ventisca",     "Psiquico",       "Soplo Helado"},
    {"Ataque Rapido","Colmillo",       "Placaje"}
};

int poder_ataque[TOTAL][NUM_ATAQUES] = {
    {30, 20, 25},
    {28, 18, 32},
    {22, 30, 28},
    {35, 40, 38},
    {25, 45, 20},
    {35, 30, 28},
    {22, 25, 20}
};

string sprites[TOTAL][SPRITE_H] = {
    // 0 - Charmander
    {
        "    _,--._      ",
        "   /   ..  )    ",
        "  ( o    o  )   ",
        "   \\  == /      ",
        "   /|    |\\     ",
        "  ( |    | )    ",
        "   \\|    |/     ",
        "    |    |      ",
        "   (_)  (_)     ",
        "  ~Charmander~  "
    },
    // 1 - Squirtle
    {
        "   _______      ",
        "  / o   o \\     ",
        " |    ^    |    ",
        " |  \\_W_/  |    ",
        "  \\_______/     ",
        "  /|     |\\     ",
        " ( |     | )    ",
        "  \\|_____|/     ",
        "   |     |      ",
        "  ~Squirtle~    "
    },
    // 2 - Bulbasaur
    {
        "  | || || |     ",
        "  |_||_||_|     ",
        "  (  o  o  )    ",
        "  (   ___  )    ",
        "  /|       |\\   ",
        " ( |       | )  ",
        "  \\|_______|/   ",
        "   |       |    ",
        "  (_)     (_)   ",
        "  ~Bulbasaur~   "
    },
    // 3 - Pikachu
    {
        "  /\\ .  . /\\    ",
        " (  o    o  )   ",
        "  \\ ------ /    ",
        "  /|      |\\    ",
        " / |  __  | \\   ",
        "|  | /  \\ |  |  ",
        " \\_|/    \\|_/   ",
        "  /|      |\\    ",
        " (_)      (_)   ",
        "  ~~Pikachu~~   "
    },
    // 4 - Geodude
    {
        "   .  .  .      ",
        "  _________     ",
        " / .  o  o \\    ",
        "|  .  ___  |    ",
        "|   \\_   _/|    ",
        " \\    ---   /   ",
        "  \\_________/   ",
        "   /       \\    ",
        "  (         )   ",
        "  ~Geodude~     "
    },
    // 5 - Jynx
    {
        "   /\\_____/\\    ",
        "  ( o     o )   ",
        "  (    <    )   ",
        "   \\  ___  /    ",
        "   /|     |\\    ",
        "  / | ~~~ | \\   ",
        " |  |     |  |  ",
        "  \\ |_____| /   ",
        "   \\_______/    ",
        "   ~~Jynx~~     "
    },
    // 6 - Eevee
    {
        "  /\\       /\\   ",
        " (  \\ . . /  )  ",
        "  ( o     o )   ",
        "   \\  ___  /    ",
        "  /|  \\_/  |\\   ",
        " / |       | \\  ",
        "|  |       |  | ",
        " \\_|       |_/  ",
        "  (_)     (_)   ",
        "   ~~Eevee~~    "
    }
};
