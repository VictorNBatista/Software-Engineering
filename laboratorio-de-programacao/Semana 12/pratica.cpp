#include <stdio.h>
#include <locale.h>
#define PRODUTOS 2
#define ARMAZENS 3

void receberPrecos(float precos[PRODUTOS]);
void receberEstoque(int estoque[ARMAZENS][PRODUTOS]);
void calcularEstoqueArmazem(const int estoque[ARMAZENS][PRODUTOS], int armazem);
int calcularEstoqueTotal(const int estoque[ARMAZENS][PRODUTOS]);
void calcularPrecoMaximo(const float precos[PRODUTOS], const int estoque[ARMAZENS][PRODUTOS]);
int calcularMenorEstoque(const int estoque[ARMAZENS][PRODUTOS]);
void calcularCustoArmazem(const float precos[PRODUTOS], const int estoque[ARMAZENS][PRODUTOS]);

int main() {
	setlocale(LC_ALL,"Portuguese");
    float precos[PRODUTOS];
    int estoque[ARMAZENS][PRODUTOS];

    printf("Recebendo os pre�os dos produtos:\n");
    receberPrecos(precos);

    printf("\nRecebendo o estoque dos produtos em cada armaz�m:\n");
    receberEstoque(estoque);

    printf("\nQuantidade de produtos estocados em cada armaz�m:\n");
    for (int i = 0; i < ARMAZENS; i++) {
        printf("Armaz�m %d: ", i + 1);
        calcularEstoqueArmazem(estoque, i);
    }

    printf("\nQuantidade de cada produto estocado em todos os armaz�ns:\n");
    calcularEstoqueTotal(estoque);

    printf("\nPre�o do produto com maior estoque em um �nico armaz�m:\n");
    calcularPrecoMaximo(precos, estoque);

    printf("\nMenor estoque armazenado: %d\n", calcularMenorEstoque(estoque));

    printf("\nCusto de cada armaz�m:\n");
    calcularCustoArmazem(precos, estoque);

    return 0;
}

void receberPrecos(float precos[PRODUTOS]) {
    for (int i = 0; i < PRODUTOS; i++) {
        printf("Digite o pre�o do produto %d: ", i + 1);
        scanf("%f", &precos[i]);
    }
}

void receberEstoque(int estoque[ARMAZENS][PRODUTOS]) {
    for (int i = 0; i < ARMAZENS; i++) {
        printf("Armaz�m %d:\n", i + 1);
        for (int j = 0; j < PRODUTOS; j++) {
            printf("Digite o estoque do produto %d: ", j + 1);
            scanf("%d", &estoque[i][j]);
        }
    }
}

void calcularEstoqueArmazem(const int estoque[ARMAZENS][PRODUTOS], int armazem) {
    int total = 0;
    for (int i = 0; i < PRODUTOS; i++) {
        total += estoque[armazem][i];
    }
    printf("%d produtos\n", total);
}

int calcularEstoqueTotal(const int estoque[ARMAZENS][PRODUTOS]) {
    int total = 0;
    for (int i = 0; i < PRODUTOS; i++) {
        int quantidade = 0;
        for (int j = 0; j < ARMAZENS; j++) {
            quantidade += estoque[j][i];
        }
        printf("Produto %d: %d unidades\n", i + 1, quantidade);
        total += quantidade;
    }
    return total;
}

void calcularPrecoMaximo(const float precos[PRODUTOS], const int estoque[ARMAZENS][PRODUTOS]) {
    float maxPreco = precos[0];
    int maxEstoque = 0;
    for (int i = 1; i < PRODUTOS; i++) {
        for (int j = 0; j < ARMAZENS; j++) {
            if (estoque[j][i] > estoque[maxEstoque][i]) {
                maxPreco = precos[i];
                maxEstoque = j;
            }
        }
    }
    printf("Produto com maior estoque em um �nico armaz�m:\n");
    printf("Produto: %.2f\nArmaz�m: %d\nEstoque: %d\n", maxPreco, maxEstoque + 1, estoque[maxEstoque]);
}

int calcularMenorEstoque(const int estoque[ARMAZENS][PRODUTOS]) {
    int menor = estoque[0][0];
    for (int i = 0; i < ARMAZENS; i++) {
        for (int j = 0; j < PRODUTOS; j++) {
            if (estoque[i][j] < menor) {
                menor = estoque[i][j];
            }
        }
    }
    return menor;
}

void calcularCustoArmazem(const float precos[PRODUTOS], const int estoque[ARMAZENS][PRODUTOS]) {
    for (int i = 0; i < ARMAZENS; i++) {
        float custo = 0;
        for (int j = 0; j < PRODUTOS; j++) {
            custo += precos[j] * estoque[i][j];
        }
        printf("Armaz�m %d: R$%.2f\n", i + 1, custo);
    }
}

