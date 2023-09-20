#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "arff.h"

void exibe_atributos(atributo *infos, int quantidade)
{
  // Função do A1 (com modificações para o atributo de categorias)

  if (infos == NULL)
  {
    printf("O arquivo ARFF fornecido é inválido!\n");
    exit(0);
  }

  printf("=== ATRIBUTOS DO ARQUIVO ===\n");
  for (int i = 0; i < quantidade; i++)
  {
    printf("-> Atributo #%d\n", i + 1);
    printf("Rótulo: %s\n", infos[i].rotulo);
    printf("Tipo: %s\n", infos[i].tipo);
    // if (infos[i].categorias)
    //   printf("Categorias: %s\n", infos[i].categorias);
    if (i < quantidade - 1)
      printf("------------------------------\n");
  }
  printf("===============================\n");
}

int conta_atributos(FILE *arff)
{
  // Função do A1
  char line[LINESIZE];
  int attributeCount = 0;

  while (fgets(line, sizeof(line), arff) != NULL)
  {
    if (strstr(line, "@attribute") == line)
    {
      attributeCount++;
    }
  }

  return attributeCount;
}

void processa_categorias(atributo *elemento, char *categorias)
{
  // Recbe uma string com as categorias e atualiza o elemento com um vetor de strings (modificar a struct)
}

atributo *processa_atributos(FILE *arff, int quantidade)
{
  // Função do A1 (com modificações para o atributo de categorias)

  char line[256];             // Tamanho da linha arbitrário
  atributo *atributos = NULL; // vetor
  int numAtributos = 0;
  rewind(arff);
  
  while (fgets(line, sizeof(line), arff) != NULL)
  {
    if (strstr(line, "@attribute") == line)
    {

      atributo novoAtributo;
      char *token = strtok(line, " ");
      token = strtok(NULL, " ");           // Pula o "@attribute"
      novoAtributo.rotulo = strdup(token); // Copia o rótulo
      token = strtok(NULL, " ");           // Pega o nome
      novoAtributo.tipo = strdup(token);   // Copia o tipo

      // mudar para estrutura de vetor
      novoAtributo.categorias = NULL;

      // Adicione o novo atributo à lista
      numAtributos++;
      atributos = realloc(atributos, numAtributos * sizeof(atributo));
      atributos[numAtributos - 1] = novoAtributo;
    }
  }

  return atributos;
}

void valida_arff(FILE *arff, atributo *atributos, int quantidade)
{
  // Recebe um arquivo arff com ponteiro de leitura antes do "@data"; passa por todas as linhas de dados e valida cada elementos de cada coluna em
  // relação ao vetor de atributos também fornecido como argumento.
}
