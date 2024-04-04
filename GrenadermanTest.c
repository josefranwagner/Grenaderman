#include <stdio.h>
#include <stdbool.h>
#include "Grenaderman.h"

void mostrarMatriz(char matriz[][MAXIMO_HECTAREAS]){
	for(int i=0;i<MAXIMO_HECTAREAS;i++){
		for(int j=0;j<MAXIMO_HECTAREAS;j++){
			printf("%c",matriz[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}

void inicializarTerrenos(char terrenos[][MAXIMO_HECTAREAS]){
	for(int i=0;i<MAXIMO_HECTAREAS;i++){
		for(int j=0;j<MAXIMO_HECTAREAS;j++){
			terrenos[i][j]=' ';
		}
	}
}

void inicializarMaquinas(char maquinas[][MAXIMO_HECTAREAS]){
	for(int i=0;i<MAXIMO_HECTAREAS;i++){
		for(int j=0;j<MAXIMO_HECTAREAS;j++){
			maquinas[i][j]=' ';
		}
	}
}

//Inicio Tests terrenos.

void cambiarTerrenoASimpleSinMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	
	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 4, 4, ' ');
	resultado = (resultado == true) && (terrenos[3][3] == ' ');
	
	if (resultado == true)
		printf("cambiarTerreno a simple sin maquina: OK\n\n");
	else
		printf("cambiarTerreno a simple sin maquina: ERROR\n\n");
}

void cambiarTerrenoASimpleConMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	
	maquinas[3][3]='C';
	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 4, 4, ' ');
	resultado = (resultado == true) && (terrenos[3][3] == ' ')&&(maquinas[3][3]=='C');
	
	if (resultado == true)
		printf("cambiarTerreno a simple con maquina: OK\n\n");
	else
		printf("cambiarTerreno a simple con maquina: ERROR\n\n");
}

void cambiarTerrenoAAbismalSinMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	
	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 4, 4, 'A');
	resultado = (resultado == true) && (terrenos[3][3] == 'A');
	
	if (resultado == true)
		printf("cambiar terreno a abismal sin maquina: OK\n\n");
	else
		printf("cambiar terreno a abismal sin maquina: ERROR\n\n");
}

void cambiarTerrenoAAbismalConMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	
	posicionarCanionPerlas(terrenos,maquinas,4,4);
	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 4, 4, 'A');
	resultado = (resultado == true) && (terrenos[3][3] == 'A') && (maquinas[3][3]==' ');
	
	if (resultado == true)
		printf("cambiar terreno a abismal con maquina: OK\n\n");
	else
		printf("cambiar terreno a abismal con maquina: ERROR\n\n");
}

void cambiarTerrenoSinMaquinaAMontanioso () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 1, 1, 'M');
	resultado = (resultado == true) && (terrenos[0][0] == 'M');

	if (resultado == true) {
		printf("Cambiar terreno sin maquina a montañoso: OK\n\n");
	}
	else {
		printf("Cambiar terreno sin maquina a montañoso: ERROR\n\n");
	}
}

void cambiarTerrenoConMaquinaAMontanioso () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	posicionarCanionPerlas(terrenos,maquinas,1,1);
	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 1, 1, 'M');
	resultado = (resultado == false) && (terrenos[0][0] != 'M') && (maquinas[0][0]=='C');

	if (resultado == true) {
		printf("Cambiar terreno con maquina a montañoso: OK\n\n");
	}
	else {
		printf("Cambiar terreno con maquina a montañoso: ERROR\n\n");
	}
}

void cambiarTerrenoFueraDelMapa () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = cambiarTipoTerreno(terrenos, maquinas, 0, 0, 'M');

	if (resultado == false) {
		printf("Cambio del terreno coordenadas afuera del mapa : OK\n\n");
	}
	else {
		printf("Cambio del terreno coordenadas afuera del mapa : ERROR\n\n");
	}
}

//Fin Tests Terrenos

//Inicio Test Cañon Perlas

void posicionarCanionFueraDelMapa (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarCanionPerlas (terrenos, maquinas, -1, -1);

	if (resultado == false) {
		printf("Posicionar el Cañon de perlas fuera del mapa : OK\n\n");
	}
	else {
		printf("Posicionar el Cañon de perlas fuera del mapa : ERROR\n\n");
	}
}

void posicionarCanionSobreMontania (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='M';
	bool resultado = posicionarCanionPerlas (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar cañon sobre montaña : OK\n\n");
	}
	else {
		printf("Posicionar cañon sobre montaña : ERROR\n\n");
	}
}

void posicionarCanionSobreAbismo (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='A';
	bool resultado = posicionarCanionPerlas (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar cañon sobre abismo : OK\n\n");
	}
	else {
		printf("Posicionar cañon sobre abismo : ERROR\n\n");
	}
}

