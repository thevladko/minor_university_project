// Klasse Konto:
// kontonummer string
// kontostand int
// disporahmen int
// gebuehren int //oder double
// vector<std::weak_ptr<Person>> zeichnungsberechtigt //max 10 mind. 1
// void einzahlen (unsigned betrag)
// bool auszahlen (unsigned betrag)
// bool ueberweisen(unsigned betrag, Konto& ziel)
// Klasse Person:
// name string
// vector<std::shared_ptr<Konto>> konten; //beliebig viele mind. 1
// bool konto_teilen(Konto& k, Person& p)
// bool neues_konto()
// void kuendigen()
// Klasse Bank:
// void neuerKunde(string name)
// Klasse Girokonto:
// Kontoart, für die pro Buchung ein fixer Betrag als Gebuehr verbucht wird;
// Klasse Businesskonto:
// Kontoart, für die ein festgelegter Prozentsatz vom Buchungsbetrag als Gebühr verbucht wird ;
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>
#include "konto.h"
#include "person.h"
#include "bank.h"
#include "girokonto.h"
#include "businesskonto.h"

int main() {

  auto bank = std::make_shared<Bank>();

  auto mark = bank->neuer_kunde("Mark");
  auto gregor = bank->neuer_kunde("Gregor");
  auto maria = bank->neuer_kunde("Maria");

  auto konto = mark->neues_konto(false);

  mark->konto_teilen(*konto, *gregor);
  mark->konto_teilen(*konto, *maria);

  mark->get_konten()[0]->ueberweisen(95, *konto);

  bank->print_clients(std::cout);
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________\n\n";
  bank->print_accounts(std::cout);

  mark->kuendigen();
  maria->kuendigen();
  gregor->kuendigen();

  bank->print_clients(std::cout);
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________\n\n";
  bank->print_accounts(std::cout);

  return 0;
}
