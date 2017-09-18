#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <stdlib.h>

void GameState::updatePaddleAI (float timePassed, int gameWidth, int gameHeight) {
  if (ball.getX() > gameWidth / 5 &&
      ball.getX() < gameWidth) {
    // check if the right paddle is lower on the screen than the ball
    if (rightPaddle.getY() > ball.getY() + 10 &&
        rightPaddle.getY() - rightPaddle.getHeight() / 2 > 5.f) {
          rightPaddle.move(-rightPaddle.getSpeed() * timePassed);
    // check if right paddle is higher on the screen than the ball
    } else if (rightPaddle.getY() < ball.getY() - 10 &&
             rightPaddle.getY() + rightPaddle.getHeight() / 2 < gameHeight - 5.f) {
               rightPaddle.move(rightPaddle.getSpeed() * timePassed);
    }
  }
};

void GameState::updateBall (float timePassed, int gameWidth, int gameHeight) {
  ball.move(cos(ball.getAngle()) * ball.getSpeed() * timePassed, sin(ball.getAngle()) * ball.getSpeed() * timePassed);
  // check for screen edge collisions
  if (ball.getY() - ball.getRadius() < 0) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getRadius() + 0.1);
  } else if (ball.getY() + ball.getRadius() > gameHeight) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getY() - ball.getRadius() - 0.1);
  }
  // check for paddle collisions
  if (ball.getX() - ball.getRadius() < leftPaddle.getX() + leftPaddle.getWidth() / 2 &&
      ball.getX() - ball.getRadius() > leftPaddle.getX() &&
      ball.getY() + ball.getRadius() >= leftPaddle.getY() - leftPaddle.getHeight() / 2 &&
      ball.getY() - ball.getRadius() <= leftPaddle.getY() + leftPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (10.f * 3.14159 / 180.f) + float(std::rand() % 20) * 3.14159 / 180.f);
        ball.setX(leftPaddle.getX() + ball.getRadius() + leftPaddle.getWidth() / 2  + 1);
  } else if (ball.getX() + ball.getRadius() > rightPaddle.getX() - rightPaddle.getWidth() / 2 &&
             ball.getX() + ball.getRadius() < rightPaddle.getX() &&
             ball.getY() + ball.getRadius() >= rightPaddle.getY() - rightPaddle.getHeight() / 2 &&
             ball.getY() - ball.getRadius() <= rightPaddle.getY() + rightPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (10.f * 3.14159 / 180.f) + float(std::rand() % 20) * 3.14159 / 180.f);
        ball.setX(rightPaddle.getX() - ball.getRadius() - rightPaddle.getWidth() / 2 - 1);
  }
};

Paddle GameState::getLeftPaddle () {
  return leftPaddle;
}

Paddle GameState::getRightPaddle () {
  return rightPaddle;
}

void GameState::init (int gameWidth, int gameHeight) {
  this -> leftPaddle.set(10, gameHeight / 2, 60, 10, 400.f);
  this -> rightPaddle.set(gameWidth - 10, gameHeight / 2, 60, 10, 250.f);
  this -> ball.set(gameWidth / 2, gameHeight / 2, 800.f, 2*3.14159, 5);
  this -> leftPoints = 0;
  this -> rightPoints = 0;
};

int GameState::getLeftPoints () {
  return leftPoints;
};

int GameState::getRightPoints () {
  return rightPoints;
};

void GameState::addLeftPoint () {
  this -> leftPoints ++;
};

void GameState::addRightPoint () {
  this -> rightPoints ++;
};

void GameState::moveLeftPaddle (float y) {
  leftPaddle.move(y);
};

void GameState::update (float timePassed, int gameWidth, int gameHeight) {
  this -> updatePaddleAI(timePassed, gameWidth, gameHeight);
  this -> updateBall(timePassed, gameWidth, gameHeight);
}

Ball GameState::getBall () {
  return ball;
}
