#include <iostream>
#include "../hpps/vendedor.hpp"
using namespace std;

Vendedor::Vendedor(){}

Vendedor::Vendedor(char tipoVendedor){ 
    this->tipoVendedor = tipoVendedor;
}

string Vendedor::getTipoVendedor(){ 
    return this->tipoVendedor; 
}

void Vendedor::setTipoVendedor(string tipoVendedor){ 
    this->tipoVendedor = tipoVendedor; 
}

float Vendedor::calcularSalario(int diasFaltas){
    float precoDia = getSalario()/30;     
    float desconto = precoDia * diasFaltas;
    float salarioMes = (getSalario() - desconto); 

    if (this->tipoVendedor == "A") {
        salarioMes *= (1 + 0.25);
    }
    else if (this->tipoVendedor == "B"){
        salarioMes *= (1 + 0.10);
    }
    else{
        salarioMes *= (1 + 0.05);
    }
    return salarioMes;
}

float Vendedor::calcularRecisao(Data desligamento){
    float anos = (desligamento.ano - 1) - getDataingresso().ano;
    float meses = (desligamento.mes + 11) - getDataingresso().mes;
    float dias = (desligamento.dia + 30) - getDataingresso().dia;
    float totalAnos = anos + (meses / 12) + (dias / 365);
    float valorRecisao = totalAnos * getSalario();
    return valorRecisao;
}