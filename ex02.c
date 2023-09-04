/*
Fernando Dias Motta - 180016
Leonardo Picanço Bottaro - 180043
Lucas Fernando Basilio da Costa - 173264
Marcelo Zaguette Junior - 180998
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Task {
    char *name;
    int memoryAllocated;
    float tempExec;
} Task;

typedef struct Queue {
    int capacity;
    Task *data;
    int head;
    int tail;
    int nItems;
} Queue;

void createQueue(struct Queue *f, int c) {
    f->capacity = c;
    f->data = (Task *)malloc(f->capacity * sizeof(Task));
    f->head = 0;
    f->tail = -1;
    f->nItems = 0;
}

void insert(struct Queue *f, Task task) {
    if (f->tail == f->capacity - 1)
        f->tail = -1;

    f->tail++;
    f->data[f->tail] = task;
    f->nItems++;
}

Task delete(struct Queue *f) {
    Task temp = f->data[f->head++];

    if (f->head == f->capacity)
        f->head = 0;

    f->nItems--;
    return temp;
}

int queueIsEmpty(struct Queue *f) {
    return (f->nItems == 0);
}

int queueIsFull(struct Queue *f) {
    return (f->nItems == f->capacity);
}

void showQueue(struct Queue *f) {
    int cont, i;

    for (cont = 0, i = f->head; cont < f->nItems; cont++) {
        printf("Task: %s, Memoria Alocada: %d, Tempo de execucao: %.2f\n",
               f->data[i].name, f->data[i].memoryAllocated, f->data[i].tempExec);
        i = (i + 1) % f->capacity;
    }

    printf("\n");
}

int main() {
    int option, capacity;
    struct Queue queue;

    // cria a fila
    printf("Capacidade da fila? ");
    scanf("%d", &capacity);
    createQueue(&queue, capacity);

    // apresenta menu
    while (1) {
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
        scanf("%d", &option);

        switch (option) {
            case 0:
                exit(0);

            case 1: // insere elemento
                if (queueIsFull(&queue)) {
                    printf("\nFila Cheia!!!\n\n");
                } else {
                    Task task;
                    task.name = (char *)malloc(50 * sizeof(char)); // Allocate memory for task name
                    printf("\nNome da tarefa: ");
                    scanf("%s", task.name);
                    printf("Memoria alocada: ");
                    scanf("%d", &task.memoryAllocated);
                    printf("Tempo de execucao: ");
                    scanf("%f", &task.tempExec);
                    insert(&queue, task);
                }
                break;

            case 2: // remove elemento
                if (queueIsEmpty(&queue)) {
                    printf("\nFila vazia!!!\n\n");
                } else {
                    Task removedTask = delete(&queue);
                    printf("\nTarefa removida com sucesso:\n");
                    printf("Task: %s, Memoria Alocada: %d, Tempo de Execucao: %.2f\n",
                           removedTask.name, removedTask.memoryAllocated, removedTask.tempExec);
                    free(removedTask.name); // Free the memory allocated for the task name
                }
                break;

            case 3: // mostrar fila
                if (queueIsEmpty(&queue)) {
                    printf("\nFila vazia!!!\n\n");
                } else {
                    printf("\nConteudo da fila:\n");
                    showQueue(&queue);
                }
                break;

            default:
                printf("\nOpcao Invalida\n\n");
        }
    }
}
