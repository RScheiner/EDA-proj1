#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"
#include "lista.h"

struct lista{
  char nome[10];
  float **end;
  lista *prox;
};

void criarLista(lista **listaMatrizes,char nome,int linha,int coluna)
{
  lista *novo = (lista *)malloc(sizeof(lista));
  strcpy(novo->nome,nome);
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