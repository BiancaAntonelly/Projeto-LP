#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
#include <iostream>
#include "util.hpp"

class Funcionario {
private:
    float salario;
    int diasFaltas;
    std::string matricula;
    Data ingressoEmpresa;

public:
    virtual float calcularSalario(int diasFaltas) = 0;
    virtual float calcularRecisao(Data desligamento) = 0;
    float getSalario();
    std::string getMatricula();
    Data getDataingresso();
    void setSalario(float salario);
    void setMatricula(std::string matricula);
    void setDataingresso(Data ingressoEmpresa);
    int getDiasFaltas();
    void setDiasFaltas(int diasFaltas);
};

#endif