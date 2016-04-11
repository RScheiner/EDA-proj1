#ifndef LISTA_H_
#define LISTA_H_

/* tipo exportado */

typedef struct lista Lista;

/* Funcoes */
void criarLista(lista **listaMatrizes,char nome,int linha,int coluna);

void inserir(lista **listaMatrizes, lista *novo,int linha,int coluna);