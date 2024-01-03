import PySimpleGUI as sg

class Escola:
    def __init__(self, tipo_ensino, alunos_semestre):
        self.__tipo_ensino = tipo_ensino
        self.__alunos_semestre = alunos_semestre

    def get_tipo_ensino(self):
        return self.__tipo_ensino

    def set_tipo_ensino(self, tipo_ensino):
        self.__tipo_ensino = tipo_ensino

    def get_alunos_semestre(self):
        return self.__alunos_semestre

    def set_alunos_semestre(self, alunos_semestre):
        self.__alunos_semestre = alunos_semestre

    def calcular_custo(self):
        custo = self.__alunos_semestre * 1000
        return custo

    def __str__(self):
        return f"Tipo de Ensino: {self.__tipo_ensino}, Alunos por Semestre: {self.__alunos_semestre}"

class EducacaoInfantil(Escola):
    def __init__(self, tipo_ensino, alunos_semestre):
        super().__init__(tipo_ensino, alunos_semestre)

class EnsinoFundamental(Escola):
    def __init__(self, tipo_ensino, alunos_semestre):
        super().__init__(tipo_ensino, alunos_semestre)

class EnsinoMedio(Escola):
    def __init__(self, tipo_ensino, alunos_semestre):
        super().__init__(tipo_ensino, alunos_semestre)

class Municipio:
    def __init__(self, nome):
        self.__nome = nome
        self.__escolas = []

    def get_nome(self):
        return self.__nome

    def adicionar_escola(self, tipo_ensino, alunos_semestre):
        escola = Escola(tipo_ensino, alunos_semestre)
        self.__escolas.append(escola)

    def remover_escola(self, tipo_ensino):
        for escola in self.__escolas:
            if escola.get_tipo_ensino() == tipo_ensino:
                self.__escolas.remove(escola)
                return

    def calcular_custo_total(self):
        custo_total = 0
        for escola in self.__escolas:
            custo_total += escola.calcular_custo()
        return custo_total

    def listar_escolas_str(self):
        if not self.__escolas:
            return "Nenhuma escola cadastrada neste município."
        else:
            escolas_str = f"\nEscolas do município {self.__nome}:\n"
            escolas_str += "-------------------------------------------------------------\n"
            escolas_str += "{:<5} {:<20} {:<20}\n".format("Nº", "Tipo de Ensino", "Alunos por Semestre")
            escolas_str += "-------------------------------------------------------------\n"
            for idx, escola in enumerate(self.__escolas, start=1):
                escolas_str += "{:<5} {:<20} {:<20}\n".format(idx, escola.get_tipo_ensino(), escola.get_alunos_semestre())
            return escolas_str

    def __str__(self):
        return f"Município: {self.__nome}\nEscolas:\n{', '.join(map(str, self.__escolas))}"

# Função para construir a interface gráfica
def build_gui():
    layout = [
        [sg.Text('Menu:')],
        [sg.Button('Adicionar uma nova escola')],
        [sg.Button('Listar escolas de um município')],
        [sg.Button('Remover uma escola')],
        [sg.Button('Calcular custo total do município')],
        [sg.Button('Sair do programa')]
    ]

    return sg.Window('Programa Escolar', layout, finalize=True)

# Criando objetos de Município com os nomes do Nordeste Goiano
municipios_nordeste_goiano = [
    "Alto Paraíso de Goiás", "Alvorada do Norte", "Buritinópolis", "Campos Belos", "Cavalcante",
    "Colinas do Sul", "Damianópolis", "Divinópolis de Goiás", "Flores de Goiás", "Guarani de Goiás",
    "Iaciara", "Mambaí", "Monte Alegre de Goiás", "Nova Roma", "Posse", "São Domingos",
    "São João D'Aliança", "Simolândia", "Sitio D'Abadia", "Teresina de Goiás"
]

municipios_objetos = [Municipio(nome) for nome in municipios_nordeste_goiano]

# Criando a janela
window = build_gui()

