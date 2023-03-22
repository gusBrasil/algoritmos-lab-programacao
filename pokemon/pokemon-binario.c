// Programa feito por Gustavo Medeiros Brasil na aula de Algoritmos
// Agora o programa de pokemons que cria uma pasta recebendo inputs de informação do usuário, conta com uma função deletar
// Além disso, também cria o arquivo em binário, usando o arquivo leitura-pokemon para buscar o arquivo e ler.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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
    char nome_pasta[MAX_NOME_POKEMON];
    int num_arquivos, i, j;
    
    printf("Digite o nome da pasta que deseja criar: ");
    scanf("%s", nome_pasta);
    mkdir(nome_pasta);
    
    printf("Digite o numero de arquivos que deseja criar: ");
    scanf("%d", &num_arquivos);
    
    for (i = 1; i <= num_arquivos; i++) {
        char nome_arquivo[MAX_NOME_POKEMON];
        printf("Digite o nome do %do. arquivo: ", i);
        scanf("%s", nome_arquivo);
        
        char caminho_arquivo[MAX_NOME_POKEMON + 10]; // tamanho maximo de nome_pasta + "/ + nome_arquivo"
        sprintf(caminho_arquivo, "%s/%s.txt", nome_pasta, nome_arquivo);
        
        Pokemon pokemon;
        strcpy(pokemon.nome, nome_arquivo);
        
        printf("Digite o tipo do pokemon: ");
        scanf("%s", pokemon.tipo);
        printf("Digite as evolucoes do pokemon (separadas por barra): ");
        scanf("%s", pokemon.evolucoes);
        printf("Digite as fraquezas do pokemon (separadas por barra): ");
        scanf("%s", pokemon.fraquezas);
        
        int corrigir = 1;
        int salvar = 0;
        
        while (corrigir) { // enquanto o usuario quiser corrigir
            printf("Os dados digitados foram:\n");
            printf("Nome: %s\n", pokemon.nome);
            printf("Tipo: %s\n", pokemon.tipo);
            printf("Evolucoes: %s\n", pokemon.evolucoes);
            printf("Fraquezas: %s\n", pokemon.fraquezas);
            
            printf("O que deseja corrigir?\n");
            printf("0 - Nome\n");
            printf("1 - Tipo\n");
            printf("2 - Evolucoes\n");
            printf("3 - Fraquezas\n");
            printf("4 - Nada\n");
            printf("5 - Deletar\n");
			int opcao_correcao;
            scanf("%d", &opcao_correcao);
            
            switch (opcao_correcao) {
                case 0:
                    printf("Digite o novo nome: ");
                    scanf("%s", pokemon.nome);
                    break;
                case 1:
                    printf("Digite o novo tipo: ");
                    scanf("%s", pokemon.tipo);
                    break;
                case 2:
                    printf("Digite as novas evolucoes (separadas por barra): ");
                    scanf("%s", pokemon.evolucoes);
                    break;
                case 3:
                    printf("Digite as novas fraquezas (separadas por barra): ");
                    scanf("%s", pokemon.fraquezas);
                    break;
				case 4:
    				salvar = 1;
    				corrigir = 0;
    				break;
    			case 5:
        			printf("Deseja excluir alguma entrada?\n");
        			printf("0 - Nome\n");
        			printf("1 - Tipo\n");
        			printf("2 - Evolucoes\n");
        			printf("3 - Fraquezas\n");
        			printf("4 - Nada\n");
        			int opcao_excluir;
        			scanf("%d", &opcao_excluir);
        			switch (opcao_excluir) {
            			case 0:
                			strcpy(pokemon.nome, "");
                			break;
            			case 1:
                			strcpy(pokemon.tipo, "");
                			break;
            			case 2:
                			strcpy(pokemon.evolucoes, "");
                			break;
            			case 3:
                			strcpy(pokemon.fraquezas, "");
                			break;
            			case 4:
                			break;
            			default:
                			printf("Opcao invalida!\n");
                			break;
        			}    			
				default:
    				printf("Opcao invalida!\n");
   					break;
				}

				if (salvar) {
    				FILE *arquivo = fopen(caminho_arquivo, "wb");
   					 if (arquivo == NULL) {
       				 printf("Erro ao criar arquivo!\n");
       				 exit(1);
    				}
    				fwrite(&pokemon, sizeof(Pokemon), 1, arquivo);
    				fclose(arquivo);
				} else {
    				printf("Dados nao foram salvos!\n");
				}
			}
		}		
    return 0;
}


