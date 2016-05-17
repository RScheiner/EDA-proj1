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
#include "matriz.h"
#include "lista.h"

int main (void)
{
  char operation[2];
  char nome[10],nome2[10],nomeResultado[10];
  char valores[50];
  int linhas=0,colunas=0,ret=0,i=0,j=0,cont=0;
  float val = 0;
  Lista *slot = NULL;
  Lista *recebe1=NULL;
  Lista *recebe2=NULL;
  Lista *recebe3=NULL;
  do{
    printf("CM-Criar Matriz\n");
    printf("DM-Destruir Matriz\n");
    printf("IM-Imprimir Matriz\n");
    printf("AE-Atribuir Elemento a matriz\n");
    printf("AL-Atribuir uma Linha a matriz\n");
    printf("AC-Atribuir uma Coluna a matriz\n");
    printf("TM-Transpor uma Matriz\n");
    printf("SM-Somar duas Matrizes\n");
    printf("DV-Dividir uma matriz por outra(elemento por elemento)\n");
    printf("MM-Multiplicar uma Matriz por outra\n");
    printf("ME-Multiplicar uma matriz por outra (elemento a elemento) \n");
    printf("FE-Finaliza a Execução\n");
	__fpurge(stdin);
        fgets(operation,32,stdin);
	
	if(strcmp("CM",operation)==0)
	{	
	fgets(nome,32,stdin);
	scanf("%i %i",&linhas,&colunas);
	ret = criarLista(&slot,nome,linhas,colunas);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}

      if(strcmp("DM",operation)==0)
	{
	fgets(nome,32,stdin);
	ret=destroirMatriz(&slot,nome);
	if(ret==0)
	{
	  printf("ERRO");
	}
	else
	{
	  if(ret==1)
	  {
	     printf("OK");
	  }
	  else
	  {
	    printf("ERRO");
	  }
	}
	}
    
	if(strcmp("IM",operation)==0)
	{
	fgets(nome,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	else
	{
	recebe1 = procuraMat(slot,nome);
	ret=imprimirMatriz(recebe1->end,recebe1->i,recebe1->j);
	}
	if(ret =0)
	{
	  printf("ERRO");
	}
	}
      if(strcmp("AE",operation)==0)
	{
	fgets(nome,32,stdin);
	scanf( "%i %i %f",&linhas,&colunas,&val);
	if(!slot)
	{
	  printf("ERRO");
	}
	else
	{
	recebe1 = procuraMat(slot,nome);
	if((recebe1->i < linhas)||(recebe1->j < colunas))
	{
	  printf("ERRO");
	}
	else
	{
	ret=atribuirElemento(recebe1->end,recebe1->i,recebe1->j,val);
	}
	}
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
      if(strcmp("AL",operation)==0)
	{
	fgets(nome,32,stdin);
	scanf("%i", &linhas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",&valores[i]);
	  if(strcmp("#",valores[i])==0)
	    break;
	  cont++;
	}
	if(!slot)
	{
	  printf("ERRO");
	}
	else
	{
	recebe1 = procuraMat(slot,nome);
	if(recebe1->j < cont)
	{
	  printf("ERRO");
	}
	else
	{
	ret=atribruirLinha(recebe1->end,linhas,valores);
	} 
	}
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
      if(strcmp("AC",operation)==0)
	{
	fgets(nome,32,stdin);
	scanf("%i", &colunas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",&valores[i]);
	  if(strcmp("#",valores[i])==0)
	    break;
	  cont++;
	}
	if(!slot)
	{
	  printf("ERRO");
	}
	else
	{
	recebe1 = procuraMat(slot,nome);
	if(recebe1->i < cont)
	{
	  printf("ERRO");
	}
	else
	{
	ret=atribruirLinha(recebe1->end,colunas,valores);
	} 
	}
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
     if(strcmp("TM",operation)==0)
	{
	fgets(nome,32,stdin);
	fgets(nomeResultado,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	  else
	  {
	  
	recebe1=procuraMat(slot,nome);
	 Lista *novo = (Lista *)malloc(sizeof(Lista));
	  strcpy(novo->nome,nomeResultado);
	    novo->i= recebe1->j;
	      novo->j= recebe1->i;
		novo->end=criarMatriz(recebe1->j,recebe1->i); 
	ret = inserir(&slot,novo);
	if(ret == 0)
	{
	  printf("ERRO");
	}
	else
	{
	recebe2=procuraMat(slot,nomeResultado);
	ret=transporMatriz(recebe1->end,recebe2->end,recebe1->i,recebe1->j);
	}
	    
	}
	if(ret = 0)
	{
	  printf("ERRO");
	}
	}
      if(strcmp("SM",operation)==0)
	{
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	  else
	  {
	    recebe1=procuraMat(slot,nome);
	    recebe2=procuraMat(slot,nome2);
	    if(recebe1->i != recebe2->i || recebe1->j != recebe2->j)
	    {
	       printf("ERRO");
	    }
	    else
	    {
	      Lista *novo = (Lista *)malloc(sizeof(Lista));
	      strcpy(novo->nome,nomeResultado);
	      novo->i= recebe1->j;
	      novo->j= recebe1->i;
	      novo->end=criarMatriz(recebe1->j,recebe1->i); 
	      ret = inserir(&slot,novo);
	      if(ret ==0)
	      {
		printf("ERRO");
	      }
	      else
	      {
	      recebe3=procuraMat(slot,nomeResultado);
	      ret=somarMatrizes(recebe1->end,recebe2->end,recebe3->end,recebe1->i,recebe1->j);
	  }
	  }
	  }
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
      if(strcmp("DV",operation)==0)
	{
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	  else
	  {
	    recebe1=procuraMat(slot,nome);
	    recebe2=procuraMat(slot,nome2);
	    if(recebe1->i != recebe2->i || recebe1->j != recebe2->j)
	    {
	       printf("ERRO");
	    }
	    else
	    {
	      Lista *novo = (Lista *)malloc(sizeof(Lista));
	      strcpy(novo->nome,nomeResultado);
	      novo->i= recebe1->j;
	      novo->j= recebe1->i;
	      novo->end=criarMatriz(recebe1->j,recebe1->i); 
	      ret = inserir(&slot,novo);
	      if(ret ==0)
	      {
		printf("ERRO");
	      }
	      else
	      {
	      recebe3=procuraMat(slot,nomeResultado);
	      ret=dividirMatrizes(recebe1->end,recebe2->end,recebe3->end,recebe1->i,recebe1->j);
	  }
	  }
	  }
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
      if(strcmp("MM",operation)==0)
	{
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	  else
	  {
	    recebe1=procuraMat(slot,nome);
	    recebe2=procuraMat(slot,nome2);
	    if(recebe1->i != recebe2->j)
	    {
	       printf("ERRO");
	    }
	    else
	    {
	      Lista *novo = (Lista *)malloc(sizeof(Lista));
	      strcpy(novo->nome,nomeResultado);
	      novo->i= recebe1->j;
	      novo->j= recebe1->i;
	      novo->end=criarMatriz(recebe1->j,recebe1->i); 
	      ret = inserir(&slot,novo);
	      if(ret ==0)
	      {
		printf("ERRO");
	      }
	      else
	      {
	      recebe3=procuraMat(slot,nomeResultado);
	      ret=multiplicarMatrizes(recebe1->end,recebe2->end,recebe3->end,recebe1->i,recebe1->j,recebe2->j);
	  }
	  }
	  }
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
      if(strcmp("ME",operation)==0)
	{
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	if(!slot)
	{
	  printf("ERRO");
	}
	  else
	  {
	    recebe1=procuraMat(slot,nome);
	    recebe2=procuraMat(slot,nome2);
	    if(recebe1->i != recebe2->i || recebe1->j != recebe2->j)
	    {
	       printf("ERRO");
	    }
	    else
	    {
	      Lista *novo = (Lista *)malloc(sizeof(Lista));
	      strcpy(novo->nome,nomeResultado);
	      novo->i= recebe1->j;
	      novo->j= recebe1->i;
	      novo->end=criarMatriz(recebe1->j,recebe1->i); 
	      ret = inserir(&slot,novo);
	      if(ret ==0)
	      {
		printf("ERRO");
	      }
	      else
	      {
	      recebe3=procuraMat(slot,nomeResultado);
	      ret=multiplicarElementosMatrizes(recebe1->end,recebe2->end,recebe3->end,recebe1->i,recebe1->j);
	  }
	  }
	  }
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	}
    
  }while(strcmp("FE",operation)==0);
  
  return 0;
}