#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Incluindo a biblioteca locale.h

// Defini��o da estrutura para representar uma escola
struct Escola {
    char tipo_ensino[20];
    int alunos_semestre;
    struct Escola* proximo;
};

// Defini��o da estrutura para representar um munic�pio que cont�m uma escola
struct Municipio {
    char nome[50];
    struct Escola* escolas;
    struct Municipio* proximo;
};

// Prot�tipos das fun��es
void inserirEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[], int alunos_semestre);
void cadastrarEscolas(struct Municipio** listaMunicipios, char municipios[][50]);
void listarMunicipios(struct Municipio* listaMunicipios);
void removerEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[]);
void liberarMemoria(struct Municipio* listaMunicipios);
void inicializarMunicipios(struct Municipio** listaMunicipios);

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configurando o idioma para Portugu�s
    struct Municipio* listaMunicipios = NULL;
    int numeroMunicipio;
    
    // Declara��o da matriz de nomes de munic�pios
	char municipios[][50] = {
        "Alto Para�so de Goi�s",
        "Alvorada do Norte",
        "Buritin�polis",
        "Campos Belos",
        "Cavalcante",
        "Colinas do Sul",
        "Damian�polis",
        "Divin�polis de Goi�s",
        "Flores de Goi�s",
        "Guarani de Goi�s",
        "Iaciara",
        "Mamba�",
        "Monte Alegre de Goi�s",
        "Nova Roma",
        "Posse",
        "S�o Domingos",
        "S�o Jo�o D'Alian�a",
        "Simol�ndia",
        "Sitio D'Abadia",
        "Teresina de Goi�s"
    };
	
	inicializarMunicipios(&listaMunicipios); // Inicializa a lista de munic�pios

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Escola\n");
        printf("2. Listar Munic�pios\n");
        printf("3. Remover Escola\n");
        printf("4. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEscolas(&listaMunicipios,municipios);
                break;
            case 2:
                listarMunicipios(listaMunicipios);
                break;
            case 3:
                char tipoEnsinoRemover[20];
				printf("Digite o n�mero do munic�pio desejado: ");
			    scanf("%d", &numeroMunicipio);
			    if (numeroMunicipio < 1 || numeroMunicipio > 20) {
					printf("N�mero de munic�pio inv�lido. Tente novamente.\n");
				}
	    		char nomeMunicipioRemover[50];
	    		strcpy(nomeMunicipioRemover, municipios[numeroMunicipio - 1]); // Obt�m o nome do munic�pio com base no n�mero de �ndice
	    		
	    		printf("Digite o tipo de ensino da escola a ser removida: ");
    			scanf(" %[^\n]s", tipoEnsinoRemover);
                removerEscola(&listaMunicipios, nomeMunicipioRemover, tipoEnsinoRemover);
                break;
            case 4:
                liberarMemoria(listaMunicipios);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}

// Fun��o para inicializar a lista de munic�pios com os nomes fornecidos
void inicializarMunicipios(struct Municipio** listaMunicipios) {
    char municipios[][50] = {
        "Alto Para�so de Goi�s",
        "Alvorada do Norte",
        "Buritin�polis",
        "Campos Belos",
        "Cavalcante",
        "Colinas do Sul",
        "Damian�polis",
        "Divin�polis de Goi�s",
        "Flores de Goi�s",
        "Guarani de Goi�s",
        "Iaciara",
        "Mamba�",
        "Monte Alegre de Goi�s",
        "Nova Roma",
        "Posse",
        "S�o Domingos",
        "S�o Jo�o D'Alian�a",
        "Simol�ndia",
        "Sitio D'Abadia",
        "Teresina de Goi�s"
    };

    for (int i = 0; i < 20; i++) {
        struct Municipio* novoMunicipio = (struct Municipio*)malloc(sizeof(struct Municipio));
        if (!novoMunicipio) {
            printf("Erro ao alocar mem�ria para o munic�pio.\n");
            exit(1);
        }

        strcpy(novoMunicipio->nome, municipios[i]);
        novoMunicipio->escolas = NULL;
        novoMunicipio->proximo = NULL;

        if (*listaMunicipios == NULL) {
            *listaMunicipios = novoMunicipio;
        } else {
            struct Municipio* atual = *listaMunicipios;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoMunicipio;
        }
    }
}

// Fun��o para inserir uma escola em um munic�pio
void inserirEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[], int alunos_semestre) {
    struct Escola* novaEscola = (struct Escola*)malloc(sizeof(struct Escola));
    if (!novaEscola) {
        printf("Erro ao alocar mem�ria.\n");
        exit(1);
    }

    strcpy(novaEscola->tipo_ensino, tipo_ensino);
    novaEscola->alunos_semestre = alunos_semestre;
    novaEscola->proximo = NULL;

    // Verifica se o munic�pio j� existe na lista
    struct Municipio** atualMunicipio = listaMunicipios;
    while (*atualMunicipio != NULL && strcmp((*atualMunicipio)->nome, nomeMunicipio) != 0) {
        atualMunicipio = &(*atualMunicipio)->proximo;
    }

    if (*atualMunicipio == NULL) {
        // O munic�pio n�o foi encontrado, cria um novo
        struct Municipio* novoMunicipio = (struct Municipio*)malloc(sizeof(struct Municipio));
        if (!novoMunicipio) {
            printf("Erro ao alocar mem�ria para o munic�pio.\n");
            exit(1);
        }

        strcpy(novoMunicipio->nome, nomeMunicipio);
        novoMunicipio->escolas = NULL;
        novoMunicipio->proximo = NULL;
        *atualMunicipio = novoMunicipio;
    }

    // Insere a escola na lista de escolas do munic�pio
    struct Escola** atualEscola = &((*atualMunicipio)->escolas);
    while (*atualEscola != NULL) {
        atualEscola = &(*atualEscola)->proximo;
    }
    *atualEscola = novaEscola;
}