void posicionarCanionSobreMaquina (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[0][0]='T';
	bool resultado = posicionarCanionPerlas (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar cañon sobre maquina : OK\n\n");
	}
	else {
		printf("Posicionar cañon sobre maquina : ERROR\n\n");
	}
}

void posicionarCanionSobreTerrenoSimple(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarCanionPerlas(terrenos,maquinas,1,1);
	resultado = (resultado==true)&&(maquinas[0][0]=='C');

	if (resultado == true) {
		printf("Posicionar cañon sobre terreno simple : OK\n\n");
	}
	else {
		printf("Posicionar cañon sobre terreno simple : ERROR\n\n");
	}		
}
//Fin Tests Cañon Perlas
//Inicio Tests Torre Coralina

void posicionarTorreFueraDelMapa (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, -1, -1);

	if (resultado == false) {
		printf("Posicionar Torre fuera del mapa : OK\n\n");
	}
	else {
		printf("Posicionar Torre fuera del mapa : ERROR\n\n");
	}
}

void posicionarTorreSobreMontania (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='M';
	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar torre sobre montaña : OK\n\n");
	}
	else {
		printf("Posicionar torre sobre montaña : ERROR\n\n");
	}
}

void posicionarTorreSobreAbismo (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='A';
	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar torre sobre abismo : OK\n\n");
	}
	else {
		printf("Posicionar torre sobre abismo : ERROR\n\n");
	}
}

void posicionarTorreSobreMaquina (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[0][0]='T';
	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 1, 1);

	if (resultado == false) {
		printf("Posicionar torre sobre maquina : OK\n\n");
	}
	else {
		printf("Posicionar torre sobre maquina : ERROR\n\n");
	}
}

void posicionarTorreSobreTerrenoSimple(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 5, 5);
	resultado = (resultado==true)&&(maquinas[3][3]=='t')&&(maquinas[3][4]=='t')&&(maquinas[3][5]=='t');
	resultado = (resultado==true)&&(maquinas[4][3]=='t')&&(maquinas[4][4]=='T')&&(maquinas[4][5]=='t');
	resultado = (resultado==true)&&(maquinas[5][3]=='t')&&(maquinas[5][4]=='t')&&(maquinas[5][5]=='t');

	if (resultado == true) {
		printf("Posicionar Torre sobre terreno simple : OK\n\n");
	}
	else {
		printf("Posicionar Torre sobre terreno simple : ERROR\n\n");
	}
}

void posicionarTorreConMontaniaASuDerecha(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[4][5]='M';
	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 5, 5);
	resultado = (resultado==true)&&(maquinas[3][3]=='t')&&(maquinas[3][4]=='t')&&(maquinas[3][5]=='t');
	resultado = (resultado==true)&&(maquinas[4][3]=='t')&&(maquinas[4][4]=='T')&&(maquinas[4][5]==' ');
	resultado = (resultado==true)&&(maquinas[5][3]=='t')&&(maquinas[5][4]=='t')&&(maquinas[5][5]=='t');

	if (resultado == true) {
		printf("Posicionar torre con montaña a su derecha : OK\n\n");
	}
	else {
		printf("Posicionar torre con montaña a su derecha : ERROR\n\n");
	}
}

void posicionarTorreEsquinaSuperiorIzquierda(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 1, 1);
	resultado = (resultado==true)&&(maquinas[0][0]=='T')&&(maquinas[0][1]=='t')&&(maquinas[1][0]=='t')&&(maquinas[1][1]=='t');

	if (resultado == true) {
		printf("Posicionar torre esquina superior izquierda: OK\n\n");
	}
	else {
		printf("Posicionar torre esquina superior izquierda: ERROR\n\n");
	}
}

void posicionarTorreEsquinaSuperiorDerecha(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 1, 10);
	resultado = (resultado==true)&&(maquinas[0][9]=='T')&&(maquinas[0][8]=='t')&&(maquinas[1][8]=='t')&&(maquinas[1][9]=='t');

	if (resultado == true) {
		printf("Posicionar torre esquina superior derecha: OK\n\n");
	}
	else {
		printf("Posicionar torre esquina superior derecha: ERROR\n\n");
	}
}

void posicionarTorreEsquinaInferiorDerecha(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 10, 10);
	resultado = (resultado==true)&&(maquinas[9][9]=='T')&&(maquinas[8][9]=='t')&&(maquinas[8][8]=='t')&&(maquinas[9][8]=='t');

	if (resultado == true) {
		printf("Posicionar torre esquina inferior derecha: OK\n\n");
	}
	else {
		printf("Posicionar torre esquina inferior derecha: ERROR\n\n");
	}
}

