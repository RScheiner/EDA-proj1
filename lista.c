#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "lista.h"

struct lista{
  char nome[10];
  float **end;
  int i,j; //i == linhas j == colunas
  lista *prox;
};

void criarLista(lista **listaMatrizes,char nome,int linha,int coluna)
{
  lista *novo = (lista *)malloc(sizeof(lista));
  strcpy(novo->nome,nome);
  novo->i=linhas;
  novo->j=colunas;
  inserir(listaMatrizes,novo,linha,coluna);
}

void inserir(lista **listaMatrizes, lista *novo,int linha,int coluna)
{
  lista *atual = *lista;
  lista *anterior = NULL;
 
  if(!(*listaMatrizes)) //lista vazia
    {
    (*listaMatrizes)=novo;
    novo->prox=NULL;
    (*listaMatrizes)->end = criarMatriz(linha,coluna);
    }
  else
    {  
      while((atual))
	{
	  anterior=atual;
	  atual=atual->prox;
	}
      if(!atual) //insere final
	{
	  anterior->prox = novo;
	  novo->prox= NULL;
	  novo->end = criarMatriz(linha,coluna);
	}
   
    }
}

//DM
int destroirMatriz(lista **mat,char nome)
{
  lista *atual = *mat;
  lista *anterior=NULL;
  if(!mat)
    {
      return 0;
    }
    else
      {
	while(!(*mat) && (strcmp((mat->nome),nome)==0))
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