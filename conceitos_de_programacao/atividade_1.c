/*
Elaborar um programa em C utilizando estruturas para coletar informações de idade,
peso e altura de uma pessoa e imprimi-las na tela.
*/
#include<stdio.h>

typedef struct person{
    float height;
    float weight;
} person;

void setWeightAndHeight(person* person_attributes);

int main(){
    person person_attributes = {0.0, 0.0};

    person* person_attributes_pointer = &person_attributes;
    setWeightAndHeight(person_attributes_pointer);
    while(person_attributes.weight != 0.0 && person_attributes.height != 0.0){
    printf("Peso: %.2f\tAltura: %.2f\n", person_attributes.weight, person_attributes.height);
    setWeightAndHeight(person_attributes_pointer);
    }

    return 0;
}

void setWeightAndHeight(person* person_attributes){
    printf("Digite o valor do peso e da altura separado por espaco (0.0 e 0.0 para parar execucao): ");
    scanf("%f %f", &(person_attributes->weight), &(person_attributes->height));
}