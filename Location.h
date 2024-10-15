#ifndef LOCATION_H
#define LOCATION_H

#include "Player.h"
#include <string>

class Location {
protected:
  bool visited = false;

public:
  virtual void visit(Player &player) { visited = true; }
  bool isVisited() const { return visited; }
  virtual std::string getType() const = 0;
  virtual ~Location() = default;
};

#endif
