#include "../include/ordenacao.hpp"

// 0 quick 1 merge 2 radix
void Ordenar(dupla *vetor, int tamanho, int tipo){
  cout << "Ordenando tipo "<< tipo << "..." << endl;
  if (tipo == 0) {
    quicksort(vetor, tamanho);
  }
  else if (tipo == 1) {
    mergesort(vetor, tamanho);
  }
  else if (tipo == 2) {
    radix(vetor, tamanho);
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

void quicksort(dupla *vetor, int tamanho){
  string pivo;
  pivo = string_media(vetor[0].index, vetor[tamanho/2].index, vetor[tamanho-1].index);
  
  }

}

// retorna nem a maior nem a menor string para ser um bom pivo
string string_media(string a, string b, string c) {
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    } else {
        return c;
    }
}