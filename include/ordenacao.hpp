#pragma once

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
void Ordenacao(dupla *vetor, int tamanho, int tipo);
void imprimeVetor(dupla *vetor, int tamanho, int tipo);