# -*- coding: utf-8 -*-
class Carro:
    def __init__(self, consumo):
        self.consumo = consumo  # consumo em km/litro
        self.combustivel = 30  # nível inicial de combustível em litros

    def mover(self, km):
        # Calcula a quantidade de combustível necessária para a distância   
        combustivel_necessario = km / self.consumo

        # Verifica se há combustível suficiente
        if combustivel_necessario <= self.combustivel:
            self.combustivel -= combustivel_necessario
            print(f"Carro percorreu {km} km.")
        else:
            print("Carro não tem combustível suficiente para percorrer a distância.")

    def gasolina(self):
        return self.combustivel

    def abastecer(self, litros):
        self.combustivel += litros
        print(f"Carro abastecido com {litros} litros de combustível. Novo nível: {self.combustivel} litros")

# Criando uma instância da classe Carro com consumo de 10 km/litro
meu_carro = Carro(10)

# Verificando o nível de combustível inicial
print("Nível de combustível inicial:", meu_carro.gasolina(), "litros")

# Movendo o carro
meu_carro.mover(50)

# Abastecendo o carro
meu_carro.abastecer(20)

# Movendo o carro novamente
meu_carro.mover(150)

# Verificando o nível de combustível após as operações
print("Nível de combustível atual:", meu_carro.gasolina(), "litros")