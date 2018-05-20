#ifndef BANK_H
#define BANK_H

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "person.h"

class Person;

class Bank {
  // std::unordered_map< std::string, std::vector<std::shared_ptr<Person> > > konten_map; //bank account name to people that can manage it
  // std::unordered_map< std::string, std::vector<std::weak_ptr<Konto> > > kunden_map; //name of person to the bank accounts
  std::vector<std::shared_ptr<Person>> kunden;

public:
  Bank();
  ~Bank();
  void neuer_kunde(std::string);
  std::shared_ptr<Person> get_kunde_for_name(std::string);
  std::vector<std::shared_ptr<Person>> get_kunden();
  void kunde_loeschen(std::shared_ptr<Person>);
};

#endif
