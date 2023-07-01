#include "../hpps/empresa.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

Empresa::Empresa() {}

Empresa::Empresa(string nomeEmpresa, float faturamentoMensal, string cnpj) {
  this->faturamentoMensal = faturamentoMensal;
  this->nomeEmpresa = nomeEmpresa;
  this->cnpj = cnpj;
}

float Empresa::getFaturamentoMensal() { return this->faturamentoMensal; }

string Empresa::getNomeEmpresa() { return this->nomeEmpresa; }

string Empresa::getCnpj() { return this->cnpj; }

Pessoa *Empresa::getDono() { return Dono; }

vector<Vendedor> Empresa::getVendedores() { return this->vendedores; }

vector<Asg> Empresa::getAsg() { return this->asgs; }

vector<Gerente> Empresa::getGerente() { return this->gerentes; }

void Empresa::setFaturamentoMensal(float faturamentoMensal) {
  this->faturamentoMensal = faturamentoMensal;
}

void Empresa::setNomeEmpresa(string nomeEmpresa) {
  this->nomeEmpresa = nomeEmpresa;
}

void Empresa::setCnpj(string cnpj) { this->cnpj = cnpj; }

void Empresa::carregaFuncoes() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/funcoes.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    for (int i = 0; i < temp.size(); i++) {
      if (temp[i] == "carregarEmpresa()") {
        cout << "\nCarregando empresa..." << endl;
        carregarEmpresa();
      } else if (temp[i] == "carregarAsg()") {
        cout << "\nCarregando asgs..." << endl;
        carregarAsg();
      } else if (temp[i] == "carregarVendedor()") {
        cout << "\nCarregando vendedores..." << endl;
        carregarVendedor();
      } else if (temp[i] == "carregarGerente()") {
        cout << "\nCarregando gerentes..." << endl;
        carregarGerente();
      } else if (temp[i] == "carregaDono()") {
        cout << "\nCarregando dono..." << endl;
        carregaDono();
      } else if (temp[i] == "imprimeAsgs()") {
        imprimeAsgs();
      } else if (temp[i] == "imprimeVendedores()") {
        imprimeVendedores();
      } else if (temp[i] == "imprimeGerentes()") {
        imprimeGerentes();
      } else if (temp[i] == "imprimeDono()") {
        imprimeDono();
      } else if (temp[i] == "buscaFuncionario()") {
        string matricula = temp[i + 1];
        i++;
        buscaFuncionario(matricula);
      } else if (temp[i] == "calculaSalarioFuncionario()") {
        string matricula = temp[i + 1];
        i++;
        calculaSalarioFuncionario(matricula);
      } else if (temp[i] == "calculaTodoOsSalarios()") {
        calculaTodoOsSalarios();
      } else if (temp[i] == "calcularRescisao()") {
        string matricula = temp[i + 1];
        Data desligamento;
        desligamento.ano = stoi(temp[i + 2]);
        desligamento.mes = stoi(temp[i + 3]);
        desligamento.dia = stoi(temp[i + 4]);
        i += 4;
        calcularRescisao(matricula, desligamento);
      } else if (temp[i] == "demitirFuncionario()") {
        string matricula = temp[i + 1];
        Data desligamento;
        desligamento.ano = stoi(temp[i + 2]);
        desligamento.mes = stoi(temp[i + 3]);
        desligamento.dia = stoi(temp[i + 4]);
        i += 4;
        demitirFuncionario(matricula, desligamento);
      } else if (temp[i] == "contratarFuncionario()") {
        contratarFuncionario();
      }
    }
  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo de funções. Erro: " << erro.what()
         << endl;
  }
}

void Empresa::carregarEmpresa() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/empresa.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    this->nomeEmpresa = temp[2];
    this->cnpj = temp[3];
    this->faturamentoMensal = stof(temp[4]);

  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo empresa.txt. Erro: " << erro.what()
         << endl;
  }
}

void Empresa::carregarAsg() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/asg.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    Asg tAsg;

    for (int i = 0; i < temp.size(); i += 26) {
      tAsg.setNome(temp[i + 3]);
      tAsg.setCpf(temp[i + 4]);
      tAsg.setQtdFilhos(stoi(temp[i + 5]));
      tAsg.setEstadoCivil(temp[i + 6]);
      Endereco tEnd;
      tEnd.cidade = temp[i + 8];
      tEnd.cep = temp[i + 9];
      tEnd.bairro = temp[i + 10];
      tEnd.rua = temp[i + 11];
      tEnd.numero = stoi(temp[i + 12]);
      tAsg.setEndereco(tEnd);
      Data tnasc;
      tnasc.ano = stoi(temp[i + 14]);
      tnasc.mes = stoi(temp[i + 15]);
      tnasc.dia = stoi(temp[i + 16]);
      tAsg.setDataNascimento(tnasc);
      tAsg.setMatricula(temp[i + 18]);
      tAsg.setSalario(stof(temp[i + 19]));
      tAsg.setAdcionalInsabubridade(stof(temp[i + 20]));
      tAsg.setDiasFaltas(stoi(temp[i + 21]));
      Data ting;
      ting.ano = stoi(temp[i + 23]);
      ting.mes = stoi(temp[i + 24]);
      ting.dia = stoi(temp[i + 25]);
      tAsg.setDataingresso(ting);
      asgs.push_back(tAsg);
    }
  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo de asgs.txt. Erro: " << erro.what()
         << endl;
  }
}

