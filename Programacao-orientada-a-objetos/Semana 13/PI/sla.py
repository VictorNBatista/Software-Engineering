class Usuario:
    def __init__(self, id, nome):
        self._nome = nome
        self.id    = id

class Professor(Usuario):
    def __init__(self, id, nome, biografia, formacoes, contato, custo_hora_aula, disciplina_id):
        super().__init__(id, nome)
        self.biografia       = biografia
        self.formacoes       = formacoes
        self.contato         = contato
        self.custo_hora_aula = custo_hora_aula
        self.displina_id     = disciplina_id

class Aluno(Usuario):
    def __init__(self, id, nome, forma_de_pagamento, contato):
        super().__init__(id, nome)
        self.forma_de_pagamento = forma_de_pagamento
        self.contato            = contato                

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


