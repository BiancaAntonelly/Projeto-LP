#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include "util.hpp"

class Pessoa {
private:
  std::string nome;
  std::string cpf;
  Data dataNascimento;
  Endereco enderecoPessoal;
  std::string estadoCivil;
  int qtdFilhos;

public:
  Pessoa();
  Pessoa(std::string nome, std::string cpf, Data dataNascimento, Endereco enderecoPessoal, std::string estadoCivil, int qtdFilhos);
  std::string getNome();
  std::string getCpf();
  Data getDataNascimento();
  Endereco getEndereco();
  std::string getEstadoCivil();
  int getQtdFilhos();
  void setNome(std::string nome);
  void setCpf(std::string cpf);
  void setDataNascimento(Data dataNascimento);
  void setEndereco(Endereco enderecoPessoal);
  void setEstadoCivil(std::string estadoCivil);
  void setQtdFilhos(int qtdFilhos);
};

#endif