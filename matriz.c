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
  Matriz = malloc(colunas * sizeof(float *));
  for(i=0;i<linhas;i++)
  {
    Matriz[i]= malloc(linhas* sizeof(float));
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
int atribuirElemento(lista **mat,char nome,int linha, int coluna, int valor)
{
  lista *atual=*mat;
  lista *anterior=NULL;

  if(!(*mat))
  {
    return 0;
  }
    else
      {
	while((atual) && (strcmp(atual->nome,nome)!=0))
	  {
	    anterior=atual;
	    atual=atual->prox;
	  }
	  if((atual->i < linha)||(atual->j < coluna))
	    {
	      return 0;
	    }
	    else
	    {
	      atual->end[linha][coluna]=valor;
	      return 1;
	    }
	 return 0;
      }
}
//AL
int atribruirLinha(lista mat,int linha, int valor)
{
}
//AC
int atribuirColuina(lista mat,int coluna, int valor)
{
}
//TM
int transporMatriz(lista mat, lista resposta)
{
}
//SM
int somarMatrizes(lista mat1, lista mat2, lista resposta)
{
}
//DV
int dividirMatrizes(lista mat1, lista mat2, lista resposta)
{
}
//MM
int multiplicarMatrizes(lista mat1, lista mat2, lista resposta)
{
}
//ME
int multiplicarElementosMatrizes(lista mat1, lista mat2, lista resposta)
{
}