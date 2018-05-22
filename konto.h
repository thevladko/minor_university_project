#ifndef KONTO_H
#define KONTO_H

class Person;
class Bank;
#include <memory>
#include <vector>
#include <string>
#include "person.h"
#include "bank.h"

class Konto : public std::enable_shared_from_this<Konto> {
protected:
  std::string kontonummer;
  int kontostand;
  int disporahmen;
  std::vector<std::weak_ptr<Person>> zeichnungsberechtigt;
  double gebuehren;

public:
  Konto();
  std::string get_account_number() const;
  int get_kontostand() const;
  int get_disporahmen() const;
  double get_gebuehren() const;
  virtual void einzahlen(unsigned int);
  virtual bool auszahlen(unsigned int);
  virtual bool ueberweisen(unsigned int, Konto&);
  bool add_zeichnungsberechtigt(Person&);
  void zeichnungsberechtigung_loeschen(std::shared_ptr<Person>);
  void setup(std::shared_ptr<Person>);
  std::shared_ptr<Konto> get_shared_ptr_to_konto();
  std::vector<std::weak_ptr<Person>> get_all_zeichnungsberechtigt();
  virtual void print(std::ostream&) const = 0;
  virtual void berechne_gebuehren(int) = 0;
  virtual void set_gebuehren(double){}
};

#endif
