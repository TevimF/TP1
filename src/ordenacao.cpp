#include "../include/ordenacao.hpp"

void Ordenacao(dupla *vetor, int tamanho, int tipo){
  cout << "Ordenando tipo "<< tipo << "..." << endl;
  imprimeVetor(vetor, tamanho, tipo);
}

void imprimeVetor(dupla *vetor, int tamanho, int tipo){
  int i=0;
  cout << "vou imprimir só as primeiras 3 linhas" << endl;
  tamanho = 3;
  while (i < tamanho){
    cout << vetor[i].index << endl;
    i++;
  }
}