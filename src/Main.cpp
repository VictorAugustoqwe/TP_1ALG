#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "Pessoa.h"
#include "Loja.h"
#include "ListaEncadeada.h"

using namespace std;

//Função que retorna score baseado no estado de origem 
int scoreEstado(string estado){
    if(estado == "MG"){
        return(0);
    }
    if(estado == "PR"){
        return(10);
    }
    if(estado == "SP"){
        return(20);
    }
    if(estado == "SC"){
        return(30);
    }
    if(estado == "RJ"){
        return(40);
    }
    if(estado == "RN"){
        return(50);
    }
    if(estado == "RS"){
        return(60);
    }
    return(0);
}

//Função que retorna score baseado no tipo de pagamento
double scorePagamento(string pagamento){
    if(pagamento == "DINHEIRO"){
        return(1.0);
    }
    if(pagamento == "DEBITO"){
        return(2.0);
    }
    if(pagamento == "CREDITO"){
        return(3.0);
    }
    return(0);
}

//Função que calcula distância baseada nos pontos do grid (x1,y1) e (x2,y2) 
int distancia(int posx1, int posy1, int posx2, int posy2){
    int dx = std::abs(posx2-posx1)-1;
    int dy = std::abs(posy2-posy1)-1;
    if(dx < 0){
        dx = 0;
    }
    if(dy < 0){
        dy = 0;
    }
    if(dx > dy){
        return(dx);
    }
    else{
        return(dy);
    }
}

//Função auxiliar para tratar as partições no QuickSortDouble
void ParticaoDouble(int esq, int dir, int *pontEsq, int *pontDir, double *vetor){
    double pivo, aux;
    *pontEsq = esq;
    *pontDir = dir;
    pivo = vetor[(*pontEsq + *pontEsq)/2];
    do{
        while(pivo < vetor[*pontEsq]) (*pontEsq)++;
        while(pivo > vetor[*pontDir]) (*pontDir)--;
        if(*pontEsq <= *pontDir){
            aux = vetor[*pontEsq];
            vetor[*pontEsq] = vetor[*pontDir];
            vetor[*pontDir] = aux;
            (*pontEsq)++;
            (*pontDir)--;
        }
    } while(*pontEsq <= *pontDir);
}

//Função a fazer o particinamento recursivo do array para QuickSortDouble
void OrdenaDouble(int esq, int dir, double *vetor){
    int pontEsq;
    int pontDir;
    ParticaoDouble(esq, dir, &pontEsq, &pontDir, vetor);
    if(esq < pontDir) OrdenaDouble(esq, pontDir, vetor);
    if(pontEsq < dir) OrdenaDouble(pontEsq, dir, vetor);
}

//Função para chamar a implementação do QuickSort Decrescente para double
void QuickSortDouble(double *vetor, int n){
    OrdenaDouble(0, n-1, vetor);
}

//Função auxiliar para tratar as partições no QuickSort
void Particao(int esq, int dir, int *pontEsq, int *pontDir, int *vetor){
    int pivo, aux;
    *pontEsq = esq;
    *pontDir = dir;
    pivo = vetor[(*pontEsq + *pontEsq)/2];
    do{
        while(pivo > vetor[*pontEsq]) (*pontEsq)++;
        while(pivo < vetor[*pontDir]) (*pontDir)--;
        if(*pontEsq <= *pontDir){
            aux = vetor[*pontEsq];
            vetor[*pontEsq] = vetor[*pontDir];
            vetor[*pontDir] = aux;
            (*pontEsq)++;
            (*pontDir)--;
        }
    } while(*pontEsq <= *pontDir);
}

//Função a fazer o particinamento recursivo do array para QuickSort
void Ordena(int esq, int dir, int *vetor){
    int pontEsq;
    int pontDir;
    Particao(esq, dir, &pontEsq, &pontDir, vetor);
    if(esq < pontDir) Ordena(esq, pontDir, vetor);
    if(pontEsq < dir) Ordena(pontEsq, dir, vetor);
}

//Função para chamar a implementação do QuickSort Crescente para int
void QuickSort(int *vetor, int n){
    Ordena(0, n-1, vetor);
}

//Gera lista de prioridades para um array do tipo int (valores menores sendo prioridade) em arrayOrdenado
void listaDePrioridade(int *array, int *arrayOrdenado, int tamanho){
    QuickSort(arrayOrdenado, tamanho);
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(arrayOrdenado[i] == array[j]){
                arrayOrdenado[i] = j;
                array[j] = -1;
                break;
            }
        }
    }
}

