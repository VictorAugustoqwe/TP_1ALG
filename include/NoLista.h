#ifndef NOLISTA_H
#define NOLISTA_H

#include <iostream>

class NoLista{
    public:
        //Construtor
        NoLista();
        //Construtor com parâmetro
        NoLista(int _dado);

        //Conteúdo do nó da lista
        int dado;
        //Próximo nó da lista
        NoLista *prox; 
};

#endif