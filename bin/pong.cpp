#include <SFML/Graphics.hpp>

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Hello World - SFML", sf::Style::Titlebar | sf::Style::Close);

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

    // clear screen and fill with blue
    App.clear(sf::Color::Blue);

    // display
    App.display();
  }


  // Done.
  return 0;
}
