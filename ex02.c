#include <stdio.h>
#include <stdlib.h>

struct Task{
    char *name;
    int memoryAllocated;
    float tempExec;
};

struct Queue {

	int capacity;
	float *data;
	int head;
	int tail;
	int nItems;

};

void createQueue( struct Queue *f, int c ) {

	f->capacity = c;
	f->data = (float*) malloc (f->capacity * sizeof(float));
	f->head = 0;
	f->tail = -1;
	f->nItems = 0;
}

void insert(struct Queue *f, int v) {

	if(f->tail == f->capacity-1)
		f->tail = -1;

	f->tail++;
	f->data[f->tail] = v; // incrementa ultimo e insere
	f->nItems++; // mais um item inserido

}

int delete( struct Queue *f ) { // pega o item do comeÃ§o da fila

	int temp = f->data[f->head++]; // pega o valor e incrementa o primeiro

	if(f->head == f->capacity)
		f->head = 0;

	f->nItems--;  // um item retirado
	return temp;

}

int queueIsEmpty( struct Queue *f ) { // retorna verdadeiro se a fila estÃ¡ vazia

	return (f->nItems==0);
}

int queueIsFull( struct Queue *f ) { // retorna verdadeiro se a fila estÃ¡ cheia

	return (f->nItems == f->capacity);
}

void showQueue(struct Queue *f){

	int cont, i;

	for ( cont=0, i= f->head; cont < f->nItems; cont++){
		printf("%.2f\t",f->data[i++]);

		if (i == f->capacity)
			i=0;
	}

	printf("\n\n");

}

void main () {

	int option, capacity;
	float valor;
	struct Queue queue;

	// cria a fila
	printf("\nCapacidade da fila? ");
	scanf("%d",&capacity);
	createQueue(&queue, capacity);

	// apresenta menu
	while( 1 ){

		printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &option);

		switch(option){

			case 0: exit(0);

			case 1: // insere elemento
				if (queueIsFull(&queue)){
					printf("\nFila Cheia!!!\n\n");
				}
				else {
					printf("\nValor do elemento a ser inserido? ");
					scanf("%f", &valor);
					insert(&queue,valor);
				}

				break;

			case 2: // remove elemento
				if (queueIsEmpty(&queue)){
					printf("\nFila vazia!!!\n\n");
				}
				else {
					valor = delete(&queue);
					printf("\n%1f removido com sucesso\n\n", valor) ;
				}
				break;

				case 3: // mostrar fila
					if (queueIsEmpty(&queue)){
						printf("\nFila vazia!!!\n\n");
					}
					else {
						printf("\nConteudo da fila => ");
						showQueue(&queue);
					}
					break;

				default:
					printf("\nOpcao Invalida\n\n");

		}
	}
}
