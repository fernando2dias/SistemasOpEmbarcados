/*
Elaborar um programa em C utilizando estruturas para coletar informações de idade,
peso e altura de 5 pessoas e imprimi-las na tela
*/
#include<stdio.h>
#include<stdbool.h>

typedef struct person{
    float height;
    float weight;
} person;

void setWeightAndHeight(person* person_attributes);
void printWeightAndHeight(person* person_attributes);

int main(){
    person person_attributes[5];
    person* person_attributes_pointer = &person_attributes;

    int stop = 1;

    while (stop != 0){
        setWeightAndHeight(person_attributes_pointer);
        printWeightAndHeight(person_attributes_pointer);
        printf("Digite 0 para sair e 1 para continuar: ");
        scanf("%i", &stop);
    }

}

void setWeightAndHeight(person* person_attributes){
    for(int i=0; i<5; i++){
        printf("Digite o valor do peso e da altura separado por espaco para a pessoa %i: ", i+1);
        scanf("%f %f", &((person_attributes+i)->weight), &((person_attributes + i)->height));
    }
}

void printWeightAndHeight(person* person_attributes){
    for(int i=0; i<5; i++){
        printf("\nValor dos atributos da pessoa %i\n\tPeso: %.2f\t Altura: %.2f", i+1, ((person_attributes+i)->weight), ((person_attributes+i)->height));
    }
}