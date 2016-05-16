/*
 * Integrantes:
 * Rafael Sperandio Scheiner - RA:12014569
 * Brunno Vega		     - RA:13144175
 * Vitor Borela 	     - RA:14056626
 */

//#ifndef LISTA_H_
#define LISTA_H_

/* tipo exportado */

typedef struct lista Lista;

struct lista{
  char nome[10];
  float **end;
  int i,j; //i == linhas j == colunas
  Lista *prox;
};


/* Funcoes */
//CM - OK
int criarLista(Lista **listaMatrizes,char nome[],int linha,int coluna);

int inserir(Lista **listaMatrizes, Lista *novo);

//DM - OK
int destroirMatriz(Lista **mat,char nome[]);

/* Funcoes Aux*/
Lista procuraMat(Lista *mat,char nome[]);

//CM
float **criarMatriz(int linhas, int colunas);
