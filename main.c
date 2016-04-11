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
  char nome;
  int linhas,colunas;
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
        fgets(operation,32,stdin);
	
	
    switch (operation)
    {
      case CM:
	scanf("%s %i %i",&nome,&linhas,&colunas);
	criarLista(slot,nome,linhas,colunas);
	break;
      case DM:
	break;
      case IM:
	break;
      case AE:
	break;
      case AL:
	break;
      case AC:
	break;
      case TM:
	break;
      case SM:
	break;
      case DV:
	break;
      case MM:
	break;
      case ME:
	break;
      case FE:
	break;
    }
    
  }while(strcmp(FE,operation)==0)
  
  return 0;
}