/*
 * Integrantes:
 * Rafael Sperandio Scheiner - RA:12014569
 * Brunno Vega		     - RA:13144175
 * Vitor Borela 	     - RA:14056626
 * 
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
  char nome,nomeResultado;
  char valores[50];
  int linhas=0,colunas=0,ret=0,i=0,j=0,cont=0;
  float val = 0;
  lista *slot = NULL;
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
      case CM:
	scanf("%s %i %i",&nome,&linhas,&colunas);
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
      case DM:
	scanf("%s",&nome);
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
      case IM:
	
	ret=imprimirMatriz(slot,nome);
	if(ret =0)
	{
	  printf("ERRO");
	}
	break;
	
      case AE:
	scanf("%s %i %i %f",&nome,&linhas,&colunas,&val);
	ret=atribuirElemento(&slot,nome,linhas,colunas,val);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case AL:
	scanf("%s %i", &nome, &linhas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",valores[i]);
	  if(strcmp(valores[i],"#")==0)
	    break;
	  cont++;
	}
	ret=atribruirLinha(slot,nome,linhas,valores,cont);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case AC:
	scanf("%s %i", &nome, &colunas);
	for(i=0;i<51;i++)
	{
	  __fpurge(stdin);
	  scanf("%s",valores[i]);
	  if(strcmp(valores[i],"#")==0)
	    break;
	  cont++;
	}
	ret=atribuirColuna(slot,nome,colunas,valores,cont();
	if(ret = 0)
	{
	  printf("ERRO");
	}
	else
	{
	  printf("OK");
	}
	break;
      case TM:
	scanf("%s %s",&nome,&nomeResultado);
	ret=transporMatriz(slot,nome,nomeResultado);
	if(ret = 0)
	{
	  printf("ERRO");
	}
	break;
      case SM:
	//if para o erro
	break;
      case DV:
	//if para o erro
	break;
      case MM:
	//if para o erro
	break;
      case ME:
	//if para o erro
	break;
      case FE:
	break;
    }
    
  }while(strcmp(FE,operation)==0)
  
  return 0;
}