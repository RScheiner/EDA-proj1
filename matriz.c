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
int imprimirMatriz(Lista *mat, char nome)
{
  int auxI=0, auxJ=0;
  Lista *imprimir;
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
int atribuirElemento(Lista **mat,char nome,int linha, int coluna, int valor)
{
  Lista *atual=*mat;
  Lista *anterior=NULL;

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
int atribruirLinha(Lista **mat,char nome,int linha, char valores,int var)
{
 Lista *atual=*mat;
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
    if(var > atual->j)
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
int atribuirColuna(Lista **mat,char nome,int coluna, char valores,int var)
{
  Lista *atual = *mat;
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
    if(var > atual->i)
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
int transporMatriz(Lista *mat,char nome,char nomeResultado)
{
  Lista *atual=mat;
  int i,j,ret;
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
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    strcpy(novo->nome,nomeResultado);
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
    ret = inserir(novo,nomeResultado);
    return ret;
  }
}
//SM
int somarMatrizes(Lista *mat,char nome,char nome2,char nomeResultado)
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
	  novo->end[i][j]= m1->end[i][j]+m2->end[i][j];
        }
      }
      ret=inserir(novo,nomeResultado);
      return ret;
    }
  }
}
//DV
int dividirMatrizes(Lista *mat,char nome,char nome2,char nomeResultado)
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
int multiplicarMatrizes(Lista *mat,char nome,char nome2,char nomeResultado)
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
int multiplicarElementosMatrizes(Lista *mat,char nome,char nome2,char nomeResultado)
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

/* Funcoes Aux*/
Lista procuraMat(Lista *mat,char nome)
{
  Lista *atual=mat;
  while((atual) && (strcmp(atual->nome,nome)!=0))
  {
    atual=atual->prox;
  }
  return atual;
}