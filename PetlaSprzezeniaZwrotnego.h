#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

class PetlaSprzezeniaZwrotnego {
public:
    double operator()(RegulatorPID& regulator, ModelARX& model, double wartosc_zadana = 1.0) ;
};