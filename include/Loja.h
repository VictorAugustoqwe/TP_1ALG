#ifndef LOJA_H
#define LOJA_H

#include <iostream>
#include "ListaEncadeada.h"
#include "Pessoa.h"

class Loja{
    public:
        //Construtor
        Loja();
        //Destrutor
        ~Loja();

        //Retorna se o cliente foi alocado ou não
        int alocar(int IndicePessoaAtual);

        //Quantidade de produtos na loja
        int quantidade;
        //Lista de clintes das loja
        ListaEncadeada clientes;
        //Posição x da loja no grid 
        int posX;
        //Posição y da loja no grid 
        int posY;
};

#endif