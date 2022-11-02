
/**********************************************************************
Declaraciones de funciones para el primer proyecto de:
Algoritmos y Programacion II

Por: 
Diego Peña
Luis Enrique Salazar 
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

nodeF *nuevoElementoF(int i){
	nodeF *new;
	if ((new = (nodeF*)malloc(sizeof(nodeF)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
		}
	new->fila = i;
	new->nextf = NULL;
	new->nextc = NULL;
	return new;
}

nodeC *nuevoElementoM(int val, int j){
	nodeC *new;
	if ((new = (nodeC*)malloc(sizeof(nodeC)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
		}
	new->value = val;
	new->colm = j;
	new->nextc = NULL;
	return new;
}

nodeFst *crearM(int fil, int colm){
	nodeFst *new;
	
	if(fil <= 0 || colm <= 0)
		return NULL;
	
	if ((new = (nodeFst*)malloc(sizeof(nodeFst)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
	}
	
	new->fil = fil;
	new->colm = colm;
	
	return new;
	
}

nodeMay *nuevoMay(){
	nodeMay *new;
	
	if ((new = (nodeMay*)malloc(sizeof(nodeMay)))== NULL){
		printf("\nERROR: Problema en malloc");
		exit(1);
	}
	
	return new;
}

int crearFile(char*arch, nodeFst *m){
	nodeF *auxf;
	nodeC *auxc;
	int num;
	char txt[20];
	
	FILE *file = fopen(arch, "w");
	if (!file)
		return 0;
	
	//Recibir filas y escribirlas
	num = m->fil;
	sprintf(txt, "%d", num);
	fputs(txt,file);
	
	fputc('\n',file);
	
	//Recibir filas y escribirlas
	num = m->colm;
	sprintf(txt, "%d", num);
	fputs(txt,file);
	
	fputc('\n',file);
	
	for(auxf = m->nextf; auxf; auxf = auxf->nextf)
		for(auxc = auxf->nextc; auxc; auxc = auxc->nextc){
			//Recibir fila y escribirla
			num = auxf->fila;
			sprintf(txt, "%d", num);
			fputs(txt,file);
			
			fputc(' ',file);
			
			//Recibir columna y recibirla
			num = auxc->colm;
			sprintf(txt, "%d", num);
			fputs(txt,file);
			
			fputc(' ',file);
			
			//Recibir valor y eescribirlo
			num = auxc->value;
			sprintf(txt, "%d", num);
			fputs(txt,file);
			
			fputc('\n',file);
		}
	
	fclose(file);
	
	return 1;
}

nodeFst *leerFile(char* arch){
	nodeFst *new;
	nodeF *auxf;
	nodeC *auxc;
	int fil, filant, colm, val,i;
	char txt[20];
	
	FILE *file = fopen(arch, "r");
	if (!file) return NULL;
	
	//Leer filas
	fgets(txt, 20, file);
	fil = atoi(txt);
	
	//Leer columnas
	fgets(txt, 20, file);
	colm = atoi(txt);
	
	new = crearM(fil,colm);

	if (feof(file)) return new;
	
	//Leer la primera fila
	for(i = 0; i<20;txt[i] = 0, i++); //Resetea txt
        
	for(i = 0; txt[i-1]!= ' '; i++) //Obtener los caracteres hasta el primer ' '
		txt[i] = (char)fgetc(file);
	filant  = fil = atoi(txt);
	

	auxf = new->nextf = nuevoElementoF(fil);
	
	do{
		//Leer la columna
		for(i = 0; i<20;txt[i] = 0, i++);
        
		for(i = 0; txt[i-1]!= ' '; i++)
			txt[i] = (char)fgetc(file);
		colm = atoi(txt);
		
		//Leer el valor
		for(i = 0; i<20;txt[i] = 0, i++);
        
		for(i = 0; txt[i-1]!= ' '; i++)
			txt[i] = (char)fgetc(file);
		val = atoi(txt);
		
		if(auxf->nextc){
			auxc->nextc = nuevoElementoM(val,colm);
			auxc = auxc->nextc;
		}
		else
			auxc = auxf->nextc = nuevoElementoM(val, colm);
		
		//Leer la nueva fila
		if(!feof(file)){
			
			for(i = 0; i<20;txt[i] = 0, i++);
        
			for(i = 0; txt[i-1]!= ' '; i++)
				txt[i] = (char)fgetc(file);
			fil = atoi(txt);
			
			if(fil!=filant){
				auxf->nextf = nuevoElementoF(fil);
				auxf = auxf->nextf;
				afilant = fil;
			}
		}
		
		
	}while(!feof(file));
		
	fclose(file);
	
	return new;
}

int obtenerElemento(int fila, int colm, nodeFst *m){
	nodeF *auxf;
	nodeC *auxc;
	
	for(auxf = m->nextf; auxf; auxf=auxf->nextf){
	
		if (auxf->fila == fila){
			for(auxc = auxf->nextc; auxc; auxc=auxc->nextc){
				
				if (auxc->colm == colm)
					return auxc->value;
				else
					if (auxc->colm > colm)
						return 0;
			}
		}
		else 
			if (auxf->fila > fila)
				return 0;
	}
	return 0;
}

int asignarElemento(int fila, int colm, int val, nodeFst *m){
	nodeC *auxc, *auxantc = NULL, *newc;
	nodeF *auxf, *auxantf = NULL, *newf;
	
	if (!(fila <= m->fil && colm <= m->colm)){
		printf("Sucedio un error, no se guardo el valor");
		return 0;
	}
	
	if(!m->nextf){
		m->nextf = nuevoElementoF(fila);
		m->nextf->nextc = nuevoElementoM(val, colm);
	}
	
	for(auxf = m->nextf;; auxantf = auxf ,auxf=auxf->nextf){
		
		//Llega a la ultima fila sin encontrar a la que asignar
		if (!auxf){
			auxf = nuevoElementoF(fila);
			auxantf->nextf = auxf;
			auxf->nextc= nuevoElementoM(val, colm);
			
			return 1;
		}
		else{
			//Encuentra la fila
			if (auxf->fila == fila){
				for(auxc = auxf->nextc;; auxantc=auxc, auxc=auxc->nextc){
					
					//Llego al final de la fila sin encontrar la casilla, crea una
					if(!auxc){
						auxc = nuevoElementoM(val, colm);
						auxantc->nextc = auxc;
						return 1;
					}
					else{
						//Encuentra la casilla a la que va a asignar
						if (auxc->colm == colm){
							auxc->value = val;
							return 1;
						}
						else{
							//Se paso la posicion que debia ocupar, crea una entre la actual y la anterior
							if (auxc->colm > colm){
								newc = nuevoElementoM(val, colm);
								newc->nextc = auxc;
								if (auxantc)
									auxantc->nextc = newc;
								else
									auxf->nextc = newc;
								return 1;
							}
						}
					}
				}
			}
			else 
				//Se pasa de la fila
				if (auxf->fila > fila){
					newf = nuevoElementoF(fila);
					newf->nextf = auxf;
					if(auxantf)
						auxantf->nextf = newf;
					else
						m->nextf = newf;
					
					newf->nextc = nuevoElementoM(val, colm);
					return 1;
				}
					
		}
	}
	printf("Sucedio un error, no se guardo el valor");
	return 0;
}

nodeFst *suma(nodeFst *m1, nodeFst *m2){
	nodeFst *new;
	nodeC *auxc1, *auxc2, *auxc3;
	nodeF *auxf1, *auxf2, *auxf3;
	
	if (m1->colm != m2->colm || m1->fil != m2-> fil)
		return NULL;
	
	auxf1 = m1->nextf;
	auxf2 = m2->nextf;
	
	//Crea la nueva matriz vacia
	new = crearM(m1->fil, m1->colm); 
	
	//Primer elemento de las filas para no perder el apuntador
	if (auxf1 && (!auxf2 || auxf1->fila <= auxf2->fila)) //Crea la primera fila basada en m1
		new->nextf = nuevoElementoF(auxf1->fila);
	else if(auxf2)
		new->nextf = nuevoElementoF(auxf2->fila); //Crea la primera fila basada en m2
	
	
	
	for (auxf3 = new->nextf; auxf1 || auxf2; auxf3 = auxf3->nextf){
		
		//Si para ambas matrices hay elementos en la misma fila
		if (auxf1->fila == auxf2->fila){
			
			auxc1 = auxf1->nextc;
			auxc2 = auxf2->nextc;
			
			//primer elemento para no perder el apuntador
			if(auxc1->colm < auxc2->colm) //En caso de que la columna menor sea de f1
				auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value, auxc1->colm);
			else if(auxc1->colm > auxc2->colm)//En caso de que la columna menor sea de f2
					auxc3 = auxf3->nextc = nuevoElementoM(auxc2->value, auxc2->colm);
				else //Sino ambas son de la misma colummna y se suman
					auxc3 = auxf3->nextc = nuevoElementoM(auxc1->value + auxc2->value, auxc1->colm);
					
			//Ciclo parra sumar las demas columnas
			for(auxc1 = auxc1->nextc, auxc2 = auxc2->nextc; auxc1 || auxc2;){
				
				//En caso de que c2 no exista o su columna sea mayor a c1
				if(auxc1 && (!auxc2 || auxc1->colm < auxc2->colm)){
					auxc3->nextc = nuevoElementoM(auxc1->value, auxc1->colm); //Se crea un elemento con c1.value y c2.colm
					auxc1 = auxc1->nextc;
					auxc3 = auxc3->nextc;
				}
				//	En caso de que no exista c1 o su colmuna sea mayor a c2
				else if(!auxc1 || auxc1->colm > auxc2->colm){
						auxc3->nextc = nuevoElementoM(auxc2->value, auxc2->colm); //Se crea un elemento con c2.value y c2.colm
						auxc2 = auxc2->nextc;
						auxc3 = auxc3->nextc;
					}
					//Ambos existen y son de la misma columna
					else{
						if (auxc1->value + auxc2->value !=0)//Siempre que su suma no sea cero...
							auxc3->nextc = nuevoElementoM(auxc1->value + auxc2->value, auxc1->colm); //Se crea un elemento con su suma y con colm
						auxc1 = auxc1->nextc;
						auxc2 = auxc2->nextc;
						auxc3 = auxc3->nextc;
					}
			}
			
			//Continuar con el ciclo de filas
			auxf1 = auxf1->nextf;
			auxf2 = auxf2->nextf;
		}
		else{
			//Si existen elementos para la fila 1
			if(auxf1 && (!auxf2 || auxf1->fila < auxf2->fila)){
				
				//crea el primer elemento por separado para no perder el apuntador
				auxc3 = auxf3->nextc = nuevoElementoM(auxf1->nextc->value, auxf1->nextc->colm);
				
				for(auxc1 = auxf1->nextc->nextc; auxc1; auxc1=auxc1->nextc, auxc3 = auxc3->nextc)
					auxc3->nextc = nuevoElementoM(auxc1->value,auxc1->colm);
				
				//instruccion para continuar el ciclo de filas
				auxf1=auxf1->nextf;
			}
			
			else{
				//Si existen elementos para la fila 2
				
				//crea el primer elemento por separado para no perder el apuntador
				auxc3 = auxf3->nextc = nuevoElementoM(auxf2->nextc->value, auxf2->nextc->colm);
				
				for(auxc2 = auxf2->nextc->nextc; auxc2; auxc2=auxc2->nextc, auxc3 = auxc3->nextc)
					auxc3->nextc = nuevoElementoM(auxc2->value,auxc2->colm);
					
				//Para continuar el ciclo de filas
				auxf2 = auxf2->nextf;
			}
		}
		
		
		//Crear el siguiente elemento de m3
		if (auxf1 && (!auxf2 || auxf1->fila <= auxf2->fila))
			auxf3->nextf = nuevoElementoF(auxf1->fila);
		else if(auxf2)
			auxf3->nextf = nuevoElementoF(auxf2->fila);
			
	}
	
	return new;
}

void productoEsc(int e, nodeFst *m){
	nodeF *fil;
	nodeC *col;
	for(fil = m->nextf; fil; fil = fil->nextf)
		for (col = fil->nextc; col; col = col->nextc)
			col->value *= e; 
}

int trasponer(nodeFst *m){
	unsigned char listo;
	int menorc;
	nodeF *auxf, *auxfnew,*oldf;
	nodeC *auxc;
	
	//Guarda el apuntador a la fila de apuntadores que se van a descartar
	oldf = m->nextf;
	
	//Si la matriz esta vacia, salir
	if (!m->nextf) return 0;
	
	//Crear el primer elemento para no perderlo
	auxfnew = m->nextf = nuevoElementoF(0);
	
	//Primer for, para recorrer las columnas
	for(listo = 0; !listo ;){
		
		//encontrar el elemento de menor columna y conectarlo con la fila nueva
		for(auxf = oldf->nextf, menorc = 9999999; auxf; auxf = auxf->nextf){
			if(auxf->nextc && auxf->nextc->colm < menorc){
				menorc = auxf->nextc->colm;
				auxfnew->fila = menorc;
				auxfnew->nextc = auxf->nextc;
			}
		}
			
		//conectar las columnas de menorc a la lista de filas nueva
		for(auxf = oldf->nextf, auxc = NULL; auxf; auxf = auxf->nextf){
			//Si se encuentra con el primer elemento de la columna con menorc (ya conectado)
			if (!auxc && auxf->nextc->colm == menorc){
				auxc = auxfnew->nextc;
				auxf->nextc->colm = auxf->fila;	//Cambiar fila por columna
				auxf->nextc = auxf->nextc->nextc;
			}
			//Sino, si encuentra un elemento con columna menorc
			else if(auxf->nextc->colm == menorc){
				auxc->nextc = auxf->nextc;
				auxf->nextc->colm = auxf->fila; //Cambiar fila por columna
				auxf->nextc = auxf->nextc->nextc;
				auxc = auxc->nextc;
			}
		}
		
		//Verificar que existan mas columnas que trasponer
		for(auxf = oldf->nextf, listo = 1; listo && auxf ; auxf=auxf->nextf)
			if (auxf->nextc){
				//Si existe al menos una columna sin trasponer, se continua el ciclo
				listo = 0;
				auxfnew->nextf = nuevoElementoF(0);
				auxfnew = auxfnew->nextf;
			}
	}
	
	//Libera la fila de apuntadores descartada
	while(oldf){
		auxf = oldf;
		oldf = oldf->nextf;
		free(auxf);
	}
	return 1;
}

nodeFst *producto(nodeFst*m1, nodeFst*m2){
	nodeFst *new;
	nodeF *auxf1, *auxf2, *auxf3, *auxf4, *filaAux;
	nodeC *auxc1, *auxc3;
	int val, menorc = 0;
	
	//Comprueba que las columnas de m1 sean iguales a las filas de m2
	if (m1->colm != m2->fil) return NULL;
	
	new = crearM(m1->fil, m2->colm);
	
	//Comprueba que alguna de las dos no sea 0
	if (!m1->nextf || !m2->nextf) return new;
	
	//Crea la primera fila para no perder el apuntador
	auxf3 = new->nextf = nuevoElementoF(m1->nextf->fila);
	
	//Crea una lista de nodos de fila, clones de m2 para usarlos sin perder los originales
	auxf1 = filaAux = nuevoElementoF(0);
	auxf2 = m2->nextf;
	for(;auxf2;auxf1 =auxf1->nextf, auxf2 = auxf2->nextf){
		auxf1->nextc = auxf2->nextc;
		auxf1->fila = auxf2->fila;
		auxf1->nextf = nuevoElementoF(0);
	}
	free(auxf1); //Siempre queda un nodo extra, se borra
	
	//Recorrer cada fila de m1
	for(auxf1 = m1->nextf; auxf1;auxf1=auxf1->nextf){
		
		//Reinicia los apuntadores de filaAux a los primeros elementos de las columnas de m2
		for(auxf2 = filaAux,auxf4 = m2->nextf ; auxf4 ; auxf2 =auxf2->nextf, auxf4 = auxf4->nextf)
			auxf2->nextc = auxf4->nextc;
			
		//Ciclo para hacer la multiplicacion de cada columna por la fila actual
		while(menorc != 9999999){
			
			//encontrar el elemento de menor columna
			for(auxf2 = filaAux, menorc = 9999999; auxf2; auxf2 = auxf2->nextf){
				if(auxf2->nextc && auxf2->nextc->colm < menorc)
					menorc = auxf2->nextc->colm;
			}
			
			//multiplicar y sumar columnas y filas
			for(val = 0, auxc1 = auxf1->nextc, auxf2 = filaAux;auxf2 && auxc1;){
			
				//Caso de que ningun auxiliar haya llegado al final, auxf2 apunte a algo, la fila de auxf2 sea la columna de auxc1 y sea la columna menor
				if (auxc1 && auxf2 && auxf2->nextc && auxc1->colm == auxf2->fila  && auxf2->nextc->colm == menorc){
					val += auxc1->value * auxf2->nextc->value;
					auxc1=auxc1->nextc;
					auxf2->nextc = auxf2->nextc->nextc;
					auxf2=auxf2->nextf;
				}
				//Caso de que ambos existan, y la columna de auxc1 sea menor a la fila de auxf2
				else if(auxc1 && auxf2 && auxc1->colm < auxf2->fila)
					auxc1=auxc1->nextc;
				//Caso de que ambos existan, auxf2 no tenga columnas o su fila sea menor a la columna de auxc1
				else if (auxc1 && auxf2 && (!auxf2->nextc || auxf2-> fila < auxc1->colm)){
					if (auxf2->nextc && auxf2->nextc->colm == menorc)
						auxf2->nextc = auxf2->nextc->nextc;
					auxf2=auxf2->nextf;
					
				}
			}
			//Crear elemento en la nueva matriz
			//Si valor no es 0
			if (val){
				//Si es el primer elemento de la fila, conectarlo a auxf3
				if(!auxf3->nextc)
					auxc3 = auxf3->nextc = nuevoElementoM(val,menorc);
				//sino, continuar la cadena
				else
					auxc3->nextc = nuevoElementoM(val, menorc);
				auxc3 = auxc3->nextc;
			}
				
		}
		
		//Se crea un nuevo nodo auxf3 si el auxf3 actual tiene elementos en su columna y hay mas filas en m1
		if(auxf3->nextc && auxf1->nextf){
			auxf3->nextf = nuevoElementoF(auxf1->fila);
			auxf3 = auxf3->nextf;
		}
		
	}
	//Si por alguna razon la matriz quedo nula, se borra el unico nodof que tenia
	if (!new->nextf->nextf && !new->nextf->nextc)
		free(new->nextf);
		
	while(filaAux){
		auxf2 = filaAux;
		filaAux = filaAux->nextf;
		free(auxf2);
	}
	
	return new;
}

void imprimir(nodeFst *m){
	nodeF *auxf;
	nodeC *auxc;
	register int i,j;
	
	for(auxf = m->nextf, i=1; i<= m->fil;i++){
		
		//si no existe la fila
		if (!auxf || auxf->fila != i){
			for(j=1;j<=m->colm;j++)
				printf("0 ");
			printf("\n");
		}
		else{
			//Imprimir los elementos de la fila
			for(auxc=auxf->nextc, j=1;j<=m->colm; j++){
				//si la columna correspondiente hay un 0, no existe en la lista
				if (!auxc || auxc->colm != j)
					printf("0 ");
				else{
					//imprime el valor en la lista
					printf("%d ", auxc->value);
					auxc=auxc->nextc;
				}
			}
			
			printf("\n");
			auxf=auxf->nextf;
		}
	}
}
