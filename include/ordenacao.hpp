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

// tipo 1 = nome, 2 = cpf, 3 = endereco
void Ordenar(dupla *vetor, int tamanho, int tipo);

void imprimirParametros(ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);

void imprimeVetor(dupla *vetor, int tamanho,ofstream &arquivoSaida, int campos, string colunas[], int quantindade_linhas);