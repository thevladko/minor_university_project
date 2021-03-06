#include "bank.h"
#include <iostream>

Bank::Bank() {}

std::shared_ptr<Person> Bank::neuer_kunde(std::string name) {
  auto new_client{std::make_shared<Person>(name)};
  new_client->connect_with_bank(this);
  new_client->neues_konto(true);
  return new_client;
}

std::unordered_map< std::string, std::vector<std::shared_ptr<Konto> > > Bank::get_clients_map() const {
  return clients_map;
}

std::unordered_map< std::string, std::vector<std::weak_ptr<Person> > > Bank::get_accounts_map() const {
  return accounts_map;
}

void Bank::update_clients(std::string name, std::vector<std::shared_ptr<Konto>> accounts) {
  clients_map[name] = accounts;
}

void Bank::update_accounts(std::string number, std::vector<std::weak_ptr<Person>> authorized_clients) {
  accounts_map[number] = authorized_clients;
}

void Bank::remove_client(std::shared_ptr<Person> p) {
  for(auto it = clients_map.begin(); it != clients_map.end();){
    if(it->first == p->get_name()) {
      it = clients_map.erase(it);
    } else {
      ++it;
    }
  }
}

void Bank::remove_account(std::shared_ptr<Konto> k) {
  for(auto it = accounts_map.begin(); it != accounts_map.end();){
    if(it->first == k->get_account_number()) {
      it = accounts_map.erase(it);
    } else {
      ++it;
    }
  }
}

void Bank::print_clients(std::ostream& o) const {
  o << "|*** BANK CLIENTS ***|\n\n";
  o << "|############################################################|\n\n";
  for(auto elem : clients_map){
    o << "|*** NAME ***|\n";
    o << elem.first << ": \n\n";
    o << "|*** ACCOUNTS MANAGED BY CLIENT ***|\n\n";
    for(auto account : elem.second) {
      account->print(std::cout);
    }
    o << "|############################################################|\n\n";
  }
}


void Bank::print_accounts(std::ostream& o) const {
  o << "|*** BANK ACCOUNTS ***|\n\n";
  o << "|############################################################|\n\n";
  for(auto elem : accounts_map){
    o << "|*** IBAN ***|\n";
    o << elem.first << ": \n\n";
    o << "|*** CLIENTS THAT MANAGE THIS ACCOUNT ***|\n\n";
    for(auto client : elem.second) {
      client.lock()->print(std::cout);
    }
    o << "|############################################################|\n\n";
  }
}
