#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

typedef struct Pessoa{
  string nome;
  string cpf;
  string endereco;
  string lorem;

  void imprimir(ofstream &arquivoSaida){
    // se o arquivo de saída foi passado como argumento, imprime no arquivo
    // caso contrário, imprime no terminal
    if (arquivoSaida.good()) {
      arquivoSaida << nome << ',' << cpf << ',' << endereco << lorem << endl;
    }
    else cout << nome << ',' << cpf << ',' << endereco << ',' << lorem << endl;
  }
} Pessoa;



// Estrutura de nó de pessoas
  typedef struct No {
    Pessoa indice;
    No* proximo = nullptr;
  } No_t, *No_ptr;

// Estrutura de dados para armazenar os dados
// Essa lista retorna o ponteiro na hora da inserção
// a lista armazena pessoas
class Lista_dados{
  private:
    No_ptr _cabeca;
    No_ptr _cauda;
    int _tamanho;

  public:
    Lista_dados();
    ~Lista_dados();
    Pessoa* inserir(Pessoa indice);
    void imprimir();
    int getTamanho();
    bool vazia();
    void limpar();
};