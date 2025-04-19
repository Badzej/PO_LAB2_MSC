#include "PetlaSprzezeniaZwrotnego.h"
#include <deque>
    double PetlaSprzezeniaZwrotnego::operator()(RegulatorPID& regulator, ModelARX& model, double wartosc_zadana) {
        // Zakładamy, że ostatnie wyjście to ostatnia wartość z y_hist
        double poprzednie_wyjscie = model.pobierzOstatnieWyjscie();
        // Oblicz uchyb
        double uchyb = wartosc_zadana - poprzednie_wyjscie;

        // Regulator liczy sygnał sterujący
        double sterowanie = regulator.symuluj(uchyb);

        // Model symuluje kolejny krok i zwraca nową wartość wyjściową
        double wyjscie = model.symuluj(sterowanie);

        // Zwracamy wartość regulowaną
        return wyjscie;
    }