void Empresa::carregarVendedor() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/vendedor.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    Vendedor tVend;
    for (int i = 0; i < temp.size(); i += 26) {
      tVend.setNome(temp[i + 3]);
      tVend.setCpf(temp[i + 4]);
      tVend.setQtdFilhos(stoi(temp[i + 5]));
      tVend.setEstadoCivil(temp[i + 6]);
      Endereco tEnd;
      tEnd.cidade = temp[i + 8];
      tEnd.cep = temp[i + 9];
      tEnd.bairro = temp[i + 10];
      tEnd.rua = temp[i + 11];
      tEnd.numero = stoi(temp[i + 12]);
      tVend.setEndereco(tEnd);
      Data tnasc;
      tnasc.ano = stoi(temp[i + 14]);
      tnasc.mes = stoi(temp[i + 15]);
      tnasc.dia = stoi(temp[i + 16]);
      tVend.setDataNascimento(tnasc);
      tVend.setMatricula(temp[i + 18]);
      tVend.setSalario(stof(temp[i + 19]));
      tVend.setTipoVendedor(temp[i + 20]);
      tVend.setDiasFaltas(stoi(temp[i + 21]));
      Data ting;
      ting.ano = stoi(temp[i + 23]);
      ting.mes = stoi(temp[i + 24]);
      ting.dia = stoi(temp[i + 25]);
      tVend.setDataingresso(ting);
      vendedores.push_back(tVend);
    }
  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo vendedores.txt. Erro: "
         << erro.what() << endl;
  }
}

void Empresa::carregarGerente() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/gerente.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    Gerente tGer;

    for (int i = 0; i < temp.size(); i += 26) {
      tGer.setNome(temp[i + 3]);
      tGer.setCpf(temp[i + 4]);
      tGer.setQtdFilhos(stoi(temp[i + 5]));
      tGer.setEstadoCivil(temp[i + 6]);
      Endereco tEnd;
      tEnd.cidade = temp[i + 8];
      tEnd.cep = temp[i + 9];
      tEnd.bairro = temp[i + 10];
      tEnd.rua = temp[i + 11];
      tEnd.numero = stoi(temp[i + 12]);
      tGer.setEndereco(tEnd);
      Data tnasc;
      tnasc.ano = stoi(temp[i + 14]);
      tnasc.mes = stoi(temp[i + 15]);
      tnasc.dia = stoi(temp[i + 16]);
      tGer.setDataNascimento(tnasc);
      tGer.setMatricula(temp[i + 18]);
      tGer.setSalario(stof(temp[i + 19]));
      tGer.setParticipacaoLucros(stof(temp[i + 20]));
      tGer.setDiasFaltas(stoi(temp[i + 21]));
      Data ting;
      ting.ano = stoi(temp[i + 23]);
      ting.mes = stoi(temp[i + 24]);
      ting.dia = stoi(temp[i + 25]);
      tGer.setDataingresso(ting);
      gerentes.push_back(tGer);
    }
  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo gerente.txt. Erro: " << erro.what()
         << endl;
  }
}

void Empresa::carregaDono() {
  try {
    fstream arquivo;
    arquivo.open("./leitura/dono.txt", ios::in);
    vector<string> temp;
    string linha;

    while (getline(arquivo, linha)) {
      temp.push_back(linha);
    }

    arquivo.close();
    for (int i = 0; i < temp.size(); i += 25) {
      getDono()->setNome(temp[i + 2]);
      getDono()->setCpf(temp[i + 3]);
      getDono()->setQtdFilhos(stoi(temp[i + 4]));
      getDono()->setEstadoCivil(temp[i + 5]);
      Endereco tEnd;
      tEnd.cidade = temp[i + 6];
      tEnd.cep = temp[i + 7];
      tEnd.bairro = temp[i + 8];
      tEnd.rua = temp[i + 9];
      tEnd.numero = stoi(temp[i + 10]);
      getDono()->setEndereco(tEnd);
      Data tnasc;
      tnasc.ano = stoi(temp[i + 11]);
      tnasc.mes = stoi(temp[i + 12]);
      tnasc.dia = stoi(temp[i + 13]);
      getDono()->setDataNascimento(tnasc);
    }
  } catch (exception &erro) {
    cout << "Não foi possivel abrir arquivo dono.txt. Erro: " << erro.what()
         << endl;
  }
}

void Empresa::imprimeAsgs() {
  cout << "\n#################    ASGS    #################" << endl;
  for (int i = 0; i < asgs.size(); i++) {
    cout << "Nome: " << asgs[i].getNome() << endl;
    cout << "CPF: " << asgs[i].getCpf() << endl;
    cout << "FILHOS: " << asgs[i].getQtdFilhos() << endl;
    cout << "Estado civil: " << asgs[i].getEstadoCivil() << endl;
    cout << "Cidade: " << asgs[i].getEndereco().cidade << endl;
    cout << "Rua: " << asgs[i].getEndereco().rua << endl;
    cout << "Data de nascimento: " << asgs[i].getDataNascimento().dia << "/"
         << asgs[i].getDataNascimento().mes << "/"
         << asgs[i].getDataNascimento().ano << endl;
    cout << "Matrícula: " << asgs[i].getMatricula() << endl;
    cout << "Salário: " << asgs[i].getSalario() << endl;
    cout << "Insalubridade: " << asgs[i].getAdcionalInsabubridade() << endl;
    cout << "Data de ingresso: " << asgs[i].getDataingresso().dia << "/"
         << asgs[i].getDataingresso().mes << "/"
         << asgs[i].getDataingresso().ano << endl;
    cout << "*****************************************" << endl;
  }
}

