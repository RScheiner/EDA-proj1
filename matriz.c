#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

//matriz ortogonais (ver material)

/*struct matriz{
  int valor
  matriz *lado, *baixo;
};*/


/* Funcoes */

//CM
float **criarMatriz(int linhas, int colunas)
{
  float **Matriz;
  int i,j;
  Matriz = malloc(linhas * sizeof(int *));
  for(i=0;i<linhas;i++)
  {
    Matriz[i]= malloc(colunas* sizeof(int));
  }
  return Matriz;
}

//DM
int destroirMatriz(Matriz mat)
{
}
//IM
int imprimirMatriz(Matriz mat)
{
}
//AE
int atribuirElemento(Matriz mat,int linha, int coluna, int valor)
{
}
//AL
int atribruirLinha(Matriz mat,int linha, int valor)
{
}
//AC
int atribuirColuina(Matriz mat,int coluna, int valor)
{
}
//TM
int transporMatriz(Matriz mat, Matriz resposta)
{
}
//SM
int somarMatrizes(Matriz mat1, Matriz mat2, Matriz resposta)
{
}
//DV
int dividirMatrizes(Matriz mat1, Matriz mat2, Matriz resposta)
{
}
//MM
int multiplicarMatrizes(Matriz mat1, Matriz mat2, Matriz resposta)
{
}
//ME
int multiplicarElementosMatrizes(Matriz mat1, Matriz mat2, Matriz resposta)
{
}