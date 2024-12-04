#pragma once

#include <iostream>
#include <string>
#include "lista.hpp"

using namespace std;

struct dupla
{
  string index;
  // aponta para um endereço de memoria que tem uma pessoa
  Pessoa *ponteiro;
};

// 0 quick 1 merge 2 radix
void Ordenar(dupla *vetor, int tamanho, int tipo);

void quicksort(dupla *vetor, int inicio, int fim);
void mergesort(dupla *vetor, dupla *vetor_aux, int inicio, int fim);
void shellsort(dupla *vetor,int tamanho);

int particionar(dupla *vetor, int inicio, int fim);
void merge(dupla *vetor, dupla *vetor_aux, int inicio, int meio, int fim);

void imprimirParametros(ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);

void imprimeVetor(dupla *vetor, int tamanho,ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);