void Empresa::imprimeVendedores() {
  cout << "\n##############    VENDEDORES    ##############" << endl;
  for (int i = 0; i < vendedores.size(); i++) {
    cout << "Nome: " << vendedores[i].getNome() << endl;
    cout << "CPF: " << vendedores[i].getCpf() << endl;
    cout << "FILHOS: " << vendedores[i].getQtdFilhos() << endl;
    cout << "Estado civil: " << vendedores[i].getEstadoCivil() << endl;
    cout << "Cidade: " << vendedores[i].getEndereco().cidade << endl;
    cout << "Rua: " << vendedores[i].getEndereco().rua << endl;
    cout << "Data de nascimento: " << vendedores[i].getDataNascimento().dia
         << "/" << vendedores[i].getDataNascimento().mes << "/"
         << vendedores[i].getDataNascimento().ano << endl;
    cout << "Matrícula: " << vendedores[i].getMatricula() << endl;
    cout << "Salário: " << vendedores[i].getSalario() << endl;
    cout << "Tipo de vendedor: " << vendedores[i].getTipoVendedor() << endl;
    cout << "Data de ingresso: " << vendedores[i].getDataingresso().dia << "/"
         << vendedores[i].getDataingresso().mes << "/"
         << vendedores[i].getDataingresso().ano << endl;
    cout << "*****************************************" << endl;
  }
}

void Empresa::imprimeGerentes() {
  cout << "\n##############    GERENTES    ##############" << endl;
  for (int i = 0; i < gerentes.size(); i++) {
    cout << "Nome: " << gerentes[i].getNome() << endl;
    cout << "CPF: " << gerentes[i].getCpf() << endl;
    cout << "FILHOS: " << gerentes[i].getQtdFilhos() << endl;
    cout << "Estado civil: " << gerentes[i].getEstadoCivil() << endl;
    cout << "Cidade: " << gerentes[i].getEndereco().cidade << endl;
    cout << "Rua: " << gerentes[i].getEndereco().rua << endl;
    cout << "Data nascimento: " << gerentes[i].getDataNascimento().dia << "/"
         << gerentes[i].getDataNascimento().mes << "/"
         << gerentes[i].getDataNascimento().ano << endl;
    cout << "Matrícula: " << gerentes[i].getMatricula() << endl;
    cout << "Salário: " << gerentes[i].getSalario() << endl;
    cout << "Tipo de vendedor: " << gerentes[i].getParticipacaoLucros() << endl;
    cout << "Data de ingresso: " << gerentes[i].getDataingresso().dia << "/"
         << gerentes[i].getDataingresso().mes << "/"
         << gerentes[i].getDataingresso().ano << endl;
    cout << "*****************************************" << endl;
  }
}

void Empresa::imprimeDono() {
  cout << "\n##############    DONO    ##############" << endl;
  cout << "Nome: " << getDono()->getNome() << endl;
  cout << "CPF: " << getDono()->getCpf() << endl;
  cout << "FILHOS: " << getDono()->getQtdFilhos() << endl;
  cout << "Estado civil: " << getDono()->getEstadoCivil() << endl;
  cout << "Cidade: " << getDono()->getEndereco().cidade << endl;
  cout << "Rua: " << getDono()->getEndereco().rua << endl;
  cout << "Data de nascimento: " << getDono()->getDataNascimento().dia << "/"
       << getDono()->getDataNascimento().mes << "/"
       << getDono()->getDataNascimento().ano << endl;
  cout << "*****************************************" << endl;
}

void Empresa::buscaFuncionario(string matricula) {
  cout << "\n##########    Buscando funcionário    ##########" << endl;
  for (int i = 0; i < asgs.size(); i++) {
    if (matricula == asgs[i].getMatricula()) {
      cout << "Função: ASG" << endl;
      cout << "Nome: " << asgs[i].getNome() << endl;
      cout << "CPF: " << asgs[i].getCpf() << endl;
      cout << "Salário base: " << asgs[i].getSalario() << endl;
      return;
    }
  }
  for (int i = 0; i < vendedores.size(); i++) {
    if (matricula == vendedores[i].getMatricula()) {
      cout << "Função: Vendedor" << endl;
      cout << "Nome: " << vendedores[i].getNome() << endl;
      cout << "CPF: " << vendedores[i].getCpf() << endl;
      cout << "Salário base: " << vendedores[i].getSalario() << endl;
      return;
    }
  }
  for (int i = 0; i < gerentes.size(); i++) {
    if (matricula == gerentes[i].getMatricula()) {
      cout << "Função: Gerente" << endl;
      cout << "Nome: " << gerentes[i].getNome() << endl;
      cout << "CPF: " << gerentes[i].getCpf() << endl;
      cout << "Salário base: " << gerentes[i].getSalario() << endl;
      return;
    }
  }
  cout << "Funcionario não localizado no sistema!" << endl;
}

void Empresa::calculaSalarioFuncionario(string matricula) {
  cout << "\n##########    Calculando salário de funcionário    ##########"
       << endl;
  for (int i = 0; i < asgs.size(); i++) {
    if (matricula == asgs[i].getMatricula()) {
      cout << "Função: ASG" << endl;
      cout << "Nome: " << asgs[i].getNome() << endl;
      cout << "Salario base: " << asgs[i].getSalario() << endl;
      cout << "Salario calculado: "
           << asgs[i].calcularSalario(asgs[i].getDiasFaltas()) << endl;
      return;
    }
  }
  for (int i = 0; i < vendedores.size(); i++) {
    if (matricula == vendedores[i].getMatricula()) {
      cout << "Função: Vendedor" << endl;
      cout << "Nome: " << vendedores[i].getNome() << endl;
      cout << "Salario base: " << vendedores[i].getSalario() << endl;
      cout << "Salario calculado: "
           << vendedores[i].calcularSalario(vendedores[i].getDiasFaltas())
           << endl;
      return;
    }
  }
  for (int i = 0; i < gerentes.size(); i++) {
    if (matricula == gerentes[i].getMatricula()) {
      cout << "Função: Gerente" << endl;
      cout << "Nome: " << gerentes[i].getNome() << endl;
      cout << "Salario base: " << gerentes[i].getSalario() << endl;
      cout << "Salario calculado: "
           << gerentes[i].calcularSalario(gerentes[i].getDiasFaltas()) << endl;
      return;
    }
  }
  cout << "Funcionario não localizado no sistema!" << endl;
}

