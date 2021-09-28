#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DELIM_CH '|'
#define DELIM_STR "|"
#define TAM_MAX_REG 64

FILE* openReadFile(char *nome){
    FILE* dados;
    if( (dados = fopen(nome, "r") ) == NULL ){
        printf("Algo deu errado na leitura do arquivo");
        exit(EXIT_FAILURE);
    }
    return dados;
} 

int readRegister(char * buffer, int tam, FILE* binaryData){
    char *pt;
    char registro[tam];
    memset(registro, 0, tam);
    pt = strtok(buffer, DELIM_STR);
    for (int i = 0; i < 4; i++){    
        strcat(registro, pt);
        strcat(registro, DELIM_STR);
        pt = strtok(NULL, DELIM_STR);
    }
    // printf("\nescrevendo: %s", registro);
    fwrite(registro , 1 , sizeof(registro) , binaryData);
    return strlen(registro);
}

int importacao(char* dados){

    FILE* dadosTxt;
    if( (dadosTxt = fopen(dados, "r") ) == NULL ){
        printf("Algo deu errado na leitura do arquivo %s", dados);
        return 0;
        exit(EXIT_FAILURE);
    }

    FILE *dadosBinarios;
    if( (dadosBinarios = fopen("dados","w+b") ) == NULL ){
        printf("Algo deu errado na leitura do arquivo dados.dat");
        return 0;
        exit(EXIT_FAILURE);
    }

    int proxRegistro = 0;
    char reg[TAM_MAX_REG];
    int existeReg = 1;

    while (existeReg == 1){
        fread(&reg, sizeof(reg), 1, dadosTxt);
        fseek(dadosTxt, proxRegistro * sizeof (char), SEEK_SET);
        if(fread(&reg, sizeof(reg), 1, dadosTxt) != 1){
            // acabou os registros
            existeReg = 0;
        }
        //move o ponteiro de leitura para o prox registro (somatorio dos bytes lidos ate agora)
        proxRegistro += readRegister(&reg, TAM_MAX_REG, dadosBinarios);
    }

    fclose(dadosTxt);
    fclose(dadosBinarios);
    return 1;
}