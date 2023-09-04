/*
Elaborar um programa em C utilizando estruturas e ponteiros para coletar informações
de idade, peso e altura de uma pessoa e imprimi-las na tela. Nesse caso, uma das
variáveis estruturas deve ser um ponteiro que irá obter as informações de outra
estrutura (não ponteiro).
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct person{
    int age;
    float weight;
    float height;
} person;

void aloca(person **person_pointer);
void transferData(person *from, person *to);

int main(){
    person person1;
    person* person_pointer = NULL;

    int stop = 1;

    while(stop != 0){
        printf("Digite o valor da altura, peso e altura separado por espaco: ");
        scanf("%i %f %f", &(person1.age), &(person1.weight), &(person1.height));

        printf("\nValor da pessoa digitada: \t%i\t%.2f\t%.2f ", person1.age, person1.weight, person1.height);
        aloca(&person_pointer);
        transferData(&person1, person_pointer);
        printf("\nValor da pessoa copiada: \t%i\t%.2f\t%.2f ", (person_pointer->age), (person_pointer->weight), (person_pointer->height));
        free(person_pointer);
        printf("\nDigite 0 para sair e 1 para continuar: ");
        scanf("%i", &stop);
    }
    return 0;
}

void aloca(person **person_pointer){
    *person_pointer = (person *)malloc(sizeof(person));
    if( person_pointer == NULL ){
        exit(1);
    }
}

void transferData(person *from, person *to){
    (to->age) = (from->age);
    (to->weight) = (from->weight);
    (to->height) = (from->height);
}