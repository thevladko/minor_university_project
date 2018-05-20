#include "person.h"
#include <iostream>

Person::Person(std::string name) {
  this->name = name;
  bank = std::make_shared<Bank>();
}

Person::Person(std::string name, std::shared_ptr<Konto> k) {
  this->name = name;
  this->konten.push_back(k);
  bank = std::make_shared<Bank>();
}

Person::Person(std::string name, std::vector<std::shared_ptr<Konto>> konten) {
  this->name = name;
  this->konten = konten;
  bank = std::make_shared<Bank>();
}

Person::~Person() {}

bool Person::konto_teilen(Konto& k, Person& p) {
  return k.add_zeichnungsberechtigt(p);
}

bool Person::neues_konto() {
  auto k{std::make_shared<Konto>(this->get_shared_ptr_to_person())};
  this->konten.push_back(k);
  return true;
}

std::string Person::get_name() {
  return name;
}

void Person::kuendigen() {
  for(std::shared_ptr<Konto> account : konten) {
    // std::cout << "Num of references: " << account->get_all_zeichnungsberechtigt().size() << std::endl;
    account->zeichnungsberechtigung_loeschen(this->get_shared_ptr_to_person());
    // std::cout << "Deletion. Number of references: " << account->get_all_zeichnungsberechtigt().size() << std::endl;
  }
  // for(auto &account : konten) {
  //   std::cout << "HERE 1: " << account->get_all_zeichnungsberechtigt().size() << std::endl;
  // }
  konten.clear();
  bank->kunde_loeschen(this->get_shared_ptr_to_person());
}

std::shared_ptr<Person> Person::get_shared_ptr_to_person() {
  return shared_from_this();
}

std::vector<std::shared_ptr<Konto>> Person::get_konten() {
  return konten;
}
