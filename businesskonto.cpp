#include "businesskonto.h"
#include <iostream>

Businesskonto::Businesskonto() : Konto() {
  prozent = 5;
}

void Businesskonto::set_gebuehren(double betrag) {
  if(betrag < 0) {
    throw std::runtime_error("Fee cannot have negative value");
  }
  gebuehren = betrag;
}

void Businesskonto::berechne_gebuehren(int buchung) {
  gebuehren = gebuehren + (buchung * prozent)/100;
}

int Businesskonto::get_prozent() {
  return prozent;
}

void Businesskonto::einzahlen(unsigned int betrag) {
  Konto::einzahlen(betrag);
  berechne_gebuehren(betrag);
}

bool Businesskonto::auszahlen(unsigned int betrag) {
  if(Konto::auszahlen(betrag)) {
    berechne_gebuehren(betrag);
    return true;
  }
  return false;
}

bool Businesskonto::ueberweisen(unsigned int betrag, Konto& ziel) {
  if (Konto::ueberweisen(betrag, ziel)){
    berechne_gebuehren(betrag);
    return true;
  }
  return false;
}

void Businesskonto::print(std::ostream& o) const {
  o << "|*** ACCOUNT OBJECT ***|\n";
  o << "Account number: " << kontonummer << '\n';
  o << "Bank balance: " << kontostand << '\n';
  o << "Credit Boundaries: " << disporahmen << '\n';
  o << "Fees: " << gebuehren << '\n';
  o << "Percent: " << prozent << '\n';
  o << "|********************|\n\n";
}
