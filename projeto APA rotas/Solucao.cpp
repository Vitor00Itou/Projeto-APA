#include "Solucao.h"

Solucao::Solucao()
{

}

Solucao::~Solucao()
{

}

std::vector<std::vector<int>>* Solucao::getRotas()
{
    return &(this->rotas);
}

void Solucao::setRotas(std::vector<std::vector<int>> rotas)
{
    this->rotas = rotas;
}

int Solucao::getCustoTotal()
{
    return this->custoTotal;
}

void Solucao::setCustoTotal(int custoTotal)
{
    this->custoTotal = custoTotal;
}

int Solucao::getCustoRoteamento()
{
    return this->custoRoteamento;
}

void Solucao::setCustoRoteamento(int custoRoteamento)
{
    this->custoRoteamento = custoRoteamento;
}


int Solucao::getCustoVeiculos()
{
    return this->custoVeiculos;
}


void Solucao::setCustoVeiculos(int custoVeiculos)
{
    this->custoVeiculos = custoVeiculos;
}

int Solucao::getCustoTerceirizar()
{
    return this->custoTerceirizar;
}


void Solucao::setCustoTerceirizar(int custoTerceirizar)
{
    this->custoTerceirizar = custoTerceirizar;
}


std::vector<int> Solucao::getClientesTerceirizados()
{
    return this->clientesTerceirizados;
}


void Solucao::setClientesTerceirizados(std::vector<int> clientesTerceirizados)
{
    this->clientesTerceirizados = clientesTerceirizados;
}

std::vector<int>* Solucao::getCustoRotas(){
    return &(this->custoRotas);
}

void Solucao::setCustoRostas(std::vector<int> custoRotas){
    this->custoRotas = custoRotas;
}

void Solucao::adicionarRota(std::vector<int> rota){
    this->rotas.push_back(rota);
}

void Solucao::adicionarCustoRota(int custoRota){
    this->custoRotas.push_back(custoRota);
}

void Solucao::printaRotas(){
    int count = 0;
    for (int i = 0; i < rotas.size(); i++)
    {
        for (int j = 0; j < rotas[i].size(); j++)
        {
            std::cout << rotas[i][j] << " ";
            count++;
        }
        std::cout << " " << std::endl;
        
    }

    std::cout << "Sem terceirização: " << count << std::endl;
    
}

void Solucao::calcularCustoRoteamento(){
    int custototal = 0;

    for (int i = 0; i < custoRotas.size(); i++)
    {
        custototal += custoRotas[i];
    }
    
    this->custoRoteamento = custototal;
}