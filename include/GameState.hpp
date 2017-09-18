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
    void addLeftPoint ();
    void addRightPoint ();
    char status;
  public:
    GameState (void) {};
    void init (int, int);
    int getLeftPoints ();
    int getRightPoints ();
    Paddle getRightPaddle ();
    Paddle getLeftPaddle ();
    Ball getBall ();
    void moveLeftPaddle (float);
    void update (float, int, int);
    void keyIn (char, float);
    char getStatus ();
};

#endif
