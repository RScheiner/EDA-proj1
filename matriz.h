/*
 * Integrantes:
 * Rafael Sperandio Scheiner - RA:12014569
 * Brunno Vega		     - RA:13144175
 * Vitor Borela 	     - RA:14056626
 */

#ifndef MATRIZ_H_
#define MATRIZ_H_

/* tipo exportado */


/* Funcoes */

//DM-> na lista.H

//IM - OK
int imprimirMatriz(float **mat, int i, int j);

//AE
int atribuirElemento(float **mat, int i, int j, float val);

//AL
int atribruirLinha(float **mat, int linha, char valores[]);

//AC
int atribuirColuna(float **mat, int coluna, char valores[]);

//TM
int transporMatriz(float **mat1, float **mat2, int L, int C);

//SM
int somarMatrizes(float **mat1,float **mat2,float **matR, int linha, int coluna);

//DV
int dividirMatrizes(float **mat1,float **mat2,float **matR, int linha, int coluna);

//MM
int multiplicarMatrizes(float **mat1,float **mat2,float **matR, int linha, int coluna,int coluna2);

//ME
int multiplicarElementosMatrizes(float **mat1,float **mat2,float **matR, int linha, int coluna);

#endif