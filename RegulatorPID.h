#pragma once
#include "ObiektSISO.h"
#include <vector>
// TODO: funktor
/**
 * @class RegulatorPID
 * @brief Klasa implementująca regulator PID
 * Człon proporcjonalny - P y(t) = k * x(t)
 * Człon całkujący(integral) - y(t) = k calka(0,t)x(tau)d(tau)
 * Człon różniczkujący (differential) - y(t) = kd d/dt e(t)
 */
class RegulatorPID : public ObiektSISO {
 double kp=0;
 double ki=0;
 double kd=0;
 double suma_uchybow=0;
 double poprzednia_wartosc;
 bool sprawdzCzyDodatnia(double wartosc_spr);
 double obliczP(double e);
 double obliczI(double e);
 double obliczD(double e);
public:
 explicit RegulatorPID(double p);
 explicit RegulatorPID(double p, double i);
 explicit RegulatorPID(double p, double i, double d);

 void ustawP(double p);
 void ustawPI(double p, double i);
 void ustawPID(double p, double i, double d);

 double symuluj(double e) override;
  };