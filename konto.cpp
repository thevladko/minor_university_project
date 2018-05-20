#include "konto.h"
#include <iostream>
static int counter = 0;

Konto::Konto(std::shared_ptr<Person> zeichnungsberechtigt) {
  kontonummer = std::string("AT")+std::to_string(counter++);
  kontostand = 0;
  disporahmen = 0;
  this->zeichnungsberechtigt.push_back(zeichnungsberechtigt);
}

Konto::Konto(std::vector<std::weak_ptr<Person>> zeichnungsberechtigt) {
  kontonummer = std::string("AT")+std::to_string(counter++);
  kontostand = 0;
  disporahmen = 0;
  this->zeichnungsberechtigt = zeichnungsberechtigt;
}

Konto::~Konto() {}

void Konto::einzahlen(unsigned int betrag) {
  kontostand += betrag;
}

//TODO: take into account the credit limit of the bank account "disporahmen"
bool Konto::auszahlen(unsigned int betrag) {
  if (kontostand >= betrag) {
    kontostand -= betrag;
    return true;
  }
  return false;
}

bool Konto::ueberweisen(unsigned int betrag, Konto& ziel) {
  if (kontostand >= betrag) {
    kontostand -= betrag;
    ziel.kontostand += betrag;
    return true;
  }
  return false;
}

bool Konto::add_zeichnungsberechtigt(Person& p) {
  if (zeichnungsberechtigt.size() == 10) {
    return false;
  }
  zeichnungsberechtigt.push_back(p.get_shared_ptr_to_person());
  p.get_konten().push_back(this->get_shared_ptr_to_konto());
  return true;
}

std::shared_ptr<Konto> Konto::get_shared_ptr_to_konto() {
  return shared_from_this();
}

std::vector<std::weak_ptr<Person>> Konto::get_all_zeichnungsberechtigt() {
  return zeichnungsberechtigt;
}

void Konto::zeichnungsberechtigung_loeschen(std::shared_ptr<Person> p) {
  for(auto it = this->zeichnungsberechtigt.begin(); it != this->zeichnungsberechtigt.end();){
    if (it->lock()->get_name() == p->get_name()) {
      it = this->zeichnungsberechtigt.erase(it);
    } else {
      ++it;
    }
  }
  // std::cout << "HERE " << zeichnungsberechtigt.size() << std::endl;
}
