class Vetor:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    
    def __str__(self):
        return f"({self.x}, {self.y}, {self.z})"
    
    def __add__(self, outro):
        return Vetor(self.x + outro.x, self.y + outro.y, self.z + outro.z)
    
    def __sub__(self, outro):
        return Vetor(self.x - outro.x, self.y - outro.y, self.z - outro.z)
    
    def produto_escalar(self, outro):
        return self.x * outro.x + self.y * outro.y + self.z * outro.z
    
    def produto_vetorial(self, outro):
        novo_x = self.y * outro.z - self.z * outro.y
        novo_y = self.z * outro.x - self.x * outro.z
        novo_z = self.x * outro.y - self.y * outro.x
        return Vetor(novo_x, novo_y, novo_z)
    
    def modulo(self):
        return (self.x * 2 + self.y * 2 + self.z * 2) * 0.5

vetor1 = Vetor(1, 2, 3)
vetor2 = Vetor(4, 5, 6)

soma = vetor1 + vetor2
subtracao = vetor1 - vetor2
produto_escalar = vetor1.produto_escalar(vetor2)
produto_vetorial = vetor1.produto_vetorial(vetor2)
modulo_vetor1 = vetor1.modulo()
modulo_vetor2 = vetor2.modulo()

print("Vetor 1:", vetor1)
print("Vetor 2:", vetor2)
print("Soma:", soma)
print("Subtração:", subtracao)
print("Produto Escalar:", produto_escalar)
print("Produto Vetorial:", produto_vetorial)
print("Módulo Vetor 1:", modulo_vetor1)
print("Módulo Vetor 2:", modulo_vetor2)