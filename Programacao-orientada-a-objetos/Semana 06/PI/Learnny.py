"""
Projeto Integrador Estrutura de dados / POO
Grupo: Learnny (Antigo NatuVation)
Integrantes:
Victor Hugo  Nunes Batista
Gustavo Henrique Santos
Jhonata dos Santos Alves
Gabriel Marques de Freitas
Chrystopher Allan Campos
Guilherme Nunes Caldeira
Guilherme Ferreira Bertuoso
Felipe Brian Marques
"""

class Professor:
    def __init__(self, nome, materia_ensino, preco_por_hora):
        self.nome = nome
        self.materia_ensino = materia_ensino
        self.preco_por_hora = preco_por_hora

    def __str__(self):
        return f"Nome: {self.nome}, Matéria de Ensino: {self.materia_ensino}, Preço por Hora: R${self.preco_por_hora:.2f}"


class Aluno:
    def __init__(self, nome):
        self.nome = nome

    def buscar_professores(self, materia_ensino, professores):
        professores_disponiveis = []
        for professor in professores:
            if professor.materia_ensino == materia_ensino:
                professores_disponiveis.append(professor)
        return professores_disponiveis


# Lista de professores
professores = [
    Professor("João", "Matemática", 50.0),
    Professor("Maria", "Inglês", 40.0),
    Professor("Pedro", "Física", 60.0),
]

# Menu principal
while True:
    print("\nMenu:")
    print("1. Sou professor (Cadastrar-se)")
    print("2. Sou aluno (Buscar professores por matéria)")
    print("3. Sair do programa")

    escolha = input("Escolha uma opção: ")

    if escolha == "1":
        nome = input("Digite seu nome: ")
        materia_ensino = input("Digite a matéria de ensino que você pode ensinar: ")
        preco_por_hora = float(input("Digite o preço por hora das aulas: "))
        novo_professor = Professor(nome, materia_ensino, preco_por_hora)
        professores.append(novo_professor)
        print("Professor cadastrado com sucesso!")

    elif escolha == "2":
        nome_aluno = input("Digite seu nome: ")
        materia_busca = input("Digite a matéria que você deseja aprender: ")
        aluno = Aluno(nome_aluno)
        professores_disponiveis = aluno.buscar_professores(materia_busca, professores)
        if not professores_disponiveis:
            print("Nenhum professor disponível para a matéria especificada.")
        else:
            print(f"\nProfessores disponíveis para a matéria {materia_busca}:")
            print("-------------------------------------------------------------")
            print("{:<5} {:<20} {:<20}".format("Nº", "Nome", "Preço por Hora"))
            print("-------------------------------------------------------------")
            for idx, professor in enumerate(professores_disponiveis, start=1):
                print("{:<5} {:<20} R${:<20.2f}".format(idx, professor.nome, professor.preco_por_hora))

    elif escolha == "3":
        print("Saindo do programa.")
        break

    else:
        print("Opção inválida. Tente novamente.")
