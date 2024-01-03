import math

class Ponto:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

class Linha:
    def __init__(self, ponto_a, ponto_b):
        self.ponto_a = ponto_a
        self.ponto_b = ponto_b
    
    def comprimento(self):
        dx = self.ponto_a.x - self.ponto_b.x
        dy = self.ponto_a.y - self.ponto_b.y
        dz = self.ponto_a.z - self.ponto_b.z
        return math.sqrt(dx**2 + dy**2 + dz**2)

class Triangulo:
    def __init__(self, ponto_a, ponto_b, ponto_c):
        self.ponto_a = ponto_a
        self.ponto_b = ponto_b
        self.ponto_c = ponto_c
    
    def comprimento_lados(self):
        lado_a = Linha(self.ponto_a, self.ponto_b).comprimento()
        lado_b = Linha(self.ponto_b, self.ponto_c).comprimento()
        lado_c = Linha(self.ponto_c, self.ponto_a).comprimento()
        return lado_a, lado_b, lado_c
    
    def area(self):
        lado_a, lado_b, lado_c = self.comprimento_lados()
        s = (lado_a + lado_b + lado_c) / 2
        return math.sqrt(s * (s - lado_a) * (s - lado_b) * (s - lado_c))

# Criando pontos
ponto_a = Ponto(0, 0, 0)
ponto_b = Ponto(3, 0, 0)
ponto_c = Ponto(0, 4, 0)

# Criando linha e triângulo
linha_ab = Linha(ponto_a, ponto_b)
triangulo_abc = Triangulo(ponto_a, ponto_b, ponto_c)

# Calculando e imprimindo resultados
print("Comprimento da Linha AB:", linha_ab.comprimento())
print("Comprimento dos lados do Triângulo ABC:", triangulo_abc.comprimento_lados())
print("Área do Triângulo ABC:", triangulo_abc.area())