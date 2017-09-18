#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include <Paddle.hpp>
#include <Ball.hpp>


sf::RectangleShape makePaddleShape (Paddle paddle) {
  sf::RectangleShape paddleShape;
  paddleShape.setSize(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
  paddleShape.setFillColor(sf::Color(255, 255, 255));
  paddleShape.setOrigin(paddle.getWidth() / 2.f, paddle.getHeight()/ 2.f);
  paddleShape.setPosition(paddle.getX(), paddle.getY());
  return paddleShape;
}

void updatePaddleAI (Paddle& paddle, float ballY, int gameHeight, float deltaTime) {
  if ((paddle.getY() > ballY + 10) &&
    (paddle.getY() - paddle.getHeight() / 2 > 5.f)) {
    paddle.move(-paddle.getSpeed() * deltaTime);
  } else if ((paddle.getY() < ballY - 10) &&
    (paddle.getY() + paddle.getHeight() / 2 < gameHeight - 5.f)) {
    paddle.move(paddle.getSpeed() * deltaTime);
  }
}

void updateBall (Ball& ball, Paddle leftPaddle, Paddle rightPaddle, float deltaTime, int gameWidth, int gameHeight) {
  ball.move(cos(ball.getAngle()) * ball.getSpeed() * deltaTime, sin(ball.getAngle()) * ball.getSpeed() * deltaTime);
  if (ball.getY() - ball.getRadius() < 0) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getRadius() + 0.1);
  } else if (ball.getY() + ball.getRadius() > gameHeight) {
    ball.setAngle(-ball.getAngle());
    ball.setY(ball.getY() - ball.getRadius() - 0.1);
  }
  if (ball.getX() - ball.getRadius() < leftPaddle.getX() + leftPaddle.getWidth() / 2 &&
      ball.getX() - ball.getRadius() > leftPaddle.getX() &&
      ball.getY() + ball.getRadius() >= leftPaddle.getY() - leftPaddle.getHeight() / 2 &&
      ball.getY() - ball.getRadius() <= leftPaddle.getY() + leftPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle());
        ball.setX(leftPaddle.getX() + ball.getRadius() + leftPaddle.getWidth() / 2  + 1);
  } else if (ball.getX() + ball.getRadius() > rightPaddle.getX() - rightPaddle.getWidth() / 2 &&
             ball.getX() + ball.getRadius() < rightPaddle.getX() &&
             ball.getY() + ball.getRadius() >= rightPaddle.getY() - rightPaddle.getHeight() / 2 &&
             ball.getY() - ball.getRadius() <= rightPaddle.getY() + rightPaddle.getHeight() / 2) {
        ball.setAngle(3.14159 - ball.getAngle());
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
  rightPaddle.set(gameWidth - 10, gameHeight / 2, 60, 10, 300.f);
  sf::RectangleShape leftPaddleShape = makePaddleShape(leftPaddle);
  sf::RectangleShape rightPaddleShape = makePaddleShape(rightPaddle);

  // make ball, ball shapes
  Ball ball;
  ball.set(gameWidth / 2, gameHeight / 2, 400.f, 3, 5);
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

    float deltaTime = clock.restart().asSeconds();

    // get input for left paddle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) &&
        (leftPaddle.getY() - leftPaddle.getHeight() / 2 > 5.f))
    {
        leftPaddle.move(-leftPaddle.getSpeed() * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (leftPaddle.getY() + leftPaddle.getHeight() / 2 < gameHeight - 5.f))
    {
        leftPaddle.move(leftPaddle.getSpeed() * deltaTime);
    }

    updatePaddleAI(rightPaddle, ball.getY(), gameHeight, deltaTime);
    updateBall(ball, leftPaddle, rightPaddle, deltaTime, gameWidth, gameHeight);

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
