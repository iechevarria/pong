#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <stdlib.h>

void GameState::updatePaddleAI (Paddle& paddle, float ballY, float ballX, int gameHeight, int gameWidth, float timePassed) {
  if (ballX > gameWidth / 5 &&
      ballX < gameWidth) {
    // check if the right paddle is lower on the screen than the ball
    if (paddle.getY() > ballY + 10 &&
      paddle.getY() - paddle.getHeight() / 2 > 5.f) {
      paddle.move(-paddle.getSpeed() * timePassed);
    // check if right paddle is higher on the screen than the ball
    } else if ((paddle.getY() < ballY - 10) &&
      (paddle.getY() + paddle.getHeight() / 2 < gameHeight - 5.f)) {
      paddle.move(paddle.getSpeed() * timePassed);
    }
  }
};

void GameState::updateBall (Ball& ball, Paddle leftPaddle, Paddle rightPaddle, float timePassed, int gameWidth, int gameHeight) {
  // move ball
  ball.move(cos(ball.getAngle()) * ball.getSpeed() * timePassed, sin(ball.getAngle()) * ball.getSpeed() * timePassed);
  // check for collisions at top of the screen
  if (ball.getY() - ball.getRadius() < 0) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getRadius() + 0.1);
  // check for collisions at bottom of the screen
  } else if (ball.getY() + ball.getRadius() > gameHeight) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getY() - ball.getRadius() - 0.1);
  }
  // check for left paddle collisions
  if (ball.getX() - ball.getRadius() < leftPaddle.getX() + leftPaddle.getWidth() / 2 &&
      ball.getX() - ball.getRadius() > leftPaddle.getX() &&
      ball.getY() + ball.getRadius() >= leftPaddle.getY() - leftPaddle.getHeight() / 2 &&
      ball.getY() - ball.getRadius() <= leftPaddle.getY() + leftPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (10 * 3.14159 / 180) + float(std::rand() % 20) * 3.14159 / 180);
        ball.setX(leftPaddle.getX() + ball.getRadius() + leftPaddle.getWidth() / 2  + 1);
  // check for right paddle collisions
  } else if (ball.getX() + ball.getRadius() > rightPaddle.getX() - rightPaddle.getWidth() / 2 &&
             ball.getX() + ball.getRadius() < rightPaddle.getX() &&
             ball.getY() + ball.getRadius() >= rightPaddle.getY() - rightPaddle.getHeight() / 2 &&
             ball.getY() - ball.getRadius() <= rightPaddle.getY() + rightPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (10 * 3.14159 / 180) + float(std::rand() % 20) * 3.14159 / 180);
        ball.setX(rightPaddle.getX() - ball.getRadius() - rightPaddle.getWidth() / 2 - 1);
  }
};

void GameState::init () {
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
