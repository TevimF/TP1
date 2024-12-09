#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "../include/memlog.hpp"
#include "../include/lista.hpp"
#include "../include/ordenacao.hpp"
using namespace std;

bool validarArgumentos(int argc, char *argv[]) {
  if (argc < 2 || argc > 3) {
    cerr << "Erro: Número incorreto de argumentos." << endl;
    cerr << "Uso: " << argv[0] << " <arquivo_entrada.csv> <arquivo_saida.txt>(opcional)" << endl;
    return false;
  }
  return true;
}

void ordenaEImprime(dupla* nome, dupla* cpf, dupla* endereco, int quantidade_linhas, ofstream& arquivoSaida, int campos, string colunas[], int tipo) {
  // ordena cada vetor de duplas de acordo com o index
  // ordenar por quicksort
  ativaMemLog();
  Ordenar(nome, quantidade_linhas, tipo);
  Ordenar(cpf, quantidade_linhas, tipo);
  Ordenar(endereco, quantidade_linhas, tipo);
  // se o arquivo de saída não foi passado como argumento, imprime no terminal
  desativaMemLog();
  imprimeVetor(nome, quantidade_linhas, arquivoSaida, campos, colunas, quantidade_linhas);
  imprimeVetor(cpf, quantidade_linhas, arquivoSaida, campos, colunas, quantidade_linhas);
  imprimeVetor(endereco, quantidade_linhas, arquivoSaida, campos, colunas, quantidade_linhas);
}

int main(int argc, char *argv[]) {
  iniciaMemLog("memlog.txt");

  // semente para gerar números aleatórios
  srand(time(NULL));

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
  ESCREVEMEMLOG((long int)nome, sizeof(dupla) * quantindade_linhas, 0);
  dupla cpf[quantindade_linhas];
  ESCREVEMEMLOG((long int)cpf, sizeof(dupla) * quantindade_linhas, 0);
  dupla endereco[quantindade_linhas];
  ESCREVEMEMLOG((long int)endereco, sizeof(dupla) * quantindade_linhas, 0);

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
    ESCREVEMEMLOG((long int) &nome[i], sizeof(nome[i]), 0);

    //cpf
    getline(arquivoEntrada, temp, ',');  
    pessoa.cpf = temp;
    cpf[i].index = temp;
    ESCREVEMEMLOG((long int)&cpf[i], sizeof(cpf[i]), 0);

    //endereco
    getline(arquivoEntrada, temp, ',');
    pessoa.endereco = temp;
    endereco[i].index = temp;
    ESCREVEMEMLOG((long int)&endereco[i], sizeof(endereco[i]), 0);

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
  //limpa a saida de erro
  cerr.clear();

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

  int quick = 0;
  int merge = 1;
  int shell = 2;

  // ordenar por quicksort
  ordenaEImprime(nome, cpf, endereco, quantindade_linhas, arquivoSaida, campos, colunas, quick);

  // ordenar por mergesort
  ordenaEImprime(nome, cpf, endereco, quantindade_linhas, arquivoSaida, campos, colunas, merge);
 
  // ordenar por shellsort
  ordenaEImprime(nome, cpf, endereco, quantindade_linhas, arquivoSaida, campos, colunas, shell);
  
  // fecha arquivo
  arquivoEntrada.close();

  finalizaMemLog();

  return 0;
}
