/*
 * Integrantes:
 * Rafael Sperandio Scheiner - RA:12014569
 * Brunno Vega		     - RA:13144175
 * Vitor Borela 	     - RA:14056626
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

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

int criarLista(Lista **listaMatrizes,char nome[],int linha,int coluna)
{	
  int ret;
  
  if(linha > 50 || coluna > 50)
  {
    return 0;
  }
  else
  {
  Lista *novo = (Lista *)malloc(sizeof(Lista));
  strcpy(novo->nome,nome);
  novo->i=linha;
  novo->j=coluna;
  novo->end = criarMatriz(linha,coluna);
  ret = inserir(listaMatrizes,novo);
    if(ret == 1)
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
}
int inserir(Lista **listaMatrizes, Lista *novo)
{
  Lista *atual = *listaMatrizes;
  Lista *anterior = NULL;
 
  if(!(*listaMatrizes)) //lista vazia
    {
    (*listaMatrizes)=novo;
    novo->prox=NULL;
    //(*listaMatrizes)->end = criarMatriz(linha,coluna);
    return 1;
    }
  else
    {  
      while((atual) && (strcmp(atual->nome,novo->nome)!=0))
	{
	  anterior=atual;
	  atual=atual->prox;
	}
      if(strcmp(atual->nome,novo->nome)==0)
	{
	  return 0;
	}
	else
	  {
	    if(!atual) //insere final
	      {
		anterior->prox = novo;
		novo->prox= NULL;
		//novo->end = criarMatriz(linha,coluna);
		return 1;
	      }
   
	  }
    }
}

//DM
int destroirMatriz(Lista **mat,char nome[])
{
  Lista *atual = *mat;
  Lista *anterior=NULL;
  if(!mat)
    {
      return 0;
    }
    else
      {
	while(!(*mat) && (strcmp((atual->nome),nome)==0))
	  {
	    anterior = atual;
	    atual=atual->prox;
	  }
	if(!anterior)
	  {
	    *mat =atual->prox;
	    free(atual);
	    return 1;
	  }
	  else
	    {
	      if(!atual->prox)
		{
		  anterior->prox=NULL;
		  free(atual);
		  return 1;
		}
		else
		  {
		    anterior->prox = atual->prox;
		    free(atual);
		    return 1;
		  }
	    }
  
      }
  
}

/* Funcoes Aux*/
Lista *procuraMat(Lista *mat,char nome[])
{
  Lista *atual=mat;
  while((atual) && (strcmp(atual->nome,nome)!=0))
  {
    atual=atual->prox;
  }
  return atual;
}