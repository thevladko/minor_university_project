#ifndef PERSON_H
#define PERSON_H

class Konto;
class Bank;
#include <memory>
#include <vector>
#include <string>
#include "bank.h"
#include "konto.h"

class Person : public std::enable_shared_from_this<Person> {
  Bank* bank;
  std::string name;
  std::vector<std::shared_ptr<Konto>> konten;

public:
  Person(std::string);
  bool konto_teilen(Konto&, Person&);
  //TODO::change return type of neues_konto() back to bool
  std::shared_ptr<Konto> neues_konto();
  void kuendigen();
  std::string get_name() const;
  std::shared_ptr<Person> get_shared_ptr_to_person();
  std::vector<std::shared_ptr<Konto>> get_konten() const;
  void add_konto(std::shared_ptr<Konto>);
  void connect_with_bank(Bank*);
  Bank* get_ref_to_bank();
  void print(std::ostream&) const;
};

#endif
