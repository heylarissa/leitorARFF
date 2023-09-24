#ifndef __LOG__
#define __LOG__

#include "arff.h"

typedef struct
{
    int ocorrencias;
    char *nome;

} log;

#define ATAQUES_FILE "R_ATAQUES.txt"
#define ENTIDADES_FILE "R_ENTIDADES.txt"

#define TRUE 1
#define FALSE 0
void get_ataques(atributo *dados, int quantidade, FILE *arquivo);
void get_entidades(atributo *dados, int quantidade, FILE *arquivo);
void get_tamanho(atributo *dados, int quantidade);
void get_firewall(atributo *dados, int quantidade);

#endif