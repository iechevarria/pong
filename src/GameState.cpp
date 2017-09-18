#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include "GameState.hpp"

/**
  Moves right paddle to follow the ball, with a few quirks

  @param timePassed to determine the paddle's speed
  @param gameWidth to add different behavior
  @param gameHeight to prevent the paddle from going out of bounds
*/
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

/**
  Handles collisions and boundaries for the ball

  @param timePassed to determine how far the ball goes
  @param gameWidth to determine when the ball is out of bounds
  @param gameHeight to add collisions
*/
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
        ball.setAngle(3.14159 - ball.getAngle() - (12.5 * 3.14159 / 180.0) + (std::rand() % 25) * 3.14159 / 180.0);
        ball.setX(leftPaddle.getX() + ball.getRadius() + leftPaddle.getWidth() / 2  + 0.1);
  } else if (ball.getX() + ball.getRadius() > rightPaddle.getX() - rightPaddle.getWidth() / 2 &&
             ball.getX() + ball.getRadius() < rightPaddle.getX() &&
             ball.getY() + ball.getRadius() >= rightPaddle.getY() - rightPaddle.getHeight() / 2 &&
             ball.getY() - ball.getRadius() <= rightPaddle.getY() + rightPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (12.5 * 3.14159 / 180.0) + float(std::rand() % 25) * 3.14159 / 180.0);
        ball.setX(rightPaddle.getX() - ball.getRadius() - rightPaddle.getWidth() / 2 - 0.1);
  }
  // check for ball out-of-bounds
  if (ball.getX() < -400) {
    addRightPoint();
    ball.set(gameWidth / 2, gameHeight / 2, ball.getSpeed(), 2 * 3.14159, ball.getRadius());
  } else if (ball.getX() > gameWidth + 400) {
    addLeftPoint();
    ball.set(gameWidth / 2, gameHeight / 2, ball.getSpeed(), 2 * 3.14159, ball.getRadius()) ;
  }
};

/**
  @return leftPaddle
*/
Paddle GameState::getLeftPaddle () {
  return leftPaddle;
}

/**
  @return rightPaddle
*/
Paddle GameState::getRightPaddle () {
  return rightPaddle;
}

/**
  Sets all agents to beginning positions

  @param gameWidth to place objects
  @param gameHeight to place objects
*/
void GameState::init (int gameWidth, int gameHeight) {
  this -> leftPaddle.set(10, gameHeight / 2, 60, 10, 400.f);
  this -> rightPaddle.set(gameWidth - 10, gameHeight / 2, 60, 10, 250.f);
  this -> ball.set(gameWidth / 2, gameHeight / 2, 800.f, 2*3.14159, 5);
  this -> leftPoints = 0;
  this -> rightPoints = 0;
  status = 'P';
};

/**
  @return leftPoints
*/
int GameState::getLeftPoints () {
  return leftPoints;
};

/**
  @return rightPoints
*/
int GameState::getRightPoints () {
  return rightPoints;
};

/**
  increments points on the left
*/
void GameState::addLeftPoint () {
  this -> leftPoints ++;
};

/**
  increments points on the right
*/
void GameState::addRightPoint () {
  this -> rightPoints ++;
};

/**
  Moves the left paddle

  @param y for the distance to move the paddle
*/
void GameState::moveLeftPaddle (float y) {
  leftPaddle.move(y);
};

/**
  Updates ball and right paddle

  @param timePassed
  @param gameWidth
  @param gameHeight
*/
void GameState::update (float timePassed, int gameWidth, int gameHeight) {
  if (status = 'P') {
    this -> updatePaddleAI(timePassed, gameWidth, gameHeight);
    this -> updateBall(timePassed, gameWidth, gameHeight);
  }
  if (rightPoints > 10) {
    status = 'L';
  }
  if (leftPoints > 10) {
    status = 'W';
  }
}

/**
  @return ball
*/
Ball GameState::getBall () {
  return ball;
}

/**
*/
void GameState::keyIn (char key, float timePassed) {
  if (status == 'P') {
    if (key == 'U' &&
        leftPaddle.getY() - leftPaddle.getHeight() / 2 > 5.f)  {
      leftPaddle.move(-leftPaddle.getSpeed() * timePassed);
    } else if (key == 'D' &&
      leftPaddle.getY() + leftPaddle.getHeight() / 2 < 600 - 5.f) {
      leftPaddle.move(leftPaddle.getSpeed() * timePassed);
    }
  } else if (status == 'W' || status == 'L') {
    if (key == 'R') {
      init(800, 600);
    }
  }
}

char GameState::getStatus () {
  return status;
}
