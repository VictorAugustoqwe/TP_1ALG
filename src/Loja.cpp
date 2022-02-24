#include "Loja.h"

Loja::Loja(){
}

Loja::~Loja(){
}

int Loja::alocar(int IndicePessoaAtual){
    return clientes.inserirConsiderandoQuantidade(IndicePessoaAtual, quantidade);
}