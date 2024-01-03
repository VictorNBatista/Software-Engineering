#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Incluindo a biblioteca locale.h

// Definição da estrutura para representar uma escola
struct Escola {
    char tipo_ensino[20];
    int alunos_semestre;
    struct Escola* proximo;
};

// Definição da estrutura para representar um município que contém uma escola
struct Municipio {
    char nome[50];
    struct Escola* escolas;
    struct FilaEscola* filaEscolas;             // Fila de escolas
    struct PilhaEscola* pilhaEscolasRemovidas;   // Pilha de escolas removidas
    struct Municipio* proximo;
};

struct FilaEscola {
    struct Escola escola;
    struct FilaEscola* proximo;
};

struct PilhaEscola {
    struct Escola escola;
    struct PilhaEscola* proximo;
};

// Protótipos das funções
void inserirEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[], int alunos_semestre);
void cadastrarEscolas(struct Municipio** listaMunicipios, char municipios[][50]);
void listarMunicipios(struct Municipio* listaMunicipios);
void removerEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[]);
void liberarMemoria(struct Municipio* listaMunicipios);
void inicializarMunicipios(struct Municipio** listaMunicipios);
void enfileirarEscola(struct Municipio* municipio, char tipo_ensino[], int alunos_semestre);
void desenfileirarEscola(struct Municipio* municipio);
void imprimirFilaEscolas(struct Municipio* municipio);
void liberarFilaEscolas(struct Municipio* municipio);
void pushEscolaRemovida(struct Municipio* municipio, struct Escola* escola);
void popEscolaRemovida(struct Municipio* municipio);
void imprimirPilhaEscolasRemovidas(struct Municipio* municipio);
void liberarPilhaEscolasRemovidas(struct Municipio* municipio);

