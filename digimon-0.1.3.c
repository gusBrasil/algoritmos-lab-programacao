// Programa feito por Gustavo Medeiros Brasil para a matéria Algoritmos e Laboratório de Programação.
// A função desse algoritmo é gerar uma struct de Digimons, salvando os dados de cada digimon de acordo com o input do usuário.
// Atualizado: Agora o resultado gerado pelo usuário será salvo em um arquivo de texto para se ter as informações salvas localmente.

#include <stdio.h>
#include <string.h>

struct Digievolucoes {
    char pre[30];
    char pos[30];
};

struct Digimon {
    char nome[30];
    char nivel[20];
    char atributo[20];
    struct Digievolucoes digievolucoes;
};

void mostrarDigimon(struct Digimon digimon) { 
    printf("Nome: %s\nNivel: %s\nAtributo: %s\nPre-evolucao: %s\nPos-evolucao: %s\n", digimon.nome, digimon.nivel, digimon.atributo, digimon.digievolucoes.pre, digimon.digievolucoes.pos);
}

int main() {
    FILE *arq;
    arq = fopen("digimons.txt", "w"); // abre o arquivo para escrita
    
    if (arq == NULL) {
        printf("Erro ao criar arquivo!\n");
        return 1;
    }
    
    struct Digimon digimons[3]; // cria uma array de Digimon com 3 elementos
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
        // Recebe input do usuário com as informações necessárias

        fprintf(arq, "Nome: %s\nNivel: %s\nAtributo: %s\nForma anterior: %s\nForma posterior: %s\n\n", digimons[i].nome, digimons[i].nivel, digimons[i].atributo, digimons[i].digievolucoes.pre, digimons[i].digievolucoes.pos);
        // Escreve as informações no arquivo
        
        printf("\nNovo Digimon cadastrado:\n"); 
        printf("Nome: %s\nNivel: %s\nAtributo: %s\nForma anterior: %s\nForma posterior: %s\n\n", digimons[i].nome, digimons[i].nivel, digimons[i].atributo, digimons[i].digievolucoes.pre, digimons[i].digievolucoes.pos);
        //Imprime o que foi preenchido para o usuário
    }

    fclose(arq); // fecha o arquivo

    int numElemento;
    printf("Digite o numero do elemento que deseja exibir: ");
    scanf("%d", &numElemento);

    mostrarDigimon(digimons[numElemento - 1]);

    return 0;
}

