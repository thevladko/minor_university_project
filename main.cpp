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

  std::cout << "Hello World!";

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

  bank->print_clients(std::cout);
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________\n\n";
  bank->print_accounts(std::cout);

  maria->kuendigen();

  bank->print_clients(std::cout);
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________" << std::endl;
  std::cout << "___________________________________________________________________________________________\n\n";
  bank->print_accounts(std::cout);

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
