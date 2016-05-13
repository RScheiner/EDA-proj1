//#ifndef LISTA_H_
#define LISTA_H_

/* tipo exportado */

typedef struct lista Lista;

/* Funcoes */
//CM - OK
int criarLista(Lista **listaMatrizes,char nome,int linha,int coluna);

int inserir(Lista **listaMatrizes, Lista *novo);

//DM - OK
int destroirMatriz(Lista **mat,char nome);