/**
 *@brief Função que calcula todos os salários e cria um relatório financeiro
 *@param Nenhum
 *@return Sem retorno
 */
void Empresa::calculaTodoOsSalarios() {
  fstream relatorio;
  relatorio.open("./escrita/relatorioFinanceiro.txt", ios::out);

  float soma = 0, somaAsg = 0, somaVend = 0, somaGer = 0;

  relatorio << "######### Relatório Financeiro ########" << endl << endl;

  /**@brief Cálculo dos salários por tipo de funcionário e cálculo total dos
   * salários*/
  relatorio << "Cargo: ASG" << endl;
  for (int i = 0; i < asgs.size(); i++) {
    relatorio << asgs[i].getMatricula() << " - " << asgs[i].getNome() << " -R$ "
              << asgs[i].getSalario() << endl;
    somaAsg += asgs[i].getSalario();
    soma += somaAsg;
  }
  relatorio << "Total ASG: R$ " << fixed << setprecision(2) << somaAsg << endl
            << endl;

  relatorio << "Cargo: Vendedor" << endl;
  for (int i = 0; i < vendedores.size(); i++) {
    relatorio << vendedores[i].getMatricula() << " - "
              << vendedores[i].getNome() << " - R$ "
              << vendedores[i].getSalario() << endl;
    somaVend += vendedores[i].getSalario();
    soma += somaVend;
  }
  relatorio << "Total Vendedor: R$ " << fixed << setprecision(2) << somaVend
            << endl
            << endl;

  relatorio << "Cargo: Gerente" << endl;
  for (int i = 0; i < gerentes.size(); i++) {
    relatorio << gerentes[i].getMatricula() << " - " << gerentes[i].getNome()
              << " - R$ " << gerentes[i].getSalario() << endl;
    somaGer += gerentes[i].getSalario();
    soma += somaGer;
  }

  /** @brief Escreve as informações dos salários no relatório financeiro*/
  relatorio << "Total Gerente: R$ " << fixed << setprecision(2) << somaGer
            << endl
            << endl;

  relatorio << "CUSTO TOTAL: R$ " << fixed << setprecision(2) << soma << endl
            << endl;
  relatorio << "FATURAMENTO MENSAL: R$ " << fixed << setprecision(2)
            << faturamentoMensal << endl
            << endl;

  relatorio << "Custo ASG(%): " << fixed << setprecision(2)
            << (somaAsg / soma) * 100 << "%" << endl;
  relatorio << "Custo Vendedor(%): " << fixed << setprecision(2)
            << (somaVend / soma) * 100 << "%" << endl;
  relatorio << "Custo Gerente(%): " << fixed << setprecision(2)
            << (somaGer / soma) * 100 << "%" << endl
            << endl;

  double lucro = faturamentoMensal - soma;
  relatorio << "LUCRO DA EMPRESA: R$ " << fixed << setprecision(2) << lucro
            << endl
            << endl;

  if (lucro >= 0) {
    relatorio << "SITUAÇÃO: Lucro" << endl;
  } else {
    relatorio << "SITUAÇÃO: Prejuízo" << endl;
  }

  relatorio.close();

  relatorio.open("./escrita/relatorioFinanceiro.txt",
                 ios::in); /**<Abre o arquivo novamente para leitura*/

  cout << endl;

  /** @brief Imprime o conteúdo do arquivo no console */
  if (relatorio.is_open()) {
    string linha;
    while (getline(relatorio, linha)) {
      cout << linha << endl;
    }
    relatorio.close();
  } else {
    cout << "Erro ao abrir o arquivo." << endl;
  }

  cout << "\nRelatório financeiro gerado com sucesso!" << endl;
}

/**
 *@details Função que faz o cálculo da rescisão por tipo de usuário e imprime no
 *console as informações sobre esse funcionário
 *@param Matrícula e data de desligamento
 *@return Sem retorno
 */
void Empresa::calcularRescisao(string matricula, Data desligamento) {
  cout << "\n##########    Calculando a rescisão de funcionário    ##########"
       << endl;

  /** @brief Verifica se a matrícula existe no sistema e calcula a rescisão de
   * acordo com o tipo de funcionário (ASG, Gerente ou Vendedor)*/
  for (int i = 0; i < asgs.size(); i++) {
    if (matricula == asgs[i].getMatricula()) {
      cout << "Função: ASG" << endl;
      cout << "Nome: " << asgs[i].getNome() << endl;
      cout << "Salario base: " << asgs[i].getSalario() << endl;
      cout << "Rescisão calculada: " << asgs[i].calcularRecisao(desligamento)
           << endl;
      return;
    }
  }
  for (int i = 0; i < vendedores.size(); i++) {
    if (matricula == vendedores[i].getMatricula()) {
      cout << "Função: Vendedor" << endl;
      cout << "Nome: " << vendedores[i].getNome() << endl;
      cout << "Salario base: " << vendedores[i].getSalario() << endl;
      cout << "Rescisão calculada: "
           << vendedores[i].calcularRecisao(desligamento) << endl;
      return;
    }
  }
  for (int i = 0; i < gerentes.size(); i++) {
    if (matricula == gerentes[i].getMatricula()) {
      cout << "Função: Gerente" << endl;
      cout << "Nome: " << gerentes[i].getNome() << endl;
      cout << "Salario base: " << gerentes[i].getSalario() << endl;
      cout << "Rescisão calculada: "
           << gerentes[i].calcularRecisao(desligamento) << endl;
      return;
    }
  }
  cout << "Funcionario não localizado no sistema!" << endl;
}

