#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include <ctime>
#include <cstdlib>

int main(int argc, char** argv)
{
  // create main window
  int gameHeight = 600;
  int gameWidth = 800;
  sf::Vector2f paddleSize(10, 60);
  sf::RenderWindow App(sf::VideoMode(gameWidth, gameHeight, 32), "Super Pong 3000", sf::Style::Titlebar | sf::Style::Close);

  // make left paddle
  sf::RectangleShape leftPaddle;
  leftPaddle.setSize(paddleSize - sf::Vector2f(3, 3));
  leftPaddle.setOutlineThickness(3);
  leftPaddle.setFillColor(sf::Color(255, 255, 255));
  leftPaddle.setOrigin(paddleSize / 2.f);
  leftPaddle.setPosition(5 + paddleSize.x / 2, gameHeight / 2);


  sf::Clock clock;
  const float paddleSpeed = 400.f;


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
        (leftPaddle.getPosition().y - paddleSize.y / 2 > 5.f))
    {
        leftPaddle.move(0.f, -paddleSpeed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) &&
        (leftPaddle.getPosition().y + paddleSize.y / 2 < gameHeight - 5.f))
    {
        leftPaddle.move(0.f, paddleSpeed * deltaTime);
    }


    // clear screen and fill with blue
    App.clear(sf::Color::Black);
    App.draw(leftPaddle);


    // display
    App.display();
  }


  // Done.
  return 0;
}
