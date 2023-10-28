#include "solucionador.h"


Solucionador::Solucionador(Data instancia) {
    this->instancia = instancia;
}

Solucionador::~Solucionador()
{

}

Solucao Solucionador::construtor()
{
    Solucao construindoSolucao;
    std::vector<int> candidatos;

    std::vector<std::vector<int>>* matrizCustos = instancia.getCustos();
    std::vector<int>* demandas = instancia.getDemandas();

    //std::cout << (*matrizCustos)[0][0] << std::endl;

    for (int i = 1; i <= instancia.getQtdClientes(); i++)
    {
        candidatos.push_back(i);
    }

    for (int i = 0; i < instancia.getQtdVeiculos(); i++)
    {
        if (candidatos.empty())
        {
            break;
        }
        
        std::vector<int> novaRota;
        int custoRota = 0;
        int cargaRestante = instancia.getCapacidadeVeiculos();
        int posMelhorCandidato;
        int custoInsercaoAtual;
        int flagZeroChecagens = 1;
        int menorCusto;
        
        while (1)
        {
            flagZeroChecagens = 1;
            menorCusto = std::numeric_limits<int>::max(); //menorCusto = inf
            for (unsigned int j = 0; j < candidatos.size(); j++)
            {
                if ((*demandas)[candidatos[j]-1] > cargaRestante)
                {
                    continue;
                }
                flagZeroChecagens = 0;

                if (novaRota.empty())
                {
                    custoInsercaoAtual = (*matrizCustos)[0][candidatos[j]] + (*matrizCustos)[candidatos[j]][0];
                    
                }else{
                    custoInsercaoAtual = (*matrizCustos)[novaRota.back()][candidatos[j]] + (*matrizCustos)[candidatos[j]][0] - (*matrizCustos)[novaRota.back()][0];

                }

                if (custoInsercaoAtual < menorCusto){
                    menorCusto = custoInsercaoAtual;
                    posMelhorCandidato = j;
                }
            }
            if (flagZeroChecagens)
            {
                break;
            }

            //inserção do candidato na rota atual e romação da lista de candidatos
            cargaRestante -= (*demandas)[candidatos[posMelhorCandidato]-1];
            novaRota.push_back(candidatos[posMelhorCandidato]);
            candidatos.erase(candidatos.begin() + posMelhorCandidato);
            custoRota += menorCusto;

        }

        //Adiciona a rota criada à solução atual
        construindoSolucao.adicionarRota(novaRota);
        construindoSolucao.adicionarCustoRota(custoRota);
       
    }

    //Terceriza todos os candidatos que não entraram em nenhuma rota
    construindoSolucao.setClientesTerceirizados(candidatos);

    //Guarda a solução construida pelo guloso
    this->solucaoConstruida = construindoSolucao;
    return construindoSolucao;
}


Solucao Solucionador::VND() {

    int i = 0;

    switch (i)
    {
    case 1:
        // vizinhanca1()
        
        break;
    case 2:
        break;
    case 3:
        break;

    
    }
    
}
Solucao Solucionador::resolver() {

    this->construtor();
    //this->VND();

    solucaoConstruida.printaRotas();
    solucaoConstruida.calcularCustoRoteamento();

    std::cout << "Custo roteamento:" << solucaoConstruida.getCustoRoteamento() << std::endl;

    //instancia.printInstancia();
    while (reinsercao())
    {
        std::cout << "reinsercao" << std::endl;
    }
    
    solucaoConstruida.printaRotas();
    solucaoConstruida.calcularCustoRoteamento();

    std::cout << "Custo roteamento:" << solucaoConstruida.getCustoRoteamento() << std::endl;

    return this->solucaoConstruida;
}

