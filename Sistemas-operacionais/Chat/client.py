import socket #importacao da biblioteca de conexao

def cliente():
    #cria um socket TCP/IP
    cliente_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    #define o endereco IP do servidor
    endereco_servidor = ('10.24.0.137', 5000)

    try:
        #estabelece uma conexao com o servidor
        cliente_socket.connect(endereco_servidor)

        while True:
            #solicita a mensagem do usuario
            mensagem = input("Digite uma mensagem (exit para sair): ")

            if mensagem == 'exit':
                break

            # Envia a mensagem para o servidor
            cliente_socket.send(mensagem.encode())

    finally:
        #fecha a conexao com o servidor
        cliente_socket.close()

cliente()