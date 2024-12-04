#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "../include/lista.hpp"
#include "../include/ordenacao.hpp"
using namespace std;


bool validarArgumentos(int argc, char *argv[]) {
  if (argc < 2) {
    cerr << "Erro: Número incorreto de argumentos." << endl;
    cerr << "Uso: " << argv[0] << " <arquivo_entrada.csv> <arquivo_saida.txt>(opcional)" << endl;
    return false;
  }

  return true;
}



int main(int argc, char *argv[]) {

  if (!validarArgumentos(argc, argv)) {
    return 1;
  }
  // debug 
  // cout << "Argumentos validados com sucesso!" << endl;

  Lista_dados lista;
  string diretorio = "../data/";

  // busca o arquivo de entrada
  ifstream arquivoEntrada(diretorio + argv[1]);
  if (!arquivoEntrada.good()) {
    try {
      arquivoEntrada.open(argv[1]);
      if (!arquivoEntrada.good()) {
        throw runtime_error("Erro: Falha ao abrir o arquivo de entrada: " + string(argv[1]));
      }
    }
    catch (const runtime_error& e) {
      cerr << e.what() << endl;
      return 1;
    }
  }

  // lê o arquivo de entrada
  int campos;
  int quantindade_linhas;
  try {
    if (!(arquivoEntrada >> campos)) {
      throw runtime_error("Erro: O arquivo de entrada deve começar com um inteiro referente ao número de campos.");
    }
  } 
  catch (const runtime_error& e) {
    cerr << e.what() << endl;
    arquivoEntrada.close();
    return 1;
  }

  // debug
  // cout << "Quantidade de campos: " << campos << endl;
  
  string colunas[campos];

  for(int i = 0; i < campos; i++) {
    try {
      if (!(arquivoEntrada >> colunas[i])) {
      throw runtime_error("Erro: Falha ao ler o nome da coluna." + campos);
      }
    } 
    catch (const runtime_error& e) {
      cerr << e.what() << endl;
      arquivoEntrada.close();
      return 1;
    }
  }

  // debug
  /*
  cout << "Colunas: " << endl;
  for(int i = 0; i<campos; i++) {
    cout << colunas[i] << endl;
  }
  */

  try {
    if (!(arquivoEntrada >> quantindade_linhas)) {
      throw runtime_error("Erro: Falha ao ler o número de linhas.");
    }
  } 
  catch (const runtime_error& e) {
    cerr << e.what() << endl;
    arquivoEntrada.close();
    return 1;
  }

  // debug
  // cout << "Quantidade de linhas: " << quantindade_linhas << endl;
  
  // Criação de vetores para ordenar indiretamente os dados
  dupla nome[quantindade_linhas];
  dupla cpf[quantindade_linhas];
  dupla endereco[quantindade_linhas];

  // debug
  // cout << "Começando a leitura dos dados..." << endl;
  // Começa o preenchimento dos dados de pessoas
  
  // ** solução para o problema de leitura de strings com endl **
  string temp;
  getline(arquivoEntrada, temp);

  for (int i = 0; i < quantindade_linhas; i++) {
    Pessoa pessoa;

    //nome
    getline(arquivoEntrada, temp, ',');
    pessoa.nome = temp;
    nome[i].index = temp;

    //cpf
    getline(arquivoEntrada, temp, ',');  
    strcpy(pessoa.cpf, temp.c_str());
    cpf[i].index = temp;

    //endereco
    getline(arquivoEntrada, temp, ',');
    pessoa.endereco = temp;
    endereco[i].index = temp;

    //lorem 
    getline(arquivoEntrada, temp);
    pessoa.lorem = temp;

    Pessoa *var = lista.inserir(pessoa);
    nome[i].ponteiro = var;
    cpf[i].ponteiro = var;
    endereco[i].ponteiro = var;
  }
  //debug
  // cout << "Dados lidos com sucesso!" << endl;

  // inicia o arquivo de saída como nulo caso não seja passado como argumento
  ofstream arquivoSaida(nullptr);

  if (argc > 2 && argv[2] != nullptr) {
    // se o arquivo de saída foi passado como argumento, tenta abrir o arquivo
    arquivoSaida.open(diretorio + argv[2]);
    if (!arquivoSaida.good()) {
      // se o arquivo não existe, cria um novo arquivo com o nome passado
      arquivoSaida.clear(); // limpa o estado de erro
      arquivoSaida.open(diretorio + argv[2], ios::out);
      if (!arquivoSaida.good()) {
        cerr << "Erro: Falha ao criar o arquivo de saída: " << argv[2] << endl;
        return 1;
      }
    }
}

  // ordena cada vetor de duplas de acordo com o index
  // ordenar por quicksort
  Ordenar(nome, quantindade_linhas, 0);
  Ordenar(cpf, quantindade_linhas, 0);
  Ordenar(endereco, quantindade_linhas, 0);
  // se o arquivo de saída não foi passado como argumento, imprime no terminal
  imprimeVetor(nome, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(cpf, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(endereco, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);

  // ordenar por mergesort
  Ordenar(nome, quantindade_linhas, 1);
  Ordenar(cpf, quantindade_linhas, 1);
  Ordenar(endereco, quantindade_linhas, 1);
  imprimeVetor(nome, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(cpf, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(endereco, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);

  // ordenar por shellsort
  Ordenar(nome, quantindade_linhas, 2);
  Ordenar(cpf, quantindade_linhas, 2);
  Ordenar(endereco, quantindade_linhas, 2);
  imprimeVetor(nome, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(cpf, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);
  imprimeVetor(endereco, quantindade_linhas, arquivoSaida, campos, colunas, quantindade_linhas);

  

  // fecha arquivo
  arquivoEntrada.close();


  return 0;
}
