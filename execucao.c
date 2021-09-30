#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

int execucaoMenu(){
    char opcao[TAM_MAX_REG+2];
    do{
        printf("\nMenu do modo de execucao:\n");
        printf("\n0 - Sair");
        printf("\nb <chave> - Buscar");
        printf("\ni <registro> - Inserir");
        printf("\nr <chave> - Remover");
        printf("\nO que deseja fazer: ");
        input(opcao, TAM_MAX_REG+2);

        if(strncmp(opcao, "b", 1) == 0){
            printf("\nEntrei no modo de busca\n");

        }else if(strncmp(opcao, "i", 1) == 0){
            printf("\nEntrei no modo de insercao\n");
            
        }else if(strncmp(opcao, "r", 1) == 0){
            printf("\nEntrei no modo de remocao\n");
            
        }else{
            if(strncmp(opcao, "0", 1) != 0){
                printf("\nOpcao nao existe, escolha uma das opcoes do menu\n");
            }
        }

    }while (strncmp(opcao, "0", 1) != 0);

    printf("\nMetodo de execucao finalizado");
}