 #include "Game.h"

Game::Game() : requiredCrystals(crystalsToWin), requiredGoblins(goblinsToWin) {}

Game::~Game() {
  for (auto &row : locations) {
    for (auto &loc : row) {
      delete loc;
    }
  }
}

void Game::playGame() {
  std::cout << "\033[1;32m <<< ******* Welcome to the Adventure Game ******* "
               ">>>\033[0m\n";

  std::cout << "\033[1;33mRule 1:\033[0m \033[1;35mYou need to collect "
            << requiredCrystals << " crystals and defeat " << requiredGoblins
            << " goblins to win the game.\n";
  std::cout << "\033[1;33mRule 2:\033[0m \033[1;35mBe careful, goblins can "
               "attack and reduce your "
               "health.\033[0m\n";

  while (true) {
    displayMap();
    displayStatus();

    std::cout << "\033[37mEnter new column and row to move (1-based index): "
              << "\033[0m";
    int newRow, newCol;

    std::cin >> newRow >> newCol;

    if (newRow < 1 || newRow > locations.size() || newCol < 1 ||
        newCol > locations[0].size()) {
      std::cout << "Ooops!! Invalid move. Please enter values within the grid "
                   "limits.\n";
      continue;
    }
    player.move(newRow - 1, newCol - 1);
    locations[newRow - 1][newCol - 1]->visit(player);

    // Check for win condition
    if (checkWinCondition()) {
      std::cout << "Congratulations! You've collected enough crystals and "
                   "defeated enough goblins to win the game!!\n";
      break;
    }

    // Check for loss condition
    if (player.getHealth() <= 0) {
      std::cout << "Game over! You have lost all your health.\n";
      break;
    }
  }
}

void Game::loadGameFromFile(const std::string &fileName) {
  std::ifstream file(fileName);
  if (!file) {
    std::cerr << "Unable to open file\n";
    return;
  }

  file >> rows >> cols;
  locations.resize(rows, std::vector<Location *>(cols, nullptr));

  // Read the location data and create the appropriate objects
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::string locType;
      if (!(file >> locType)) {
        std::cerr << "Error reading location type at (" << i << ", " << j
                  << ")\n";
        return;
      }

      if (locType == "crystal") {
        locations[i][j] = new CrystalLocation();
      } else if (locType == "goblin") {
        locations[i][j] = new GoblinLocation();
      } else if (locType == "empty") {
        locations[i][j] = new EmptyLocation();
      } else {
        std::cerr << "Unknown location type: " << locType << " at (" << i
                  << ", " << j << ")\n";
        return;
      }
    }
  }
}

void Game::displayStatus() {
  std::cout << "Your current status:\n";
  std::cout << "\033[1;31mHealth:\033[0m " << player.getHealth() << " ("
            << player.getHealthPercentage() << "%)\n";
  std::cout << "\033[1;31mScore:\033[0m " << player.getScore()
            << "\n"; // Score in red
  std::cout << "\033[1;31mGoblins Defeated:\033[0m "
            << player.getGoblinsDefeated() << "\n\n";

  int healthPercentage = player.getHealthPercentage();
  std::cout << "\033[1;31mHealth Bar:\033[0m [\033[32m";
  int barWidth = 20;
  int filledBars = barWidth * healthPercentage / 100;

  for (int i = 0; i < filledBars; ++i) {
    std::cout << "=";
  }

  std::cout << "\033[0m";

  for (int i = filledBars; i < barWidth; ++i) {
    std::cout << " ";
  }
  std::cout << "] " << healthPercentage << "%\n";
}

void Game::displayMap() {
  std::cout
      << "\033[1;37mHere \033[1;33mis \033[1;37mthe map (You are represented "
         "as \033[1;90m'P'\033[1;37m):\033[0m\n";
  std::cout << "   ";

  for (int j = 1; j <= locations[0].size(); ++j) {
    std::cout << j << " ";
  }
  std::cout << "\n";

  for (int i = 0; i < locations.size(); ++i) {
    std::cout << i + 1 << " ";
    for (int j = 0; j < locations[i].size(); ++j) {
      if (i == player.getRow() && j == player.getCol()) {
        std::cout << "\033[1;90mP\033[0m ";
      } else {
        if (locations[i][j]->isVisited()) {
          std::string locType = locations[i][j]->getType();
          if (locType == "crystal") {
            std::cout << "\033[1;36m♦\033[0m ";
          } else if (locType == "goblin") {
            std::cout << "\033[1;31m:|\033[0m ";
          } else {
            std::cout << "\033[1;37mo\033[0m ";
          }
        } else {
          std::cout << "\033[1;37m?\033[0m ";
        }
      }
    }
    std::cout << "\n";
  }
}

bool Game::checkWinCondition() {
  return player.getScore() >= requiredCrystals * 10 &&
         player.getGoblinsDefeated() >= requiredGoblins;
}