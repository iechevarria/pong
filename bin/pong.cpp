#include <SFML/Graphics.hpp>
#include <stdlib.h>

#include "Paddle.hpp"
#include "Ball.hpp"
#include "GameState.hpp"
#include "GameView.hpp"

int main(int argc, char** argv) {

  // create main window
  int gameHeight = 600;
  int gameWidth = 800;

  // create game state, game view
  GameState state;
  state.init(gameWidth, gameHeight);
  GameView view(gameWidth, gameHeight);
  view.init(state.getLeftPaddle(), state.getRightPaddle(), state.getBall());

  sf::Clock timer;

  // start main loop
  while(view.isOpen()) {

    float timePassed = timer.restart().asSeconds();

    // handle input for the left paddle
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
    view.draw(state.getLeftPaddle(), state.getRightPaddle(), state.getBall());
  }

  return 0;
}
