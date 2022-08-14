/*****************************************************
Fecha: 06 de Agosto de 2022
Autor: Juan Camilo De Los Ríos
Materia: Parallel and Distributed Computing
Tema: Primer taller introducción a C
*******************************************************/

/*Importación de las bibliotecas*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "taller_lib.h"

void primerPunto(){
	int var1, var2;
	printf("CALCULADORA DEL PRODUCTO DE DOS NÚMEROS:\n");
	printf("---------------------------------------------\n");
	printf("Digite el primer número\n");
	scanf("%d",&var1);
	printf("Digite el segundo número\n");
	scanf("%d",&var2);

	printf("El resultado de la operación es:\n%d * %d = %d\n", var1,var2, var1*var2);
}

void segundoPunto(){
	int daysI, years, weeks, daysO;
	printf("CALCULADORA DE DIAS A AÑOS\n");
	printf("---------------------------------------------\n");
	printf("Digite el tiempo en días:\n");
	scanf("%d", &daysI);
	/*Se hace la división por la cantidad de días en un año (No se toman en cuenta años bisiestos)*/
	years = daysI / 365;
	weeks = (daysI % 365)/7;
	daysO = ((daysI % 365)%7);

	printf("%d días son equivalentes a %d años %d semanas % días\n", daysI,years,weeks,daysO);
}

void tercerPunto(){
	float coords[4], distance;
	printf("CALCULADORA DEL LA DISTANCIA ENTRE DOS PUNTOS:\n");
	printf("---------------------------------------------\n");
	printf("Digite la primera coordenada (x1)\n");
	scanf("%f",&coords[0]);
	printf("Digite la primera coordenada (y1)\n");
	scanf("%f",&coords[1]);
	printf("Digite la segunda coordenada (x2)\n");
	scanf("%f",&coords[2]);
	printf("Digite la segunda coordenada (y2)\n");
	scanf("%f",&coords[3]);

	/*Se usa el formateo de caracteres para la aproximación de decimales*/
	printf("Las coordenadas introducidas son:\n(%0.1f,%0.1f)\n(%0.1f,%0.1f)\n",coords[0],coords[1],coords[2],coords[3]);
	/*Formula de la distancia entre dos puntos derivada de el teorema de pitágoras, se utilizan modulos de la biblioteca math.h */
	distance = sqrt((coords[2]-coords[0])*(coords[2]-coords[0]) + (coords[3]-coords[1])*(coords[3]-coords[1]));

	printf("La distancia entre los dos puntos es:\n%0.4f\n",distance);

}

void cuartoPunto(){
	printf("ESCRITURA DE LOS DIEZ PRIMEROS NÚMEROS NATURALES:\n");
	printf("---------------------------------------------\n");
	for(int i = 0; i<10;i++){
		printf("%d ",(i+1));
	}
	printf("\n");
}

void quintoPunto(){
	int rows;
	printf("ESCRITURA DE PATRÓN PIRAMIDAL:");
	printf("---------------------------------------------\n");
	printf("Digite la cantidad de filas que tendrá el tríangulo\n");
	scanf("%d",&rows);
	for (int i = 0; i <= rows; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
}
/*Se hacen una serie de métodos a modo de interfaz para la optimización y modularidad del código*/

/*Se verifica iterativamente los parámetros exigidos y se toma el dato requerido*/
int matrixDataRecolection(){
	int mSize;
	printf("Digite el tamaño de la matriz:\n");
	do{
		printf("Recuerde que el tamaño de la matriz debe ser mayor a 0 y menor a 8\n");
		scanf("%d", &mSize);
	}while(!(mSize > 0 && mSize<8));
	printf("El tamaño de la matriz será de %dx%d\n",mSize,mSize);
	return mSize;
}
/*Se imprime la matriz */
void matrixPrinting(int mSize, int matrix[mSize][mSize]){
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			printf("\t%d\t",matrix[i][j]);
		}
		printf("\n");
	}
}
/*Genera un número aleatorio*/
int randomNumerGenerator(){
	return rand() % 10;
}

void sextoPunto(){
	printf("IMPRESIÓN DE MATRIZ DE 1's:\n");
	printf("---------------------------------------------\n");
	int mSize=matrixDataRecolection();
	int matrix[mSize][mSize];

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			matrix[i][j] = 1;
		}
	}
	matrixPrinting(mSize,matrix);
}

