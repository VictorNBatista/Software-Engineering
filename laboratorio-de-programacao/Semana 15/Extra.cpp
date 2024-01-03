#include <stdio.h>
#include <locale.h>
#include <string.h>

#define MAX_CONTAS 15

struct ContaBancaria {
    int numeroConta;
    char nomeCliente[100];
    float saldo;
};

struct ContaBancaria contas[MAX_CONTAS];
int numContas = 0;

void cadastrarContas();
void visualizarContasCliente();
void excluirContaMenorSaldo();


main() {
	setlocale(LC_ALL,"Portuguese");
    int op;

    do {
        printf("\nMenu de opções:\n");
        printf("1. Cadastrar contas\n");
        printf("2. Visualizar todas as contas de determinado cliente\n");
        printf("3. Excluir a conta com menor saldo\n");
        printf("4. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                cadastrarContas();
                break;
            case 2:
                visualizarContasCliente();
                break;
            case 3:
                excluirContaMenorSaldo();
                break;
            case 4:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (op != 4);

}

void cadastrarContas() {
    if (numContas >= MAX_CONTAS) {
        printf("Limite de contas atingido.\n");
        return;
    }

    struct ContaBancaria novaConta;

    printf("Digite o número da conta: ");
    scanf("%d", &novaConta.numeroConta);

    for (int i = 0; i < numContas; i++) {
        if (contas[i].numeroConta == novaConta.numeroConta) {
            printf("Já existe uma conta com esse número.\n");
            return;
        }
    }

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]",&novaConta.nomeCliente);
    novaConta.nomeCliente[strcspn(novaConta.nomeCliente, "\n")] = '\0'; 

    printf("Digite o saldo: ");
    scanf("%f", &novaConta.saldo);

    contas[numContas] = novaConta;
    numContas++;

    printf("Conta cadastrada com sucesso!\n");
}

void visualizarContasCliente() {
    char nomeCliente[100];
    int encontrou = 0;

    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]",&nomeCliente);
    printf("\n");
    nomeCliente[strcspn(nomeCliente, "\n")] = '\0';

    printf("Contas do cliente %s:\n", nomeCliente);
    for (int i = 0; i < numContas; i++) {
        if (strcmp(contas[i].nomeCliente, nomeCliente) == 0) {
            encontrou = 1;
            printf("Número da conta: %d\n", contas[i].numeroConta);
            printf("Saldo: %.2f\n\n", contas[i].saldo);
        }
    }

    if (!encontrou) {
        printf("Nenhuma conta encontrada para o cliente %s.\n", nomeCliente);
    }
}

void excluirContaMenorSaldo() {
    if (numContas == 0) {
        printf("Não há contas cadastradas.\n");
        return;
    }

    int indiceMenorSaldo = 0;
    float menorSaldo = contas[0].saldo;

    for (int i = 1; i < numContas; i++) {
        if (contas[i].saldo < menorSaldo) {
            indiceMenorSaldo = i;
            menorSaldo = contas[i].saldo;
        }
    }

    printf("Conta com menor saldo removida:\n");
    printf("Número da conta: %d\n", contas[indiceMenorSaldo].numeroConta);
    printf("Nome do cliente: %s\n", contas[indiceMenorSaldo].nomeCliente);
    printf("Saldo: %.2f\n", contas[indiceMenorSaldo].saldo);

    for (int i = indiceMenorSaldo; i < numContas - 1; i++) {
        contas[i] = contas[i + 1];
    }

    numContas--;
}
