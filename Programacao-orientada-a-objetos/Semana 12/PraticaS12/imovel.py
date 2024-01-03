class Imovel:
    def __init__(self, endereco, preco):
        self.endereco = endereco
        self.preco = preco

class Novo(Imovel):
    def __init__(self, endereco, preco, adicional):
        super().__init__(endereco, preco)
        self.adicional = adicional

    def get_preco_final(self):
        return self.preco + self.adicional

class Velho(Imovel):
    def __init__(self, endereco, preco, desconto):
        super().__init__(endereco, preco)
        self.desconto = desconto
    
    def get_preco_final(self):
        return self.preco - self.desconto


def main():
    while True:
        opcao = int(input("Digite 1 para Imóvel Novo e 2 para Imóvel Velho: "))
        endereco = input("Digite o endereço do imóvel: ")
        preco = float(input("Digite o preço do imóvel: "))

        if opcao == 1:
            adicional = float(input("Digite o valor adicional do imóvel novo: "))
            imovel = Novo(endereco, preco, adicional)
        elif opcao == 2:
            desconto = float(input("Digite o valor do desconto do imóvel velho: "))
            imovel = Velho(endereco, preco, desconto)

        print(f"Endereço: {imovel.endereco}")
        print(f"Valor final: {imovel.get_preco_final()}")

        continuar = input("Deseja adicionar outro imóvel? (s/n): ")
        if continuar.lower() != 's':
            break

if __name__ == "__main__":
    main()