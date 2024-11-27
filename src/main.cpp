#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>

#include "../include/lista.hpp"
#include "../include/ordenacao.hpp"
using namespace std;


bool validarArgumentos(int argc, char *argv[]) {
  if (argc != 3) {
    cerr << "Erro: Número incorreto de argumentos." << endl;
    cerr << "Uso: " << argv[0] << " <arquivo_entrada.csv> <arquivo_saida.txt>" << endl;
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
    cerr << "Erro: Arquivo de entrada não encontrado: " << argv[1] << endl;
    return false;
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
  cout << "Quantidade de linhas: " << quantindade_linhas << endl;
  
  // Criação de vetores para ordenar indiretamente os dados
  dupla nome[quantindade_linhas];
  dupla cpf[quantindade_linhas];
  dupla endereco[quantindade_linhas];

  // Começa o preenchimento dos dados de pessoas
  // debug
  cout << "Começando a leitura dos dados..." << endl;
  for (int i = 0; i < quantindade_linhas; i++) {
    Pessoa pessoa;
  
    string temp;
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
  cout << "Dados lidos com sucesso!" << endl;


  // ordena cada vetor de duplas de acordo com o index
  Ordenacao(nome, quantindade_linhas, 0);
  Ordenacao(cpf, quantindade_linhas, 1);
  Ordenacao(endereco, quantindade_linhas, 2);



  // imprime os 3 vetores ordenados


    
    
  // fecha arquivo
  arquivoEntrada.close();


  return 0;
}
