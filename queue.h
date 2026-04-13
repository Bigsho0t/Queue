#pragma once

#include <stdio.h>
#include <stdbool.h>
#include "../status/status.h"

typedef struct queue queue;

/**
 * @brief Inicializa e aloca uma nova instância de queue (fila).
 * * Reserva memória para a estrutura de controle. A fila opera no modelo
 * FIFO (First-In, First-Out).
 * * @param free_function  Opcional: Callback para desalocação dos elementos (pode ser NULL).
 * @param print_function Opcional: Callback para exibição dos elementos (pode ser NULL).
 * @return
 * - `queue*`: Endereço da nova instância alocada.
 * - `NULL`: Caso ocorra falha de alocação de memória.
 */
queue* new_queue(void (*free_function)(void*), void (*print_function)(const void*));

/**
 * @brief Insere um novo elemento ao final da fila (enfileirar).
 * * @param q     Instância da queue.
 * @param value Referência do valor a ser armazenado.
 * @return
 * - `SUCCESS`: Operação concluída com sucesso.
 * - `ALLOC_FAIL`: Falha ao alocar memória para o nó da fila.
 * - `NULL_POINTER`: Se 'q' for nulo.
 */
status queue_enqueue(queue* q, void* value);

/**
 * @brief Remove e retorna o elemento localizado no início da fila.
 * * @param q Instância da queue.
 * @return
 * - `void*`: Endereço do valor que estava na primeira posição.
 * - `NULL`: Se a fila estiver vazia ou 'q' for nulo.
 * @note Esta função transfere a responsabilidade da memória do valor para o chamador,
 * ignorando a 'free_function'.
 */
void* queue_dequeue(queue* q);

/**
 * @brief Recupera a referência do primeiro elemento da fila sem removê-lo.
 * * @param q Instância da queue.
 * @return
 * - `void*`: Endereço do valor na frente da fila.
 * - `NULL`: Se a fila estiver vazia ou 'q' for nulo.
 */
void* queue_front(const queue* q);

/**
 * @brief Verifica se a fila não possui elementos.
 * * @note Utiliza `assert` para validar a integridade da referência 'q' em modo debug.
 * * @param q Instância da queue.
 * @return
 * - `true`: Fila vazia.
 * - `false`: Fila contém elementos.
 */
bool queue_is_empty(const queue* q);

/**
 * @brief Retorna a quantidade total de elementos atualmente na fila.
 * * @note Utiliza `assert` para garantir que a referência 'q' não seja nula.
 * * @param q Instância da queue.
 * @return `size_t`: Número de elementos armazenados.
 */
size_t queue_size(const queue* q);

/**
 * @brief Remove e libera todos os elementos e nós contidos na fila.
 * * Invoca a 'free_function' configurada para cada elemento, mas mantém
 * a estrutura da queue alocada para novos usos.
 * * @param q Instância da queue a ser limpa.
 * @return
 * - `SUCCESS`: Fila esvaziada com sucesso.
 * - `NULL_POINTER`: Se 'q' for nulo.
 */
status queue_clear(queue* q);

/**
 * @brief Exibe no terminal os elementos da fila.
 * * Percorre a estrutura do início ao fim utilizando a 'print_function' fornecida.
 * * @param q Instância da queue.
 */
void queue_print(const queue* q);

/**
 * @brief Desaloca completamente a queue e todos os seus recursos internos.
 * * Realiza a limpeza de todos os nós (e valores, caso a 'free_function' exista)
 * antes de liberar a estrutura principal.
 * * @param q Instância da queue a ser destruída.
 */
void queue_free(queue* q);