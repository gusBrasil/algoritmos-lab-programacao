// Programa feito por Gustavo Medeiros Brasil para a matéria Algoritmos e Laboratório de Programação.
// A função desse algoritmo é gerar uma matriz, com os dados determinados pelo usuário no momento da execução do programa.

#include <stdio.h>

int main()
{
    // Criar uma matriz 3x3
    int matriz[3][3];

    // Preencher a matriz com valores inseridos pelo usuário
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir a matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
