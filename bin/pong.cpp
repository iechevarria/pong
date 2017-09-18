#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

#include <Paddle.hpp>

int main(int argc, char** argv)
{
  // create main window
  int gameHeight = 600;
  int gameWidth = 800;

  sf::RenderWindow App(sf::VideoMode(gameWidth, gameHeight, 32), "Super Pong 3000", sf::Style::Titlebar | sf::Style::Close);

  // make paddles
  Paddle leftPaddle;
  Paddle rightPaddle;
  leftPaddle.set(10, gameHeight / 2, 60, 10, 400.f);
  rightPaddle.set(gameWidth - 10, gameHeight / 2, 60, 10, 300.f);

  sf::Clock clock;

  sf::RectangleShape leftPaddleShape;
  leftPaddleShape.setSize(sf::Vector2f(leftPaddle.getWidth(), leftPaddle.getHeight()));
  leftPaddleShape.setFillColor(sf::Color(255, 255, 255));
  leftPaddleShape.setOrigin(leftPaddle.getWidth() / 2.f, leftPaddle.getHeight()/ 2.f);
  leftPaddleShape.setPosition(leftPaddle.getX(), leftPaddle.getY());

  sf::RectangleShape rightPaddleShape;
  rightPaddleShape.setSize(sf::Vector2f(rightPaddle.getWidth(), rightPaddle.getHeight()));
  rightPaddleShape.setFillColor(sf::Color(255, 255, 255));
  rightPaddleShape.setOrigin(rightPaddle.getWidth() / 2.f, rightPaddle.getHeight() / 2.f);
  rightPaddleShape.setPosition(rightPaddle.getX(), rightPaddle.getY());

  sf::CircleShape ballShape;
  ballShape.setRadius(5);
  ballShape.setFillColor(sf::Color(255, 255, 255));
  ballShape.setPosition(400,300);

  // start main loop
  while(App.isOpen())
  {

    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // exit
      if ((Event.type == sf::Event::Closed) ||
         ((Event.type == sf::Event::KeyPressed) && ((Event.key.code == sf::Keyboard::Escape) || (Event.key.code == sf::Keyboard::Q))))
        App.close();
    }

    float deltaTime = clock.restart().asSeconds();

    // move left paddle
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

    leftPaddleShape.setPosition(leftPaddle.getX(), leftPaddle.getY());

    App.clear(sf::Color::Black);
    App.draw(leftPaddleShape);
    App.draw(rightPaddleShape);
    App.draw(ballShape);
    App.display();
  }


  // Done.
  return 0;
}
