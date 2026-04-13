#include "queue.h"
#include <stdio.h>

void print_string(const void* s) {
    printf("%s", (char*)s);
}

int main() {

    queue* fila = new_queue(NULL, print_string);

    queue_enqueue(fila, NULL);
    queue_enqueue(fila, "Fred");
    queue_enqueue(fila, "Guedes");
    queue_print(fila);
    queue_free(fila);

    return 0;
}