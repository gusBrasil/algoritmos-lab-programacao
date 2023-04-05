#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char tipo[10];
    char evolucao[20];
} Pokemon;

int main() {
    int i, n;
    FILE *arquivo;
    Pokemon p;

    arquivo = fopen("pokemons.bin", "rb");

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    fread(&n, sizeof(int), 1, arquivo);

    printf("Numero de pokemons: %d\n", n);

    for(i=0; i<n; i++) {
        fread(&p, sizeof(Pokemon), 1, arquivo);
        printf("\nPokemon %d:\n", i+1);
        printf("Nome: %s\n", p.nome);
        printf("Tipo: %s\n", p.tipo);
        printf("Evolucao: %s\n", p.evolucao);
    }

    fclose(arquivo);

    return 0;
}

