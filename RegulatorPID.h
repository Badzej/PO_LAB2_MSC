#pragma once
#include "ObiektSISO.h"
/**
 * @class RegulatorPID
 * @brief Klasa implementująca regulator PID
 */
class RegulatorPID : public ObiektSISO {
 double k=0;
 double ti=0;
 double td=0;
 double suma_uchybow=0;
 double poprzedni_uchyb=0;
 inline bool czyDodatnia(double wartosc_spr);
 [[nodiscard]] double obliczWyjscieP(double e) const;
 double obliczWyjscieI(double e);
 double obliczWyjscieD(double e);
public:
 explicit RegulatorPID(double p);
 explicit RegulatorPID(double p, double i);
 explicit RegulatorPID(double p, double i, double d);

 void ustawP(double p);
 void ustawPI(double p, double i);
 void ustawPID(double p, double i, double d);

 double symuluj(double e) override;
  };