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

  auto vladik = bank->neuer_kunde("Vladik");
  auto gregor = bank->neuer_kunde("Gregor");

  // std::cout << vladik->get_name() << std::endl;
  // std::cout << gregor->get_name() << std::endl;

  // std::cout << "Anzahl von Konten fuer vladik: " << vladik->get_konten().size() << std::endl;
  // std::cout << "Anzahl von Konten fuer gregor: " << gregor->get_konten().size() << std::endl;

  auto konto = vladik->neues_konto();

  // std::cout << "Anzahl von Konten fuer vladik: " << vladik->get_konten().size() << std::endl;
  // std::cout << "Anzahl von Konten fuer gregor: " << gregor->get_konten().size() << std::endl;
  //
  // std::cout << "Konto ist geteilt." << std::endl;
  vladik->konto_teilen(*konto, *gregor);
  // std::cout << "Anzahl von Konten fuer gregor: " << gregor->get_konten().size() << std::endl;
  // std::cout << "Anzahl von Konten fuer vladik: " << vladik->get_konten().size() << std::endl;
  //
  // std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;
  // vladik->kuendigen();
  // std::cout << "Anzahl von Konten fuer vladik: " << vladik->get_konten().size() << std::endl;
  //
  // std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;


  // std::cout << bank->get_clients_map().size() << std::endl;
  // std::cout << bank->get_accounts_map().size() << std::endl;

  std::unordered_map< std::string, std::vector<std::shared_ptr<Konto> > > clients = bank->get_clients_map();
  std::unordered_map< std::string, std::vector<std::weak_ptr<Person> > > accounts = bank->get_accounts_map();

  std::vector<std::shared_ptr<Konto>> accounts_for_vlad = clients["Vladik"];
  std::vector<std::shared_ptr<Konto>> accounts_for_gregor = clients["Gregor"];

  std::cout << accounts_for_vlad.size() << std::endl;

  std::cout << "___________________________________________________" << std::endl;
  for(auto elem : bank->get_clients_map()) {
    std::cout << elem.first << std::endl;
  }

  std::cout << "___________________________________________________" << std::endl;

  for(auto elem : bank->get_accounts_map()) {
    std::cout << elem.first << std::endl;
  }

  std::cout << "___________________________________________________" << std::endl;

  std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;
  std::cout << "Gregor kuendigt" << std::endl;
  vladik->kuendigen();
  std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;
  std::cout << "Anzahl von Konten fuer gregor: " << gregor->get_konten().size() << std::endl;

  std::cout << "___________________________________________________" << std::endl;
  for(auto elem : bank->get_clients_map()) {
    std::cout << elem.first << std::endl;
  }

  std::cout << "___________________________________________________" << std::endl;

  for(auto elem : bank->get_accounts_map()) {
    std::cout << elem.first << std::endl;
  }

  std::cout << "___________________________________________________" << std::endl;
  std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;
  gregor->kuendigen();
  std::cout << "Anzahl von zeichnungsberechtigten fuer konto: " << konto->get_all_zeichnungsberechtigt().size() << std::endl;
  std::cout << "___________________________________________________" << std::endl;

  for(auto elem : bank->get_accounts_map()) {
    std::cout << elem.first << std::endl;
  }

  return 0;
}
