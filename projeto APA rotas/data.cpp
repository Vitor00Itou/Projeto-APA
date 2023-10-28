#include "data.h"

Data::Data() {

}

void Data::read(std::string arquivo) {

    std::ifstream instancia;
    instancia.open(arquivo, std::ifstream::in);

    instancia >> qtdClientes;
    instancia >> qtdVeiculos;
    instancia >> capacidadeVeiculos;
    instancia >> minSemTerceirar;
    instancia >> custoVeiculo;

    int aux;
    for(int i = 0; i < qtdClientes; i++) {
        instancia >> aux;
        demandas.push_back(aux);
    }

    for(int i = 0; i < qtdClientes; i++) {
        instancia >> aux;
        custoTerceirizacao.push_back(aux);
    }

    for(int i = 0; i <= qtdClientes; i++) {
        std::vector<int> aux_vector;
        for(int j = 0; j <= qtdClientes; j++) {
            instancia >> aux;
            aux_vector.push_back(aux);
        }
        custos.push_back(aux_vector);
    }

    instancia.close();
    
    return;
}

void Data::printInstancia() {

    std::cout << qtdClientes << std::endl;
    std::cout << qtdVeiculos << std::endl;
    std::cout << capacidadeVeiculos << std:: endl;
    std::cout << minSemTerceirar << std::endl;
    std::cout << custoVeiculo << std::endl;

    std::cout << std::endl;
    for (int d : demandas) {
        std::cout << d << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    for (int c : custoTerceirizacao) {
        std::cout << c << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for(std::vector<int> i : custos) {
        for(int c : i) {
            std::cout << c << " ";
        }
        std::cout << std::endl;
    }

}

int Data::getQtdClientes() {
    return qtdClientes;
}

int Data::getQtdVeiculos() {
    return qtdVeiculos;
}

int Data::getCapacidadeVeiculos() {
    return capacidadeVeiculos;
}

int Data::getMinSemTerceirar() {
    return minSemTerceirar;
}

int Data::getCustoVeiculo() {
    return custoVeiculo;
}

std::vector<int>* Data::getDemandas() {
    return &demandas;
}


std::vector<int>* Data::getCustoTerceirizacao() {
    return &custoTerceirizacao;
}

std::vector<std::vector<int>>* Data::getCustos() {
    return &custos;
}
