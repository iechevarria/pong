#include "Paddle.hpp"

void Paddle::set (float x, float y, int height, int width, float speed) {
  this -> x = x;
  this -> y = y;
  this -> height = height;
  this -> width = width;
  this -> speed = speed;
};

void Paddle::move (float y) {
  this -> y += y;
};

float Paddle::getX () {
  return x;
};

float Paddle::getY() {
  return y;
};

float Paddle::getSpeed() {
  return speed;
};

int Paddle::getWidth () {
  return width;
}

int Paddle::getHeight () {
  return height;
}
