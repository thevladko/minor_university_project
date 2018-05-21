#ifndef BANK_H
#define BANK_H

class Person;
class Konto;

#include <string>
#include <memory>
#include <unordered_map>
#include "person.h"
#include "konto.h"

class Bank {
  std::unordered_map< std::string, std::vector<std::shared_ptr<Konto> > > clients_map; //name of person to the bank accounts
  std::unordered_map< std::string, std::vector<std::weak_ptr<Person> > > accounts_map; //bank account name to people that can manage it

public:
  Bank();
  std::shared_ptr<Person> neuer_kunde(std::string);
  std::unordered_map< std::string, std::vector<std::shared_ptr<Konto> > > get_clients_map() const;
  std::unordered_map< std::string, std::vector<std::weak_ptr<Person> > > get_accounts_map() const;

  void add_client(std::string, std::vector<std::shared_ptr<Konto>>);
  void add_account(std::string, std::vector<std::weak_ptr<Person>>);

  void remove_client(std::shared_ptr<Person>);
  void remove_account(std::shared_ptr<Konto>);
};

#endif