void posicionarTorreEsquinaInferiorIzquierda(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarTorreCoralina (terrenos, maquinas, 10, 1);
	resultado = (resultado==true)&&(maquinas[9][0]=='T')&&(maquinas[8][0]=='t')&&(maquinas[8][1]=='t')&&(maquinas[9][1]=='t');

	if (resultado == true) {
		printf("Posicionar torre esquina inferior izquieda: OK\n\n");
	}
	else {
		printf("Posicionar torre esquina inferior izquierda: ERROR\n\n");
	}
}

//Fin Tests Torre Coralina
//Inicio Tests Nebular Cardinal

void posicionarNebularCardinalFueraDelMapa (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=true;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, -1, -1,Cardinal);

	if (resultado == false) {
		printf("Posicionar Nebular Cardinal fuera del mapa : OK\n\n");
	}
	else {
		printf("Posicionar Nebular Cardinal fuera del mapa : ERROR\n\n");
	}
}

void posicionarNebularDiagonalSobreMontania (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=false;

	terrenos[0][0]='M';
	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 1, 1,Cardinal);

	if (resultado == false) {
		printf("Posicionar Nebular Diagonal sobre montaña : OK\n\n");
	}
	else {
		printf("Posicionar Nebular Diagonal sobre montaña : ERROR\n\n");
	}
}

void posicionarNebularCardinalSobreAbismo (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=true;

	terrenos[0][0]='A';
	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 1, 1,Cardinal);

	if (resultado == false) {
		printf("Posicionar Nebular Cardinal sobre abismo : OK\n\n");
	}
	else {
		printf("Posicionar Nebular Cardinal sobre abismo : ERROR\n\n");
	}
}

void posicionarNebularDiagonalSobreMaquina (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=false;

	maquinas[0][0]='T';
	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 1, 1,Cardinal);

	if (resultado == false) {
		printf("Posicionar Nebular Diagonal sobre maquina : OK\n\n");
	}
	else {
		printf("Posicionar Nebular Diagonal sobre maquina : ERROR\n\n");
	}
}

void posicionarNebularDiagonalLimiteIzquierdo(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=false;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 6, 1,Cardinal);
	resultado = (resultado==true)&&(maquinas[5][0]=='Z')&&(maquinas[4][1]=='n')&&(maquinas[6][1]=='n');

	if (resultado == true) {
		printf("Posicionar Nebular Diagonal sobre limite izquierdo: OK\n\n");
	}
	else {
		printf("Posicionar Nebular Diagonal sobre limite izquierdo: ERROR\n\n");
	}
}
void posicionarNebularDiagonalLimiteDerecho(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=false;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 6, 10,Cardinal);
	resultado = (resultado==true)&&(maquinas[5][9]=='Z')&&(maquinas[4][8]=='n')&&(maquinas[6][8]=='n');

	if (resultado == true) {
		printf("Posicionar Nebular Diagonal sobre limite derecho: OK\n\n");
	}
	else {
		printf("Posicionar Nebular Diagonal sobre limite derecho: ERROR\n\n");
	}
	printf("Prueba");
}

void posicionarNebularCardinalLimiteSuperior(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=true;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 1, 6,Cardinal);
	resultado = (resultado==true)&&(maquinas[0][5]=='N')&&(maquinas[0][4]=='n')&&(maquinas[0][6]=='n')&&(maquinas[1][5]=='n');

	if (resultado == true) {
		printf("Posicionar Nebular Cardinal sobre limite superior: OK\n\n");
	}
	else {
		printf("Posicionar Nebular Cardinal sobre limite superior: ERROR\n\n");
	}
}
void posicionarNebularCardinalLimiteInferior(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=true;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 10, 6,Cardinal);
	resultado = (resultado==true)&&(maquinas[9][5]=='N')&&(maquinas[9][4]=='n')&&(maquinas[9][6]=='n')&&(maquinas[8][5]=='n');

	if (resultado == true) {
		printf("Posicionar Nebular Cardinal sobre limite inferior: OK\n\n");
	}
	else {
		printf("Posicionar Nebular Cardinal sobre limite inferior: ERROR\n\n");
	}
}
void posicionarNebularCardinalCompleta(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=true;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 6, 6,Cardinal);
	resultado = (resultado==true)&&(maquinas[5][5]=='N')&&(maquinas[5][4]=='n')&&(maquinas[5][6]=='n')&&(maquinas[4][5]=='n')&&(maquinas[6][5]=='n');

	if (resultado == true) {
		printf("Nebular Cardinal posicionada completamente: OK\n\n");
	}
	else {
		printf("Nebular Cardinal posicionada completamente: ERROR\n\n");
	}
}