void septimoPunto(){
	printf("IMPRESIÓN DE MATRIZ DE ENTEROS ALEATORIOS:\n");
	printf("---------------------------------------------\n");
	int mSize=matrixDataRecolection();
	int matrix[mSize][mSize];

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			matrix[i][j] = randomNumerGenerator();
		}
	}
	matrixPrinting(mSize,matrix);
}

void octavoPunto(){
	printf("IMPRESIÓN DE MATRICES DE ENTEROS ALEATORIOS (SUMA):\n");
	printf("---------------------------------------------\n");
	int mSize=matrixDataRecolection();
	int matrix[mSize][mSize], matrix2[mSize][mSize], finalMatrix[mSize][mSize];

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			matrix[i][j] = randomNumerGenerator();
			matrix2[i][j] = randomNumerGenerator();
		}
	}
	printf("Matriz #1:\n");
	matrixPrinting(mSize,matrix);
	printf("Matriz #2:\n");
	matrixPrinting(mSize,matrix2);
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			finalMatrix[i][j] = matrix[i][j]+matrix2[i][j];
		}
	}
	printf("Matriz #1 + Matriz #2 =\n");
	matrixPrinting(mSize,finalMatrix);
}

void novenoPunto(){
	printf("IMPRESIÓN DE MATRICES DE ENTEROS ALEATORIOS (RESTA):\n");
	printf("---------------------------------------------\n");
	int mSize=matrixDataRecolection();
	int matrix[mSize][mSize], matrix2[mSize][mSize], finalMatrix[mSize][mSize];

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			matrix[i][j] = randomNumerGenerator();
			matrix2[i][j] = randomNumerGenerator();
		}
	}
	printf("Matriz #1:\n");
	matrixPrinting(mSize,matrix);
	printf("Matriz #2:\n");
	matrixPrinting(mSize,matrix2);
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			finalMatrix[i][j] = matrix[i][j]-matrix2[i][j];
		}
	}
	printf("Matriz #1 - Matriz #2 =\n");
	matrixPrinting(mSize,finalMatrix);
}

void decimoPunto(){
	printf("IMPRESIÓN DE MATRICES DE ENTEROS ALEATORIOS (PRODUCTO	):\n");
	printf("---------------------------------------------\n");
	int mSize=matrixDataRecolection();
	int matrix[mSize][mSize], matrix2[mSize][mSize], finalMatrix[mSize][mSize];

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			matrix[i][j] = randomNumerGenerator();
			matrix2[i][j] = randomNumerGenerator();
		}
	}
	printf("Matriz #1:\n");
	matrixPrinting(mSize,matrix);
	printf("Matriz #2:\n");
	matrixPrinting(mSize,matrix2);
	int columnSum = 0;
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			columnSum = 0;
			for (int k = 0; k < mSize; k++)
			{
				columnSum+= matrix[i][k] * matrix2[k][j];
			}
			finalMatrix[i][j] = columnSum;
			
		}
	}
	printf("Matriz #1 * Matriz #2 =\n");
	matrixPrinting(mSize,finalMatrix);
}	

void menu(){
	int opc=0;
	system("clear");
	printf("AUTOR: JUAN CAMILO DE LOS RIOS H.\n");
	printf("PRESENTACIÓN PRIMER TALLER (C)\n");
	printf("BIENVENIDO\n");
	do{
		printf("---------------------------------------------\n");
		printf("Digite el punto que desea ver [1-10]\n[11 - exit]\n");
		scanf("%d",&opc);
		system("clear");
		switch(opc){
			case 1:
				primerPunto();
				break;
			case 2:
				segundoPunto();
				break;
			case 3:
				tercerPunto();
				break;
			case 4:
				cuartoPunto();
				break;
			case 5:
				quintoPunto();
				break;
			case 6:
				sextoPunto();
				break;
			case 7:
				septimoPunto();
				break;
			case 8:
				octavoPunto();
				break;
			case 9:
				novenoPunto();
				break;
			case 10:
				decimoPunto();
				break;
			case 11:
				printf("Gracias por su visita :3\n");
				break;
			default:
				printf("Opción inválida\n");
				break;
		}


	}while(opc!=11);

}