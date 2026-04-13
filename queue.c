#include "queue.h"
#include "../node/node.h"
#include <stdlib.h>
#include <assert.h>

typedef struct queue {
    node* first;
    node* last;
    size_t size;
    void (*free_function)(void*);
    void (*print_function)(const void*);
} queue;

queue* new_queue(void (*free_function)(void*), void (*print_function)(const void*)) {

    queue* q = malloc(sizeof(*q));

    if (q == NULL) {
        return NULL;
    }

    q->first = NULL;
    q->last = NULL;
    q->size = 0;
    q->free_function = free_function;
    q->print_function = print_function;

    return q;
}

status queue_enqueue(queue* q, void* value) {

    if (q == NULL) {
        return NULL_POINTER;
    }

    node* new_last = new_node(value);

    if (new_last == NULL) {
        return ALLOC_FAIL;
    }

    if (q->size == 0) {
        q->first = q->last = new_last;
    }

    else {
        q->last->next = new_last;
        q->last = new_last;
    }

    q->size++;

    return SUCCESS;
}

void* queue_dequeue(queue* q) {

    if (q == NULL || q->size == 0) {
        return NULL;
    }

    void* value = q->first->value;
    node* temp = q->first;
    q->first = q->first->next;

    if (q->first == NULL) {
        q->last = NULL;
    }

    free(temp);
    q->size--;

    return value;
}

void* queue_front(const queue* q) {

    if (q == NULL || q->size == 0) {
        return NULL;
    }

    return q->first->value;
}

bool queue_is_empty(const queue* q) {
    assert(q != NULL);
    return q->size == 0;
}

size_t queue_size(const queue* q) {
    assert(q != NULL);
    return q->size;
}

status queue_clear(queue* q) {

    if (q == NULL) return NULL_POINTER;

    node* current = q->first;

    while (current != NULL) {
        node* next = current->next;
        if (q->free_function != NULL && current->value != NULL) {
            q->free_function(current->value);
        }
        free(current);
        current = next;
    }

    q->first = NULL;
    q->last = NULL;
    q->size = 0;

    return SUCCESS;
}

void queue_print(const queue* q) {

    if (q == NULL || q->print_function == NULL) {
        return;
    }

    node* current = q->first;

    while (current != NULL) {

        q->print_function(current->value);
        if (current->next != NULL) printf(" -> ");
        current = current->next;
    }
}

void queue_free(queue* q) {

    if (q == NULL) return;
    queue_clear(q);
    free(q);
}