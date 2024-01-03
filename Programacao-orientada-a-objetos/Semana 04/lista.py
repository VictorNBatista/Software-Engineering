# -*- coding: utf-8 -*-
class lista(list):
    def elementos_sem_repeticao(self):
        return list(set(self))

minha_lista = lista([1,1,2,2,3,3,4,4,5,5,6,6,7,7])

elementos_unicos = minha_lista.elementos_sem_repeticao()

print("Lista sem repetições: ", elementos_unicos)