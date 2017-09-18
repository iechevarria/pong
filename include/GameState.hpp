#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState {
  private:
    //int leftPoints();
    //int rightPoints();
    //float waitTime;
    //void setWaitTime (float);
    //void decrementWaitTime (float);
    Paddle& rightPaddle();
    void updatePaddleAI ();
  public:
    Gamestate (void) {};
    void init (Paddle&);
    //void addLeftPoint ();
    //void addRightPoint ();
    void update ();
};

#endif
