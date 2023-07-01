#include <iostream>
#include "../hpps/gerente.hpp"
using namespace std;

Gerente::Gerente(){

};  

Gerente::Gerente(float participacaoLucros){
    this->participacaoLucros = participacaoLucros;
};

float Gerente::getParticipacaoLucros(){ 
    return this->participacaoLucros; 
}

void Gerente::setParticipacaoLucros(float participacaoLucros){
    this->participacaoLucros = participacaoLucros;
}

float Gerente::calcularSalario(int diasFaltas){
    float precoDia = getSalario() / 30;     // valor do dia
    float desconto = precoDia * diasFaltas; // descontos de falta
    float salarioMes = (getSalario() - desconto) + this->participacaoLucros;
    return salarioMes;
}

float Gerente::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getDataingresso().ano;
    float meses = (desligamento.mes + 11) - getDataingresso().mes;
    float dias = (desligamento.dia + 30) - getDataingresso().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
}