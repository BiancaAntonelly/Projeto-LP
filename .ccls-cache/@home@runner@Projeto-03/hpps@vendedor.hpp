#ifndef VENDEDOR_HPP
#define VENDEDOR_HPP
#include <iostream>
#include "pessoa.hpp"
#include "funcionario.hpp"

class Vendedor : public Pessoa, public Funcionario{

private:
    std::string tipoVendedor; // A, B, C

public:
    Vendedor();
    Vendedor(char tipoVendedor);
    std::string getTipoVendedor();
    void setTipoVendedor(std::string tipoVendedor);
    float calcularSalario(int diasFaltas);
    float calcularRecisao(Data desligamento);
};

#endif