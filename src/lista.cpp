#include "../include/lista.hpp"
#include "../include/memlog.hpp"

Lista_dados :: Lista_dados(){
  _cabeca = NULL;
  _cauda = NULL;
  _tamanho = 0;
}

Lista_dados :: ~Lista_dados(){
  limpar();
}

// retorna o ponteiro de Pessoa falando onde foi inserido
Pessoa* Lista_dados::inserir(Pessoa indice){
  No_ptr novo = new No_t;
  novo->indice = indice;
  novo->proximo = NULL;

  if(_cabeca == NULL){
    _cabeca = novo;
    _cauda = novo;
  } else {
    // se nao for o primeiro elemento, insere no final
    _cauda->proximo = novo;
    _cauda = novo;
  }

  _tamanho++;
  return &(novo->indice);
}

void Lista_dados::imprimir(){
  No_ptr atual = _cabeca;
  while(atual != NULL){
    cout << "Nome: " << atual->indice.nome << endl;
    cout << "CPF: " << atual->indice.cpf << endl;
    cout << "Endereço: " << atual->indice.endereco << endl;
    // atual->indice.lorem << endl;
    cout << "Lorem: " <<  endl;
    cout << "--------------------------------" << endl;
    atual = atual->proximo;
  }
}

int Lista_dados::getTamanho(){
  return _tamanho;
}

bool Lista_dados::vazia(){
  return _tamanho == 0;
}

void Lista_dados::limpar(){
  No_ptr atual = _cabeca;
  No_ptr proximo = NULL;
  while(atual != NULL){
    proximo = atual->proximo;
    delete atual;
    atual = proximo;
  }
  _cabeca = NULL;
  _cauda = NULL;
  _tamanho = 0;
}