#ifndef GAME_H
#define GAME_H

#include "CrystalLocation.h"
#include "EmptyLocation.h"
#include "GoblinLocation.h"
#include "Location.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <vector>

class Game {
private:
  int rows, cols;
  Player player;
  const int crystalsToWin = 3;
  const int goblinsToWin = 5;
  std::vector<std::vector<Location *>> locations;
  int requiredCrystals;
  int requiredGoblins;

public:
  Game();
  ~Game();
  void loadGameFromFile(const std::string &fileName);
  void playGame();
  void displayStatus();
  void displayMap();
  bool checkWinCondition();
};

#endif