#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printInt(void* valor) {

    printf("%i", *(int*)valor);
}

void printChar(void* valor) {

    printf("%c", *(char*)valor);
}

void printString(void* valor) {

    printf("%s", (char*)valor);
}

void printFloat(void* valor) {

    printf("%f", *(float*)valor);
}

void printDouble(void* valor) {

    printf("%f", *(double*)valor);
}

Fila* criarFila() {

    Fila* novaFila = (Fila*) malloc(sizeof(Fila));

    if (novaFila == NULL) {

        return NULL;
    }

    novaFila->primeiro = NULL;
    novaFila->ultimo = NULL;
    novaFila->tamanho = 0;
    return novaFila;
}

No* criarNo(void* valor) {

    No* novoNo = (No*) malloc(sizeof(No));

    if (novoNo == NULL) {

        return NULL;
    }

    novoNo->valor = valor;
    novoNo->proximo = NULL;

    return novoNo;
}

int enqueue(Fila* fila, void* valor) {

    if (fila == NULL) {

        return FALHA;
    }

    No* novoNo = criarNo(valor);

    if (novoNo == NULL) {

        return FALHA;
    }

    if (fila->primeiro == NULL) {

        fila->primeiro = novoNo;
        fila->ultimo = novoNo;
        fila->tamanho++;
        return SUCESSO;
    }

    fila->ultimo->proximo = novoNo;
    fila->ultimo = novoNo;
    fila->tamanho++;
    return SUCESSO;
}

void* dequeue(Fila* fila) {

    if (fila == NULL || fila->primeiro == NULL) {

        return NULL;
    }

    void* valor = fila->primeiro->valor;
    No* temp = fila->primeiro;
    fila->primeiro = fila->primeiro->proximo;

    if (fila->primeiro == NULL) {

        fila->ultimo = NULL;
    }

    free(temp);
    fila->tamanho--;
    return valor;
}

void* peek(Fila* fila) {

    if (fila == NULL || fila->primeiro == NULL) {

        return NULL;
    }

    void* valor = fila->primeiro->valor;
    return valor;
}

bool isEmpty(Fila* fila) {

    return fila->primeiro == NULL;
}

int size(Fila* fila) {

    return fila->tamanho;
}

void imprimeFila(Fila* fila, void (*printFunc)(void*)) {

    if (fila == NULL) {

        printf("Fila não existe\n");
        return;
    }
    
    if (fila->primeiro == NULL) {
        
        printf("Fila vazia\n");
        return;
    }

    No* atual = fila->primeiro;

    while (atual != NULL) {

        printFunc(atual->valor);
        printf(" -> ");
        atual = atual->proximo;
    }

    printf("NULL\n");
}

void liberarFila(Fila* fila) {

    if (fila == NULL) {

        return;
    }

    No* atual = fila->primeiro;

    while (atual != NULL) {

        No* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    free(fila);
}