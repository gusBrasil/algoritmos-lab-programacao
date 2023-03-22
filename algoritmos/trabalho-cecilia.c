#include <stdio.h>

int main() {
    FILE *arquivo;
    char frase[100];
    int numero, i, quantidade;

    // funcao 1
    arquivo = fopen("arquivo.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    printf("Digite uma frase para ser escrita no arquivo: ");
    fgets(frase, 100, stdin);
    fprintf(arquivo, "%s", frase);
    fclose(arquivo);
    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("Frase escrita no arquivo: ");
    fgets(frase, 100, arquivo);
    printf("%s", frase);
    fclose(arquivo);

    // funcao 2
    arquivo = fopen("arquivo.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    printf("Digite um numero para ser escrito no arquivo: ");
    scanf("%d", &numero);
    fprintf(arquivo, "%d", numero);
    fclose(arquivo);
    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    fscanf(arquivo, "%d", &numero);
    printf("Numero escrito no arquivo: %d\n", numero);
    fclose(arquivo);

    // funcao 3
    arquivo = fopen("arquivo.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    printf("Digite a quantidade de frases que deseja escrever: ");
    scanf("%d", &quantidade);
    getchar(); // consome o \n deixado pelo scanf
    for (i = 0; i < quantidade; i++) {
        printf("Digite a frase %d: ", i+1);
        fgets(frase, 100, stdin);
        fprintf(arquivo, "%s", frase);
    }
    fclose(arquivo);
    arquivo = fopen("arquivo.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("Frases escritas no arquivo:\n");
    while (fgets(frase, 100, arquivo) != NULL) {
        printf("%s", frase);
    }
    fclose(arquivo);

    return 0;
}
