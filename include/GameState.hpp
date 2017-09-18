#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "Paddle.hpp"
#include "Ball.hpp"

class GameState {
  private:
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;
    int leftPoints;
    int rightPoints;
    void updatePaddleAI (float, int, int);
    void updateBall (float, int, int);

  public:
    GameState (void) {};
    void init (int, int);
    int getLeftPoints ();
    int getRightPoints ();
    void addLeftPoint ();
    void addRightPoint ();
    Paddle getRightPaddle ();
    Paddle getLeftPaddle ();
    Ball getBall ();
    void moveLeftPaddle (float);
    void update (float, int, int);
};

#endif
