#include "GameState.hpp"
#include "Paddle.hpp"

void GameState::init (Paddle& rightPaddle) {
  this -> rightPaddle = rightPaddle;
}

void GameState::updatePaddleAI (float ballY, float ballX, int gameHeight, int gameWidth, float timePassed) {
  if (ballX > gameWidth / 5 &&
      ballX < gameWidth) {
    // check if the right paddle is lower on the screen than the ball
    if (rightPaddle.getY() > ballY + 10 &&
      rightPaddle.getY() - rightPaddle.getHeight() / 2 > 5.f) {
      rightPaddle.move(-rightPaddle.getSpeed() * timePassed);
    // check if right paddle is higher on the screen than the ball
  } else if ((rightPaddle.getY() < ballY - 10) &&
      (rightPaddle.getY() + rightPaddle.getHeight() / 2 < gameHeight - 5.f)) {
      rightPaddle.move(rightPaddle.getSpeed() * timePassed);
    }
  }
}
