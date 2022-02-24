#include "Pessoa.h"

Pessoa::Pessoa(){
    preferencias = nullptr;
    indiceLojaPreferencias = 0;
}

Pessoa::~Pessoa(){
    delete preferencias;
}

//aumenta o indice da proxima loja que o cliente deve procurar
void Pessoa::aumentarIndiceLojaPreferencias(){
    indiceLojaPreferencias = indiceLojaPreferencias + 1;
}

//retorna indice da proxima loja que o cliente deve procurar 
int Pessoa::getPreferenciaAtual(){
    return preferencias[indiceLojaPreferencias];
}