// Fun��o para cadastrar uma escola inserindo informa��es fornecidas pelo usu�rio
void cadastrarEscolas(struct Municipio** listaMunicipios, char municipios[][50]) {
    int numeroMunicipio;
    char tipo_ensino[20];
    int alunos_semestre;

    printf("Escolha o n�mero do munic�pio:\n"
           "1- Alto Para�so de Goi�s\n"
           "2- Alvorada do Norte\n"
           "3- Buritin�polis\n"
           "4- Campos Belos\n"
           "5- Cavalcante\n"
           "6- Colinas do Sul\n"
           "7- Damian�polis\n"
           "8- Divin�polis de Goi�s\n"
           "9- Flores de Goi�s\n"
           "10- Guarani de Goi�s\n"
           "11- Iaciara\n"
           "12- Mamba�\n"
           "13- Monte Alegre de Goi�s\n"
           "14- Nova Roma\n"
           "15- Posse\n"
           "16- S�o Domingos\n"
           "17- S�o Jo�o D'Alian�a\n"
           "18- Simol�ndia\n"
           "19- Sitio D'Abadia\n"
           "20- Teresina de Goi�s\n");

    printf("Digite o n�mero do munic�pio desejado: ");
    scanf("%d", &numeroMunicipio);

    if (numeroMunicipio < 1 || numeroMunicipio > 20) {
        printf("N�mero de munic�pio inv�lido. Tente novamente.\n");
        return;
    }

    char nomeMunicipio[50];
    strcpy(nomeMunicipio, municipios[numeroMunicipio - 1]); // Obt�m o nome do munic�pio com base no n�mero de �ndice

    printf("Digite o tipo de ensino (Educa��o Infantil, Ensino Fundamental, Ensino M�dio): ");
    scanf(" %[^\n]s", tipo_ensino);

    printf("Digite a quantidade de alunos por semestre: ");
    scanf("%d", &alunos_semestre);

    inserirEscola(listaMunicipios, nomeMunicipio, tipo_ensino, alunos_semestre);
    printf("Escola cadastrada com sucesso em %s.\n", nomeMunicipio);
}

// Fun��o para listar os munic�pios e suas escolas
void listarMunicipios(struct Municipio* listaMunicipios) {
    struct Municipio* atualMunicipio = listaMunicipios;
    int numeroMunicipio = 1;

    while (atualMunicipio != NULL) {
        printf("\n%d. %s\n", numeroMunicipio, atualMunicipio->nome);

        struct Escola* atualEscola = atualMunicipio->escolas;
        int numeroEscola = 1;

        while (atualEscola != NULL) {
            printf("   %d.%d Tipo de Ensino: %s, Alunos por Semestre: %d\n", numeroMunicipio, numeroEscola, atualEscola->tipo_ensino, atualEscola->alunos_semestre);
            atualEscola = atualEscola->proximo;
            numeroEscola++;
        }

        atualMunicipio = atualMunicipio->proximo;
        numeroMunicipio++;
    }
}

// Fun��o para remover uma escola de um munic�pio
void removerEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[]) {
    struct Municipio* atualMunicipio = *listaMunicipios;
	
	while (atualMunicipio != NULL) {
        if (strcmp(atualMunicipio->nome, nomeMunicipio) == 0) {
            struct Escola* atualEscola = atualMunicipio->escolas;
            struct Escola* anteriorEscola = NULL;

            while (atualEscola != NULL) {
                if (strcmp(atualEscola->tipo_ensino, tipo_ensino) == 0) {
                    if (anteriorEscola == NULL) {
                        atualMunicipio->escolas = atualEscola->proximo; // Atualiza a cabe�a da lista de escolas
                    } else {
                        anteriorEscola->proximo = atualEscola->proximo;
                    }
                    free(atualEscola); // Libera a mem�ria da escola removida
                    printf("Escola removida com sucesso.\n");
                    return;
                }

                anteriorEscola = atualEscola;
                atualEscola = atualEscola->proximo;
            }

            printf("Escola n�o encontrada no munic�pio.\n");
            return;
        }

        atualMunicipio = atualMunicipio->proximo;
    }

    printf("Munic�pio n�o encontrado.\n");
}

// Fun��o para liberar a mem�ria alocada para a lista de munic�pios e suas escolas
void liberarMemoria(struct Municipio* listaMunicipios) {
    while (listaMunicipios != NULL) {
        struct Escola* atualEscola = listaMunicipios->escolas;
        while (atualEscola != NULL) {
            struct Escola* proximaEscola = atualEscola->proximo;
            free(atualEscola);
            atualEscola = proximaEscola;
        }

        struct Municipio* proximoMunicipio = listaMunicipios->proximo;
        free(listaMunicipios);
        listaMunicipios = proximoMunicipio;
    }
}

