#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM_STR "|"
#define TAM_MAX_REG 64

int main(int argc, char *argv[]) {

    if (argc == 3 && strcmp(argv[1], "-i") == 0) {

        printf("Modo de importacao ativado ... nome do arquivo = %s\n", argv[2]);

        FILE *dados;
        FILE *saida;
        if( (dados = fopen(argv[2], "r") ) == NULL ){
            printf("deu merda na leitura do arquivo");
            exit(EXIT_FAILURE);
        }

        char reg[TAM_MAX_REG];
        fread(&reg, sizeof(reg), 1, dados);

        printf("%s\n", reg);
        char* teste = strtok(reg, DELIM_STR);
        printf("%s\n", teste);

        fclose(dados);
        printf("passei por tudo");
        

    }else if(argc == 3 && strcmp(argv[1], "-e") == 0) {

        printf("Modo de execucao de operacoes ativado ... nome do arquivo = %s\n", argv[2]);
        //executa_operacoes(argv[2]);

    } else if (argc == 2 && strcmp(argv[1], "-p") == 0) {

        printf("Modo de impressao da PED ativado ...\n");
        //imprime_ped();

    } else {

        fprintf(stderr, "Argumentos incorretos!\n");
        fprintf(stderr, "Modo de uso:\n");
        fprintf(stderr, "$ %s (-i|-e|-p) nome_arquivo\n", argv[0]);
        fprintf(stderr, "$ %s -p\n", argv[0]);
        exit(EXIT_FAILURE);

    }

    return 0;
}