void posicionarNebularDiagonalCompleta(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);
	bool Cardinal=false;

	bool resultado = posicionarNebularHirviente (terrenos, maquinas, 6, 6,Cardinal);
	resultado = (resultado==true)&&(maquinas[5][5]=='Z')&&(maquinas[4][4]=='n')&&(maquinas[4][6]=='n')&&(maquinas[6][4]=='n')&&(maquinas[6][6]=='n');

	if (resultado == true) {
		printf("Nebular Diagonal posicionada completamente: OK\n\n");
	}
	else {
		printf("Nebular Diagonal posicionada completamente: ERROR\n\n");
	}
}
//Fin Tests Nebular Hirviente

//Inicio Tests Huracan de Tiburones
void posicionarHuracanDeTiburonesFueraDelMapa () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarHuracanTiburones (terrenos, maquinas, -1, 5);

	if (resultado == false) {
		printf("Posicionar el huracan fuera del mapa: OK\n\n");
	}
	else {
		printf("Posicionar el huracan fuera del mapa: ERROR\n\n");
	}
}

void posicionarHuracanDeTiburonesSobreAbismo (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[6][6]='A';
	bool resultado = posicionarHuracanTiburones (terrenos, maquinas, 7, 7);
	resultado = (resultado == true) && (maquinas[6][6] == 'H');

	if (resultado == true) {
		printf("Posicionar Huracan de Tiburones sobre un abismo : OK\n\n");
	}
	else {
		printf("Posicionar Huracan de Tiburones sobre un abismo : ERROR\n\n");
	}
}

void posicionarHuracanDeTiburonesSobreMontania (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[6][6]='M';
	bool resultado = posicionarHuracanTiburones (terrenos, maquinas, 7, 7);

	if (resultado == false) {
		printf("Posicionar Huracan de Tiburones sobre montaña : OK\n\n");
	}
	else {
		printf("Posicionar Huracan de Tiburones sobre montaña : ERROR\n\n");
	}
}

void posicionarHuracanDeTiburonesSobreMaquina (){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[6][6]='C';
	bool resultado = posicionarHuracanTiburones (terrenos, maquinas, 7, 7);

	if (resultado == false) {
		printf("Posicionar Huracan de Tiburones sobre maquina : OK\n\n");
	}
	else {
		printf("Posicionar Huracan de Tiburones sobre maquina : ERROR\n\n");
	}
}
void posicionarHuracanDeTiburonesSobreTerrenoSimple(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarHuracanTiburones (terrenos, maquinas, 7, 7);
	resultado = (resultado==true)&&(maquinas[6][6]=='H');

	if (resultado == true) {
		printf("Posicionar Huracan de Tiburones sobre terreno simple: OK\n\n");
	}
	else {
		printf("Posicionar Huracan de Tiburones sobre terreno simple: ERROR\n\n");
	}	
}
//Fin Tests Huracan de Tiburones

//Inicio Tests Leviatanque
void posicionarLeviatanqueFueraDelMapa () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 10, 2, 11);

	if (resultado == false) {
		printf("Posicionar el Leviatanque fuera del mapa: OK\n\n");
	}
	else {
		printf("Posicionar el Leviatanque fuera del mapa: ERROR\n\n");
	}
}

void posicionarLeviatanqueConLeviatanqueCerca () {
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[0][0]='L';
	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 2, 2, 3);

	if (resultado == false) {
		printf("Posicionar Leviatanque con Leviatanque cerca: OK\n\n");
	}
	else {
		printf("Posicionar Leviatanque con Leviatanque cerca: ERROR\n\n");
	}
}

void validarRangosLeviatanque(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 2, 3, 5);

	if (resultado == false) {
		printf("Validar rangos para posicionar Leviatanque: OK\n\n");
	}
	else {
		printf("Validar rangos para posicionar Leviatanque: ERROR\n\n");
	}		
}
void posicionarLeviatanqueSobreMontania(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='M';
	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 1, 2, 2);

	if (resultado == false) {
		printf("Posicionar Leviatanque sobre Montaña: OK\n\n");
	}
	else {
		printf("Posicionar Leviatanque sobre Montaña: ERROR\n\n");
	}
}

void posicionarLeviatanqueSobreMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[0][0]='C';
	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 1, 2, 2);

	if (resultado == false) {
		printf("Posicionar Leviatanque sobre maquina: OK\n\n");
	}
	else {
		printf("Posicionar Leviatanque sobre maquina: ERROR\n\n");
	}	
}
void posicionarLeviatanqueSobreAbismo(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[0][0]='A';
	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 1, 2, 2);
	resultado = (resultado==true)&&(maquinas[0][0]=='L')&&(maquinas[0][1]=='L')&&(maquinas[1][0]=='L')&&(maquinas[1][1]=='L');

	if (resultado == true) {
		printf("Posicionar Leviatanque sobre abismo: OK\n\n");
	}
	else {
		printf("Posicionar Leviatanque sobre abismo: ERROR\n\n");
	}		
}

