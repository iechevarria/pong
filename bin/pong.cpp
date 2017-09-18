#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "Paddle.hpp"
#include "Ball.hpp"

sf::RectangleShape makePaddleShape (Paddle paddle) {
  sf::RectangleShape paddleShape;
  paddleShape.setSize(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
  paddleShape.setFillColor(sf::Color(255, 255, 255));
  paddleShape.setOrigin(paddle.getWidth() / 2.f, paddle.getHeight()/ 2.f);
  paddleShape.setPosition(paddle.getX(), paddle.getY());
  return paddleShape;
}

void updatePaddleAI (Paddle& paddle, float ballY, float ballX, int gameHeight, int gameWidth, float timePassed) {
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
}

void updateBall (Ball& ball, Paddle leftPaddle, Paddle rightPaddle, float timePassed, int gameWidth, int gameHeight) {
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
        ball.setAngle(3.14159 - ball.getAngle() - (10 * 3.14159 / 180) + (std::rand() % 20) * 3.14159 / 180);
        ball.setX(leftPaddle.getX() + ball.getRadius() + leftPaddle.getWidth() / 2  + 1);
  // check for right paddle collisions
  } else if (ball.getX() + ball.getRadius() > rightPaddle.getX() - rightPaddle.getWidth() / 2 &&
             ball.getX() + ball.getRadius() < rightPaddle.getX() &&
             ball.getY() + ball.getRadius() >= rightPaddle.getY() - rightPaddle.getHeight() / 2 &&
             ball.getY() - ball.getRadius() <= rightPaddle.getY() + rightPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle() - (10 * 3.14159 / 180) + (std::rand() % 20) * 3.14159 / 180);
        ball.setX(rightPaddle.getX() - ball.getRadius() - rightPaddle.getWidth() / 2 - 1);
  }
}

int main(int argc, char** argv) {

  // create main window
  int gameHeight = 600;
  int gameWidth = 800;
  sf::RenderWindow ctx(sf::VideoMode(gameWidth, gameHeight, 32), "Super Pong 3000", sf::Style::Titlebar | sf::Style::Close);

  // make paddles, paddle shapes
  Paddle leftPaddle;
  Paddle rightPaddle;
  leftPaddle.set(10, gameHeight / 2, 60, 10, 400.f);
  rightPaddle.set(gameWidth - 10, gameHeight / 2, 60, 10, 250.f);
  sf::RectangleShape leftPaddleShape = makePaddleShape(leftPaddle);
  sf::RectangleShape rightPaddleShape = makePaddleShape(rightPaddle);

  //GameState state;
  //state.init(rightPaddle)

  // make ball, ball shapes
  Ball ball;
  ball.set(gameWidth / 2, gameHeight / 2, 800.f, 2*3.14159, 5);
  sf::CircleShape ballShape;
  ballShape.setRadius(ball.getRadius());
  ballShape.setOrigin(ball.getRadius(), ball.getRadius());
  ballShape.setFillColor(sf::Color(255, 255, 255));
  ballShape.setPosition(ball.getX(), ball.getY());

  sf::Clock clock;

  // start main loop
  while(ctx.isOpen())
  {

    // process events
    sf::Event Event;
    while(ctx.pollEvent(Event))
    {
      // exit
      if ((Event.type == sf::Event::Closed) ||
         ((Event.type == sf::Event::KeyPressed) && ((Event.key.code == sf::Keyboard::Escape) || (Event.key.code == sf::Keyboard::Q))))
        ctx.close();
    }

    float timePassed = clock.restart().asSeconds();

    // get input for left paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        (leftPaddle.getY() - leftPaddle.getHeight() / 2 > 5.f))
    {
        leftPaddle.move(-leftPaddle.getSpeed() * timePassed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (leftPaddle.getY() + leftPaddle.getHeight() / 2 < gameHeight - 5.f))
    {
        leftPaddle.move(leftPaddle.getSpeed() * timePassed);
    }

    updatePaddleAI(rightPaddle, ball.getY(), ball.getX(), gameHeight, gameWidth, timePassed);
    updateBall(ball, leftPaddle, rightPaddle, timePassed, gameWidth, gameHeight);


    ballShape.setPosition(ball.getX(), ball.getY());
    leftPaddleShape.setPosition(leftPaddle.getX(), leftPaddle.getY());
    rightPaddleShape.setPosition(rightPaddle.getX(), rightPaddle.getY());

    ctx.clear(sf::Color::Black);
    ctx.draw(leftPaddleShape);
    ctx.draw(rightPaddleShape);
    ctx.draw(ballShape);
    ctx.display();

  }

  // Done.
  return 0;
}
