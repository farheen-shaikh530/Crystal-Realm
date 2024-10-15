#ifndef GOBLINLOCATION_H
#define GOBLINLOCATION_H

#include "Location.h"
#include <iostream>

class GoblinLocation : public Location {
public:
  void visit(Player &player) override {
    if (!visited) {
      std::cout << "You encountered a goblin!\n";
      player.takeDamage(20);
      std::cout << "You took 20 damage! Your health is now "
                << player.getHealth() << ".\n";

      if (player.getHealthPercentage() <= 20) {
        std::cout << "\033[31mWarning: Your health is critically low! ("
                  << player.getHealthPercentage() << "%)\033[0m\n";
      }
      visited = true;
    } else {
      std::cout << "You have already encountered the goblin here.\n";
    }
  }

  std::string getType() const override { return "goblin"; }
};

#endif
