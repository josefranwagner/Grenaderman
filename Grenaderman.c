#include <stdio.h>
#include <stdbool.h>
#include "Grenaderman.h"
	
	bool hayMaquina(char posicion){
		if (posicion!=' '){
			return true;
		}
		else{
			return false;
		}
	}
	bool terrenoAptoTerrestre(char posicion){
		if (posicion==' '){
			return true;
		}
		else{
			return false;
		}
	}

	bool terrenoAptoVolador(char posicion){
		if (((posicion)==' ')||((posicion)=='A')){
			return true;
		}
		else{
			return false;
		}
	}

	bool rangoValido(int fila, int columna){
		if ((fila>=1)&&(fila<=MAXIMO_HECTAREAS)){
			if((columna>=1)&&(columna<=MAXIMO_HECTAREAS)){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	void eliminarCanionPerlas(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		maquinas[fila][columna]=' ';
	}

	void eliminarTorreCoralina(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		maquinas[fila][columna]=' ';
		for(int i=fila-1;i<=fila+1;i++){
			for(int j=columna-1;j<=columna+1;j++){
				if(rangoValido(i,j)==true){
					if(maquinas[i][j]=='t'){
						maquinas[i][j]=' ';
					}
				}
			}
		}
	}

	void eliminarNebularCardinal(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		maquinas[fila][columna]=' ';
		for(int i=fila-1;i<=fila+1;i++){
			for(int j=columna-1;j<=columna+1;j++){
				if((i==fila)||(j==columna)){
					if(rangoValido(i,j)==true){
						if((maquinas[i][j])=='n'){
							maquinas[i][j]=' ';
						}
					}
				}
			}
		}
	}

	void eliminarNebularDiagonal(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		maquinas[fila][columna]=' ';
		for(int i=fila-1;i<=fila+1;i++){
			for(int j=columna-1;j<=columna+1;j++){
				if((i!=fila)&&(j!=columna)){
					if(rangoValido(i,j)==true){
						if((maquinas[i][j])=='n'){
							maquinas[i][j]=' ';
						}
					}
				}
			}
		}
	}

	void eliminarHuracanTiburones(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		maquinas[fila][columna]=' ';
	}

	void eliminarLeviatanque(char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		int contador=0;

		maquinas[fila][columna]='l';
		for(int i=fila-1;i<=fila+1;i++){
			for(int j=columna-1;j<=columna+1;j++){
				if(rangoValido(i,j)==true){
					if((maquinas[i][j])=='l'){
						contador=contador+1;
					}
				}
			}
		}
		if(contador==4){ //verifica si estan destruidas las 4 partes del leviatanque
			for(int i=fila-1;i<=fila+1;i++){
				for(int j=columna-1;j<=columna+1;j++){
					if(rangoValido(i,j)==true){
						if((maquinas[i][j])=='l'){
							maquinas[i][j]=' ';
						}
					}
				}
			}
		}
	}
	bool cambiarTipoTerreno(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna, char tipoTerreno){
		if(rangoValido(fila,columna)==true){
			switch (tipoTerreno){
				case 'A':{
					if(hayMaquina(maquinas[fila-1][columna-1])==true){
						switch(maquinas[fila-1][columna-1]){
							case 'C':{
								eliminarCanionPerlas(maquinas,fila-1,columna-1);
							}
							break;
							case 'T':{
								eliminarTorreCoralina(maquinas,fila-1,columna-1);
							}
							break;
							case 't':{
								maquinas[fila-1][columna-1]=' ';
							}
							break;
							case 'N':{
								eliminarNebularCardinal(maquinas,fila-1,columna-1);
							}
							break;
							case 'n':{
								maquinas[fila-1][columna-1]=' ';
							}
							case 'Z':{
								eliminarNebularDiagonal(maquinas,fila-1,columna-1);
							}
							break;
							case 'H':{
								eliminarHuracanTiburones(maquinas,fila-1,columna-1);
							}
							break;
							case 'L':{
								eliminarLeviatanque(maquinas,fila-1,columna-1);
							}
							break;
							case 'l':
							break;
							default:{
								(maquinas[fila-1][columna-1])=' ';
								return true;
							}
							break;
						}
					}
					(terrenos[fila-1][columna-1])='A';
					return true;
				}
				break;

				case 'M':{
					if(hayMaquina(maquinas[fila-1][columna-1])==true){
						return false;
					}
					else{
						(terrenos[fila-1][columna-1])='M';
						return true;
					}
				}
				break;

				case ' ':{
					(terrenos[fila-1][columna-1])=' ';
					return true;
				}
				break;
			
				default:{
					return false;
				}
				break;	
			}
		}
		else{
			return false;
		}
	}

	bool posicionarCanionPerlas(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		if(rangoValido(fila,columna)==true){
			if (terrenoAptoTerrestre(terrenos[fila-1][columna-1])==true){
				if (hayMaquina(maquinas[fila-1][columna-1])==false){
					(maquinas[fila-1][columna-1])='C';
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	void posicionarDefensasTorreCoralina(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		for(int i=(fila-1);i<=(fila+1);i++){
			for(int j=(columna-1);j<=(columna+1);j++){
				if((rangoValido(i+1,j+1))==true){
					if((terrenoAptoTerrestre(terrenos[i][j]))==true){
						if((hayMaquina(maquinas[i][j]))==false){
							(maquinas[i][j])='t';
						}
					}
				}
			}
		}
	}

	bool posicionarTorreCoralina(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){

		if(rangoValido(fila,columna)==true){
			if (terrenoAptoTerrestre(terrenos[fila-1][columna-1])==true){
				if (hayMaquina(maquinas[fila-1][columna-1])==false){
					(maquinas[fila-1][columna-1])='T';
					posicionarDefensasTorreCoralina(terrenos,maquinas,fila-1,columna-1);
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
	void posicionarDefensasNebular(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,bool enDireccionesCardinales){
		if(enDireccionesCardinales==true){
			for(int i=fila-1;i<=fila+1;i++){
				for(int j=columna-1;j<=columna+1;j++){
					if((i==fila)||(j==columna)){
						if(rangoValido(i+1,j+1)==true){
							if(terrenoAptoTerrestre(terrenos[i][j])==true){
								if(hayMaquina(maquinas[i][j])==false){
									(maquinas[i][j])='n';
								}
							}
						}
					}
				}
			}
		}
		else{
			for(int i=fila-1;i<=fila+1;i++){
				for(int j=columna-1;j<=columna+1;j++){
					if((i!=fila)&&(j!=columna)){
						if(rangoValido(i+1,j+1)==true){
							if(terrenoAptoTerrestre(terrenos[i][j])==true){
								if(hayMaquina(maquinas[i][j])==false){
									(maquinas[i][j])='n';
								}
							}
						}
					}
				}
			}
		}
	}

	bool posicionarNebularHirviente (char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,bool enDireccionesCardinales){

		if(rangoValido(fila,columna)==true){
			if (terrenoAptoTerrestre(terrenos[fila-1][columna-1])==true){
				if (hayMaquina(maquinas[fila-1][columna-1])==false){
					if(enDireccionesCardinales==true){
						(maquinas[fila-1][columna-1])='N';
						posicionarDefensasNebular(terrenos,maquinas,fila-1,columna-1,enDireccionesCardinales);
					}
					else{
						(maquinas[fila-1][columna-1])='Z';
						posicionarDefensasNebular(terrenos,maquinas,fila-1,columna-1,enDireccionesCardinales);
					}
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}		
		}
		else{
			return false;
		}
	}

	bool posicionarHuracanTiburones(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna){
		if(rangoValido(fila,columna)==true){
			if (terrenoAptoVolador(terrenos[fila-1][columna-1])==true){
				if (hayMaquina(maquinas[fila-1][columna-1])==false){
					(maquinas[fila-1][columna-1])='H';
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	bool hayLeviatanque(char posicion){
		if((posicion=='L')||(posicion=='l')){
			return true;
		}
		else{
			return false;
		}
	}

	bool posicionarLeviatanque(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int filaDesde, int columnaDesde,int filaHasta, int columnaHasta){

		int filaDesdeReal=filaDesde-1;
		int filaHastaReal=filaHasta-1;
		int columnaDesdeReal=columnaDesde-1;
		int columnaHastaReal=columnaHasta-1;

		if(rangoValido(filaDesde,columnaDesde)==true){
			if (rangoValido(filaHasta,columnaHasta)==true){
				if((filaHasta-filaDesde==1)&&(columnaHasta-columnaDesde==1)){
					for(int i=(filaDesdeReal-1);i<=(filaHastaReal+1);i++){
						for(int j=(columnaDesdeReal-1);j<=(columnaHastaReal+1);j++){
							if(rangoValido(i+1,j+1)==true){
								if(hayLeviatanque(maquinas[i][j])==true){
									return false;
								}
								if(((i>=filaDesdeReal)&&(i<=filaHastaReal))&&(j>=columnaDesdeReal)&&(j<=columnaHastaReal)){
									if(hayMaquina(maquinas[i][j])==false){
										if(terrenoAptoVolador(terrenos[i][j])==false){
											return false;
										}
									}
									else{
										return false;
									}
								}
							}
						}
					}
					for(int i=(filaDesdeReal);i<=(filaHastaReal);i++){
						for(int j=(columnaDesdeReal);j<=(columnaHastaReal);j++){
							(maquinas[i][j])='L';
						}
					}
					return true;
				}
				else{
					return false;
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	void cargarHectareasAfectadas(int hectareasAfectadas[9][2], int hectarea, int fila, int columna){
		hectareasAfectadas[hectarea-1][0]=fila;
		hectareasAfectadas[hectarea-1][1]=columna;
	}

	bool liberarGranadaJusticiera(char terrenos[][MAXIMO_HECTAREAS],char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,int *municiones, int *cantHectareasAfectadas,
	int hectareasAfectadas[9][2]){

		int filaReal;
		int columnaReal;
		bool frenarExpansion;
		int j;
		int k;

		if((*municiones)>0){
			if(rangoValido(fila,columna)==true){
				filaReal=(fila-1);
				columnaReal=(columna-1);
				if(terrenoAptoTerrestre(terrenos[filaReal][columnaReal])==true){ 
					if((hayMaquina(maquinas[filaReal][columnaReal])!=true)||maquinas[filaReal][columnaReal]=='l'){ //devuelve false si hay una maquina en la posicion ingresada
						*municiones=((*municiones)-1);
						*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
						cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal,columnaReal);
						for(int i=1;i<=4;i++){
							j=0; //controla el movimiento de las filas
							k=0; //controla el movimiento de las columnas
							frenarExpansion=false;
							while((frenarExpansion==false)&&(j>-2)&&(j<2)&&(k>-2)&&(k<2)){
								switch(i){
									case 1: j++; //expande explosion hacia abajo
									break;
									case 2: k++; //expande explosion hacia la derecha
									break;
									case 3: j--; //expande explosion hacia arriba
									break;
									case 4: k--; //expande explosion hacia la izquierda
									break;
								}
								if(rangoValido(filaReal+j,columnaReal+k)==true){
									if(terrenoAptoVolador(terrenos[filaReal+j][columnaReal+k])==true){ //verifica si el terreno es simple o abismal para seguir explosion
										if((hayMaquina(maquinas[filaReal+j][columnaReal+k])==false)||maquinas[filaReal+j][columnaReal+k]=='l'){
											*cantHectareasAfectadas=(*cantHectareasAfectadas)+1;
											cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
										}
										else{
											switch(maquinas[filaReal+j][columnaReal+k]){
												case 'C':{
													eliminarCanionPerlas(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 't':{
													maquinas[filaReal+j][columnaReal+k]=' ';
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'T':{
													eliminarTorreCoralina(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'H':{
													eliminarHuracanTiburones(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'N':{
													eliminarNebularCardinal(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;													
												}
												break;
												case 'Z':{
													eliminarNebularDiagonal(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'L':{
													eliminarLeviatanque(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'l':
												break;
												default:{
													frenarExpansion=true;
												}
												break;
											}
										}
									}
									else{
										frenarExpansion=true;
									}
								}
								else{
									frenarExpansion=true;
								}
							}
						}
						return true;
					}
					else{
						*municiones=((*municiones)-1);
						return true;  
					}
				}
				else{
					if((terrenos[filaReal][columnaReal])=='A'){
						*municiones=((*municiones)-1);
						return true;
					}
					else{
						return false;
					} 
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}

	bool liberarGranadaVerdadera(char terrenos[][MAXIMO_HECTAREAS], char maquinas[][MAXIMO_HECTAREAS], int fila, int columna,int *municiones, int *cantHectareasAfectadas,
	int hectareasAfectadas[9][2]){

		int filaReal;
		int columnaReal;
		bool frenarExpansion;
		int j;
		int k;

		if((*municiones)>0){
			if(rangoValido(fila,columna)==true){
				filaReal=(fila-1);
				columnaReal=(columna-1);
				if(terrenoAptoTerrestre(terrenos[filaReal][columnaReal])==true){ 
					if((hayMaquina(maquinas[filaReal][columnaReal])!=true)||maquinas[filaReal][columnaReal]=='l'){ //devuelve false si hay una maquina en la posicion ingresada
						*municiones=((*municiones)-1);
						*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
						cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal,columnaReal);
						for(int i=1;i<=4;i++){
							j=0; //controla el movimiento de las filas
							k=0; //controla el movimiento de las columnas
							frenarExpansion=false;
							while((frenarExpansion==false)&&(j>-2)&&(j<2)&&(k>-2)&&(k<2)){
								switch(i){
									case 1:{ //expande explosion hacia abajo
										j++;
										k++;	
									}  
									break;
									case 2:{ //expande explosion hacia la derecha
										j--;
										k++;
									}  
									break;
									case 3:{ //expande explosion hacia arriba
										j--;
										k--;
									}  
									break;
									case 4:{ //expande explosion hacia la izquierda
										j++;
										k--;
									}  
									break;
								}
								if(rangoValido(filaReal+j,columnaReal+k)==true){
									if(terrenoAptoVolador(terrenos[filaReal+j][columnaReal+k])==true){ //verifica si el terreno es simple o abismal para seguir explosion
										if((hayMaquina(maquinas[filaReal+j][columnaReal+k])==false)||maquinas[filaReal+j][columnaReal+k]=='l'){
											*cantHectareasAfectadas=(*cantHectareasAfectadas)+1;
											cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
										}
										else{
											switch(maquinas[filaReal+j][columnaReal+k]){
												case 'C':{
													eliminarCanionPerlas(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 't':{
													maquinas[filaReal+j][columnaReal+k]=' ';
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'T':{
													eliminarTorreCoralina(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'H':{
													eliminarHuracanTiburones(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'N':{
													eliminarNebularCardinal(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;													
												}
												break;
												case 'Z':{
													eliminarNebularDiagonal(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'L':{
													eliminarLeviatanque(maquinas,filaReal+j,columnaReal+k);
													*cantHectareasAfectadas=((*cantHectareasAfectadas)+1);
													cargarHectareasAfectadas(hectareasAfectadas,*cantHectareasAfectadas,filaReal+j,columnaReal+k);
													frenarExpansion=true;
												}
												break;
												case 'l':
												break;
												default:{
													frenarExpansion=true;
												}
												break;
											}
										}
									}
									else{
										frenarExpansion=true;
									}
								}
								else{
									frenarExpansion=true;
								}
							}
						}
						return true;
					}
					else{
						*municiones=((*municiones)-1);
						return true;  
					}
				}
				else{
					if((terrenos[filaReal][columnaReal])=='A'){
						*municiones=((*municiones)-1);
						return true;
					}
					else{
						return false;
					} 
				}
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
