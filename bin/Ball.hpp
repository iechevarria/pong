#ifndef BALL_HPP
#define BALL_HPP

#include <vector>

class Ball {
  private:
    int x;
    int y;
    float speed;
    float angle;
    int radius;
  public:
    Ball (void) {};
    void set (double x, double y, double z, double rad);
    void move (std::vector<int> leftPaddle, std::vector<int> rightPaddle);
    std::vector<int> getPosition ()
};

#endif
