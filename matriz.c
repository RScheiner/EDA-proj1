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
  int auxI=0,auxJ=0
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
	      atual->end[linha][coluna]=valor;
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
int atribruirLinha(float **mat,int linha,char valores)
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
int atribuirColuna(float **mat,int coluna,char valores)
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
	  atual->mat[i][coluna]=atof(valores[i]);
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

}
//DV
int dividirMatrizes()
{
  Lista *m1, *m2;
  int i,j,ret;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
  *m1=procuraMat(mat,nome);
  *m2=procuraMat(mat,nome2);
    if(m1->i != m2->i || m1->j != m2->j)
    {
      return 0;
    }
    else
    {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome,nomeResultado);
    novo->i= m1->i;
    novo->j= m1->j;
    novo->end=criarMatriz(m1->i,m1->j);
      for(i=0;i<(m1->i);i++)
      {
        for(j=0;j<(m1->j);j++)
	{
	  if(m2[i][j] != 0)
	  {
	  novo->end[i][j]= m1->end[i][j]/m2->end[i][j];
	  }
	  else
	  {
	    novo->end[i][j]=0;
	  }
        }
      }
      ret=inserir(novo,nomeResultado);
      return ret;
    }
  }
}
//MM
int multiplicarMatrizes()
{
  Lista *m1, *m2;
  int i,j,n,ret;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
  *m1=procuraMat(mat,nome);
  *m2=procuraMat(mat,nome2);
    if(m1->i != m2->j)
    {
    return 0;
    }
    else
    {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome,nomeResultado);
    novo->i= m1->i;
    novo->j= m1->j;
    novo->end=criarMatriz(m1->i,m2->j);
       for(i=0;i< m1->i;i++)
       {
        for(j=0;j< m2->j;j++)
	{
            for(n=0;n<m1->j;n++)
	    {
                novo->end[i][j]= novo->end[i][j] + m1->end[i][n] * m2->end[n][j];
            }
        }
       }
    }
  }
}
//ME
int multiplicarElementosMatrizes()
{
  Lista *m1, *m2;
  int i,j,ret;
  if(!(*mat))
  {
    return 0;
  }
  else
  {
  *m1=procuraMat(mat,nome); 	 	
  *m2=procuraMat(mat,nome2);
    if(m1->i != m2->i || m1->j != m2->j)
    {
      return 0;
    }
    else
    {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome,nomeResultado);
    novo->i= m1->i;
    novo->j= m1->j;
    novo->end=criarMatriz(m1->i,m1->j);
      for(i=0;i<(m1->i);i++)
      {
        for(j=0;j<(m1->j);j++)
	{
	  novo->end[i][j]= m1->end[i][j]*m2->end[i][j];
        }
      }
      ret=inserir(novo,nomeResultado);
      return ret;
    }
  }
}

