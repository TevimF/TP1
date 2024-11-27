#include "../include/ordenacao.hpp"

// tipo 1 = nome, 2 = cpf, 3 = endereco
void Ordenar(dupla *vetor, int tamanho, int tipo){
  cout << "Ordenando tipo "<< tipo << "..." << endl;
  if (tipo == 0) {
    //quicksort(vetor, tamanho);
  }
  else if (tipo == 1) {
    //mergesort(vetor, tamanho);
  }
  else if (tipo == 2) {
    //radix(vetor, tamanho);
  }
}

void imprimirParametros(ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas) {
  arquivoSaida << campos << endl;
  for(int i = 0; i < campos; i++) {
    arquivoSaida << colunas[i] << endl;
  }
  arquivoSaida << quantindade_linhas << endl;
}

void imprimeVetor(dupla *vetor, int tamanho, ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas){
  int i=0;
  imprimirParametros(arquivoSaida, campos, colunas, quantindade_linhas);
  while (i < tamanho){
    vetor[i].ponteiro->imprimir(arquivoSaida);
    i++;
  }
}