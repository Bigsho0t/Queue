#pragma once

#ifndef __queue_h__
#define __queue_h__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SUCESSO 0;
#define FALHA 1;

typedef struct No {

    void* valor;
    struct No* proximo;

} No;

typedef struct Fila {

    No* primeiro;
    No* ultimo;
    int tamanho;

} Fila;

void printInt(void* valor);
void printChar(void* valor);
void printString(void* valor);
void printFloat(void* valor);
void printDouble(void* valor);
Fila* criarFila();
No* criarNo(void* valor);
int enqueue(Fila* fila, void* valor);
void* dequeue(Fila* fila);
void* peek(Fila* fila);
bool isEmpty(Fila* fila);
int size(Fila* fila);
void imprimeFila(Fila* fila, void (*printFunc)(void*));
void liberarFila(Fila* fila);

#endif