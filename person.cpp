#include "person.h"
#include "girokonto.h"
#include "businesskonto.h"
#include <iostream>

Person::Person(std::string name) {
  this->name = name;
}

bool Person::konto_teilen(Konto& k, Person& p) {
  return k.add_zeichnungsberechtigt(p);
}

void Person::kuendigen() {
  for(std::shared_ptr<Konto> account : konten) {
    account->zeichnungsberechtigung_loeschen(get_shared_ptr_to_person());
    bank->update_accounts(account->get_account_number(), account->get_all_zeichnungsberechtigt());
    if(account->get_all_zeichnungsberechtigt().size() < 1){
      bank->remove_account(account->get_shared_ptr_to_konto());
    }
  }
  konten.clear();
  bank->remove_client(get_shared_ptr_to_person());
}

std::shared_ptr<Konto> Person::neues_konto(bool giro) {
  std::shared_ptr<Konto> new_account;
  if(giro) {
    new_account = std::make_shared<Girokonto>();
  } else {
    new_account = std::make_shared<Businesskonto>();
  }
  new_account->setup(this->get_shared_ptr_to_person());
  return new_account;
}

std::string Person::get_name() const {
  return name;
}

std::shared_ptr<Person> Person::get_shared_ptr_to_person() {
  return shared_from_this();
}

std::vector<std::shared_ptr<Konto>> Person::get_konten() const {
  return konten;
}

void Person::add_konto(std::shared_ptr<Konto> account) {
  konten.push_back(account);
}

void Person::connect_with_bank(Bank* b) {
  this->bank = b;
}

Bank* Person::get_ref_to_bank() {
  return bank;
}

void Person::print(std::ostream& o) const {
  o << "|*** CLIENT OBJECT ***|\n";
  o << "Client Name: " << name << '\n';
  o << "|********************|\n\n";
}
