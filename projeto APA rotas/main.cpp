#include <iostream>
#include "data.h"
#include "Solucionador.h"

int main(int argc, char *argv[]) {

    Data dados;

    std::string instancia = argv[1];
    dados.read(instancia);
    //SOlucionar RESOLVEEDOR(data);
    //RESOLVEDOR.SOLVE()
    //RESOOVE.GETSPÇEI

    // dados.printInstancia();
    Solucionador solucionador(dados);
    solucionador.resolver();

    std::cout << "Minimo: " << dados.getMinSemTerceirar() << std::endl;

    return 0;
}