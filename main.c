#include "queue.h"

int main() {

    Fila* fila = criarFila();

    enqueue(fila, "Davi");
    enqueue(fila, "Amor");
    enqueue(fila, "Guedes");

    imprimeFila(fila, printString);
    liberarFila(fila);

    return 0;
}