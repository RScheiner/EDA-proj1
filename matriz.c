#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "lista.h"

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

  for(i=0;i<linhas;i++)
  {
    for(j=0;j<colunas;j++)
    {
      Matriz[i][j]=0;
    }
  }
  return Matriz;
}

//DM-> na lista.C

//IM
int imprimirMatriz(lista *mat, char nome)
{
  int auxI=0, auxJ=0;
  lista *imprimir;
  if(!mat)
    {
      return 0;
    }
    else
      {
	imprimir = procuraMat(mat,nome);
	
	  for(auxI;auxI<imprimir->i;auxI++)
	  {
	    for(auxJ;auxJ<imprimir->j;auxJ++)
	    {
	      printf("%6.2f",imprimir->end[auxI][auxJ]);
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
/*
 * fazer um vetor para pegar os valores
 * usar
 * atof (asc to float) <- retorna um float obs: Matriz[i][j] = atof();
 * para converter
 * verificar com o #
 */
int atribruirLinha(lista **mat,char nome,int linha, char valores,int var)
{
 lista *atual=*mat;
 int j=0;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
    while((atual) && (strcmp(atual->nome,nome)!=0))
    {
      atual=atual->prox;
    }
    if(var < atual->j)
    {
      return 0;
    }
    else
    {
      for(j=0;j<51;j++)
      {
	if(strcmp(valores[j],"#")==0)
	{
	  return 1;
	}
	else
	{
	  atual->end[linha][j]=atof(valores[j]);
	}
      }
    }
  }
}
//AC
int atribuirColuna(lista **mat,char nome,int coluna, char valores,int var)
{
  lista *atual = *mat;
  int i=0;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
    while((atual) && (strcmp(atual->nome,nome)!=0))
    {
      atual=atual->prox;
    }
    if(var < atual->i)
    {
      return 0;
    }
     else
    {
      for(i=0;i<51;i++)
      {
	if(strcmp(valores[i],"#")==0)
	{
	  return 1;
	}
	else
	{
	  atual->end[i][coluna]=atof(valores[i]);
	}
      }
    }
  }
}
//TM
int transporMatriz(lista *mat,char nome,char nomeResultado)
{
  lista *atual=mat;
  int i,j;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
    while(atual && strcmp(atual->nome,nome) !=0 )
    {
      atual=atual->prox;
    }
    lista *novo = (lista *)malloc(sizeof(lista));
    strcpy(novo->nome,nome);
    novo->i= atual->j;
    novo->j= atual->i;
    novo->end=criarMatriz(atual->j,atual->i);
    for(i=0;i<(atual->i);i++)
    {
      for(j=0;j<(atual->j);j++)
      {
	novo->end[j][i]=atual->end[i][j];
      }
    }
  }
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

/* Funcoes Aux*/
lista procuraMat(lista *mat,char nome)
{
  lista *atual=mat;
  while((atual) && (strcmp(atual->nome,nome)!=0))
  {
    atual=atual->prox;
  }
  return atual;
}