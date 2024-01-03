# Classe base para todos os métodos de pagamento
class MetodoPagamento:
    def processar_pagamento(self):
        print("Método de pagamento não especificado")

# Classe para pagamento com cartão de crédito
class PagamentoCartaoCredito(MetodoPagamento):
    def processar_pagamento(self):
        print("Pagamento com cartão de crédito processado com sucesso")

# Classe para pagamento com PayPal
class PagamentoPayPal(MetodoPagamento):
    def processar_pagamento(self):
        print("Pagamento com PayPal processado com sucesso")

# Classe para pagamento com boleto
class PagamentoBoleto(MetodoPagamento):
    def processar_pagamento(self):
        print("Pagamento com boleto processado com sucesso")

# Exemplo de uso
metodo1 = PagamentoCartaoCredito()
metodo2 = PagamentoPayPal()
metodo3 = PagamentoBoleto()

metodo1.processar_pagamento()  # Saída: Pagamento com cartão de crédito processado com sucesso
metodo2.processar_pagamento()  # Saída: Pagamento com PayPal processado com sucesso
metodo3.processar_pagamento()  # Saída: Pagamento com boleto processado com sucesso
