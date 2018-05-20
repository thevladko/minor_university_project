#include "bank.h"
#include <iostream>

Bank::Bank() {}

Bank::~Bank() {}

void Bank::neuer_kunde(std::string name) {
  auto kunde = std::make_shared<Person>(name);
  kunde->neues_konto();
  this->kunden.push_back(kunde);
}

std::shared_ptr<Person> Bank::get_kunde_for_name(std::string name) {
  std::shared_ptr<Person> kunde;
  for(const auto& elem : kunden){
    if (elem->get_name() == name) {
      kunde = elem;
    }
  }
  return kunde;
}

std::vector<std::shared_ptr<Person>> Bank::get_kunden() {
  return kunden;
}

//reset on pointer
//delete from vector

void Bank::kunde_loeschen(std::shared_ptr<Person> p){
  for(auto it = kunden.begin(); it != kunden.end();){
    if((*it)->get_name() == p->get_name()) {
      it = this->kunden.erase(it);
    } else {
      ++it;
    }
  }
}
