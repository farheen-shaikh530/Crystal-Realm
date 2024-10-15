#ifndef EMPTYLOCATION_H
#define EMPTYLOCATION_H

#include "Location.h"
#include <iostream>

class EmptyLocation : public Location {
public:
  void visit(Player &player) override {

    std::cout << "You moved to an empty location.\n";
  }
  std::string getType() const override { return "empty"; }
};

#endif