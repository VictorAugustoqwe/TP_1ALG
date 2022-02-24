#include "ListaEncadeada.h"

//Construtor
ListaEncadeada::ListaEncadeada(){
    primeiro = new NoLista();
    ultimo = primeiro;
    tamanho = 0;
}

//Destrutor
ListaEncadeada::~ListaEncadeada(){
    limpa();
    delete primeiro;
}

//Insere dado no inicio da lista encadeada
void ListaEncadeada::insereInicio(int dado){
    NoLista *novo;
    novo = new NoLista(dado);
    novo->prox = primeiro->prox;
    primeiro->prox = novo;
    tamanho = tamanho + 1;
}

//Insere dado no final da lista encadeada
void ListaEncadeada::insereFinal(int dado){
    NoLista *novo;
    novo = new NoLista(dado);
    ultimo->prox = novo;
    ultimo = novo;
    tamanho = tamanho + 1;
}

//Remove dado no inicio da lista encadeada
void ListaEncadeada::removeInicio(){
    if(!vazia()){
        NoLista *aux = primeiro->prox;
        primeiro->prox = primeiro->prox->prox;
        delete aux;
        tamanho = tamanho - 1;
    }
}

//Retorna o primeiro elemento da lista
int ListaEncadeada::primeiroElemento(){
    return primeiro->prox->dado;
}

//Apaga todos os elementos da lista exceto o primeiro
void ListaEncadeada::limpa(){
    NoLista *aux;

    aux = primeiro->prox;
    while(aux != nullptr){
        primeiro->prox = aux->prox;
        delete aux;
        aux = primeiro->prox;
    }
    tamanho = 0;
    ultimo = primeiro;
}

//Retorna se a lista está vazia
int ListaEncadeada::vazia(){
    return tamanho == 0;
}

//imprime do primeiro para o último
void ListaEncadeada::imprime(){
    NoLista *aux;
    aux = primeiro -> prox;
    while (aux != nullptr){
        std::cout << aux->dado;
        aux = aux->prox;
        if(aux != nullptr){
            std::cout << " ";    
        }
    }
    
}

//Retorna tamanho da lista
int ListaEncadeada::getTamanho(){
    return tamanho;
}

//Insere nova pessoa se for preferida ou se ainda houver espaço na lista
int ListaEncadeada::inserirConsiderandoQuantidade(int IndicePessoaAtual, int quantidade){
    if(tamanho < quantidade){
        insereFinal(IndicePessoaAtual);
        return(1);
    }
    else{
        return(0);
    }
}