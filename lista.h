#ifndef LISTA_H_
#define LISTA_H_

/* tipo exportado */

typedef struct lista Lista;

/* Funcoes */
//CM - OK
int criarLista(lista **listaMatrizes,char nome,int linha,int coluna);

int inserir(lista **listaMatrizes, lista *novo,int linha,int coluna);

//DM - OK
int destroirMatriz(Matriz **mat,char nome);