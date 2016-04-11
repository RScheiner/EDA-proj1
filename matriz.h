#ifndef MATRIZ_H_
#define MATRIZ_H_

/* tipo exportado */
typedef struct matriz Matriz;

/* Funcoes */

//CM
int criarMatriz(Matriz mat, int linhas, int colunas);
//DM
int destroirMatriz(Matriz mat);
//IM
int imprimirMatriz(Matriz mat);
//AE
int atribuirElemento(Matriz mat,int linha, int coluna, int valor);
//AL
int atribruirLinha(Matriz mat,int linha, int valor);
//AC
int atribuirColuina(Matriz mat,int coluna, int valor);
//TM
int transporMatriz(Matriz mat, Matriz resposta);
//SM
int somarMatrizes(Matriz mat1, Matriz mat2, Matriz resposta);
//DV
int dividirMatrizes(Matriz mat1, Matriz mat2, Matriz resposta);
//MM
int multiplicarMatrizes(Matriz mat1, Matriz mat2, Matriz resposta);
//ME
int multiplicarElementosMatrizes(Matriz mat1, Matriz mat2, Matriz resposta);

#endif