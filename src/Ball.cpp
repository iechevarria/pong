#include "Ball.hpp"

void Ball::set (float x, float y, float speed, float angle, int radius) {
  this -> x = x;
  this -> y = y;
  this -> speed = speed;
  this -> angle = angle;
  this -> radius = radius;
};

void Ball::move (float x, float y) {
  this -> x += x;
  this -> y += y;
};

void Ball::setAngle (float angle) {
  this -> angle = angle;
};

void Ball::setY (float y) {
  this -> y = y;
}

void Ball::setX (float x) {
  this -> x = x;
}

float Ball::getX () {
  return x;
};

float Ball::getY () {
  return y;
};

float Ball::getSpeed () {
  return speed;
};

float Ball::getAngle () {
  return angle;
};

int Ball::getRadius () {
  return radius;
};
