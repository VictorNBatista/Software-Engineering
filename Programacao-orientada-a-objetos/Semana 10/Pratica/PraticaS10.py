class Conta:
    def __init__(self, numero, titular, saldo):
        self.numero = numero
        self.titular = titular
        self.saldo = saldo

    def deposita(self, valor):
        self.saldo += valor

    def saca(self, valor):
        if self.saldo >= valor:
            self.saldo -= valor
            return True
        else:
            print("Saldo insuficiente.")
            return False

    def atualiza(self, taxa):
        self.saldo += self.saldo * taxa


class ContaCorrente(Conta):
    def __init__(self, numero, titular, saldo, limite=1000):
        super().__init__(numero, titular, saldo)
        self.limite = limite


class ContaPoupanca(Conta):
    def atualiza(self, taxa):
        self.saldo += self.saldo * taxa * 3


class Banco:
    def __init__(self):
        self.contas = []

    def adiciona(self, conta):
        self.contas.append(conta)

    def pega_conta(self, posicao):
        return self.contas[posicao]

    def pega_total_de_contas(self):
        return len(self.contas)


class AtualizadorDeContas:
    def __init__(self, taxa):
        self.taxa = taxa

    def roda(self, banco):
        for conta in banco.contas:
            conta.atualiza(self.taxa)


# Teste do código
banco = Banco()

conta1 = ContaCorrente(1, "João", 1000)
conta2 = ContaPoupanca(2, "Maria", 500)

banco.adiciona(conta1)
banco.adiciona(conta2)

atualizador = AtualizadorDeContas(0.01)
atualizador.roda(banco)

for i in range(banco.pega_total_de_contas()):
    conta = banco.pega_conta(i)
    print(f"Conta {conta.numero}: Saldo atualizado - R${conta.saldo:.2f}")


'''
Respondendo as perguntas
1- Como poderíamos implementar o método atualiza() nas classes ContaCorrente e ContaPoupança poupando reescrita de código?
R: Para evitar a reescrita de código no método atualiza() das classes ContaCorrente e ContaPoupanca, pode-se usar o conceito de métodos abstratos. Em Python, é possível criar uma classe abstrata que define a estrutura dos métodos, mas não fornece implementações concretas. As subclasses então devem fornecer implementações concretas para esses métodos. Para criar uma classe abstrata em Python, pode-se usar o módulo abc (Abstract Base Classes).

2- E se criarmos uma classe que não é filha de Conta e tentar passar uma instância no método roda de AtualizadorDeContas ? Com o que aprendemos até aqui, como podemos evitar que erros aconteçam nestes casos?
R: Para evitar que uma instância de uma classe que não é filha de Conta seja passada para o método roda() de AtualizadorDeContas, você pode usar o conceito de duck typing e verificar se o objeto passado possui o método necessário (atualiza() neste caso) antes de chamá-lo. Em Python, isso é feito de forma nativa e não requer declarações formais de interface. 
'''