void posicionarLeviatanqueSobreTerrenoSimple(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = posicionarLeviatanque (terrenos, maquinas, 1, 1, 2, 2);
	resultado = (resultado==true)&&(maquinas[0][0]=='L')&&(maquinas[0][1]=='L')&&(maquinas[1][0]=='L')&&(maquinas[1][1]=='L');

	if (resultado == true) {
		printf("Posicionar Leviatanque sobre terreno simple: OK\n\n");
	}
	else {
		printf("Posicionar Leviatanque sobre terreno simple: ERROR\n\n");
	}		
}
//Fin Tests Leviatanque

//Inicio Tests Granada Justiciera
void liberarGranadaJusticieraFueraDelMapa(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 2, -3, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	if (resultado == false) {
		printf("Liberar Granada Justiciera fuera del mapa: OK\n\n");
	}
	else {
		printf("Liberar Granada Justiciera fuera del mapa: ERROR\n\n");
	}
}

void liberarGranadaJusticieraSinMuniciones(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=0;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	if (resultado == false) {
		printf("Liberar Granada Justiciera sin municiones: OK\n\n");
	}
	else {
		printf("Liberar Granada Justiciera sin municiones: ERROR\n\n");
	}
}

void liberarGranadaJusticieraSobreMontania(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[1][1]='M';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==false)&&(municionesRestantes==7)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Justiciera sobre montaña: OK\n\n");
	}
	else {
		printf("Liberar Granada Justiciera sobre montaña: ERROR\n\n");
	}
}

void liberarGranadaJusticieraSobreMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[1][1]='T';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Justiciera sobre maquina: OK\n\n");
	}
	else {
		printf("Liberar Granada Justiciera sobre maquina: ERROR\n\n");
	}
}

void liberarGranadaJusticieraSobreAbismo(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[1][1]='A';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Justiciera sobre abismo: OK\n\n");
	}
	else {
		printf("Liberar Granada Justiciera sobre abismo: ERROR\n\n");
	}
}

void verificarExpansionGranadaJusticieraContraMontania(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[4][3]='M';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==7);
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==4)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==4);

	if (resultado == true) {
		printf("Expansion de granada contra montaña: OK\n\n");
	}
	else {
		printf("Expansion de granada contra montaña: ERROR\n\n");
	}
}

void verificarExpansionGranadaJusticieraContraMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='C';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==4)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==4)&&(hectareasAfectadas[7][1]==3);

	if (resultado == true) {
		printf("Expansion de granada contra maquina: OK\n\n");
	}
	else {
		printf("Expansion de granada contra maquina: ERROR\n\n");
	}
}

void verificarEliminacionTorreConGranadaJusticiera(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='T';
	maquinas[3][2]='t';
	maquinas[3][3]='t';
	maquinas[3][4]='t';
	maquinas[4][2]='t';
	maquinas[5][2]='t';
	maquinas[5][3]='t';
	maquinas[5][4]='t';
	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==6)&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==4)&&(hectareasAfectadas[2][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==3)&&(hectareasAfectadas[4][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==4)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(maquinas[3][2]==' ')&&(maquinas[3][3]==' ');
	resultado = (resultado==true)&&(maquinas[3][4]==' ')&&(maquinas[4][2]==' ')&&(maquinas[5][2]==' ');
	resultado = (resultado==true)&&(maquinas[5][3]==' ')&&(maquinas[5][4]==' ');


	if (resultado == true) {
		printf("Eliminacion de torre coralina con granada justiciera: OK\n\n");
	}
	else {
		printf("Eliminacion de torre coralina con granada justiciera: ERROR\n\n");
	}
}

void verificarEliminacionDefensaTorreConGranadaJusticiera(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='t';
	maquinas[4][2]='T';
	maquinas[3][2]='t';
	maquinas[5][2]='t';

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==4)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==4)&&(hectareasAfectadas[7][1]==3);
	resultado = (resultado==true)&&(maquinas[4][2]=='T')&&(maquinas[3][2]=='t')&&(maquinas[5][2]=='t');


	if (resultado == true) {
		printf("Eliminacion de defensa torre coralina con granada justiciera: OK\n\n");
	}
	else {
		printf("Eliminacion de defensa torre coralina con granada justiciera: ERROR\n\n");
	}
}

