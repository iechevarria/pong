#include "Paddle.hpp"

void Paddle::set (int x, int y, int height, int speed) {
  this -> x = x;
  this -> y = y;
  this -> height = height;
  this -> speed = speed;
};

void Paddle::move (int y) {
  this -> y = y;
};

std::vector<int> Paddle::getPosition () {
  std::vector<int> result;
  result[0] = x;
  result[1] = y;
  return result;
}
