# -*- coding: utf-8 -*-
class Quadrado:
    def __init__(self, lado):
        self.lado = lado

    def mostrar_lado(self):
        return self.lado

    def mudar_lado(self,lado_novo):
        self.lado = lado_novo

    def calc_area(self):
        return self.lado**2

quadrado1 = Quadrado(4)

#Mostrando os valores retornado do Quadrado já definido pelo programa
print("Valor atual do lado do quadrado: ", quadrado1.mostrar_lado())
print("Valor da área do quadrado atual: ", quadrado1.calc_area())

#Recebendo o novo valor do lado do quadrado
novo = int(input("Digite o novo valor do lado do quadrado: "))

quadrado1   .mudar_lado(novo)
print("Valor atualizado do lado do quadrado: ", quadrado1.mostrar_lado())
print("Nova área obtida: ", quadrado1.calc_area())