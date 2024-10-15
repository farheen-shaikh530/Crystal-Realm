#include "Game.h"
#include <iostream>

int main() {
  Game game;
  game.loadGameFromFile("game_data.txt");
  game.playGame();
  return 0;
}