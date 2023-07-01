#ifndef EMPRESA_HPP
#define EMPRESA_HPP
#include <iostream>
#include <vector>
#include "asg.hpp"
#include "vendedor.hpp"
#include "gerente.hpp"

class Empresa {
private:
  float faturamentoMensal;
  std::string nomeEmpresa;
  std::string cnpj;
  Pessoa *Dono = new Pessoa();
  std::vector<Asg> asgs;
  std::vector<Vendedor> vendedores;
  std::vector<Gerente> gerentes;

public:
  Empresa();
  Empresa(std::string nomeEmpresa,  float faturamentoMensal, std::string cnpj);
  float getFaturamentoMensal();
  std::string getNomeEmpresa();
  std::string getCnpj();
  Pessoa *getDono();
  std::vector<Vendedor> getVendedores();
  std::vector<Asg> getAsg();
  std::vector<Gerente> getGerente();
  void setFaturamentoMensal(float faturamentoMensal);
  void setNomeEmpresa(std::string nomeEmpresa);
  void setCnpj(std::string cnpj);
  void carregaFuncoes();
  void carregarEmpresa();
  void carregarAsg();
  void carregarVendedor();
  void carregarGerente();
  void carregaDono();
  void imprimeAsgs();
  void imprimeVendedores();
  void imprimeGerentes();
  void imprimeDono();
  void buscaFuncionario(std::string matricula);
  void calculaSalarioFuncionario(std::string matricula);
  void calculaTodoOsSalarios();
  void calcularRescisao(std::string matricula, Data desligamento);
  void demitirFuncionario(std::string matricula, Data dataDesligamento);
  void contratarFuncionario();
  std::string calculaTempoTrabalho(Data dataIngresso, Data dataDesligamento);
  void salvaFuncionarioArquivo(std::string tipoFuncionario);
  void imprimirNovoFuncionarioConsole(std::string tipoFuncionario);
};

#endif