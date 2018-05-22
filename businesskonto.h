#ifndef BUSINESSKONTO_H
#define BUSINESSKONTO_H

class Konto;

#include "konto.h"

class Businesskonto: public Konto {
  int prozent;

public:
  Businesskonto();
  void set_gebuehren(double) override;
  void berechne_gebuehren(int) override;
  int get_prozent();
  void einzahlen(unsigned int) override;
  bool auszahlen(unsigned int) override;
  bool ueberweisen(unsigned int, Konto&) override;
  void print(std::ostream&) const override;
};

#endif