int main() {
    setlocale(LC_ALL, "Portuguese"); // Configurando o idioma para Português
    struct Municipio* listaMunicipios = NULL;
    int numeroMunicipio;
    
    // Declaração da matriz de nomes de municípios
	char municipios[][50] = {
        "Alto Paraíso de Goiás",
        "Alvorada do Norte",
        "Buritinópolis",
        "Campos Belos",
        "Cavalcante",
        "Colinas do Sul",
        "Damianópolis",
        "Divinópolis de Goiás",
        "Flores de Goiás",
        "Guarani de Goiás",
        "Iaciara",
        "Mambaí",
        "Monte Alegre de Goiás",
        "Nova Roma",
        "Posse",
        "São Domingos",
        "São João D'Aliança",
        "Simolândia",
        "Sitio D'Abadia",
        "Teresina de Goiás"
    };
	
	inicializarMunicipios(&listaMunicipios); // Inicializa a lista de municípios

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Escola\n");
        printf("2. Listar Municípios\n");
        printf("3. Remover Escola\n");
        printf("4. Enfileirar Escola\n");
        printf("5. Desenfileirar Escola\n");
        printf("6. Imprimir Fila de Escolas\n");
        printf("7. Imprimir Pilha de Escolas Removidas\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarEscolas(&listaMunicipios, municipios);
                break;
            case 2:
                listarMunicipios(listaMunicipios);
                break;
            case 3:
                char tipoEnsinoRemover[20];
                printf("Digite o número do município desejado: ");
                scanf("%d", &numeroMunicipio);
                if (numeroMunicipio < 1 || numeroMunicipio > 20) {
                    printf("Número de município inválido. Tente novamente.\n");
                }
                char nomeMunicipioRemover[50];
                strcpy(nomeMunicipioRemover, municipios[numeroMunicipio - 1]); // Obtém o nome do município com base no número de índice

                printf("Digite o tipo de ensino da escola a ser removida: ");
                scanf(" %[^\n]s", tipoEnsinoRemover);
                removerEscola(&listaMunicipios, nomeMunicipioRemover, tipoEnsinoRemover);
                break;
            case 4:
                char tipoEnsinoEnfileirar[20];
                int alunosSemestreEnfileirar;
                printf("Digite o número do município desejado: ");
                scanf("%d", &numeroMunicipio);
                if (numeroMunicipio < 1 || numeroMunicipio > 20) {
                    printf("Número de município inválido. Tente novamente.\n");
                }
                printf("Digite o tipo de ensino da escola a ser enfileirada: ");
                scanf(" %[^\n]s", tipoEnsinoEnfileirar);
                printf("Digite a quantidade de alunos por semestre: ");
                scanf("%d", &alunosSemestreEnfileirar);
                enfileirarEscola(&listaMunicipios[numeroMunicipio - 1], tipoEnsinoEnfileirar, alunosSemestreEnfileirar);
                break;
            case 5:
                printf("Digite o número do município desejado: ");
                scanf("%d", &numeroMunicipio);
                if (numeroMunicipio < 1 || numeroMunicipio > 20) {
                    printf("Número de município inválido. Tente novamente.\n");
                }
                desenfileirarEscola(listaMunicipios + numeroMunicipio - 1);
                break;
            case 6:
                printf("Digite o número do município desejado: ");
                scanf("%d", &numeroMunicipio);
                if (numeroMunicipio < 1 || numeroMunicipio > 20) {
                    printf("Número de município inválido. Tente novamente.\n");
                }
                imprimirFilaEscolas(listaMunicipios + numeroMunicipio - 1);
                break;
            case 7:
                printf("Digite o número do município desejado: ");
                scanf("%d", &numeroMunicipio);
                if (numeroMunicipio < 1 || numeroMunicipio > 20) {
                    printf("Número de município inválido. Tente novamente.\n");
                }
                imprimirPilhaEscolasRemovidas(listaMunicipios + numeroMunicipio - 1);
                break;
            case 8:
                liberarMemoria(listaMunicipios);
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}

// Função para inicializar a lista de municípios com os nomes fornecidos
void inicializarMunicipios(struct Municipio** listaMunicipios) {
    char municipios[][50] = {
        "Alto Paraíso de Goiás",
        "Alvorada do Norte",
        "Buritinópolis",
        "Campos Belos",
        "Cavalcante",
        "Colinas do Sul",
        "Damianópolis",
        "Divinópolis de Goiás",
        "Flores de Goiás",
        "Guarani de Goiás",
        "Iaciara",
        "Mambaí",
        "Monte Alegre de Goiás",
        "Nova Roma",
        "Posse",
        "São Domingos",
        "São João D'Aliança",
        "Simolândia",
        "Sitio D'Abadia",
        "Teresina de Goiás"
    };

    for (int i = 0; i < 20; i++) {
        struct Municipio* novoMunicipio = (struct Municipio*)malloc(sizeof(struct Municipio));
        if (!novoMunicipio) {
            printf("Erro ao alocar memória para o município.\n");
            exit(1);
        }

        strcpy(novoMunicipio->nome, municipios[i]);
        novoMunicipio->escolas = NULL;
        novoMunicipio->filaEscolas = NULL;  // Inicializa a fila de escolas
        novoMunicipio->pilhaEscolasRemovidas = NULL;  // Inicializa a pilha de escolas removidas
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

// Função para inserir uma escola em um município
void inserirEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[], int alunos_semestre) {
    struct Escola* novaEscola = (struct Escola*)malloc(sizeof(struct Escola));
    if (!novaEscola) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(novaEscola->tipo_ensino, tipo_ensino);
    novaEscola->alunos_semestre = alunos_semestre;
    novaEscola->proximo = NULL;

    // Verifica se o município já existe na lista
    struct Municipio** atualMunicipio = listaMunicipios;
    while (*atualMunicipio != NULL && strcmp((*atualMunicipio)->nome, nomeMunicipio) != 0) {
        atualMunicipio = &(*atualMunicipio)->proximo;
    }

    if (*atualMunicipio == NULL) {
        // O município não foi encontrado, cria um novo
        struct Municipio* novoMunicipio = (struct Municipio*)malloc(sizeof(struct Municipio));
        if (!novoMunicipio) {
            printf("Erro ao alocar memória para o município.\n");
            exit(1);
        }

        strcpy(novoMunicipio->nome, nomeMunicipio);
        novoMunicipio->escolas = NULL;
        novoMunicipio->filaEscolas = NULL;  // Inicializa a fila de escolas
        novoMunicipio->pilhaEscolasRemovidas = NULL;  // Inicializa a pilha de escolas removidas
        novoMunicipio->proximo = NULL;
        *atualMunicipio = novoMunicipio;
    }

    // Insere a escola na lista de escolas do município
    struct Escola** atualEscola = &((*atualMunicipio)->escolas);
    while (*atualEscola != NULL) {
        atualEscola = &(*atualEscola)->proximo;
    }
    *atualEscola = novaEscola;

    // Enfileira a escola na fila de escolas do município
    enfileirarEscola(*atualMunicipio, tipo_ensino, alunos_semestre);

    printf("Escola inserida com sucesso em %s.\n", nomeMunicipio);
}

// Função para cadastrar uma escola inserindo informações fornecidas pelo usuário
void cadastrarEscolas(struct Municipio** listaMunicipios, char municipios[][50]) {
    int numeroMunicipio;
    char tipo_ensino[20];
    int alunos_semestre;

    printf("Escolha o número do município:\n"
           "1- Alto Paraíso de Goiás\n"
           "2- Alvorada do Norte\n"
           "3- Buritinópolis\n"
           "4- Campos Belos\n"
           "5- Cavalcante\n"
           "6- Colinas do Sul\n"
           "7- Damianópolis\n"
           "8- Divinópolis de Goiás\n"
           "9- Flores de Goiás\n"
           "10- Guarani de Goiás\n"
           "11- Iaciara\n"
           "12- Mambaí\n"
           "13- Monte Alegre de Goiás\n"
           "14- Nova Roma\n"
           "15- Posse\n"
           "16- São Domingos\n"
           "17- São João D'Aliança\n"
           "18- Simolândia\n"
           "19- Sitio D'Abadia\n"
           "20- Teresina de Goiás\n");

    printf("Digite o número do município desejado: ");
    scanf("%d", &numeroMunicipio);

    if (numeroMunicipio < 1 || numeroMunicipio > 20) {
        printf("Número de município inválido. Tente novamente.\n");
        return;
    }

    char nomeMunicipio[50];
    strcpy(nomeMunicipio, municipios[numeroMunicipio - 1]); // Obtém o nome do município com base no número de índice

    printf("Digite o tipo de ensino (Educação Infantil, Ensino Fundamental, Ensino Médio): ");
    scanf(" %[^\n]s", tipo_ensino);

    printf("Digite a quantidade de alunos por semestre: ");
    scanf("%d", &alunos_semestre);

    inserirEscola(listaMunicipios, nomeMunicipio, tipo_ensino, alunos_semestre);
    printf("Escola cadastrada com sucesso em %s.\n", nomeMunicipio);
}

// Função para listar os municípios e suas escolas
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

// Função para remover uma escola de um município
// Função para remover uma escola de um município
void removerEscola(struct Municipio** listaMunicipios, char nomeMunicipio[], char tipo_ensino[]) {
    struct Municipio* atualMunicipio = *listaMunicipios;

    while (atualMunicipio != NULL) {
        if (strcmp(atualMunicipio->nome, nomeMunicipio) == 0) {
            struct Escola* atualEscola = atualMunicipio->escolas;
            struct Escola* anteriorEscola = NULL;

            while (atualEscola != NULL) {
                if (strcmp(atualEscola->tipo_ensino, tipo_ensino) == 0) {
                    if (anteriorEscola == NULL) {
                        atualMunicipio->escolas = atualEscola->proximo; // Atualiza a cabeça da lista de escolas
                    } else {
                        anteriorEscola->proximo = atualEscola->proximo;
                    }

                    // Remove a escola da fila e a adiciona à pilha de escolas removidas
                    desenfileirarEscola(atualMunicipio);
                    pushEscolaRemovida(atualMunicipio, atualEscola);

                    free(atualEscola); // Libera a memória da escola removida
                    printf("Escola removida com sucesso.\n");
                    return;
                }

                anteriorEscola = atualEscola;
                atualEscola = atualEscola->proximo;
            }

            printf("Escola não encontrada no município.\n");
            return;
        }

        atualMunicipio = atualMunicipio->proximo;
    }

    printf("Município não encontrado.\n");
}

// Função para enfileirar uma escola em um município
void enfileirarEscola(struct Municipio* municipio, char tipo_ensino[], int alunos_semestre) {
    struct FilaEscola* novoNodo = (struct FilaEscola*)malloc(sizeof(struct FilaEscola));
    if (!novoNodo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    strcpy(novoNodo->escola.tipo_ensino, tipo_ensino);
    novoNodo->escola.alunos_semestre = alunos_semestre;
    novoNodo->proximo = NULL;

    // Adiciona o nó na fila
    if (municipio->filaEscolas == NULL) {
        municipio->filaEscolas = novoNodo;
    } else {
        struct FilaEscola* atual = municipio->filaEscolas;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoNodo;
    }
}

// Função para desenfileirar uma escola de um município
void desenfileirarEscola(struct Municipio* municipio) {
    if (municipio->filaEscolas != NULL) {
        struct FilaEscola* primeiroNodo = municipio->filaEscolas;
        municipio->filaEscolas = primeiroNodo->proximo;

        // Adiciona a escola à pilha de escolas removidas
        pushEscolaRemovida(municipio, &primeiroNodo->escola);

        free(primeiroNodo);
    } else {
        printf("Fila de escolas vazia em %s.\n", municipio->nome);
    }
}

// Função para imprimir a fila de escolas em um município
void imprimirFilaEscolas(struct Municipio* municipio) {
    printf("Fila de escolas em %s:\n", municipio->nome);
    struct FilaEscola* atual = municipio->filaEscolas;

    while (atual != NULL) {
        printf("Tipo de Ensino: %s, Alunos por Semestre: %d\n", atual->escola.tipo_ensino, atual->escola.alunos_semestre);
        atual = atual->proximo;
    }
}

// Função para liberar a memória da fila de escolas em um município
void liberarFilaEscolas(struct Municipio* municipio) {
    while (municipio->filaEscolas != NULL) {
        struct FilaEscola* primeiroNodo = municipio->filaEscolas;
        municipio->filaEscolas = primeiroNodo->proximo;
        free(primeiroNodo);
    }
}

// Função para empilhar uma escola removida de um município
void pushEscolaRemovida(struct Municipio* municipio, struct Escola* escola) {
    struct PilhaEscola* novoNodo = (struct PilhaEscola*)malloc(sizeof(struct PilhaEscola));
    if (!novoNodo) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    memcpy(&novoNodo->escola, escola, sizeof(struct Escola));
    novoNodo->proximo = municipio->pilhaEscolasRemovidas;
    municipio->pilhaEscolasRemovidas = novoNodo;
}

// Função para desempilhar uma escola removida de um município
void popEscolaRemovida(struct Municipio* municipio) {
    if (municipio->pilhaEscolasRemovidas != NULL) {
        struct PilhaEscola* primeiroNodo = municipio->pilhaEscolasRemovidas;
        municipio->pilhaEscolasRemovidas = primeiroNodo->proximo;

        printf("Escola recuperada: Tipo de Ensino: %s, Alunos por Semestre: %d\n",
               primeiroNodo->escola.tipo_ensino, primeiroNodo->escola.alunos_semestre);

        free(primeiroNodo);
    } else {
        printf("Pilha de escolas removidas vazia em %s.\n", municipio->nome);
    }
}

// Função para imprimir a pilha de escolas removidas de um município
void imprimirPilhaEscolasRemovidas(struct Municipio* municipio) {
    printf("Pilha de escolas removidas de %s:\n", municipio->nome);
    struct PilhaEscola* atual = municipio->pilhaEscolasRemovidas;

    while (atual != NULL) {
        printf("Tipo de Ensino: %s, Alunos por Semestre: %d\n", atual->escola.tipo_ensino, atual->escola.alunos_semestre);
        atual = atual->proximo;
    }
}

// Função para liberar a memória da pilha de escolas removidas de um município
void liberarPilhaEscolasRemovidas(struct Municipio* municipio) {
    while (municipio->pilhaEscolasRemovidas != NULL) {
        struct PilhaEscola* primeiroNodo = municipio->pilhaEscolasRemovidas;
        municipio->pilhaEscolasRemovidas = primeiroNodo->proximo;
        free(primeiroNodo);
    }
}

// Função para liberar a memória alocada para a lista de municípios e suas escolas
void liberarMemoria(struct Municipio* listaMunicipios) {
    while (listaMunicipios != NULL) {
        struct Escola* atualEscola = listaMunicipios->escolas;
        while (atualEscola != NULL) {
            struct Escola* proximaEscola = atualEscola->proximo;
            free(atualEscola);
            atualEscola = proximaEscola;
        }

        struct FilaEscola* atualFilaEscolas = listaMunicipios->filaEscolas;
        while (atualFilaEscolas != NULL) {
            struct FilaEscola* proximoNodo = atualFilaEscolas->proximo;
            free(atualFilaEscolas);
            atualFilaEscolas = proximoNodo;
        }

        struct PilhaEscola* atualPilhaEscolasRemovidas = listaMunicipios->pilhaEscolasRemovidas;
        while (atualPilhaEscolasRemovidas != NULL) {
            struct PilhaEscola* proximoNodo = atualPilhaEscolasRemovidas->proximo;
            free(atualPilhaEscolasRemovidas);
            atualPilhaEscolasRemovidas = proximoNodo;
        }

        struct Municipio* proximoMunicipio = listaMunicipios->proximo;
        free(listaMunicipios);
        listaMunicipios = proximoMunicipio;
    }
}


