from abc import ABC, abstractmethod
import math

class Produto:
    def __init__(self, nome, preco):
        self.nome = nome
        self.preco = preco

    def __str__(self):
        return f"Nome: {self.nome}, Preço: {self.preco}"

class Livro(Produto):
    def __init__(self, nome, preco, autor):
        super().__init__(nome, preco)
        self.autor = autor

    def __str__(self):
        return super().__str__() + f", Autor: {self.autor}"

class CD(Produto):
    def __init__(self, nome, preco, num_faixas):
        super().__init__(nome, preco)
        self.num_faixas = num_faixas

    def __str__(self):
        return super().__str__() + f", Número de Faixas: {self.num_faixas}"

class DVD(Produto):
    def __init__(self, nome, preco, duracao):
        super().__init__(nome, preco)
        self.duracao = duracao

    def __str__(self):
        return super().__str__() + f", Duração: {self.duracao}"

def main():
    produtos = []
    
    for i in range(5):
        print(f"\nSelecione o tipo do produto {i+1} que deseja cadastrar:")
        print("1 - Livro")
        print("2 - CD")
        print("3 - DVD")
        
        tipo_produto = int(input("Digite o número correspondente ao tipo de produto: "))
        
        nome = input("Digite o nome do produto: ")
        preco = float(input("Digite o preço do produto: "))
        
        if tipo_produto == 1:
            autor = input("Digite o autor do livro: ")
            produto = Livro(nome, preco, autor)
        
        elif tipo_produto == 2:
            num_faixas = int(input("Digite o número de faixas do CD: "))
            produto = CD(nome, preco, num_faixas)
        
        elif tipo_produto == 3:
            duracao = input("Digite a duração do DVD (minutos): ")
            produto = DVD(nome, preco, duracao)
        
        produtos.append(produto)

    print("\nProdutos cadastrados:")
    
    for i, produto in enumerate(produtos):
        print(f"\nProduto {i+1}:")
        print(produto)

if __name__ == "__main__":
    main()