#include "Player.h"

Player::Player() : row(0), col(0), health(100), score(0), goblinsDefeated(0) {}

// Move player to a new grid position
void Player::move(int newRow, int newCol) {
  row = newRow;
  col = newCol;
}

// Get current health
int Player::getHealth() const { return health; }

// Get player's health percentage (for UI display or logic)
int Player::getHealthPercentage() const {
  return (health > 0) ? (health * 100 / 100) : 0; // Assuming max health is 100
}

// Get current score
int Player::getScore() const { return score; }

// Get goblins defeated count
int Player::getGoblinsDefeated() const { return goblinsDefeated; }

// Increment score when a crystal is collected
void Player::collectCrystal() {
  score += 10; // Each crystal gives 10 points
}

// Increment goblins defeated counter
void Player::defeatGoblin() { goblinsDefeated++; }

// Reduce health by a certain damage amount, and ensure health doesn't go below
// 0
void Player::reduceHealth(int damage) {
  health -= damage;
  if (health < 0) {
    health = 0; // Ensure health doesn't drop below 0
  }
}

// Public method to take damage
void Player::takeDamage(int damage) { reduceHealth(damage); }

// Get player's current row
int Player::getRow() const { return row; }

// Get player's current column
int Player::getCol() const { return col; }