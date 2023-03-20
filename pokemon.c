// Programa feito por Gustavo Medeiros Brasil para pôr em prática os aprendizados da Linguagem C
// Vistas tanto no Curso de C/C++ de John Haste quanto nas aulas de Algoritmos da professora Cecilia

// O foco desse programa é criar uma pasta com o nome definido pelo usuário, e então um arquivo que cataloga os pokemons do usuário,
// Baseando-se em nome, tipo, evoluções e fraquezas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MAX_NOME_POKEMON 50
#define MAX_TIPO_POKEMON 20
#define MAX_EVOLUCOES_POKEMON 100
#define MAX_FRAQUEZAS_POKEMON 100

int main() {
    char nome_pasta[MAX_NOME_POKEMON];
    int num_arquivos, i, j;
    
    printf("Digite o nome da pasta que deseja criar: ");
    scanf("%s", nome_pasta);
    mkdir(nome_pasta, 0777);
    
    printf("Digite o numero de arquivos de texto que deseja criar: ");
    scanf("%d", &num_arquivos);
    
    for (i = 1; i <= num_arquivos; i++) {
        char nome_arquivo[MAX_NOME_POKEMON];
        printf("Digite o nome do %do. arquivo: ", i);
        scanf("%s", nome_arquivo);
        
        char caminho_arquivo[MAX_NOME_POKEMON + 10]; // tamanho maximo de nome_pasta + "/ + nome_arquivo"
        sprintf(caminho_arquivo, "%s/%s.txt", nome_pasta, nome_arquivo);
        
        char nome[MAX_NOME_POKEMON], tipo[MAX_TIPO_POKEMON], evolucoes[MAX_EVOLUCOES_POKEMON], fraquezas[MAX_FRAQUEZAS_POKEMON];
        int salvar = 0, corrigir = 1; // variaveis para guardar as escolhas do usuario
        
        // printf("Digite o nome do pokemon: ");
        // scanf("%s", nome);
        // Como o nome do .txt é o mesmo do pokemon, não há necessidade de definir um nome

        printf("Digite o tipo do pokemon: ");
        scanf("%s", tipo);
        printf("Digite as evolucoes do pokemon (separadas por barra): ");
        scanf("%s", evolucoes);
        printf("Digite as fraquezas do pokemon (separadas por barra): ");
        scanf("%s", fraquezas);
        
        while (corrigir) { // enquanto o usuario quiser corrigir
            printf("Os dados digitados foram:\n");
            printf("Nome: %s\n", nome_arquivo);
            printf("Tipo: %s\n", tipo);
            printf("Evolucoes: %s\n", evolucoes);
            printf("Fraquezas: %s\n", fraquezas);
            
            printf("O que deseja corrigir?\n");
            printf("0 - Nome\n");
            printf("1 - Tipo\n");
            printf("2 - Evolucoes\n");
            printf("3 - Fraquezas\n");
            printf("4 - Nada\n");
            int opcao_correcao;
            scanf("%d", &opcao_correcao);
            
            switch (opcao_correcao) {
                case 0:
                    printf("Digite o novo nome: ");
                    scanf("%s", nome_arquivo);
                    break;
                case 1:
                    printf("Digite o novo tipo: ");
                    scanf("%s", tipo);
                    break;
                case 2:
                    printf("Digite as novas evolucoes (separadas por barra): ");
                    scanf("%s", evolucoes);
                    break;
                case 3:
                    printf("Digite as novas fraquezas (separadas por barra): ");
                    scanf("%s", fraquezas);
                    break;
                case 4:
                    salvar = 1; // se escolher "Nada", então já pode salvar sem precisar corrigir mais nada
                    corrigir = 0; // sai do loop de correção
                    break;
                default:
                    printf("Opcao invalida!\n");
                    break;
            }

            if (!salvar) { // se ainda não tiver decidido salvar, pergunta se deseja corrigir mais alguma coisa
                printf("Deseja corrigir mais alguma coisa? (0 - nao, 1 - sim): ");
                scanf("%d", &corrigir);
            }

            if (salvar) { // se escolheu "Nada", então já salvou antes de sair do loop de correção
                FILE *arquivo = fopen(caminho_arquivo, "w");
                fprintf(arquivo, "Nome: %s\n", nome_arquivo);
                fprintf(arquivo, "Tipo: %s\n", tipo);
                fprintf(arquivo, "Evolucoes: %s\n", evolucoes);
                fprintf(arquivo, "Fraquezas: %s\n", fraquezas);
                fclose(arquivo);
            }
        }
        
        FILE *arquivo = fopen(caminho_arquivo, "w");
        fprintf(arquivo, "Nome: %s\n", nome_arquivo);
        fprintf(arquivo, "Tipo: %s\n", tipo);
        fprintf(arquivo, "Evolucoes: %s\n", evolucoes);
        fprintf(arquivo, "Fraquezas: %s\n", fraquezas);
        fclose(arquivo);
    }

return 0;
}