void verificarEliminacionNebularDiagonalConGranadaJusticiera(){ //testea indirectamente la expansion de la granada contra defensa de nebular
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='Z';
	maquinas[3][2]='n';
	maquinas[3][4]='n';
	maquinas[5][2]='n';
	maquinas[5][4]='n';

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==4)&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==4)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==4)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==3);
	resultado = (resultado==true)&&(maquinas[3][2]==' ')&&(maquinas[3][4]==' ');
	resultado = (resultado==true)&&(maquinas[5][2]==' ')&&(maquinas[5][4]==' ');

	if (resultado == true) {
		printf("Eliminacion de Nebular Diagonal con granada justiciera: OK\n\n");
	}
	else {
		printf("Eliminacion de Nebular Diagonal con granada justiciera: ERROR\n\n");
	}
}

void verificarEliminacionLeviatanqueConGranadaJusticiera(){ 
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='L';
	maquinas[4][2]='l';
	maquinas[3][2]='l';
	maquinas[3][3]='l';

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==4)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==4)&&(hectareasAfectadas[7][1]==3);
	resultado = (resultado==true)&&(maquinas[4][2]==' ')&&(maquinas[3][2]==' ')&&(maquinas[3][3]==' ');

	if (resultado == true) {
		printf("Eliminacion de Leviatanque con granada justiciera: OK\n\n");
	}
	else {
		printf("Eliminacion de Leviatanque con granada justiciera: ERROR\n\n");
	}
}

void verificarExpansionGranadaJusticieraSobreLeviatanqueDaniado(){ 
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[4][3]='l';
	maquinas[4][2]='l';
	maquinas[3][2]='l';
	maquinas[3][3]='L';

	bool resultado = liberarGranadaJusticiera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==9)&&(maquinas[4][3]=='l');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==4)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==4)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==4)&&(hectareasAfectadas[7][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[8][0]==4)&&(hectareasAfectadas[8][1]==2);
	resultado = (resultado==true)&&(maquinas[4][2]=='l')&&(maquinas[3][2]=='l')&&(maquinas[3][3]=='L');

	if (resultado == true) {
		printf("Expansion de granada justiciera sobre leviatanque dañado: OK\n\n");
	}
	else {
		printf("Expansion de granada justiciera sobre leviatanque dañado: ERROR\n\n");
	}
}

//Fin Tests Granada Justiciera

//Inicio Tests Granada Verdadera
void liberarGranadaVerdaderaFueraDelMapa(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 2, -3, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	if (resultado == false) {
		printf("Liberar Granada Verdadera fuera del mapa: OK\n\n");
	}
	else {
		printf("Liberar Granada Verdadera fuera del mapa: ERROR\n\n");
	}
}

void liberarGranadaVerdaderaSinMuniciones(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=0;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	if (resultado == false) {
		printf("Liberar Granada Verdadera sin municiones: OK\n\n");
	}
	else {
		printf("Liberar Granada Verdadera sin municiones: ERROR\n\n");
	}
}

void liberarGranadaVerdaderaSobreMontania(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[1][1]='M';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==false)&&(municionesRestantes==7)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Verdadera sobre montaña: OK\n\n");
	}
	else {
		printf("Liberar Granada Verdadera sobre montaña: ERROR\n\n");
	}
}

void liberarGranadaVerdaderaSobreMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[1][1]='T';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Verdadera sobre maquina: OK\n\n");
	}
	else {
		printf("Liberar Granada Verdadera sobre maquina: ERROR\n\n");
	}
}

void liberarGranadaVerdaderaSobreAbismo(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[1][1]='A';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 2, 2, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==0);

	if (resultado == true) {
		printf("Liberar Granada Verdadera sobre abismo: OK\n\n");
	}
	else {
		printf("Liberar Granada Verdadera sobre abismo: ERROR\n\n");
	}
}

void verificarExpansionGranadaVerdaderaContraMontania(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	terrenos[3][3]='M';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==7);
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==5)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==6)&&(hectareasAfectadas[6][1]==2);

	if (resultado == true) {
		printf("Expansion de Granada Verdadera contra montaña: OK\n\n");
	}
	else {
		printf("Expansion de Granada Verdadera contra montaña: ERROR\n\n");
	}
}

