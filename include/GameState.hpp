#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Paddle.hpp"
#include "Ball.hpp"

class GameState {
  private:
    int leftPoints;
    int rightPoints;
  public:
    GameState (void) {};
    void init ();
    void updatePaddleAI (Paddle&, float, float, int, int, float);
    void updateBall (Ball&, Paddle, Paddle, float, int, int);
    int getLeftPoints ();
    int getRightPoints ();
    void addLeftPoint ();
    void addRightPoint ();
};

#endif
