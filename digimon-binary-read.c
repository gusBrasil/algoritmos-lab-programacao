// Programa feito por Gustavo Medeiros Brasil para a matéria Algoritmos e Laboratório de Programação.
// A função desse algoritmo é ler o arquivo binário gerado pelo programa que o cria.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Digievolucoes {
    char pre[40];
    char pos[40];
};

struct Digimon {
    char nome[40];
    char nivel[20];
    char atributo[20];
    struct Digievolucoes digievolucoes;
};

// recebe um Digimon como argumento e exibe na tela todas as informações armazenadas nele, incluindo nome, nível, atributo, e pré e pós-evoluções.
void mostrarDigimon(struct Digimon digimon) {
    printf("Nome: %s\nNivel: %s\nAtributo: %s\nPre-evolucao: %s\nPos-evolucao: %s\n\n", digimon.nome, digimon.nivel, digimon.atributo, digimon.digievolucoes.pre, digimon.digievolucoes.pos);
}

int main() {
    // abrir arquivo binário para leitura
    FILE *arquivo = fopen("digimons.bin", "rb");

    // verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo binario.\n");
        return 1;
    }

    // ler a lista de digimons do arquivo binário
    struct Digimon digimons[3];
    fread(digimons, sizeof(struct Digimon), 3, arquivo);

    // fechar o arquivo binário
    // fclose(arquivo);

    printf("Lista de Digimons:\n");

    int i;
    for (i = 0; i < 3; i++) {
        mostrarDigimon(digimons[i]);
    }

    return 0;
}
