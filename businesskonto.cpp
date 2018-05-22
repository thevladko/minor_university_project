#include "businesskonto.h"

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

void Businesskonto::print(std::ostream& o) const{

}
