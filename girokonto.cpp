#include "girokonto.h"
#include <iostream>

Girokonto::Girokonto() : Konto() {
  fixgebuehren = 10.0;
}

void Girokonto::set_gebuehren(double betrag) {
  if(betrag < 0) {
    throw std::runtime_error("Fee cannot have negative value");
  }
  fixgebuehren = betrag;
}

void Girokonto::berechne_gebuehren(int betrag) {
  gebuehren += fixgebuehren;
}

double Girokonto::get_fix_gebuehren() const {
  return fixgebuehren;
}

void Girokonto::einzahlen(unsigned int betrag) {
  Konto::einzahlen(betrag);
  berechne_gebuehren(betrag);
}

bool Girokonto::auszahlen(unsigned int betrag) {
  if (Konto::auszahlen(betrag)){
    berechne_gebuehren(betrag);
    return true;
  }
  return false;
}


bool Girokonto::ueberweisen(unsigned int betrag, Konto& ziel) {
  if(Konto::ueberweisen(betrag, ziel)) {
    berechne_gebuehren(betrag);
    return true;
  }
  return false;
}

void Girokonto::print(std::ostream& o) const {
  o << "|*** ACCOUNT OBJECT ***|\n";
  o << "Account number: " << kontonummer << '\n';
  o << "Bank balance: " << kontostand << '\n';
  o << "Credit Boundaries: " << disporahmen << '\n';
  o << "Fees: " << gebuehren << '\n';
  o << "Fixed fees: " << fixgebuehren << '\n';
  o << "|********************|\n\n";
}
