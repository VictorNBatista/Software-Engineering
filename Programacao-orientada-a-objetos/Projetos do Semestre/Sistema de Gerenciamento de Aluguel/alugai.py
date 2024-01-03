class Casa:
  def __init__(self, nome, codigo, endereco, quarto, preco):
    self.nome       = nome
    self.codigo     = codigo
    self.endereco   = endereco
    self.quarto     = quarto
    self.preco      = preco

  def __str__(self):
    return f"Nome: {self.nome}\nCódigo: {self.codigo}\nEndereço: {self.endereco}\nQuartos: {self.quarto}\nPreço: {self.preco}"

class CasaAluguel:
  def __init__(self, casa, dia):
    self.casa = casa
    self.dia  = dia

  def subtotal(self):
    return self.casa.preco * self.dia

  def __str__(self):
    return f"Casa: {self.casa.nome}\nDias de estadia: {self.dia}\nSubtotal: R$ {self.subtotal(): .2f}"

class ContratoAluguel:
  def __init__(self, cliente):
    self.cliente = cliente
    self.alugueis = []

  def adicionar_aluguel(self, aluguel):
    self.alugueis.append(aluguel)

  def calcular_total(self):
    total = 0
    for aluguel in self.alugueis:
      total += aluguel.subtotal()
    return total

  def __str__(self):
    info_cliente = f"Informações do Cliente: \n{self.cliente}"
    info_alugueis   = f"\n\nAlugueis ativos: \n"
    for aluguel in self.alugueis:
      info_alugueis += str(aluguel) + "\n"
    total = self.calcular_total()
    return info_cliente + info_alugueis + f"\nTotal do Pedido: R${total: .2f}"

class Cliente:
  def __init__(self, nome, endereco, telefone):
    self.nome     = nome
    self.endereco = endereco
    self.telefone = telefone

  def __str__(self):
    return f"Nome: {self.nome}\nEndereco: {self.endereco}\nTelefone: {self.telefone}"


# Criando produtos
casa1 = Casa("Casa de campo", 130, "Rua B, 234", 4, 100.00)
casa2 = Casa("Casa de praia", 982, "Rua D, 567", 3, 230.00)
casa3 = Casa("Casa centro", 45, "Rua H, 934", 2, 80.00)

# Criando itens do aluguel
item1 = CasaAluguel(casa1, 3)
item2 = CasaAluguel(casa2, 2)
item3 = CasaAluguel(casa3, 5)

# Criando CLiente
cliente = Cliente("José", "Rua A, 123", "(99) 1234-5678")

# Criando aluguel
pedido = ContratoAluguel(cliente)
pedido.adicionar_aluguel(item1)
pedido.adicionar_aluguel(item2)
pedido.adicionar_aluguel(item3)

# Exibindo informações do pedido
print(pedido)