void verificarExpansionGranadaVerdaderaContraMaquina(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[3][3]='C';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[3][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==5)&&(hectareasAfectadas[6][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==6)&&(hectareasAfectadas[7][1]==2);

	if (resultado == true) {
		printf("Expansion de Granada Verdadera contra maquina: OK\n\n");
	}
	else {
		printf("Expansion de Granada Verdadera contra maquina: ERROR\n\n");
	}
}

void verificarEliminacionTorreConGranadaVerdadera(){
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[3][3]='T';
	maquinas[2][2]='t';
	maquinas[2][3]='t';
	maquinas[2][4]='t';
	maquinas[3][2]='t';
	maquinas[3][4]='t';
	maquinas[4][2]='t';
	maquinas[4][3]='t';
	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);
	
	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[3][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==5)&&(hectareasAfectadas[6][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==6)&&(hectareasAfectadas[7][1]==2);
	resultado = (resultado==true)&&(maquinas[2][2]==' ')&&(maquinas[2][3]==' ')&&(maquinas[2][4]==' ');
	resultado = (resultado==true)&&(maquinas[3][2]==' ')&&(maquinas[3][4]==' ');
	resultado = (resultado==true)&&(maquinas[4][2]==' ')&&(maquinas[4][3]==' ');

	if (resultado == true) {
		printf("Eliminacion de torre coralina con granada verdadera: OK\n\n");
	}
	else {
		printf("Eliminacion de torre coralina con granada verdadera: ERROR\n\n");
	}
}

void verificarEliminacionNebularCardinalConGranadaVerdadera(){ 
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[3][3]='N';
	maquinas[2][3]='n';
	maquinas[4][3]='n';
	maquinas[3][2]='n';
	maquinas[3][4]='n';

	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[3][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==5)&&(hectareasAfectadas[6][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==6)&&(hectareasAfectadas[7][1]==2);
	resultado = (resultado==true)&&(maquinas[2][3]==' ')&&(maquinas[4][3]==' ');
	resultado = (resultado==true)&&(maquinas[3][2]==' ')&&(maquinas[3][4]==' ');

	if (resultado == true) {
		printf("Eliminacion de Nebular Cardinal con granada verdadera: OK\n\n");
	}
	else {
		printf("Eliminacion de Nebular Cardinal con granada verdadera: ERROR\n\n");
	}
}

void verificarEliminacionLeviatanqueConGranadaVerdadera(){ 
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[3][3]='L';
	maquinas[3][2]='l';
	maquinas[4][2]='l';
	maquinas[4][3]='l';

	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==8)&&(maquinas[3][3]==' ');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==5)&&(hectareasAfectadas[6][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==6)&&(hectareasAfectadas[7][1]==2);
	resultado = (resultado==true)&&(maquinas[3][2]==' ')&&(maquinas[4][2]==' ')&&(maquinas[4][3]==' ');

	if (resultado == true) {
		printf("Eliminacion de Leviatanque con granada verdadera: OK\n\n");
	}
	else {
		printf("Eliminacion de Leviatanque con granada verdadera: ERROR\n\n");
	}
}

void verificarExpansionGranadaVerdaderaSobreLeviatanqueDaniado(){ 
	char terrenos[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	char maquinas[MAXIMO_HECTAREAS][MAXIMO_HECTAREAS];
	int cantHectareasAfectadas=0;
	int hectareasAfectadas[9][2];
	int municionesRestantes=7;
	inicializarTerrenos(terrenos);
	inicializarMaquinas(maquinas);

	maquinas[3][2]='L';
	maquinas[2][2]='l';
	maquinas[2][3]='l';
	maquinas[3][3]='l';

	bool resultado = liberarGranadaVerdadera(terrenos, maquinas, 5, 5, &municionesRestantes, &cantHectareasAfectadas, hectareasAfectadas);

	resultado = (resultado==true)&&(municionesRestantes==6)&&(cantHectareasAfectadas==9)&&(maquinas[3][3]=='l');
	resultado = (resultado==true)&&(hectareasAfectadas[0][0]==4)&&(hectareasAfectadas[0][1]==4);
	resultado = (resultado==true)&&(hectareasAfectadas[1][0]==5)&&(hectareasAfectadas[1][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[2][0]==6)&&(hectareasAfectadas[2][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[3][0]==3)&&(hectareasAfectadas[3][1]==5);
	resultado = (resultado==true)&&(hectareasAfectadas[4][0]==2)&&(hectareasAfectadas[4][1]==6);
	resultado = (resultado==true)&&(hectareasAfectadas[5][0]==3)&&(hectareasAfectadas[5][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[6][0]==2)&&(hectareasAfectadas[6][1]==2);
	resultado = (resultado==true)&&(hectareasAfectadas[7][0]==5)&&(hectareasAfectadas[7][1]==3);
	resultado = (resultado==true)&&(hectareasAfectadas[8][0]==6)&&(hectareasAfectadas[8][1]==2);
	resultado = (resultado==true)&&(maquinas[2][2]=='l')&&(maquinas[3][2]=='L')&&(maquinas[2][3]=='l');

	if (resultado == true) {
		printf("Expansion de granada verdadera sobre leviatanque dañado: OK\n\n");
	}
	else {
		printf("Expansion de granada verdadera sobre leviatanque dañado: ERROR\n\n");
	}
}

//Fin Tests Granada Verdadera

void testTerrenos(){
	cambiarTerrenoASimpleSinMaquina();
	cambiarTerrenoASimpleConMaquina();
	cambiarTerrenoAAbismalSinMaquina();
	cambiarTerrenoAAbismalConMaquina();
	cambiarTerrenoSinMaquinaAMontanioso();
	cambiarTerrenoConMaquinaAMontanioso();
	cambiarTerrenoFueraDelMapa();
}

void testCanionPerlas(){
	posicionarCanionFueraDelMapa();
	posicionarCanionSobreMontania();
	posicionarCanionSobreAbismo();
	posicionarCanionSobreMaquina();
	posicionarCanionSobreTerrenoSimple();
}

void testTorre(){
	posicionarTorreFueraDelMapa();
	posicionarTorreSobreMontania();
	posicionarTorreSobreAbismo();
	posicionarTorreSobreMaquina();
	posicionarTorreSobreTerrenoSimple();
	posicionarTorreConMontaniaASuDerecha();
	posicionarTorreEsquinaSuperiorIzquierda();
	posicionarTorreEsquinaSuperiorDerecha();
	posicionarTorreEsquinaInferiorDerecha();
	posicionarTorreEsquinaInferiorIzquierda();
}

void testNebular(){
	posicionarNebularCardinalFueraDelMapa();
	posicionarNebularDiagonalSobreMontania();
	posicionarNebularCardinalSobreAbismo();
	posicionarNebularDiagonalSobreMaquina();
	posicionarNebularDiagonalLimiteIzquierdo();
	posicionarNebularDiagonalLimiteDerecho();
	posicionarNebularCardinalLimiteSuperior();
	posicionarNebularCardinalLimiteInferior();
	posicionarNebularCardinalCompleta();
	posicionarNebularDiagonalCompleta();
}

void testHuracan(){
	posicionarHuracanDeTiburonesFueraDelMapa();
	posicionarHuracanDeTiburonesSobreAbismo();
	posicionarHuracanDeTiburonesSobreMontania();
	posicionarHuracanDeTiburonesSobreMaquina();
	posicionarHuracanDeTiburonesSobreTerrenoSimple();
}

void testLeviatanque(){
	posicionarLeviatanqueFueraDelMapa();
	posicionarLeviatanqueConLeviatanqueCerca();
	validarRangosLeviatanque();
	posicionarLeviatanqueSobreMontania();
	posicionarLeviatanqueSobreMaquina();
	posicionarLeviatanqueSobreAbismo();
	posicionarLeviatanqueSobreTerrenoSimple();
}

void testGranadaJusticiera(){
	liberarGranadaJusticieraFueraDelMapa();
	liberarGranadaJusticieraSinMuniciones();
	liberarGranadaJusticieraSobreMontania();
	liberarGranadaJusticieraSobreMaquina();
	liberarGranadaJusticieraSobreAbismo();
	verificarExpansionGranadaJusticieraContraMontania();
	verificarExpansionGranadaJusticieraContraMaquina();
	verificarEliminacionTorreConGranadaJusticiera();
	verificarEliminacionDefensaTorreConGranadaJusticiera();
	verificarEliminacionNebularDiagonalConGranadaJusticiera();
	verificarEliminacionLeviatanqueConGranadaJusticiera();
	verificarExpansionGranadaJusticieraSobreLeviatanqueDaniado();
}

void testGranadaVerdadera(){
	liberarGranadaVerdaderaFueraDelMapa();
	liberarGranadaJusticieraSinMuniciones();
	liberarGranadaVerdaderaSobreMontania();
	liberarGranadaVerdaderaSobreMaquina();
	liberarGranadaVerdaderaSobreAbismo();
	verificarExpansionGranadaVerdaderaContraMontania();
	verificarExpansionGranadaVerdaderaContraMaquina();
	verificarEliminacionTorreConGranadaVerdadera();
	verificarEliminacionNebularCardinalConGranadaVerdadera();
	verificarEliminacionLeviatanqueConGranadaVerdadera();
	verificarExpansionGranadaVerdaderaSobreLeviatanqueDaniado();
}
int main () {
	printf("~~~~~~ Inicio de los Tests ~~~~~~\n\n");
	testTerrenos();
	testCanionPerlas();
	testTorre();
	testNebular();
	testHuracan();
	testLeviatanque();
	testGranadaJusticiera();
	testGranadaVerdadera();
	printf("~~~~~~ Fin de los Tests ~~~~~~\n\n");
	return 0;
} 