/**
 *@brief Função que calcula o tempo de trabalho de um funcionário
 *@param Data de ingresso e data de desligamento do emprego
 *@return Retorna uma mensagem personalizada com a quantidade de anos, meses e
 *dias de trabalho
 */
std::string Empresa::calculaTempoTrabalho(Data dataIngresso,
                                          Data dataDesligamento) {
  int anos = (dataDesligamento.ano - 1) - dataIngresso.ano;
  int meses = (dataDesligamento.mes + 11) - dataIngresso.mes;
  int dias = (dataDesligamento.dia + 30) - dataIngresso.dia;
  int totalAnos = anos + (meses / 12) + (dias / 365);

  string msg = to_string(totalAnos) + " anos, " + to_string(meses) +
               " meses e " + to_string(dias) +
               " dias"; /**< String com as informações do tempo de trabalho*/
  return msg;
}

/**
 *@brief Função que demiti funcionário e cria um relatório de demissão
 *@param Matrícula e data de desligamento
 *@return Sem retorno
 */
void Empresa::demitirFuncionario(std::string matricula, Data dataDesligamento) {
  fstream arquivo;
  arquivo.open("./escrita/relatorioDimissional.txt", ios::out);
  float valorRescisao;
  string nome, cargo, cpf;
  Data dataIngresso;

  /** @details Verifica se a matrícula existe no sistema para poder realizar o
   * cálculo da recisão e atribuição das informações do usuário nas variáveis*/
  for (Vendedor v : vendedores) {
    if (matricula == v.getMatricula()) {
      valorRescisao = v.calcularRecisao(dataDesligamento);
      nome = v.getNome();
      cargo = "Vendedor";
      cpf = v.getCpf();
      dataIngresso = v.getDataingresso();
    }
  }

  for (Asg a : asgs) {
    if (matricula == a.getMatricula()) {
      valorRescisao = a.calcularRecisao(dataDesligamento);
      nome = a.getNome();
      cargo = "Asg";
      cpf = a.getCpf();
      dataIngresso = a.getDataingresso();
    }
  }

  for (Gerente g : gerentes) {
    if (matricula == g.getMatricula()) {
      valorRescisao = g.calcularRecisao(dataDesligamento);
      nome = g.getNome();
      cargo = "Gerente";
      cpf = g.getCpf();
      dataIngresso = g.getDataingresso();
    }
  }

  /** @brief Calcula o tempo de trabalho na empresa */
  string tempoTrabalho = calculaTempoTrabalho(dataIngresso, dataDesligamento);

  /** @brief Atualiza o arquivo de relatório demissional*/
  arquivo << "##############################" << endl;
  arquivo << "    Relatorio Demissional" << endl;
  arquivo << "##############################" << endl;
  arquivo << "Cargo: " << cargo << endl;
  arquivo << "Nome: " << nome << endl;
  arquivo << "CPF: " << cpf << endl;
  arquivo << "Matrícula: " << matricula << endl;
  arquivo << "Data de ingresso: " << dataIngresso.dia << "/" << dataIngresso.mes
          << "/" << dataIngresso.ano << endl;
  arquivo << "Data de demissão: " << dataDesligamento.dia << "/"
          << dataDesligamento.mes << "/" << dataDesligamento.ano << endl;
  arquivo << "******************************" << endl;
  arquivo << "Valor de rescisão: R$ " << valorRescisao << endl;
  arquivo << "******************************" << endl;
  arquivo << "Tempo de Trabalho: " << tempoTrabalho << endl;

  arquivo.close();

  cout << endl;

  /** @brief Imprime no console o relatório demissional */
  cout << "##############################" << endl;
  cout << "    Relatorio Demissional" << endl;
  cout << "##############################" << endl;
  cout << "Cargo: " << cargo << endl;
  cout << "Nome: " << nome << endl;
  cout << "CPF: " << cpf << endl;
  cout << "Matrícula: " << matricula << endl;
  cout << "Data de ingresso: " << dataIngresso.dia << "/" << dataIngresso.mes
       << "/" << dataIngresso.ano << endl;
  cout << "Data de demissão: " << dataDesligamento.dia << "/"
       << dataDesligamento.mes << "/" << dataDesligamento.ano << endl;
  cout << "******************************" << endl;
  cout << "Valor de rescisão: R$ " << valorRescisao << endl;
  cout << "******************************" << endl;
  cout << "Tempo de Trabalho: " << tempoTrabalho << endl;
}

/**
 *@brief Função que salva as informações do funcionário nos arquivos do sistema
 *@param String tipoFuncionario recebe o texto com o tipo de funcionário que
 *será salvo no arquivo
 *@return Sem retorno
 */
