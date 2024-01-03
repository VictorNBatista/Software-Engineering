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

class Usuario:
    def __init__(self, id, nome):
        self._nome = nome
        self.id    = id

    @property
    def nome(self):
        return self._nome



class Professor(Usuario):
    def __init__(self, id, nome, biografia, formacoes, contato, custo_hora_aula, disciplina_id):
        super().__init__(id, nome)
        self.biografia       = biografia
        self.formacoes       = formacoes
        self.contato         = contato
        self.custo_hora_aula = custo_hora_aula
        self.displina_id     = disciplina_id


    @property
    def disciplina_id(self):
        return self.displina_id

    @property
    def custo_hora_aula(self):
        return self.custo_hora_aula

    def __str__(self):
        return f"Nome: {self.nome}, Matéria de Ensino: {self.disciplina_id}, Preço por Hora: R${self.custo_hora_aula:.2f}"



class Aluno(Usuario):
    def __init__(self, id, nome, forma_de_pagamento, contato):
        super().__init__(id, nome)
        self.forma_de_pagamento = forma_de_pagamento
        self.contato            = contato    

    def buscar_professores(self, materia_ensino, professores):
        professores_disponiveis = []
        for professor in professores:
            if professor.materia_ensino == materia_ensino:
                professores_disponiveis.append(professor)
        return professores_disponiveis
    


class Disciplina:
    def __init__(self, id, nome):
        self.id   = id
        self.nome = nome

class Agendamento:
    def __init__(self, id, data, hora, aluno_id, professor_id, horas_totais):
        self.id           = id
        self.data         = data
        self.hora         = hora
        self.aluno_id     = aluno_id
        self.professor_id = professor_id
        self.horas_totais = horas_totais

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