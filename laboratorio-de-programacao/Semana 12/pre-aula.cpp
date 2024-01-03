#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char rua[50];
    int numero;
    char complemento[50];
    char bairro[50];
    char cidade[50];
    char estado[3];
} EndCliente;

typedef struct {
    char itemComprado[50];
    char dataCompra[11];
    int qtdeItens;
    float valorUnitario;
    float totalCompra;
} CompCliente;

typedef struct {
    int idCliente;
    char nomeCliente[50];
    EndCliente endereco;
    char telCliente[15];
    char emailCliente[50];
    CompCliente compra;
} Cliente;

void preencherCliente(Cliente* cliente);
void mostrarCliente(const Cliente* cliente);

int main() {
	setlocale(LC_ALL,"Portuguese");
    Cliente cliente;

    printf("Preenchendo os dados do cliente:\n");
    preencherCliente(&cliente);

    printf("\nMostrando os dados do cliente:\n");
    mostrarCliente(&cliente);

    return 0;
}

void preencherCliente(Cliente* cliente) {
    printf("Id do cliente: ");
    scanf("%d", &cliente->idCliente);

    printf("Nome do cliente: ");
    scanf(" %[^\n]", cliente->nomeCliente);

    printf("Rua: ");
    scanf(" %[^\n]", cliente->endereco.rua);

    printf("Número: ");
    scanf("%d", &cliente->endereco.numero);

    printf("Complemento: ");
    scanf(" %[^\n]", cliente->endereco.complemento);

    printf("Bairro: ");
    scanf(" %[^\n]", cliente->endereco.bairro);

    printf("Cidade: ");
    scanf(" %[^\n]", cliente->endereco.cidade);

    printf("Estado: ");
    scanf(" %[^\n]", cliente->endereco.estado);

    printf("Telefone: ");
    scanf(" %[^\n]", cliente->telCliente);

    printf("E-mail: ");
    scanf(" %[^\n]", cliente->emailCliente);

    printf("Item comprado: ");
    scanf(" %[^\n]", cliente->compra.itemComprado);

    printf("Data da compra: ");
    scanf(" %[^\n]", cliente->compra.dataCompra);

    printf("Quantidade de itens: ");
    scanf("%d", &cliente->compra.qtdeItens);

    printf("Valor unitário: ");
    scanf("%f", &cliente->compra.valorUnitario);

    printf("Total da compra: ");
    scanf("%f", &cliente->compra.totalCompra);
}

void mostrarCliente(const Cliente* cliente) {
    printf("Id: %d\n", cliente->idCliente);
    printf("Nome: %s\n", cliente->nomeCliente);
    printf("Endereço: %s, %d, %s, %s, %s, %s\n", cliente->endereco.rua, cliente->endereco.numero, cliente->endereco.complemento, cliente->endereco.bairro, cliente->endereco.cidade, cliente->endereco.estado);
    printf("Telefone: %s\n", cliente->telCliente);
    printf("E-mail: %s\n", cliente->emailCliente);
    printf("Item comprado: %s\n", cliente->compra.itemComprado);
    printf("Data da compra: %s\n", cliente->compra.dataCompra);
    printf("Quantidade de itens: %d\n", cliente->compra.qtdeItens);
    printf("Valor unitário: %.2f\n", cliente->compra.valorUnitario);
    printf("Total da compra: %.2f\n", cliente->compra.totalCompra);
}

