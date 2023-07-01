#include <iostream>
#include "../hpps/pessoa.hpp"

using namespace std;

Pessoa::Pessoa(){}

Pessoa::Pessoa(string nome, string cpf, Data dataNascimento, Endereco enderecoPessoal, string estadoCivil, int qtdFilhos){
    this->nome = nome;
    this->cpf = cpf;
    this->estadoCivil = estadoCivil;
    this->qtdFilhos = qtdFilhos;
    this->enderecoPessoal = enderecoPessoal;
    this->dataNascimento = dataNascimento;
}

string Pessoa::getNome(){
    return this->nome;
}

string Pessoa::getCpf(){
    return this->cpf;
}

Data Pessoa::getDataNascimento(){ 
    return this->dataNascimento; 
}

Endereco Pessoa::getEndereco(){ 
    return this->enderecoPessoal; 
}

string Pessoa::getEstadoCivil(){ 
    return this->estadoCivil; 
}

int Pessoa::getQtdFilhos(){ 
    return this->qtdFilhos; 
}

void Pessoa::setNome(string nome){ 
    this->nome = nome; 
}

void Pessoa::setCpf(string cpf){ 
    this->cpf = cpf; 
}

void Pessoa::setDataNascimento(Data dataNascimento){
    this->dataNascimento = dataNascimento;
}

void Pessoa::setEndereco(Endereco enderecoPessoal){
    this->enderecoPessoal = enderecoPessoal;
}

void Pessoa::setEstadoCivil(string estadoCivil){ 
    this->estadoCivil = estadoCivil; 
}

void Pessoa::setQtdFilhos(int qtdFilhos){ 
    this->qtdFilhos = qtdFilhos; 
}
