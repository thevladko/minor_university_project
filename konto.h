#ifndef KONTO_H
#define KONTO_H

class Person;
#include <memory>
#include <vector>
#include <string>
#include "person.h"

class Konto : public std::enable_shared_from_this<Konto> {
protected:
  std::string kontonummer;
  int kontostand;
  int disporahmen;
  std::vector<std::weak_ptr<Person>> zeichnungsberechtigt;
  double gebuehren;

public:
  Konto(std::shared_ptr<Person>);
  Konto(std::vector<std::weak_ptr<Person>>);
  ~Konto();
  void einzahlen(unsigned int);
  bool auszahlen(unsigned int);
  bool ueberweisen(unsigned int, Konto&);
  bool add_zeichnungsberechtigt(Person&);
  void zeichnungsberechtigung_loeschen(std::shared_ptr<Person>);
  std::shared_ptr<Konto> get_shared_ptr_to_konto();
  std::vector<std::weak_ptr<Person>> get_all_zeichnungsberechtigt();
};

#endif
