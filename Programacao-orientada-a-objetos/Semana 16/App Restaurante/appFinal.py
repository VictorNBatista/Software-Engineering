import PySimpleGUI as sg

class Produto:
  def __init__(self, codigo, nome, preco):
    self.codigo = codigo
    self.nome   = nome
    self.preco  = preco

  def __str__(self):
    return f"{self.nome} - {self.preco} - "
  
class Bebida(Produto):
  def __init__(self, codigo, nome, preco, tipo, tamanho):
    super().__init__(codigo, nome, preco)
    self.tipo = tipo
    self.tamanho = tamanho
    
  def __str__(self):
    return f"{super().__str__()} Tipo: {self.tipo} Tamanho: {self.tamanho}"  
    
class Comida(Produto):
  def __init__(self, codigo, nome, preco, tipo):
    super().__init__(codigo, nome, preco)
    self.tipo = tipo
  
  def __str__(self):
    return f"{super().__str__()} Tipo: {self.tipo}" 

class ItemPedido:
  def __init__(self, produto, quantidade):
    self.produto    = produto
    self.quantidade = quantidade

  def subtotal(self):
    return self.produto.preco * self.quantidade

  def __str__(self):
    return f"Produto: {self.produto.nome} Quantidade: {self.quantidade} - Subtotal: R$ {self.subtotal(): .2f}"

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
produto1 = Comida(1, "Hamburguer", 15.99, "Principal")
produto2 = Comida(2, "Batata Frita", 5.99, "Entrada")
produto3 = Bebida(3, "Guaraná Antártica", 3.99, "Refrigerante", "Lata 350ml")
produto4 = Bebida(4, "Coca-Cola", 3.99, "Refrigerante", "Lata 350ml")


# Lista para armazenar os clientes
clientes = []

# Lista para armazenar os produtos do cardápio
cardapio = [Comida(1, "Hamburguer", 15.99, "Principal"),
            Comida(2, "Batata Frita", 5.99, "Entrada"),
            Bebida(3, "Guaraná Antártica", 3.99, "Refrigerante", "Lata 350ml"),
            Bebida(4, "Coca-Cola", 3.99, "Refrigerante", "Lata 350ml")]

# Lista para armazenar os itens do pedido
itens_pedido = []

# Funções para criar as janelas
def create_welcome_window():
    layout = [[sg.Text("Bem-vindo ao Restaurante")],
              [sg.Button("Sou novo aqui"), sg.Button("Já sou cliente")]]
    return sg.Window('Bem-vindo', layout, finalize=True)

def create_new_client_window():
    layout = [[sg.Text('Nome:'), sg.Input(key='-CLIENTE-')],
              [sg.Text('Endereço:'), sg.Input(key='-ENDERECO-')],
              [sg.Text('Telefone:'), sg.Input(key='-TELEFONE-')],
              [sg.Button('Cadastrar Cliente')]]
    return sg.Window('Novo Cliente', layout, finalize=True)

def create_existing_client_window():
    layout = [[sg.Text('Digite seu nome:'), sg.Input(key='-NOME-')],
              [sg.Button('Entrar')]]
    return sg.Window('Cliente Existente', layout, finalize=True)

def create_order_window():
    layout = [[sg.Text('Realizar Pedido')],
              [sg.Button('Comida'), sg.Button('Bebida')],
              [sg.Listbox(values=[str(produto) for produto in cardapio], size=(60, 6), key='-CARDÁPIO-')],
              [sg.Text('Quantidade:'), sg.Input(key='-QUANTIDADE-')],
              [sg.Button('Adicionar ao Pedido')],
              [sg.Listbox(values=[str(item) for item in itens_pedido], size=(60, 6), key='-PEDIDO-')],
              [sg.Button('Finalizar Pedido')]]
    return sg.Window('Realizar Pedido', layout, finalize=True)

def create_checkout_window(total):
    layout = [[sg.Text(f'Total do Pedido: R${total: .2f}')],
              [sg.Button('Pagar')]]
    return sg.Window('Finalizar Pedido', layout, finalize=True)

# Cria a janela de boas-vindas
window = create_welcome_window()

while True:
    event, values = window.read()
    if event == sg.WINDOW_CLOSED:
        break
    if event == 'Sou novo aqui':
        window.hide()
        new_client_window = create_new_client_window()
        while True:
            event, values = new_client_window.read()
            if event == sg.WINDOW_CLOSED:
                break
            if event == 'Cadastrar Cliente':
                cliente = Cliente(values['-CLIENTE-'], values['-ENDERECO-'], values['-TELEFONE-'])
                clientes.append(cliente)
                sg.popup('Cliente cadastrado com sucesso!')
                new_client_window.close()
                order_window = create_order_window()
                window = order_window
    if event == 'Já sou cliente':
        window.hide()
        existing_client_window = create_existing_client_window()
        while True:
            event, values = existing_client_window.read()
            if event == sg.WINDOW_CLOSED:
                break
            if event == 'Entrar':
                nome = values['-NOME-']
                cliente = next((c for c in clientes if c.nome == nome), None)
                if cliente is not None:
                    sg.popup('Bem-vindo de volta,', cliente.nome + '!')
                    existing_client_window.close()
                    order_window = create_order_window()
                    window = order_window
                else:
                    sg.popup('Cliente não encontrado.')
        existing_client_window.close()
        window.un_hide()
    if event in ('Comida', 'Bebida'):
        produtos = [produto for produto in cardapio if isinstance(produto, globals()[event])]
        window['-CARDÁPIO-'].update([str(produto) for produto in produtos])
    if event == 'Adicionar ao Pedido':
        produto_selecionado = next(produto for produto in cardapio if str(produto) == values['-CARDÁPIO-'][0])
        quantidade = int(values['-QUANTIDADE-'])
        item = ItemPedido(produto_selecionado, quantidade)
        itens_pedido.append(item)
        window['-PEDIDO-'].update([str(item) for item in itens_pedido])
    if event == 'Finalizar Pedido':
        total = sum(item.subtotal() for item in itens_pedido)
        window.hide()
        checkout_window = create_checkout_window(total)
        while True:
            event, values = checkout_window.read()
            if event == sg.WINDOW_CLOSED or event == 'Pagar':
                break
        checkout_window.close() 

window.close()
