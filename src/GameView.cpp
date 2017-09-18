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

/**
  GameView constructor that creates the game window

  @param gameWidth to set window width
  @param gameHeight to set window height
*/
GameView::GameView (int gameWidth, int gameHeight)
  : ctx(sf::VideoMode(gameWidth, gameHeight, 32), "Super Pong 3000", sf::Style::Titlebar | sf::Style::Close)
{
}

/**
  Initializes shapes for drawing

  @param leftPaddle for drawing
  @param rightPaddle for drawing
  @param ball for drawing
*/
void GameView::init (Paddle leftPaddle, Paddle rightPaddle, Ball ball) {
  leftPaddleShape = makePaddleShape(leftPaddle);
  rightPaddleShape = makePaddleShape(rightPaddle);
  ballShape = makeBallShape(ball);
}

/**
  Updates shape locations and draws

  @param leftPaddle to update and draw
  @param rightPaddle to update and draw
  @param ball to update and draw
*/
void GameView::draw (Paddle leftPaddle, Paddle rightPaddle, Ball ball) {
  checkActive();

  ballShape.setPosition(ball.getX(), ball.getY());
  leftPaddleShape.setPosition(leftPaddle.getX(), leftPaddle.getY());
  rightPaddleShape.setPosition(rightPaddle.getX(), rightPaddle.getY());

  ctx.clear(sf::Color::Blue);
  ctx.draw(leftPaddleShape);
  ctx.draw(rightPaddleShape);
  ctx.draw(ballShape);
  ctx.display();
}

/**
  Closes window when the user exits
*/
void GameView::checkActive () {
  sf::Event Event;
  while(ctx.pollEvent(Event))
  {
    if ((Event.type == sf::Event::Closed) ||
       ((Event.type == sf::Event::KeyPressed) && ((Event.key.code == sf::Keyboard::Escape) || (Event.key.code == sf::Keyboard::Q))))
      ctx.close();
  }
}

/**
  Checks if window is open

  @return bool 
*/
bool GameView::isOpen () {
  return ctx.isOpen();
}
