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
int criarLista(Lista **listaMatrizes,char nome,int linha,int coluna);

int inserir(Lista **listaMatrizes, Lista *novo);

//DM - OK
int destroirMatriz(Lista **mat,char nome);