bool Solucionador::reinsercao() {

    std::vector<std::vector<int>>* rotas = this->solucaoConstruida.getRotas();
    std::vector<std::vector<int>>* custos = this->instancia.getCustos();
    std::vector<int>* custoRotas = this->solucaoConstruida.getCustoRotas();
    int custoReinsercaoMenor;
    int custoReinsercaoAtual;
    int custoParcialInserir, custoParcialRemover;
    int melhorInsercaoOrigem, melhorInsercaoDestino;
    bool solucaoAlterada = false;
    int aux;

    for (size_t k = 0; k < rotas->size(); k++)
    {

        while (1) //while para otimizar a rota exaustivamente até que não haja mais otimizações possíveis
        {
            custoReinsercaoMenor = 0;

            
            for (size_t i = 0; i < (*rotas)[k].size(); i++)
            {

                for (size_t j = i+1; j < (*rotas)[k].size(); j++)
                {


                    if (j == (*rotas)[k].size()-1)
                    {
                        custoParcialInserir = (*custos)[(*rotas)[k][j]][(*rotas)[k][i]] + (*custos)[(*rotas)[k][i]][0] - (*custos)[(*rotas)[k][j]][0];
                    }else{
                        custoParcialInserir = (*custos)[(*rotas)[k][j]][(*rotas)[k][i]] + (*custos)[(*rotas)[k][i]][(*rotas)[k][j+1]] - (*custos)[(*rotas)[k][j]][(*rotas)[k][j+1]];
                    }

                    if (i == 0)
                    {
                        custoParcialRemover = (*custos)[0][(*rotas)[k][i+1]] - (*custos)[0][(*rotas)[k][i]] - (*custos)[(*rotas)[k][i]][(*rotas)[k][i+1]];
                    }else{
                        custoParcialRemover = (*custos)[(*rotas)[k][i-1]][(*rotas)[k][i+1]] - (*custos)[(*rotas)[k][i-1]][(*rotas)[k][i]] - (*custos)[(*rotas)[k][i]][(*rotas)[k][i+1]];
                    }

                    custoReinsercaoAtual = custoParcialInserir + custoParcialRemover;

                    if (custoReinsercaoAtual < custoReinsercaoMenor){
                        custoReinsercaoMenor = custoReinsercaoAtual;
                        melhorInsercaoDestino = j;
                        melhorInsercaoOrigem = i;
                    }
                    
                    
                }
        
                for (int j = i-2; j >= 0; j--)
                {
                    
                    if (j == 0)
                    {
                        custoParcialInserir = (*custos)[0][(*rotas)[k][i]] + (*custos)[(*rotas)[k][i]][(*rotas)[k][j]] - (*custos)[0][(*rotas)[k][j]]; //(custo do deposito até o cliente i) + (custo do cliente i até o cliente j) - (custo do deposito até o cliente j)
                    }else{
                        custoParcialInserir = (*custos)[(*rotas)[k][j-1]][(*rotas)[k][i]] + (*custos)[(*rotas)[k][i]][(*rotas)[k][j]] - (*custos)[(*rotas)[k][j-1]][(*rotas)[k][j]]; //(custo do cliente i-1 até o cliente i) + (custo do cliente i até o cliente j) - (custo do cliente i-1 até o cliente j)
                    }
                    if (i == (*rotas)[k].size()-1)
                    {
                        custoParcialRemover = (*custos)[(*rotas)[k][i-1]][0] - (*custos)[(*rotas)[k][i]][0] - (*custos)[(*rotas)[k][i-1]][(*rotas)[k][i]]; //(custo do cliente i-1 até o depósito) - (custo do cliente i até o depósito) - (custo do cliente i-1 até o cliente i)
                    }else{
                        custoParcialRemover = (*custos)[(*rotas)[k][i-1]][(*rotas)[k][i+1]] - (*custos)[(*rotas)[k][i]][(*rotas)[k][i+1]] - (*custos)[(*rotas)[k][i-1]][(*rotas)[k][i]]; //(custo do cliente i-1 até o cliente i+1) - (custo do cliente i até o cliente i+1) - (custo do cliente i-1 até o cliente i)
                    }
                    
                    custoReinsercaoAtual = custoParcialInserir + custoParcialRemover;

                    if (custoReinsercaoAtual < custoReinsercaoMenor){
                        custoReinsercaoMenor = custoReinsercaoAtual;
                        melhorInsercaoDestino = j;
                        melhorInsercaoOrigem = i;
                    }
                
                } 
                
                
            }

            if (custoReinsercaoMenor == 0) //caso nenhuma das reiserções apresentem custos menor que o custo atual, saimos do while
            {
                break;
            }

            //Atualiza a rota com a melhor inserção possível

            (*custoRotas)[k] += custoReinsercaoMenor;
            aux = (*rotas)[k][melhorInsercaoOrigem];
            (rotas)->at(k).erase((*rotas)[k].begin() + melhorInsercaoOrigem);
            (rotas)->at(k).insert((*rotas)[k].begin() + melhorInsercaoDestino, aux);

            solucaoAlterada = true;
            
        }
        
    }
    
    return solucaoAlterada;
}