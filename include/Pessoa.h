#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>

class Pessoa{
    public:
        //Construtor
        Pessoa();
        //Destrutor
        ~Pessoa();

        //aumenta o indice da proxima loja que o cliente deve procurar 
        void aumentarIndiceLojaPreferencias();
        //retorna indice da proxima loja que o cliente deve procurar 
        int getPreferenciaAtual();

        //Ticket da pessoa
        double ticket;
        //Indice da próxima pessoa no array de preferências
        int indiceLojaPreferencias;
        //Array 
        int *preferencias;
};

#endif