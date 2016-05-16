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
  char operation;
  char nome[10],nome2[10],nomeResultado[10];
  char valores[50];
  int linhas=0,colunas=0,ret=0,i=0,j=0,cont=0;
  float val = 0;
  Lista *slot = NULL;
  Lista *recebe1=NULL;
  Lista *recebe2=NULL;
  Lista *recebe3=NULL;
  do{
    printf("CM-Criar Matriz");
    printf("DM-Destruir Matriz");
    printf("IM-Imprimir Matriz");
    printf("AE-Atribuir Elemento a matriz");
    printf("AL-Atribuir uma Linha a matriz");
    printf("AC-Atribuir uma Coluna a matriz");
    printf("TM-Transpor uma Matriz");
    printf("SM-Somar duas Matrizes");
    printf("DV-Dividir uma matriz por outra(elemento por elemento)");
    printf("MM-Multiplicar uma Matriz por outra");
    printf("ME-Multiplicar uma matriz por outra (elemento a elemento) ");
    printf("FE-Finaliza a Execução");
	__fpurge(stdin);
        fgets(operation,32,stdin);
	
	
    switch (operation)
    {
      case 'CM': //ok
	fgets(nome,32,stdin);
	scanf("%i %i",&linhas,&colunas);
	ret = criarLista(slot,nome,linhas,colunas);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case 'DM': //ok
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
	break;
      case 'IM': //ok
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
	break;
	
      case 'AE': //ok
	fgets(nome,32,stdin);
	scanf( "%i %i %f",&linhas,&colunas,&val);
	if(!slot)
	{
	  printf("ERRO");
	}
	else
	{
	recebe1 = procuraMat(slot,nome);
	if((recebe1->i < linha)||(recebe1->j < coluna))
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
	break;
      case 'AL': //ok
	fgets(nome,32,stdin);
	scanf("%i", &linhas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",valores[i]);
	  if(strcmp(valores[i],"#")==0)
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
	break;
      case 'AC': //ok
	fgets(nome,32,stdin);
	scanf("%i", &colunas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",valores[i]);
	  if(strcmp(valores[i],"#")==0)
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
	break;
      case 'TM': //ok
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
	ret = inserir(&slot,novo)
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
	break;
      case 'SM': //ok
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
	      ret = inserir(&slot,novo)
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
	break;
      case 'DV'://to do
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	ret=dividirMatrizes(slot,nome,nome2,nomeResultado);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case 'MM'://to do
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	ret=multiplicarMatrizes(slot,nome,nome2,nomeResultado);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case 'ME'://to do
	fgets(nome,32,stdin);
	fgets(nome2,32,stdin);
	fgets(nomeResultado,32,stdin);
	ret=multiplicarElementosMatrizes(slot,nome,nome2,nomeResultado);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case 'FE':
	break;
    }
    
  }while(strcmp('FE',operation)==0);
  
  return 0;
}