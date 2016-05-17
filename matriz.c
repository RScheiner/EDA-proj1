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


/*mandar soh o campo float*/

//matriz ortogonais (ver material)

/*struct matriz{
  int valor
  matriz *lado, *baixo;
};*/

/* Funcoes */



//DM-> na lista.C

//IM
int imprimirMatriz(float **mat,int i,int j)
{
  int auxI=0,auxJ=0;
	for(auxI;auxI<i;auxI++)
	  {
	    for(auxJ;auxJ<j;auxJ++)
	    {
	      printf("%6.2f",mat[auxI][auxJ]);
	    }
	    printf("\n");
	  }
	  return 1;
}
//AE
int atribuirElemento(float **mat,int i,int j,float val)
{
	      mat[i][j]=val;
	      return 1;

}
//AL
/*
 * fazer um vetor para pegar os valores
 * usar
 * atof (asc to float) <- retorna um float obs: Matriz[i][j] = atof();
 * para converter
 * verificar com o #
 */
int atribruirLinha(float **mat,int linha,char valores[])
{
 int j=0;

      for(j=0;j<51;j++)
      {
	if(strcmp(valores[j],"#")==0)
	{
	  return 1;
	}
	else
	{
	  mat[linha][j]=atof(valores[j]);
	}
      }
}
//AC
int atribuirColuna(float **mat,int coluna,char valores[])
{

  int i=0;

      for(i=0;i<51;i++)
      {
	if(strcmp(valores[i],"#")==0)
	{
	  return 1;
	}
	else
	{
	  mat[i][coluna]=atof(valores[i]);
	}
      }
  
}
//TM
int transporMatriz(float **mat1,float **mat2,int L,int C)
{
  int i,j;

    for(i=0;i<L;i++)
    {
      for(j=0;j<C;j++)
      {
	mat2[j][i]=mat1[i][j];
      }
    }
    return 1;
}
//SM
int somarMatrizes(float **mat1,float **mat2,float **matR,int linha,int coluna)
{
 
  int i,j;
  
      for(i=0;i<linha;i++)
      {
        for(j=0;j<coluna;j++)
	{
	  matR[i][j]= mat1[i][j]+mat2[i][j];
        }
      }
  return 1;
}
//DV
int dividirMatrizes(float **mat1,float **mat2,float **matR,int linha,int coluna)
{

  int i,j;

      for(i=0;i<linha;i++)
      {
        for(j=0;j<coluna;j++)
	{
	  if(mat2[i][j] != 0)
	  {
	  matR[i][j]= mat1[i][j]/mat2[i][j];
	  }
	  else
	  {
	    matR[i][j]=0;
	  }
        }
      }
      return 1;
}
//MM
int multiplicarMatrizes(float **mat1,float **mat2,float **matR,int linha,int coluna,int coluna2)
{
  int i,j,n;
       for(i=0;i< linha;i++)
       {
        for(j=0;j<coluna2;j++)
	{
            for(n=0;n<coluna;n++)
	    {
                matR[i][j]= matR[i][j] + mat1[i][n] * mat2[n][j];
            }
        }
       }
  return 1;
}
//ME
int multiplicarElementosMatrizes(float **mat1,float **mat2,float **matR,int linha,int coluna)
{
  int i,j;
  
      for(i=0;i<linha;i++)
      {
        for(j=0;j<coluna;j++)
	{
	 matR[i][j]= mat1[i][j]*mat2[i][j];
        }
      }
  return 1;
}

