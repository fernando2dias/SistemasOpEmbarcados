/*
Você está desenvolvendo um sistema de gerenciamento de funcionários em uma
empresa. Crie uma estrutura chamada "Funcionario" com os seguintes campos: nome
(vetor de caracteres), idade (inteiro) e salario (ponto flutuante). Crie um ponteiro para
a estrutura "Funcionario" e aloque dinamicamente memória para ela. Preencha os
campos da estrutura através do ponteiro e, em seguida, libere a memória alocada no
final do programa.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char* nome;
    int idade;
    float salario;
} Funcionario;

void aloca(Funcionario **ptr);
void setFuncionario(Funcionario *ptr);
void printFuncionario(Funcionario *ptr);

int main(){
    Funcionario* ptr = NULL;
    int stop = 1;
    while(stop != 0){
        aloca(&ptr);
        setFuncionario(ptr);
        printFuncionario(ptr);
        free(ptr);
        printf("\nDigite 0 para parar e 1 para continuar: ");
        scanf("%i", &stop);
    }

    return 0;
}

void aloca(Funcionario **ptr){
    if ( (*ptr = (Funcionario*)malloc(sizeof(Funcionario))) == NULL ){
        exit(1);
    }
}

void setFuncionario(Funcionario *ptr){
    char nomeAux[50];
    printf("\nDigite o nome, a idade e o salário do funcionário separado por espaço: ");
    scanf("%s %i %f", nomeAux, &(ptr->idade), &(ptr->salario));
    (ptr->nome) = strdup(nomeAux);
}

void printFuncionario(Funcionario *ptr){
    printf("\nO nome, a idade e o salário do funcionário: \t%s\t%i\t%.2f", ptr->nome, ptr->idade, ptr->salario );
}