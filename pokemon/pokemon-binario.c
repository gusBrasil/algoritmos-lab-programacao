#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[20];
    char tipo[10];
    char evolucao[20];
} Pokemon;

void ordenar(Pokemon p[], int n, int crescente) {
    int i, j;
    Pokemon aux;

    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(crescente) {
                if(strcmp(p[i].nome, p[j].nome) > 0) {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            } else {
                if(strcmp(p[i].nome, p[j].nome) < 0) {
                    aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;
                }
            }
        }
    }
}

int main() {
    int i, n, crescente, opcao;
    FILE *arquivo;
    Pokemon *p;

    printf("Digite a quantidade de pokemons: ");
    scanf("%d", &n);

    p = (Pokemon*) malloc(n * sizeof(Pokemon));

    for(i=0; i<n; i++) {
        printf("\nPokemon %d:\n", i+1);
        printf("Nome: ");
        scanf("%s", p[i].nome);
        printf("Tipo: ");
        scanf("%s", p[i].tipo);
        printf("Evolucao: ");
        scanf("%s", p[i].evolucao);
    }

    printf("\nDeseja editar algum pokemon? (1-Sim / 0-Nao): ");
    scanf("%d", &opcao);

    if(opcao) {
        int index;
        char field[20], new_value[20];

        printf("\nDigite o indice do pokemon que deseja editar (1-%d): ", n);
        scanf("%d", &index);

        printf("\nDigite o campo que deseja editar (nome, tipo ou evolucao): ");
        scanf("%s", field);

        printf("\nDigite o novo valor do campo: ");
        scanf("%s", new_value);

        if(strcmp(field, "nome") == 0) {
            strcpy(p[index-1].nome, new_value);
        } else if(strcmp(field, "tipo") == 0) {
            strcpy(p[index-1].tipo, new_value);
        } else if(strcmp(field, "evolucao") == 0) {
            strcpy(p[index-1].evolucao, new_value);
        } else {
            printf("Campo invalido!\n");
            exit(1);
        }
    }
    
    printf("\nDeseja deletar algum pokemon? (1-Sim / 0-Nao): ");
		scanf("%d", &opcao);

		if(opcao) {
    	int index;
    
    	printf("\nDigite o indice do pokemon que deseja deletar (1-%d): ", n);
    	scanf("%d", &index);
    
    	// Deleta a entrada do pokemon
    	for (i = index-1; i < n-1; i++) {
       		p[i] = p[i+1];
    	}
    
    	// Atualiza o número de pokemons
    	n--;
	}

    printf("\nDeseja ordenar em ordem crescente (1) ou decrescente (0)? ");
    scanf("%d", &crescente);

    ordenar(p, n, crescente);

    arquivo = fopen("pokemons.bin", "wb");

    if(arquivo == NULL) {
        printf("Erro ao criar o arquivo!");
        exit(1);
    }

    fwrite(&n, sizeof(int), 1, arquivo);

    for(i=0; i<n; i++) {
        fwrite(&p[i], sizeof(Pokemon), 1, arquivo);
    }

    fclose(arquivo);

    printf("\nPokemons salvos no arquivo pokemons.bin\n");

    return 0;
}

