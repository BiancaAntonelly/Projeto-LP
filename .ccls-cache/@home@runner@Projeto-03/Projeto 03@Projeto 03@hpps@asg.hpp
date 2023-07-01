#ifndef ASG_HPP
#define ASG_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Asg : public Pessoa, public Funcionario{
    
private:
    float adicionalInsalubridade = 0.05;

public:
    Asg();
    Asg(float adicionalInsalubridade);
    float getAdcionalInsabubridade();
    void setAdcionalInsabubridade(float);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif