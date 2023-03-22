// Programa feito por Gustavo Medeiros Brasil na aula de Algoritmos
// A função desse programa é receber um input de pasta e arquivo do usuário e ler os binários

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_POKEMON 50
#define MAX_TIPO_POKEMON 20
#define MAX_EVOLUCOES_POKEMON 100
#define MAX_FRAQUEZAS_POKEMON 100

typedef struct {
    char nome[MAX_NOME_POKEMON];
    char tipo[MAX_TIPO_POKEMON];
    char evolucoes[MAX_EVOLUCOES_POKEMON];
    char fraquezas[MAX_FRAQUEZAS_POKEMON];
} Pokemon;

int main() {
    char nome_arquivo[MAX_NOME_POKEMON];
    char caminho_pasta[MAX_NOME_POKEMON];
    printf("Digite o nome da pasta que contem o arquivo: ");
    scanf("%s", caminho_pasta);
    printf("Digite o nome do arquivo que deseja ler: ");
    scanf("%s", nome_arquivo);

    char caminho_arquivo[MAX_NOME_POKEMON * 2 + 10]; // tamanho maximo de nome_pasta + tamanho maximo de nome_arquivo + "/ + .txt"
    sprintf(caminho_arquivo, "%s/%s.txt", caminho_pasta, nome_arquivo);

    FILE *arquivo = fopen(caminho_arquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    Pokemon pokemon;
    fread(&pokemon, sizeof(Pokemon), 1, arquivo);
    fclose(arquivo);

    printf("Dados do pokemon:\n");
    printf("Nome: %s\n", pokemon.nome);
    printf("Tipo: %s\n", pokemon.tipo);
    printf("Evolucoes: %s\n", pokemon.evolucoes);
    printf("Fraquezas: %s\n", pokemon.fraquezas);

    return 0;
}

