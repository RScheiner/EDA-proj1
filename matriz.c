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
  Matriz = malloc(colunas * sizeof(int *));
  for(i=0;i<linhas;i++)
  {
    Matriz[i]= malloc(linhas* sizeof(int));
  }
  return Matriz;
}

//DM-> na lista.C

//IM
int imprimirMatriz(lista mat, char nome)
{
  int auxI=0, auxJ=0;
  if(!mat)
    {
      return 0;
    }
    else
      {
	while(!mat && (strcmp((mat->nome),nome)==0))
	  {
	    mat=mat->prox;
	  }
	  for(auxI;auxI<mat->i;auxI++)
	  {
	    for(auxJ;auxJ<mat->j;auxJ++)
	    {
	      printf(" %4.2f ",mat->end[auxI][auxJ]);
	    }
	    printf("\n");
	  }
	  return 1;
      }
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