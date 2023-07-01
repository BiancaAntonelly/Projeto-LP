#include <iostream>
#include "../hpps/asg.hpp"
using namespace std;

Asg::Asg(){}

Asg::Asg(float adicionalInsalubridade){
    this->adicionalInsalubridade = adicionalInsalubridade;
}

float Asg::getAdcionalInsabubridade(){
    return this->adicionalInsalubridade;
}

void Asg::setAdcionalInsabubridade(float){
    this->adicionalInsalubridade = adicionalInsalubridade;
}

float Asg::calcularSalario(int diasFaltas){
    float precoDia = getSalario()/30; 
    float desconto = precoDia * diasFaltas;
    float salarioMes = (getSalario() - desconto) * (1 + adicionalInsalubridade); 
    return salarioMes;
}

float Asg::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getDataingresso().ano; 
    float meses = (desligamento.mes + 11) - getDataingresso().mes;
    float dias = (desligamento.dia + 30) - getDataingresso().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
}

