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
  std::shared_ptr<Bank> bank;
  std::string name;
  std::vector<std::shared_ptr<Konto>> konten;

public:
  Person(std::string);
  Person(std::string, std::shared_ptr<Konto>);
  Person(std::string, std::vector<std::shared_ptr<Konto>>);
  ~Person();
  bool konto_teilen(Konto&, Person&);
  bool neues_konto();
  void kuendigen();
  std::string get_name();
  std::shared_ptr<Person> get_shared_ptr_to_person();
  std::vector<std::shared_ptr<Konto>> get_konten();
};


#endif
