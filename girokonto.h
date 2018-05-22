#ifndef GIROKONTO_H
#define GIROKONTO_H

class Konto;
#include "konto.h"

class Girokonto: public Konto {
  double fixgebuehren;

public:
  Girokonto();
  double get_fix_gebuehren() const;
  void set_gebuehren(double) override;
  void berechne_gebuehren(int) override;
  void einzahlen(unsigned int) override;
  bool auszahlen(unsigned int) override;
  bool ueberweisen(unsigned int, Konto&) override;
  void print(std::ostream&) const override;
};

#endif
