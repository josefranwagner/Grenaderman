#include <stdbool.h>

#ifndef GRENADERMAN_H
#define GRENADERMAN_H

#define MAXIMO_HECTAREAS 10
#define MAXIMO_GRANADAS 7

// PRE: Las matrices deben estar creadas.
// POST: Si puede realizar el cambio de tipo de terreno de la hectárea
//ubicada en la fila y columna indicadas, lo concreta y devuelve true,
//sino abortará la operación y devolverá false.
bool cambiarTipoTerreno (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,char tipoTerreno);


// PRE: Las matrices deben estar creadas.
// POST: Si puede posicionar el cañón de perlas en la hectárea
//ubicada en la fila y columna indicadas devuelve true, sino abortará
//la operación y devolverá false.
bool posicionarCanionPerlas (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna);


// PRE: Las matrices deben estar creadas.
// POST: Si puede posicionar la torre coralina en la hectárea ubicada
//en la fila y columna indicadas devuelve true, sino abortará la
//operación y devolverá false.
bool posicionarTorreCoralina (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna);


// PRE: Las matrices deben estar creadas. Si el parámetro
//enDireccionesCardinales es true entonces se colocarán las defensas
//en las direcciones cardinales, sino será en las diagonales.
// POST: Si puede posicionar la nebular hirviente en la hectárea
//ubicada en la fila y columna indicadas devuelve true, sino abortará
//la operación y devolverá false.
bool posicionarNebularHirviente (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,bool enDireccionesCardinales);


// PRE: Las matrices deben estar creadas.
// POST: Si puede posicionar el huracán de tiburones en la hectárea
//ubicada en la fila y columna indicadas devuelve true, sino abortará
//la operación y devolverá false.
bool posicionarHuracanTiburones (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna);


// PRE: Las matrices deben estar creadas.
// POST: Si puede posicionar el leviatanque en las hectáreas
//indicadas (fila y columna desde corresponden a la punta noroeste
//de la máquina, y fila y columna hasta a la punta sureste) devuelve
//true, sino abortará la operación y devolverá false.
bool posicionarLeviatanque (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int filaDesde, int columnaDesde,int filaHasta, int columnaHasta);


// PRE: Las matrices deben estar creadas.
// POST: Si tiene suficientes municiones, libera una granada
//justiciera en la hectárea ubicada en la fila y columna indicadas.
//De ser así, actualizará la cantidad restante de municiones e
//indicará cuántas hectáreas sufrieron daño por la explosión junto
//con sus pares fila-columna, y finalmente devolverá true. Caso
//contrario se abortará la operación y devolverá false.
bool liberarGranadaJusticiera(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,int *municiones, int *cantHectareasAfectadas, int hectareasAfectadas[9][2]);


// PRE: Las matrices deben estar creadas.
// POST: Si tiene suficientes municiones, libera una granada
//verdadera en la hectárea ubicada en la fila y columna indicadas.
//De ser así, actualizará la cantidad restante de municiones e
//indicará cuántas hectáreas sufrieron daño por la explosión junto
//con sus pares fila-columna, y finalmente devolverá true. Caso
//contrario se abortará la operación y devolverá false.
bool liberarGranadaVerdadera (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,int *municiones, int *cantHectareasAfectadas, int hectareasAfectadas[9][2]);

#endif