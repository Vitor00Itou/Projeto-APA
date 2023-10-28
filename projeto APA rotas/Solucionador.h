#ifndef SOLUCIONAR_H
#define SOLUCIONAR_H
#include "data.h"
#include "Solucao.h"
#include <limits>

#pragma once

class Solucionador
{
public:
    Solucionador(Data instancia);
    ~Solucionador();
    Solucao resolver();

private:
    Data instancia;
    Solucao solucaoConstruida;
    Solucao construtor();
    Solucao VND();
    bool reinsercao();

};

#endif