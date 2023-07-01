#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Gerente : public Pessoa, public Funcionario{

private:
    float participacaoLucros;

public:
    Gerente();  
    Gerente(float participacaoLucros);
    float getParticipacaoLucros();
    void setParticipacaoLucros(float participacaoLucros);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif