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

void quicksort(dupla *vetor, int tamanho);
void mergesort(dupla *vetor,int tamanho);
void radix(dupla *vetor,int tamanho);
string string_media(string a, string b, string c);

void imprimirParametros(ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);

void imprimeVetor(dupla *vetor, int tamanho,ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);