#include "RegulatorPID.h"
#include <vector>
#include <iostream>

RegulatorPID::RegulatorPID(double p, double i, double d) : kp(p), ki(i), kd(d){}

RegulatorPID::RegulatorPID(double p, double i): kp(p), ki(i){}

RegulatorPID::RegulatorPID(double p): kp(p){}

bool RegulatorPID::sprawdzCzyDodatnia(double wartosc_spr){
  if(wartosc_spr >= 0){
    return true;
  }
  return false;
}

double RegulatorPID::obliczP(double e){
  return  e*kp;
 }

double RegulatorPID::obliczI(double e){
   double u = 1.0/ki*(suma_uchybow);
   if(sprawdzCzyDodatnia(u))
      return u;
   return 0;
  };

double RegulatorPID::obliczD(double e){
  double u = kd*(e-poprzednia_wartosc);
  if(sprawdzCzyDodatnia(u))
    return u;
  return 0;
  };

void RegulatorPID::ustawP(double p){
  if(sprawdzCzyDodatnia(p))  kp=p;
  std::cerr << "Nastawa czesci proporcjonalnej nie moze byc ujemna: p=" << p << std::endl;
}

void RegulatorPID::ustawPI(double p, double i){
  if(sprawdzCzyDodatnia(p) && sprawdzCzyDodatnia(i)) { kp=p; ki=i; }
  std::cerr << "Nastawy czesci proporcjonalnej i całkującej nie moga byc ujemne: p=" << p << " i=" << i << std::endl;
}

void RegulatorPID::ustawPID(double p, double i, double d){
  if(sprawdzCzyDodatnia(p) && sprawdzCzyDodatnia(i) && sprawdzCzyDodatnia(d)) { kp=p; ki=i; kd=d; }
  std::cerr << "Nastawy czesci proporcjonalnej, całkującej i rozniczkujacej nie moga byc ujemne: p=" << p << " i=" << i << " d=" << d << std::endl;
}

double RegulatorPID::symuluj(double e){
  double u=0;
  suma_uchybow += e;
  if(ki == 0 && kd == 0)
    u = obliczP(e);
  else if (kd == 0)
    u = obliczP(e)+ obliczI(e);
  else
    u = obliczP(e) + obliczI(e) + obliczD(e);
  poprzednia_wartosc = e;
  return u;
}