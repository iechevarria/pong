#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "Paddle.hpp"
#include "Ball.hpp"
#include "GameState.hpp"

/**
  Uses Paddle objects to make shapes for drawing

  @param paddle is the paddle that will be drawn
  @return an sf::RectangleShape to be used later for drawing
*/
sf::RectangleShape makePaddleShape (Paddle paddle) {
  sf::RectangleShape paddleShape;
  paddleShape.setSize(sf::Vector2f(paddle.getWidth(), paddle.getHeight()));
  paddleShape.setFillColor(sf::Color(255, 255, 255));
  paddleShape.setOrigin(paddle.getWidth() / 2.f, paddle.getHeight()/ 2.f);
  paddleShape.setPosition(paddle.getX(), paddle.getY());
  return paddleShape;
}

/**
  Uses ball object to make circles for drawing

  @param ball is the ball that will be drawing
  @return an sf::CircleShape to be drawn later
*/
sf::CircleShape makeBallShape (Ball ball) {
  sf::CircleShape ballShape;
  ballShape.setRadius(ball.getRadius());
  ballShape.setOrigin(ball.getRadius(), ball.getRadius());
  ballShape.setFillColor(sf::Color(255, 255, 255));
  ballShape.setPosition(ball.getX(), ball.getY());
  return ballShape;
}

int main(int argc, char** argv) {

  // create main window
  int gameHeight = 600;
  int gameWidth = 800;
  sf::RenderWindow ctx(sf::VideoMode(gameWidth, gameHeight, 32), "Super Pong 3000", sf::Style::Titlebar | sf::Style::Close);

  // create game state
  GameState state;
  state.init(gameWidth, gameHeight);

  // create shapes to draw
  sf::RectangleShape leftPaddleShape = makePaddleShape(state.getLeftPaddle());
  sf::RectangleShape rightPaddleShape = makePaddleShape(state.getRightPaddle());
  sf::CircleShape ballShape = makeBallShape(state.getBall());

  sf::Clock clock;


  // start main loop
  while(ctx.isOpen()) {

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
        (state.getLeftPaddle().getY() - state.getLeftPaddle().getHeight() / 2 > 5.f))
    {
        state.moveLeftPaddle(-state.getLeftPaddle().getSpeed() * timePassed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (state.getLeftPaddle().getY() + state.getLeftPaddle().getHeight() / 2 < gameHeight - 5.f))
    {
        state.moveLeftPaddle(state.getLeftPaddle().getSpeed() * timePassed);
    }

    state.update(timePassed, gameWidth, gameHeight);

    ballShape.setPosition(state.getBall().getX(), state.getBall().getY());
    leftPaddleShape.setPosition(state.getLeftPaddle().getX(), state.getLeftPaddle().getY());
    rightPaddleShape.setPosition(state.getRightPaddle().getX(), state.getRightPaddle().getY());

    ctx.clear(sf::Color::Black);
    ctx.draw(leftPaddleShape);
    ctx.draw(rightPaddleShape);
    ctx.draw(ballShape);
    ctx.display();

  }

  // Done.
  return 0;
}
