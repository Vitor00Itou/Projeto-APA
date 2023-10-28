#ifndef SOLUCAO_H
#define SOLUCAO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#pragma once

class Solucao
{
public:
    Solucao();
    ~Solucao();
    std::vector<std::vector<int>>* getRotas();
    void setRotas(std::vector<std::vector<int>> rotas);
    int getCustoTotal();
    void setCustoTotal(int custoTotal);
    int getCustoRoteamento();
    void setCustoRoteamento(int custoRoteamento);
    int getCustoVeiculos();
    void setCustoVeiculos(int custoVeiculos);
    int getCustoTerceirizar();
    void setCustoTerceirizar(int custoTerceirizar);
    std::vector<int> getClientesTerceirizados();
    void setClientesTerceirizados(std::vector<int> clientesTerceirizados);
    std::vector<int>* getCustoRotas();
    void setCustoRostas(std::vector<int> custoRotas);

    void adicionarRota(std::vector<int> rota);
    void adicionarCustoRota(int custoRota);

    void printaRotas();
    void calcularCustoRoteamento();

private:
    std::vector<std::vector<int>> rotas;
    std::vector<int> custoRotas;
    int custoTotal;
    int custoRoteamento;
    int custoVeiculos;
    int custoTerceirizar;
    std::vector<int> clientesTerceirizados;

};

#endif