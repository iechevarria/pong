#include "Paddle.hpp"

/**
  Sets proprties of paddle

  @param x for x position coordinate
  @param y for y position coordinate
  @param height for height of paddle
  @param width for width of paddle
  @param speed for speed of paddle
*/
void Paddle::set (float x, float y, int height, int width, float speed) {
  this -> x = x;
  this -> y = y;
  this -> height = height;
  this -> width = width;
  this -> speed = speed;
};

/**
  Moves paddle

  @param y moves paddle y distance on the y axis
*/
void Paddle::move (float y) {
  this -> y += y;
};

/**
  @return x position coordinate
*/
float Paddle::getX () {
  return x;
};

/**
  @return y position coordinate
*/
float Paddle::getY() {
  return y;
};

/**
  @return speed value for paddle
*/
float Paddle::getSpeed() {
  return speed;
};

/**
  @return width of paddle
*/
int Paddle::getWidth () {
  return width;
}

/**
  @return heigh of paddle
*/
int Paddle::getHeight () {
  return height;
}
