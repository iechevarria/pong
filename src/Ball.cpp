#include "Ball.hpp"

/**
  Sets proprties of the Ball

  @param x for x position coordinate
  @param y for y position coordinate
  @param speed for ball speed
  @param angle for angle of ball in radians
  @param radius for radius of ball
*/
void Ball::set (float x, float y, float speed, float angle, int radius) {
  this -> x = x;
  this -> y = y;
  this -> speed = speed;
  this -> angle = angle;
  this -> radius = radius;
};

/**
  move ball by these constants

  @param x move on x-axis
  @param y move on y-axis
*/
void Ball::move (float x, float y) {
  this -> x += x;
  this -> y += y;
};

/**
  set ball angle

  @param angle to set
*/
void Ball::setAngle (float angle) {
  this -> angle = angle;
};

/**
  set y coordinate of ball

  @param y to set
*/
void Ball::setY (float y) {
  this -> y = y;
}

/**
  set x coordinate of ball

  @param x coordinate of ball
*/
void Ball::setX (float x) {
  this -> x = x;
}

/**
  @return x position coordinate of ball
*/
float Ball::getX () {
  return x;
};

/**
  @return y position coordinate of ball
*/
float Ball::getY () {
  return y;
};

/**
  @return speed of ball
*/
float Ball::getSpeed () {
  return speed;
};

/**
  @return angle of ball
*/
float Ball::getAngle () {
  return angle;
};

/**
  @return radius of ball
*/
int Ball::getRadius () {
  return radius;
};
