from abc import ABC, abstractmethod
import random

class Veiculo(ABC):
    @abstractmethod
    def listarVerificacoes(self):
        pass

    @abstractmethod
    def ajustar(self):
        pass

    @abstractmethod
    def limpar(self):
        pass

    @abstractmethod
    def mudarOleo(self):
        pass

class Bicicleta(Veiculo):
    def listarVerificacoes(self):
        return "Verificando a bicicleta..."

    def ajustar(self):
        return "Ajustando a bicicleta..."

    def limpar(self):
        return "Limpando a bicicleta..."

    def mudarOleo(self):
        return "Bicicletas não precisam trocar o óleo."

class Automovel(Veiculo):
    def listarVerificacoes(self):
        return "Verificando o automóvel..."

    def ajustar(self):
        return "Ajustando o automóvel..."

    def limpar(self):
        return "Limpando o automóvel..."

    def mudarOleo(self):
        return "Trocando o óleo do automóvel..."

class Oficina:
    @staticmethod
    def proximo():
        if random.randint(0, 1) == 0:
            return Bicicleta()
        else:
            return Automovel()

    @staticmethod
    def manutencao(veiculo: Veiculo):
        print(veiculo.listarVerificacoes())
        print(veiculo.ajustar())
        print(veiculo.limpar())
        
        if isinstance(veiculo, Automovel):
            print(veiculo.mudarOleo())

def main():
    oficina = Oficina()
    
    for _ in range(5):  # Realiza manutenção em 5 veículos
        veiculo = oficina.proximo()
        
        print(f"\nRealizando manutenção em: {'Bicicleta' if isinstance(veiculo, Bicicleta) else 'Automóvel'}")
        
        oficina.manutencao(veiculo)

if __name__ == "__main__":
    main()