void Empresa::salvaFuncionarioArquivo(std::string tipoFuncionario) {

  /** @details Verifica o tipo de funcionário e salva as informações do último
   * funcionário que foi adicionado a lista no método de contratar*/
  if (tipoFuncionario == "ASG") {
    fstream arquivoAsg;
    int tam = asgs.size();
    tam -= 1;

    arquivoAsg.open("./leitura/asg.txt", ios::in | ios::app);

    arquivoAsg << "#########################################################"
               << endl;
    arquivoAsg << "ASG Nº: " << asgs.size() - 1 << endl;
    arquivoAsg << "##### DADOS PESSOAIS #####" << endl;
    arquivoAsg << asgs[tam].getNome() << endl;
    arquivoAsg << asgs[tam].getCpf() << endl;
    arquivoAsg << asgs[tam].getQtdFilhos() << endl;
    arquivoAsg << asgs[tam].getEstadoCivil() << endl;
    arquivoAsg << "***** Endereço (cidade, cep, bairro, rua e numero) ****"
               << endl;
    arquivoAsg << asgs[tam].getEndereco().cidade << endl;
    arquivoAsg << asgs[tam].getEndereco().cep << endl;
    arquivoAsg << asgs[tam].getEndereco().bairro << endl;
    arquivoAsg << asgs[tam].getEndereco().rua << endl;
    arquivoAsg << asgs[tam].getEndereco().numero << endl;
    arquivoAsg << "***** Data de nascimento (ano, mes, dia) ****" << endl;
    arquivoAsg << asgs[tam].getDataNascimento().ano << endl;
    arquivoAsg << asgs[tam].getDataNascimento().mes << endl;
    arquivoAsg << asgs[tam].getDataNascimento().dia << endl;
    arquivoAsg << "##### DADOS FUNCIONAIS #####" << endl;
    arquivoAsg << asgs[tam].getMatricula() << endl;
    arquivoAsg << asgs[tam].getSalario() << endl;
    arquivoAsg << asgs[tam].getAdcionalInsabubridade() << endl;
    arquivoAsg << asgs[tam].getDiasFaltas() << endl;
    arquivoAsg << "***** Data de ingresso (ano, mes, dia) ****" << endl;
    arquivoAsg << asgs[tam].getDataingresso().ano << endl;
    arquivoAsg << asgs[tam].getDataingresso().mes << endl;
    arquivoAsg << asgs[tam].getDataingresso().dia << endl;

    arquivoAsg.close();

  } else if (tipoFuncionario == "Vendedor") {
    fstream arquivoVendedor;
    int tam = vendedores.size();
    tam -= 1;
    arquivoVendedor.open("./leitura/vendedor.txt", ios::in | ios::app);

    arquivoVendedor
        << "#########################################################" << endl;
    arquivoVendedor << "Vendedor Nº: " << vendedores.size() - 1 << endl;
    arquivoVendedor << "##### DADOS PESSOAIS #####" << endl;
    arquivoVendedor << vendedores[tam].getNome() << endl;
    arquivoVendedor << vendedores[tam].getCpf() << endl;
    arquivoVendedor << vendedores[tam].getQtdFilhos() << endl;
    arquivoVendedor << vendedores[tam].getEstadoCivil() << endl;
    arquivoVendedor << "***** Endereço (cidade, cep, bairro, rua e numero) ****"
                    << endl;
    arquivoVendedor << vendedores[tam].getEndereco().cidade << endl;
    arquivoVendedor << vendedores[tam].getEndereco().cep << endl;
    arquivoVendedor << vendedores[tam].getEndereco().bairro << endl;
    arquivoVendedor << vendedores[tam].getEndereco().rua << endl;
    arquivoVendedor << vendedores[tam].getEndereco().numero << endl;
    arquivoVendedor << "***** Data de nascimento (ano, mes, dia) ****" << endl;
    arquivoVendedor << vendedores[tam].getDataNascimento().ano << endl;
    arquivoVendedor << vendedores[tam].getDataNascimento().mes << endl;
    arquivoVendedor << vendedores[tam].getDataNascimento().dia << endl;
    arquivoVendedor << "##### DADOS FUNCIONAIS #####" << endl;
    arquivoVendedor << vendedores[tam].getMatricula() << endl;
    arquivoVendedor << vendedores[tam].getSalario() << endl;
    arquivoVendedor << vendedores[tam].getTipoVendedor() << endl;
    arquivoVendedor << vendedores[tam].getDiasFaltas() << endl;
    arquivoVendedor << "***** Data de ingresso (ano, mes, dia) ****" << endl;
    arquivoVendedor << vendedores[tam].getDataingresso().ano << endl;
    arquivoVendedor << vendedores[tam].getDataingresso().mes << endl;
    arquivoVendedor << vendedores[tam].getDataingresso().dia << endl;

    arquivoVendedor.close();

  } else if (tipoFuncionario == "Gerente") {
    fstream arquivoGerente;
    int tam = gerentes.size();
    tam -= 1;
    arquivoGerente.open("./leitura/gerente.txt", ios::in | ios::app);

    arquivoGerente
        << "#########################################################" << endl;
    arquivoGerente << "Gerente Nº: " << vendedores.size() - 1 << endl;
    arquivoGerente << "##### DADOS PESSOAIS #####" << endl;
    arquivoGerente << gerentes[tam].getNome() << endl;
    arquivoGerente << gerentes[tam].getCpf() << endl;
    arquivoGerente << gerentes[tam].getQtdFilhos() << endl;
    arquivoGerente << gerentes[tam].getEstadoCivil() << endl;
    arquivoGerente << "***** Endereço (cidade, cep, bairro, rua e numero) ****"
                   << endl;
    arquivoGerente << gerentes[tam].getEndereco().cidade << endl;
    arquivoGerente << gerentes[tam].getEndereco().cep << endl;
    arquivoGerente << gerentes[tam].getEndereco().bairro << endl;
    arquivoGerente << gerentes[tam].getEndereco().rua << endl;
    arquivoGerente << gerentes[tam].getEndereco().numero << endl;
    arquivoGerente << "***** Data de nascimento (ano, mes, dia) ****" << endl;
    arquivoGerente << gerentes[tam].getDataNascimento().ano << endl;
    arquivoGerente << gerentes[tam].getDataNascimento().mes << endl;
    arquivoGerente << gerentes[tam].getDataNascimento().dia << endl;
    arquivoGerente << "##### DADOS FUNCIONAIS #####" << endl;
    arquivoGerente << gerentes[tam].getMatricula() << endl;
    arquivoGerente << gerentes[tam].getSalario() << endl;
    arquivoGerente << gerentes[tam].getParticipacaoLucros() << endl;
    arquivoGerente << gerentes[tam].getDiasFaltas() << endl;
    arquivoGerente << "***** Data de ingresso (ano, mes, dia) ****" << endl;
    arquivoGerente << gerentes[tam].getDataingresso().ano << endl;
    arquivoGerente << gerentes[tam].getDataingresso().mes << endl;
    arquivoGerente << gerentes[tam].getDataingresso().dia << endl;

    arquivoGerente.close();
  }
}