# Loop principal da interface gráfica
while True:
    event, values = window.read()

    if event == sg.WIN_CLOSED or event == 'Sair do programa':
        break

    elif event == 'Adicionar uma nova escola':
        window.hide()

        layout_adicionar_escola = [
            [sg.Text('Escolha o município:')],
            [sg.Listbox(values=municipios_nordeste_goiano, size=(30, 10), key='-MUNICIPIOS-')],
            [sg.Text('Tipo de Ensino:'), sg.InputText(key='-TIPO_ENSINO-')],
            [sg.Text('Alunos por Semestre:'), sg.InputText(key='-ALUNOS_SEMESTRE-')],
            [sg.Button('Adicionar'), sg.Button('Listar Escolas'), sg.Button('Cancelar')]
        ]

        window_adicionar_escola = sg.Window('Adicionar Nova Escola', layout_adicionar_escola, finalize=True)

        while True:
            event_add, values_add = window_adicionar_escola.read()

            if event_add == sg.WIN_CLOSED or event_add == 'Cancelar':
                break

            elif event_add == 'Adicionar':
                numero_municipio = municipios_nordeste_goiano.index(values_add['-MUNICIPIOS-'][0])
                municipio_selecionado = municipios_objetos[numero_municipio]
                tipo_ensino = values_add['-TIPO_ENSINO-']
                alunos_semestre = int(values_add['-ALUNOS_SEMESTRE-'])
                municipio_selecionado.adicionar_escola(tipo_ensino, alunos_semestre)
                sg.popup('Escola adicionada com sucesso!')
                break

            elif event_add == 'Listar Escolas':
                sg.popup_ok(municipio_selecionado.listar_escolas_str(), title=f'Escolas do município {municipio_selecionado.get_nome()}')

        window_adicionar_escola.close()
        window.un_hide()

    elif event == 'Listar escolas de um município':
        window.hide()

        layout_listar_escolas = [
            [sg.Text('Escolha o município:')],
            [sg.Listbox(values=municipios_nordeste_goiano, size=(30, 10), key='-MUNICIPIOS-')],
            [sg.Button('Listar'), sg.Button('Cancelar')]
        ]

        window_listar_escolas = sg.Window('Listar Escolas', layout_listar_escolas, finalize=True)

        while True:
            event_listar, values_listar = window_listar_escolas.read()

            if event_listar == sg.WIN_CLOSED or event_listar == 'Cancelar':
                break

            elif event_listar == 'Listar':
                numero_municipio = municipios_nordeste_goiano.index(values_listar['-MUNICIPIOS-'][0])
                municipio_selecionado = municipios_objetos[numero_municipio]
                sg.popup_ok(municipio_selecionado.listar_escolas_str(), title=f'Escolas do município {municipio_selecionado.get_nome()}')
                break

        window_listar_escolas.close()
        window.un_hide()

    elif event == 'Remover uma escola':
        window.hide()

        layout_remover_escola = [
            [sg.Text('Escolha o município:')],
            [sg.Listbox(values=municipios_nordeste_goiano, size=(30, 10), key='-MUNICIPIOS-')],
            [sg.Text('Tipo de Ensino da escola a ser removida:'), sg.InputText(key='-TIPO_ENSINO-')],
            [sg.Button('Remover'), sg.Button('Listar Escolas'), sg.Button('Cancelar')]
        ]

        window_remover_escola = sg.Window('Remover Escola', layout_remover_escola, finalize=True)

        while True:
            event_remove, values_remove = window_remover_escola.read()

            if event_remove == sg.WIN_CLOSED or event_remove == 'Cancelar':
                break

            elif event_remove == 'Remover':
                numero_municipio = municipios_nordeste_goiano.index(values_remove['-MUNICIPIOS-'][0])
                municipio_selecionado = municipios_objetos[numero_municipio]
                tipo_ensino = values_remove['-TIPO_ENSINO-']
                municipio_selecionado.remover_escola(tipo_ensino)
                sg.popup(f'Escola de {tipo_ensino} removida do município {municipio_selecionado.get_nome()}.')
                break

            elif event_remove == 'Listar Escolas':
                sg.popup_ok(municipio_selecionado.listar_escolas_str(), title=f'Escolas do município {municipio_selecionado.get_nome()}')

        window_remover_escola.close()
        window.un_hide()

    elif event == 'Calcular custo total do município':
        window.hide()

        layout_calcular_custo = [
            [sg.Text('Escolha o município:')],
            [sg.Listbox(values=municipios_nordeste_goiano, size=(30, 10), key='-MUNICIPIOS-')],
            [sg.Button('Calcular'), sg.Button('Listar Escolas'), sg.Button('Cancelar')]
        ]

        window_calcular_custo = sg.Window('Calcular Custo Total', layout_calcular_custo, finalize=True)

        while True:
            event_calcular, values_calcular = window_calcular_custo.read()

            if event_calcular == sg.WIN_CLOSED or event_calcular == 'Cancelar':
                break

            elif event_calcular == 'Calcular':
                numero_municipio = municipios_nordeste_goiano.index(values_calcular['-MUNICIPIOS-'][0])
                municipio_selecionado = municipios_objetos[numero_municipio]
                custo_total = municipio_selecionado.calcular_custo_total()
                sg.popup(f'Custo total do município {municipio_selecionado.get_nome()}: R${custo_total}')
                break

            elif event_calcular == 'Listar Escolas':
                sg.popup_ok(municipio_selecionado.listar_escolas_str(), title=f'Escolas do município {municipio_selecionado.get_nome()}')

        window_calcular_custo.close()
        window.un_hide()

# Fechando a janela ao sair
window.close()
