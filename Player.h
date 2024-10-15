
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
  int row, col;
  int health;
  int score;
  int goblinsDefeated;

  void reduceHealth(int damage);

public:
  Player();

  void move(int newRow, int newCol);
  int getRow() const;
  int getCol() const;

  int getHealth() const;
  int getHealthPercentage() const;
  void takeDamage(int damage);

  int getScore() const;
  int getGoblinsDefeated() const;
  void collectCrystal();
  void defeatGoblin();
};

#endif