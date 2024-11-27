#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

typedef struct Pessoa{
  string nome;
  char cpf[15];
  string endereco;
  string lorem;

  void imprimir(){
    cout << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Endereço: " << endereco << endl;
    cout << "Lorem: " << lorem << endl;
    cout << "--------------------------------" << endl;
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