/**
 *@brief Função que imprime as informações do funcionário no console
 *@param String tipoFuncionario recebe o texto com o tipo de funcionário que
 *será imprimido no console
 *@return Sem retorno
 */
void Empresa::imprimirNovoFuncionarioConsole(std::string tipoFuncionario) {

  cout << "#########CONTRATAR FUNCIONARIO#########" << endl;

  /** @details Verifica o tipo de funcionário e imprime as informações do último
   * funcionário que foi adicionado a lista no método de contratar*/
  if (tipoFuncionario == "ASG") {
    int tam = asgs.size();
    tam -= 1;

    cout << "Função: ASG" << asgs.size() - 1 << endl;
    cout << "Nome: " << asgs[tam].getNome() << endl;
    cout << "Cpf: " << asgs[tam].getCpf() << endl;
    cout << "Quantidade de filhos: " << asgs[tam].getQtdFilhos() << endl;
    cout << "Estado civil: " << asgs[tam].getEstadoCivil() << endl;
    cout << "Endereço: " << asgs[tam].getEndereco().cidade << ", "
         << asgs[tam].getEndereco().bairro << ", "
         << asgs[tam].getEndereco().rua << ", "
         << asgs[tam].getEndereco().numero << endl;
    cout << "Data de nascimento: " << asgs[tam].getDataNascimento().dia << "/"
         << asgs[tam].getDataNascimento().dia << "/"
         << asgs[tam].getDataNascimento().ano << endl;
    cout << "Matrícula" << asgs[tam].getMatricula() << endl;
    cout << "Salário" << asgs[tam].getSalario() << endl;
    cout << "Adicional de Insalubridade" << asgs[tam].getAdcionalInsabubridade()
         << endl;
    cout << "Dias de Faltas" << asgs[tam].getDiasFaltas() << endl;
    cout << "Data de Ingresso" << asgs[tam].getDataingresso().dia << "/"
         << asgs[tam].getDataingresso().mes << "/"
         << asgs[tam].getDataingresso().dia << endl;

  } else if (tipoFuncionario == "VENDEDOR") {
    int tam = vendedores.size();
    tam -= 1;

    cout << "Função: Vendedor" << vendedores.size() - 1 << endl;
    cout << "Nome: " << vendedores[tam].getNome() << endl;
    cout << "CPF: " << vendedores[tam].getCpf() << endl;
    cout << "Quantidade de filhos: " << vendedores[tam].getQtdFilhos() << endl;
    cout << "Estado civil: " << vendedores[tam].getEstadoCivil() << endl;
    cout << "Endereço: " << vendedores[tam].getEndereco().cidade << ", "
         << vendedores[tam].getEndereco().bairro << ", "
         << vendedores[tam].getEndereco().rua << ", "
         << vendedores[tam].getEndereco().numero << endl;
    cout << "Data de nascimento: " << vendedores[tam].getDataNascimento().dia
         << "/" << vendedores[tam].getDataNascimento().dia << "/"
         << vendedores[tam].getDataNascimento().ano << endl;
    cout << "Matrícula" << vendedores[tam].getMatricula() << endl;
    cout << "Salário" << vendedores[tam].getSalario() << endl;
    cout << "Adicional de Insalubridade" << vendedores[tam].getTipoVendedor()
         << endl;
    cout << "Dias de Faltas" << vendedores[tam].getDiasFaltas() << endl;
    cout << "Data de Ingresso" << vendedores[tam].getDataingresso().dia << "/"
         << vendedores[tam].getDataingresso().mes << "/"
         << vendedores[tam].getDataingresso().dia << endl;

  } else if (tipoFuncionario == "GERENTE") {
    int tam = asgs.size();
    tam -= 1;

    cout << "Função: GERENTE" << gerentes.size() - 1 << endl;
    cout << "Nome: " << gerentes[tam].getNome() << endl;
    cout << "Cpf: " << gerentes[tam].getCpf() << endl;
    cout << "Quantidade de filhos: " << gerentes[tam].getQtdFilhos() << endl;
    cout << "Estado civil: " << gerentes[tam].getEstadoCivil() << endl;
    cout << "Endereço: " << gerentes[tam].getEndereco().cidade << ", "
         << gerentes[tam].getEndereco().bairro << ", "
         << gerentes[tam].getEndereco().rua << ", "
         << gerentes[tam].getEndereco().numero << endl;
    cout << "Data de nascimento: " << gerentes[tam].getDataNascimento().dia
         << "/" << gerentes[tam].getDataNascimento().dia << "/"
         << gerentes[tam].getDataNascimento().ano << endl;
    cout << "Matrícula" << gerentes[tam].getMatricula() << endl;
    cout << "Salário" << gerentes[tam].getSalario() << endl;
    cout << "Participação dos Lucros: " << gerentes[tam].getParticipacaoLucros()
         << endl;
    cout << "Dias de Faltas" << gerentes[tam].getDiasFaltas() << endl;
    cout << "Data de Ingresso" << gerentes[tam].getDataingresso().dia << "/"
         << gerentes[tam].getDataingresso().mes << "/"
         << gerentes[tam].getDataingresso().ano << endl;
  }
}

/**
 *@brief Função que contrata funcionário
 *@param Nenhum
 *@return Sem retorno
 */
