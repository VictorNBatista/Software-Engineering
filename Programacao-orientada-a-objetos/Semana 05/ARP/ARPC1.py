class Escola:
    def __init__(self, tipo_ensino, alunos_semestre):
        self.tipo_ensino = tipo_ensino
        self.alunos_semestre = alunos_semestre

    def __str__(self):
        return f"Tipo de Ensino: {self.tipo_ensino}, Alunos por Semestre: {self.alunos_semestre}"


class Municipio:
    def __init__(self, nome):
        self.nome = nome
        self.escolas = []

    def adicionar_escola(self, tipo_ensino, alunos_semestre):
        escola = Escola(tipo_ensino, alunos_semestre)
        self.escolas.append(escola)

    def remover_escola(self, tipo_ensino):
        for escola in self.escolas:
            if escola.tipo_ensino == tipo_ensino:
                self.escolas.remove(escola)
                return

    def listar_escolas(self):
        if not self.escolas:
            print("Nenhuma escola cadastrada neste município.")
        else:
            print(f"\nEscolas do município {self.nome}:")
            print("-------------------------------------------------------------")
            print("{:<5} {:<20} {:<20}".format("Nº", "Tipo de Ensino", "Alunos por Semestre"))
            print("-------------------------------------------------------------")
            for idx, escola in enumerate(self.escolas, start=1):
                print("{:<5} {:<20} {:<20}".format(idx, escola.tipo_ensino, escola.alunos_semestre))


    def __str__(self):
        return f"Município: {self.nome}\nEscolas:\n{', '.join(map(str, self.escolas))}"


# Criando objetos de Município com os nomes do Nordeste Goiano
municipios_nordeste_goiano = [
    "Alto Paraíso de Goiás", "Alvorada do Norte", "Buritinópolis", "Campos Belos", "Cavalcante",
    "Colinas do Sul", "Damianópolis", "Divinópolis de Goiás", "Flores de Goiás", "Guarani de Goiás",
    "Iaciara", "Mambaí", "Monte Alegre de Goiás", "Nova Roma", "Posse", "São Domingos",
    "São João D'Aliança", "Simolândia", "Sitio D'Abadia", "Teresina de Goiás"
]

municipios_objetos = [Municipio(nome) for nome in municipios_nordeste_goiano]

# Menu principal
while True:
    print("\nMenu:")
    print("1. Adicionar uma nova escola")
    print("2. Listar escolas de um município")
    print("3. Remover uma escola")
    print("4. Sair do programa")

    escolha = input("Escolha uma opção: ")

    if escolha == "1":
        print("Lista de Municípios no Nordeste Goiano:")
        for idx, municipio in enumerate(municipios_objetos, start=1):
            print(f"{idx}. {municipio.nome}")
        numero_municipio = int(input("Digite o número do município (1 a 20): "))
        if 1 <= numero_municipio <= 20:
            municipio_selecionado = municipios_objetos[numero_municipio - 1]
            tipo_ensino = input("Digite o tipo de ensino: ")
            alunos_semestre = int(input("Digite o número de alunos por semestre: "))
            municipio_selecionado.adicionar_escola(tipo_ensino, alunos_semestre)
            print("Escola adicionada com sucesso ao município:", municipio_selecionado.nome)
        else:
            print("Número de município inválido.")

    elif escolha == "2":
        numero_municipio = int(input("Digite o número do município (1 a 20): "))
        if 1 <= numero_municipio <= 20:
            municipio_selecionado = municipios_objetos[numero_municipio - 1]
            municipio_selecionado.listar_escolas()
        else:
            print("Número de município inválido.")

    elif escolha == "3":
        numero_municipio = int(input("Digite o número do município (1 a 20): "))
        if 1 <= numero_municipio <= 20:
            municipio_selecionado = municipios_objetos[numero_municipio - 1]
            tipo_ensino = input("Digite o tipo de ensino da escola a ser removida: ")
            municipio_selecionado.remover_escola(tipo_ensino)
            print(f"Escola de {tipo_ensino} removida do município {municipio_selecionado.nome}.")
        else:
            print("Número de município inválido.")

    elif escolha == "4":
        print("Saindo do programa.")
        break

    else:
        print("Opção inválida. Tente novamente.")

