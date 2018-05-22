#include "konto.h"
#include <iostream>
static int counter = 0;

Konto::Konto() {
  kontonummer = std::string("AT")+std::to_string(counter++);
  kontostand = 0;
  disporahmen = 1000;
  gebuehren = 0;
}

void Konto::setup(std::shared_ptr<Person> client) {
  client->add_konto(this->get_shared_ptr_to_konto());
  this->zeichnungsberechtigt.push_back(client);
  client->get_ref_to_bank()->update_clients(client->get_name(), client->get_konten());
  client->get_ref_to_bank()->update_accounts(kontonummer, zeichnungsberechtigt);
}

bool Konto::add_zeichnungsberechtigt(Person& p) {
  if (zeichnungsberechtigt.size() <= 10) {
    zeichnungsberechtigt.push_back(p.get_shared_ptr_to_person());
    p.add_konto(this->get_shared_ptr_to_konto());
    p.get_ref_to_bank()->update_clients(p.get_name(), p.get_konten());
    p.get_ref_to_bank()->update_accounts(kontonummer, zeichnungsberechtigt);
    return true;
  }
  return false;
}


void Konto::zeichnungsberechtigung_loeschen(std::shared_ptr<Person> p) {
  for(auto it = this->zeichnungsberechtigt.begin(); it != this->zeichnungsberechtigt.end();){
    if (it->lock()->get_name() == p->get_name()) {
      it = this->zeichnungsberechtigt.erase(it);
    } else {
      ++it;
    }
  }
}

void Konto::einzahlen(unsigned int betrag) {
  kontostand += betrag;
}

bool Konto::auszahlen(unsigned int betrag) {
  if (kontostand + disporahmen >= betrag) {
    kontostand -= betrag;
    return true;
  }
  return false;
}


bool Konto::ueberweisen(unsigned int betrag, Konto& ziel) {
  if (kontostand + disporahmen >= betrag) {
    kontostand -= betrag;
    ziel.kontostand += betrag;
    return true;
  }
  // throw std::runtime_error("did not transfer. not enough credit.");
  return false;
}

std::shared_ptr<Konto> Konto::get_shared_ptr_to_konto() {
  return shared_from_this();
}

std::vector<std::weak_ptr<Person>> Konto::get_all_zeichnungsberechtigt() {
  return zeichnungsberechtigt;
}

std::string Konto::get_account_number() const {
  return kontonummer;
}

int Konto::get_kontostand() const {
  return kontostand;
}

int Konto::get_disporahmen() const {
  return disporahmen;
}

double Konto::get_gebuehren() const {
  return gebuehren;
}
