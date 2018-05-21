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
  std::ostream& print(std::ostream&) const override;
  int get_prozent();
};

#endif
