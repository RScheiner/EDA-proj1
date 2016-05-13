#ifndef MATRIZ_H_
#define MATRIZ_H_

/* tipo exportado */
typedef struct matriz Matriz;

/* Funcoes */

//CM
float **criarMatriz(int linhas, int colunas);

//DM-> na lista.H

//IM - OK
int imprimirMatriz(lista *mat);

//AE
int atribuirElemento(lista **mat,char nome,int linha, int coluna, int valor);

//AL
int atribruirLinha(lista **mat,char nome,int linha, char valores,int var);

//AC
int atribuirColuna(lista **mat,char nome,int coluna, char valores,int var);

//TM
int transporMatriz(lista *mat,char nome,char nomeResultado);

//SM
int somarMatrizes(lista *mat,char nome,char nome2,char nomeResultado);

//DV
int dividirMatrizes(lista *mat,char nome,char nome2,char nomeResultado);

//MM
int multiplicarMatrizes(lista *mat,char nome,char nome2,char nomeResultado);

//ME
int multiplicarElementosMatrizes(lista *mat,char nome,char nome2,char nomeResultado);

/* Funcoes Aux*/
lista procuraMat(lista *mat,char nome);
#endif