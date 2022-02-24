#ifndef LISTA_H
#define LISTA_H

#include "NoLista.h"
#include "Pessoa.h"

class ListaEncadeada{
    public:
        //Construtor
        ListaEncadeada();
        //Destrutor
        ~ListaEncadeada();

        //Insere dado no final da lista encadeada
        void insereFinal(int dado);
        //Insere dado no final da lista encadeada
        void insereInicio(int dado);
        //Remove dado no inicio da lista encadeada
        void removeInicio();
        //Retorna o primeiro elemento da lista
        int primeiroElemento();
        //Apaga todos os elementos da lista exceto o primeiro
        void limpa();
        //Retorna tamanho da lista
        int getTamanho();
        //Retorna se a lista está vazia
        int vazia();
        //imprime do primeiro para o último
        void imprime();
        //Insere nova pessoa se ainda houver espaço na lista da loja
        int inserirConsiderandoQuantidade(int IndicePessoaAtual, int quantidade);

    private:
        //primeiro nó da lista
        NoLista *primeiro;
        //ultimo nó da lista
        NoLista *ultimo;
        //tamanho da lista
        int tamanho;
};

#endif