//Gera lista de prioridades para um array do tipo double (valores maiores sendo prioridade) em indicesOrdenados
void listaDePrioridadeDouble(double *array, int *indicesOrdenados, int tamanho){
    double *arrayOrdenado = new double[tamanho];
    for(int i = 0; i < tamanho; i++){
        arrayOrdenado[i] = array[i];
    }
    QuickSortDouble(arrayOrdenado, tamanho);
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(arrayOrdenado[i] == array[j]){
                indicesOrdenados[i] = j;
                array[j] = -1;
                break;
            }
        }
    }

    delete[] arrayOrdenado;
}


//Lê entradas e abre o arquivo executando o algoritmo.
int main(){
    
    //Declaração de variáveis
    int nLojas, nPessoas;
    int posX, posY, quantidade, idade;
    
    int *ArrayDistanciasLojas, *ArrayPreferenciasLojas, *ArrayPreferenciasClientes;

    ListaEncadeada pessoasLivres;

    double ticket, *ArrayTicketsClientes;
    string linha, estado, pagamento;
    string nomeArquivo;

    int IndicePessoaAtual, IndiceLojaDesejada, PessoaFoiAlocada, lixo; 
    Pessoa *Pessoas, PessoaAtual;
    Loja *Lojas;

    //lendo arquivo
    cin >> lixo;
    cin >> lixo;    
    cin >> nLojas;


    //Recebe e armazena as Lojas no vetor
    Lojas = new Loja[nLojas];
    for(int i = 0; i < nLojas; i++){
        cin >> quantidade;
        cin >> posX;
        cin >> posY;
        
        Lojas[i].quantidade = quantidade;
        Lojas[i].posX = posX;
        Lojas[i].posY = posY;
    }

    cin >> nPessoas;

    //Recebe e armazena as pessoas no vetor calculando ticket e lista de prioridade de cada pessoa baseada na distância
    Pessoas = new Pessoa[nPessoas];
    ArrayTicketsClientes = new double[nPessoas];
    ArrayPreferenciasClientes = new int[nPessoas];
    ArrayDistanciasLojas = new int[nLojas]; 
    for(int i = 0; i < nPessoas; i++){
        ArrayPreferenciasLojas = new int[nLojas];

        cin >> idade;
        cin >> estado;
        cin >> pagamento;
        cin >> posX;
        cin >> posY;

        ticket = (std::abs(60 - idade) + scoreEstado(estado))/scorePagamento(pagamento);

        for(int j = 0; j < nLojas; j++){
            ArrayDistanciasLojas[j] = distancia(posX,posY,Lojas[j].posX,Lojas[j].posY);
            ArrayPreferenciasLojas[j] = ArrayDistanciasLojas[j];
        }

        listaDePrioridade(ArrayDistanciasLojas, ArrayPreferenciasLojas, nLojas);

        Pessoas[i].ticket = ticket;
        Pessoas[i].preferencias = ArrayPreferenciasLojas;

        ArrayTicketsClientes[i] = ticket;
    }

    //Calcula lista de prioridade das lojas
    listaDePrioridadeDouble(ArrayTicketsClientes, ArrayPreferenciasClientes, nPessoas);
    //insere as pessoas na ordem da prioridade na lista de pessoas livres
    for(int i = 0; i < nPessoas; i++){
        pessoasLivres.insereFinal(ArrayPreferenciasClientes[i]);
    }

    //Executa o algoritmo para alocar as pessoas nas lojas desejadas
    while (!pessoasLivres.vazia()){
        IndicePessoaAtual = pessoasLivres.primeiroElemento();
        PessoaAtual = Pessoas[IndicePessoaAtual];
        IndiceLojaDesejada = PessoaAtual.getPreferenciaAtual();
        PessoaFoiAlocada = Lojas[IndiceLojaDesejada].alocar(IndicePessoaAtual);
        pessoasLivres.removeInicio();
        //Pessoa não foi alocada
        if(!PessoaFoiAlocada){
            Pessoas[IndicePessoaAtual].aumentarIndiceLojaPreferencias();
            //Não há produtos suficientes em lojas para essa pessoa
            if(!(Pessoas[IndicePessoaAtual].indiceLojaPreferencias >= nLojas)){
                pessoasLivres.insereInicio(IndicePessoaAtual);
            }
        }
    }
    
    //Imprime na saída padrão da forma como foi descrito na especificação
    for(int i = 0; i < nLojas; i++){
        cout << i << endl;
        Lojas[i].clientes.imprime();
        cout << endl;
    }
    
    //Desaloca memória alocada dinâmicamente
    delete[] Pessoas;
    delete[] Lojas;
    delete[] ArrayDistanciasLojas;
    delete[] ArrayTicketsClientes;
    delete[] ArrayPreferenciasClientes;
    //ArrayPreferenciasLojas Já foi desalocado em delete[] Pessoas

    return 0;
}