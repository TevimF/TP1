#include "../include/ordenacao.hpp"

// 0 quick 1 merge 2 shell
void Ordenar(dupla *vetor, int tamanho, int tipo_ord){
  if (tipo_ord == 0) {
    quicksort(vetor, 0, tamanho - 1);
    //debug
    // cout << (vetor[0].ponteiro->endereco < vetor[1].ponteiro->endereco ? "true" : "false") << endl;
    // cout << vetor[0].ponteiro->endereco << "<" << vetor[1].ponteiro->endereco << endl;
  }
  else if (tipo_ord == 1) {
    dupla *vetor_aux = new dupla[tamanho];
    mergesort(vetor, vetor_aux , 0, tamanho - 1);
    delete[] vetor_aux;
  }
  else if (tipo_ord == 2) {
    shellsort(vetor, tamanho);
  }
}


void quicksort(dupla *vetor, int inicio, int fim) {
  if (fim > inicio) {
    int indice = particionar(vetor, inicio, fim);
    quicksort(vetor, inicio, indice-1);
    quicksort(vetor, indice+1, fim);
  }
}

int particionar(dupla *vetor, int inicio, int fim) {
  string pivo = vetor[fim].index;
  int i = inicio -1;

  for (int j = inicio; j < fim; j++) {
    if (vetor[j].index <= pivo) {
      i++;
      swap(vetor[i], vetor[j]);
    }
  }
  swap(vetor[i + 1], vetor[fim]);
  return i + 1;
}

void imprimirParametros(ostream &saida, int campos, string colunas[], int quantindade_linhas) {
  saida << campos << endl;
  for(int i = 0; i < campos; i++) {
    saida << colunas[i] << endl;
  }
  saida << quantindade_linhas << endl;
}

void imprimeVetor(dupla *vetor, int tamanho, ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas){  
  // se o arquivo de saída não foi passado como argumento, vai passar o cout em vez de arquivo saida
  imprimirParametros(arquivoSaida.good() ? arquivoSaida : cout, campos, colunas, quantindade_linhas);

  for (int i = 0; i < tamanho; i++){ 
    vetor[i].ponteiro->imprimir(arquivoSaida); 
  }
}

void mergesort(dupla *vetor, int tamanho) {
  dupla *vetor_aux = new dupla[tamanho];
  mergesort(vetor, vetor_aux, 0, tamanho - 1);
  delete[] vetor_aux;
}

void mergesort(dupla *vetor, dupla *vetor_aux, int inicio, int fim) {
  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    mergesort(vetor, vetor_aux, inicio, meio);
    mergesort(vetor, vetor_aux, meio + 1, fim);
    merge(vetor, vetor_aux, inicio, meio, fim);
  }
}

void shellsort(dupla *vetor, int tamanho) {
  for (int gap = tamanho / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < tamanho; i++) {
      dupla temp = vetor[i];
      int j;
      for (j = i; j >= gap && vetor[j - gap].index > temp.index; j -= gap) {
        vetor[j] = vetor[j - gap];
      }
      vetor[j] = temp;
    }
  }
}

void merge(dupla *vetor, dupla *vetor_aux, int inicio, int meio, int fim) {
  int i = inicio;
  int j = meio + 1;
  int k = inicio;

  while (i <= meio && j <= fim) {
    if (vetor[i].index <= vetor[j].index) {
      vetor_aux[k++] = vetor[i++];
    } else {
      vetor_aux[k++] = vetor[j++];
    }
  }

  while (i <= meio) {
    vetor_aux[k++] = vetor[i++];
  }

  while (j <= fim) {
    vetor_aux[k++] = vetor[j++];
  }

  for (i = inicio; i <= fim; i++) {
    vetor[i] = vetor_aux[i];
  }
}

