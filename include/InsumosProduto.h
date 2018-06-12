#ifndef INSUMOSPRODUTO_H
#define INSUMOSPRODUTO_H

#include "Insumo.h"

class InsumosProduto{

    private:
        Insumo* insumo;
        float quantidade;

    public:
        InsumosProduto();
        virtual ~InsumosProduto();

};

#endif // INSUMOSPRODUTO_H
