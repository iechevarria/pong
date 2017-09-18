#ifndef GAMEVIEW_HPP
#define GAMEVIEW_HPP

#include <SFML/Graphics.hpp>
#include "Paddle.hpp"
#include "Ball.hpp"

class GameView {
  private:
    sf::RenderWindow ctx;
    sf::RectangleShape leftPaddleShape;
    sf::RectangleShape rightPaddleShape;
    sf::CircleShape ballShape;

    sf::RectangleShape makePaddleShape (Paddle);
    sf::CircleShape makeBallShape (Ball);
    void checkActive ();

  public:
    GameView (int, int);
    void init (Paddle, Paddle, Ball);
    void draw (Paddle, Paddle, Ball);
    bool isOpen ();
};

#endif
