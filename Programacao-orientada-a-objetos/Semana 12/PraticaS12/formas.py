from abc import ABC, abstractmethod
import math

class FormaGeometrica(ABC):
    @abstractmethod
    def calcular_perimetro(self):
        pass

    @abstractmethod
    def calcular_area(self):
        pass

class Quadrilatero(FormaGeometrica):
    def __init__(self, lado1, lado2, lado3, lado4):
        self.lado1 = lado1
        self.lado2 = lado2
        self.lado3 = lado3
        self.lado4 = lado4

    def calcular_perimetro(self):
        return self.lado1 + self.lado2 + self.lado3 + self.lado4

class Retangulo(Quadrilatero):
    def __init__(self, base, altura):
        super().__init__(base, altura, base, altura)
        self.base = base
        self.altura = altura

    def calcular_area(self):
        return self.base * self.altura

class Quadrado(Quadrilatero):
    def __init__(self, lado):
        super().__init__(lado, lado, lado, lado)
        self.lado = lado

    def calcular_area(self):
        return self.lado ** 2

class Circulo(FormaGeometrica):
    def __init__(self, raio):
        self.raio = raio

    def calcular_perimetro(self):
        return round(2 * 3.14 * self.raio, 2)

    def calcular_area(self):
        return round(3.14 * (self.raio ** 2), 2)

def main():
    formas = []
    n = int(input("Quantas formas você deseja criar? "))
    
    for i in range(n):
        tipo_forma = input("Qual tipo de forma desejada (quadrado, retângulo ou círculo)? ")
        
        if tipo_forma.lower() == 'quadrado':
            lado = float(input("Digite o tamanho do lado do quadrado: "))
            forma = Quadrado(lado)
        
        elif tipo_forma.lower() == 'retângulo':
            base = float(input("Digite o tamanho da base do retângulo: "))
            altura = float(input("Digite o tamanho da altura do retângulo: "))
            forma = Retangulo(base, altura)
        
        elif tipo_forma.lower() == 'círculo':
            raio = float(input("Digite o tamanho do raio do círculo: "))
            forma = Circulo(raio)
        
        formas.append(forma)

    for i, forma in enumerate(formas):
        print(f"\nForma {i+1}:")
        
        if isinstance(forma, Quadrado):
            print(f"Lado: {forma.lado}")
        
        elif isinstance(forma, Retangulo):
            print(f"Base: {forma.base}, Altura: {forma.altura}")
        
        elif isinstance(forma, Circulo):
            print(f"Raio: {forma.raio}")
        
        print(f"Perímetro: {forma.calcular_perimetro()}")
        print(f"Área: {forma.calcular_area()}")

if __name__ == "__main__":
    main()
