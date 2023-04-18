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

void busca_linear(Pokemon p[], int n, char nome[]) {
    int i, encontrado = 0;
    char atributo[10];

    for(i=0; i<n; i++) {
        if(strcmp(p[i].nome, nome) == 0) {
            printf("\nPokemon encontrado!\n");
            printf("Digite o atributo que deseja ver (nome, tipo ou evolucao): ");
            scanf("%s", atributo);
            if(strcmp(atributo, "nome") == 0) {
                printf("Nome: %s\n", p[i].nome);
            } else if(strcmp(atributo, "tipo") == 0) {
                printf("Tipo: %s\n", p[i].tipo);
            } else if(strcmp(atributo, "evolucao") == 0) {
                printf("Evolucao: %s\n", p[i].evolucao);
            } else {
                printf("Atributo invalido!\n");
                break;
            }
            encontrado = 1;
            break;
        }
    }

    if(!encontrado) {
        printf("\nPokemon nao encontrado!\n");
    }
}

int buscaBinaria(Pokemon p[], int n, char nome[]) {
    int inicio = 0;
    int fim = n - 1;
    while(inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if(strcmp(p[meio].nome, nome) == 0) {
            return meio;
        } else if(strcmp(p[meio].nome, nome) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
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
        
            // Atualiza o n�mero de pokemons
            n--;
        }

        printf("\nDeseja ordenar em ordem crescente (1) ou decrescente (0)? ");
        scanf("%d", &crescente);

        ordenar(p, n, crescente);

        char nome[20];
        printf("\nDigite o nome do pokemon que deseja buscar: ");
        scanf("%s", nome);

        // Busca linear
        busca_linear(p, n, nome);

        // Busca binária
        int index = buscaBinaria(p, n, nome);
        if(index != -1) {
            printf("\nPokemon encontrado!\n");
            printf("Nome: %s\n", p[index].nome);
            printf("Tipo: %s\n", p[index].tipo);
            printf("Evolucao: %s\n", p[index].evolucao);
        } else {
            printf("\nPokemon nao encontrado!\n");
        }

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