void Empresa::contratarFuncionario() {
  fstream arquivoNovoFuncionario;
  arquivoNovoFuncionario.open("./leitura/novoFuncionario.txt", ios::in);
  string linha;
  vector<string> informacoes;
  Data dataIngresso;

  /** @brief Verifica se o arquivo foi aberto*/
  if (!arquivoNovoFuncionario.is_open()) {
    cout << "Erro ao abrir o arquivo de novo funcionário." << endl;
    return;
  }

  /** @brief Lê as informações do funcionário */
  while (getline(arquivoNovoFuncionario, linha)) {
    if (linha.empty()) { /**<Ignora as linhas vazias*/
      continue;
    }

    /** @brief Adiciona a linha à lista de informações */
    informacoes.push_back(linha);
  }

  string tipo = informacoes[0];

  cout << endl;

  /** @brief Verifica qual o tipo de funcionário (ASG, Gerente ou Vendedor) e
   * adiciona o funcionário a lista de acordo com seu tipo, e imprime no console
   * informações do usuário contratado*/
  if (tipo == "ASG") {
    Asg asg;
    fstream arquivoAsg;
    arquivoAsg.open("./leitura/asg.txt", ios::in | ios::app);

    asg.setNome(informacoes[2]);
    asg.setCpf(informacoes[3]);
    asg.setQtdFilhos(stoi(informacoes[4]));
    asg.setEstadoCivil(informacoes[5]);

    Endereco endereco;
    endereco.cidade = informacoes[7];
    endereco.cep = informacoes[8];
    endereco.bairro = informacoes[9];
    endereco.rua = informacoes[10];
    endereco.numero = stoi(informacoes[11]);

    asg.setEndereco(endereco);

    Data dataNascimento;
    dataNascimento.ano = stoi(informacoes[13]);
    dataNascimento.mes = stoi(informacoes[14]);
    dataNascimento.dia = stoi(informacoes[15]);
    asg.setDataNascimento(dataNascimento);

    asg.setMatricula(informacoes[17]);
    asg.setSalario(stod(informacoes[18]));
    asg.setAdcionalInsabubridade(stof(informacoes[19]));
    asg.setDiasFaltas(stoi(informacoes[20]));

    dataIngresso.ano = stoi(informacoes[22]);
    dataIngresso.mes = stoi(informacoes[23]);
    dataIngresso.dia = stoi(informacoes[24]);
    asg.setDataingresso(dataIngresso);

    asgs.push_back(asg);

    imprimirNovoFuncionarioConsole("ASG");
    salvaFuncionarioArquivo("ASG");

  } else if (tipo == "Vendedor") {
    Vendedor vendedor;
    fstream arquivoVendedor;
    arquivoVendedor.open("./leitura/vendedor.txt", ios::in | ios::app);

    vendedor.setNome(informacoes[2]);
    vendedor.setCpf(informacoes[3]);
    vendedor.setQtdFilhos(stoi(informacoes[4]));
    vendedor.setEstadoCivil(informacoes[5]);

    Endereco endereco;
    endereco.cidade = informacoes[7];
    endereco.cep = informacoes[8];
    endereco.bairro = informacoes[9];
    endereco.rua = informacoes[10];
    endereco.numero = stoi(informacoes[11]);
    vendedor.setEndereco(endereco);

    Data dataNascimento;
    dataNascimento.ano = stoi(informacoes[13]);
    dataNascimento.mes = stoi(informacoes[14]);
    dataNascimento.dia = stoi(informacoes[15]);
    vendedor.setDataNascimento(dataNascimento);

    vendedor.setMatricula(informacoes[17]);
    vendedor.setSalario(stod(informacoes[18]));
    vendedor.setTipoVendedor(informacoes[19]);
    vendedor.setDiasFaltas(stof(informacoes[20]));

    dataIngresso.ano = stoi(informacoes[22]);
    dataIngresso.mes = stoi(informacoes[23]);
    dataIngresso.dia = stoi(informacoes[24]);
    vendedor.setDataingresso(dataIngresso);

    vendedores.push_back(vendedor);

    imprimirNovoFuncionarioConsole("VENDEDOR");
    salvaFuncionarioArquivo("Vendedor");

  } else if (tipo == "Gerente") {
    Gerente gerente;
    fstream arquivoGerente;
    arquivoGerente.open("./leitura/gerente.txt", ios::in | ios::app);

    gerente.setNome(informacoes[2]);
    gerente.setCpf(informacoes[3]);
    gerente.setQtdFilhos(stoi(informacoes[4]));
    gerente.setEstadoCivil(informacoes[5]);

    Endereco endereco;
    endereco.cidade = informacoes[7];
    endereco.cep = informacoes[8];
    endereco.bairro = informacoes[9];
    endereco.rua = informacoes[10];
    endereco.numero = stoi(informacoes[11]);
    gerente.setEndereco(endereco);

    Data dataNascimento;
    dataNascimento.ano = stoi(informacoes[13]);
    dataNascimento.mes = stoi(informacoes[14]);
    dataNascimento.dia = stoi(informacoes[15]);
    gerente.setDataNascimento(dataNascimento);

    gerente.setMatricula(informacoes[17]);
    gerente.setSalario(stod(informacoes[18]));
    gerente.setParticipacaoLucros(stoi(informacoes[19]));
    gerente.setDiasFaltas(stof(informacoes[20]));

    dataIngresso.ano = stoi(informacoes[22]);
    dataIngresso.mes = stoi(informacoes[23]);
    dataIngresso.dia = stoi(informacoes[24]);
    gerente.setDataingresso(dataIngresso);

    gerentes.push_back(gerente);

    imprimirNovoFuncionarioConsole("GERENTE");
    salvaFuncionarioArquivo("Gerente");
  }
}
