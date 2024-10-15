#ifndef CRYSTALLOCATION_H
#define CRYSTALLOCATION_H

#include "Location.h"
#include <iostream>
#include <string>

class CrystalLocation : public Location {
public:
  void visit(Player &player) override {
    if (!visited) {
      player.collectCrystal();
      std::cout << "You found a crystal! Your score increased by 10.\n";
      visited = true;
    } else {
      std::cout << "You have already collected the crystal here.\n";
    }
  }

  std::string getType() const override { return "crystal"; }
};

#endif
