/*
Elaborar um programa em C para ler um vetor de float que retorne a quantidade de
elementos lidos, ao qual tal quantidade de elementos e os elementos devem ser
fornecidos pelo usuário e os imprima na tela. Utilize funções e considere que o vetor
tem até 20 elementos
*/
#include<stdio.h>
#include<stdlib.h>

void aloca(float **prt, int size);

int main(){
    float *prt = NULL;
    int stop = 1;
    int size = 0;
    int totalSize = 0;
    while(stop != 0){
        printf("Digite o tamanho do vetor que deseja armazenar: ", size);
        scanf("%i", &size);

        aloca(&prt, totalSize + size);
        for(int i=totalSize; i < (totalSize + size); i++){
            scanf("%f", (prt + i));
        }
        totalSize += size;

        printf("Digite 0 para parar e 1 para continuar: ");
        scanf("%i", &stop);
    }

    for(int i=0; i < totalSize; i++){
        printf("\nValores finais %i: %.2f\n", i+1, *(prt + i));
    }
  

    return 0;
}

void aloca(float **prt, int size){
    if((*prt = (float *) realloc(*prt, size * sizeof(float))) == NULL ){
        exit(1);
    }
}