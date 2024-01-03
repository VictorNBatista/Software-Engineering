class Produto:
  def __init__(self, codigo, nome, preco):
    self.codigo = codigo
    self.nome   = nome
    self.preco  = preco

  def __str__(self):
    return f"Código: {self.codigo}\nNome: {self.nome}\nPreço: {self.preco}"

class ItemPedido:
  def __init__(self, produto, quantidade):
    self.produto    = produto
    self.quantidade = quantidade

  def subtotal(self):
    return self.produto.preco * self.quantidade

  def __str__(self):
    return f"Produto: {self.produto.nome}\nQuantidade: {self.quantidade}\nSubtotal: R$ {self.subtotal(): .2f}"

class Pedido:
  def __init__(self, cliente):
    self.cliente = cliente
    self.itens = []

  def adicionar_item(self, item):
    self.itens.append(item)

  def calcular_total(self):
    total = 0
    for item in self.itens:
      total += item.subtotal()
    return total

  def __str__(self):
    info_cliente = f"Informações do Cliente: \n{self.cliente}"
    info_itens   = f"\n\nItens do Pedido:\n"
    for item in self.itens:
      info_itens += str(item) + "\n"
    total = self.calcular_total()
    return info_cliente + info_itens + f"\nTotal do Pedido: R${total: .2f}"

class Cliente:
  def __init__(self, nome, endereco, telefone):
    self.nome     = nome
    self.endereco = endereco
    self.telefone = telefone

  def __str__(self):
    return f"Nome: {self.nome}\nEndereco: {self.endereco}\nTelefone: {self.telefone}"


# Criando produtos
produto1 = Produto(1, "Hamburguer", 15.99)
produto2 = Produto(2, "Batata Frita", 5.99)
produto3 = Produto(3, "Refrigerante", 3.99)

# Criando itens de pedido
item1 = ItemPedido(produto1, 2)
item2 = ItemPedido(produto2, 3)
item3 = ItemPedido(produto3, 1)

# Criando CLiente
cliente = Cliente("João", "Rua A, 123", "(99) 1234-5678")

# Criando pedido
pedido = Pedido(cliente)
pedido.adicionar_item(item1)
pedido.adicionar_item(item2)
pedido.adicionar_item(item3)

# Exibindo informações do pedido
print(pedido)