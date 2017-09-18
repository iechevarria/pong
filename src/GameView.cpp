#include "GameView.hpp"

/**
  Uses Paddle objects to make shapes for drawing

  @param paddle is the paddle that will be drawn
  @return an sf::RectangleShape to be used later for drawing
*/
sf::RectangleShape GameView::makePaddleShape (Paddle paddle) {
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
sf::CircleShape GameView::makeBallShape (Ball ball) {
  sf::CircleShape ballShape;
  ballShape.setRadius(ball.getRadius());
  ballShape.setOrigin(ball.getRadius(), ball.getRadius());
  ballShape.setFillColor(sf::Color(255, 255, 255));
  ballShape.setPosition(ball.getX(), ball.getY());
  return ballShape;
}

GameView::GameView (int width, int height)
  : ctx(sf::VideoMode(width, height, 32), "Pooper Pong 2000", sf::Style::Titlebar | sf::Style::Close)
{
}

void GameView::init (Paddle leftPaddle, Paddle rightPaddle, Ball ball) {
  this -> leftPaddleShape = makePaddleShape(leftPaddle);
  this -> rightPaddleShape = makePaddleShape(rightPaddle);
  this -> ballShape = makeBallShape(ball);
}

void GameView::draw (Paddle leftPaddle, Paddle rightPaddle, Ball ball) {
  checkActive();

  ballShape.setPosition(ball.getX(), ball.getY());
  leftPaddleShape.setPosition(leftPaddle.getX(), leftPaddle.getY());
  rightPaddleShape.setPosition(rightPaddle.getX(), rightPaddle.getY());

  ctx.clear(sf::Color::Blue);
  ctx.draw(this -> leftPaddleShape);
  ctx.draw(this -> rightPaddleShape);
  ctx.draw(this -> ballShape);
  ctx.display();
}

void GameView::checkActive () {
  sf::Event Event;
  while(ctx.pollEvent(Event))
  {
    if ((Event.type == sf::Event::Closed) ||
       ((Event.type == sf::Event::KeyPressed) && ((Event.key.code == sf::Keyboard::Escape) || (Event.key.code == sf::Keyboard::Q))))
      ctx.close();
  }
}

bool GameView::isOpen () {
  return ctx.isOpen();
}
