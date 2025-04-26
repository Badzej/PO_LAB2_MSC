#pragma once
#include "ModelARX.h"
#include "RegulatorPID.h"

class PetlaSprzezeniaZwrotnego {
public:
    [[nodiscard]] double operator()(RegulatorPID& regulator, ModelARX& model, double wartosc_zadana = 1.0) ;
};