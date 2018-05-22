#include "girokonto.h"

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

void Girokonto::print(std::ostream& o) const {

}
