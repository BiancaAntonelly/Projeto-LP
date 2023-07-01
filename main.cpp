#include "./hpps/empresa.hpp"
#include <iostream>
#include <vector>

/**
 *@brief Classe de execução do projeto
 *@param Nenhum
 *@return Retorna o valor zero
 *@author Bianca Antonelly, Vanessa Maria
 *@version 1.1.1
 */
int main() {
  Empresa *atacadaoDosCalcados = new Empresa(); /**<Objeto empresa */
  atacadaoDosCalcados->carregaFuncoes(); /**<Carrega as funções do sistema*/
  return 0;
}