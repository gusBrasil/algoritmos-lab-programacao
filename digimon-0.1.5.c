// Programa feito por Gustavo Medeiros Brasil para a matéria Algoritmos e Laboratório de Programação.
// A função desse algoritmo é gerar uma struct de Digimons, salvando os dados de cada digimon de acordo com o input do usuário.
// Atualizado: Agora os digimons são exibidos em uma lista, e o usuário pode escolher entre ordenar na ordem alfabética crescente ou decrescente.
// O programa salva num arquivo binário, que deve ser lido com o algoritmo correto.

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

// responsável por comparar os nomes de dois digimons e retornar um valor positivo se o primeiro for maior que o segundo, um valor negativo se o segundo for maior que o primeiro, e zero se forem iguais. 
int compararNomesCrescente(const void* a, const void* b) {
    struct Digimon *digimonA = (struct Digimon*) a;
    struct Digimon *digimonB = (struct Digimon*) b;
    return strcmp(digimonA->nome, digimonB->nome);
}

// faz o mesmo da função acima, porém para ordem decrescente.
int compararNomesDecrescente(const void* a, const void* b) {
    struct Digimon *digimonA = (struct Digimon*) a;
    struct Digimon *digimonB = (struct Digimon*) b;
    return strcmp(digimonB->nome, digimonA->nome);
}

// recebe um Digimon como argumento e exibe na tela todas as informações armazenadas nele, incluindo nome, nível, atributo, e pré e pós-evoluções.
void mostrarDigimon(struct Digimon digimon) {
    printf("Nome: %s\nNivel: %s\nAtributo: %s\nPre-evolucao: %s\nPos-evolucao: %s\n\n", digimon.nome, digimon.nivel, digimon.atributo, digimon.digievolucoes.pre, digimon.digievolucoes.pos);
}

int main() {
    struct Digimon digimons[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Digite o nome do Digimon %d: ", i+1);
        scanf("%s", digimons[i].nome);
        printf("Digite o nivel do Digimon %d: ", i+1);
        scanf("%s", digimons[i].nivel);
        printf("Digite o atributo do Digimon %d: ", i+1);
        scanf("%s", digimons[i].atributo);
        printf("Digite a forma anterior do Digimon %d: ", i+1);
        scanf("%s", digimons[i].digievolucoes.pre);
        printf("Digite a forma posterior do Digimon %d: ", i+1);
        scanf("%s", digimons[i].digievolucoes.pos);
        printf("\n");
    }

    int opcao;
    //printf("Digite 1 para ordenar em ordem crescente ou 2 para ordenar em ordem decrescente: ");
    printf("Deseja ordenar em ordem crescente ou decrescente? (1/2): ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        qsort(digimons, 3, sizeof(struct Digimon), compararNomesCrescente);
    } else if (opcao == 2) {
        qsort(digimons, 3, sizeof(struct Digimon), compararNomesDecrescente);
    } else {
        printf("Opcao invalida!\n");
        return 1;
    }

        // abrir arquivo binário para escrita
    FILE *arquivo = fopen("digimons.bin", "wb");

    // verificar se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo binario.\n");
        return 1;
    }

    // escrever a lista de digimons no arquivo binário
    fwrite(digimons, sizeof(struct Digimon), 3, arquivo);

    // fechar o arquivo binário
    fclose(arquivo);

    printf("Arquivo binario criado com sucesso.\n");

    printf("Lista de Digimons:\n");

    for (i = 0; i < 3; i++) {
        mostrarDigimon(digimons[i]);
    }

    return 0;
}
