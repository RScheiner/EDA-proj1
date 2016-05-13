#ifndef MATRIZ_H_
#define MATRIZ_H_
#include "lista.h"

/* tipo exportado */
typedef struct matriz Matriz;

/* Funcoes */

//CM
float **criarMatriz(int linhas, int colunas);

//DM-> na lista.H

//IM - OK
int imprimirMatriz(Lista *mat, char nome);

//AE
int atribuirElemento(Lista **mat,char nome,int linha, int coluna, int valor);

//AL
int atribruirLinha(Lista **mat,char nome,int linha, char valores,int var);

//AC
int atribuirColuna(Lista **mat,char nome,int coluna, char valores,int var);

//TM
int transporMatriz(Lista *mat,char nome,char nomeResultado);

//SM
int somarMatrizes(Lista *mat,char nome,char nome2,char nomeResultado);

//DV
int dividirMatrizes(Lista *mat,char nome,char nome2,char nomeResultado);

//MM
int multiplicarMatrizes(Lista *mat,char nome,char nome2,char nomeResultado);

//ME
int multiplicarElementosMatrizes(Lista *mat,char nome,char nome2,char nomeResultado);

/* Funcoes Aux*/
Lista procuraMat(Lista *mat,char nome);
#endif