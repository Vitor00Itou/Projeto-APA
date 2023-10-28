#ifndef DATA_H
#define DATA_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Data {

    public:
        Data();
        void read(std::string);
        void printInstancia();
        int getQtdClientes();
        int getQtdVeiculos();
        int getCapacidadeVeiculos();
        int getMinSemTerceirar();
        int getCustoVeiculo();
        std::vector<int>* getDemandas();
        std::vector<int>* getCustoTerceirizacao();
        std::vector<std::vector<int>>* getCustos();

    private:
        
        int qtdClientes;
        int qtdVeiculos;
        int capacidadeVeiculos;
        int minSemTerceirar;
        int custoVeiculo;
        std::vector<int> demandas;
        std::vector<int> custoTerceirizacao;
        std::vector<std::vector<int>> custos;
};

#endif 