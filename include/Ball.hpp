#ifndef BALL_HPP
#define BALL_HPP

#include <vector>

class Ball {
  private:
    float x;
    float y;
    float speed;
    float angle;
    int radius;
  public:
    Ball (void) {};
    void set (float x, float y, float speed, float angle, int radius);
    void move (float x, float y);
    void setAngle (float angle);
    void setX (float x);
    void setY (float y);
    float getX ();
    float getY ();
    float getSpeed ();
    float getAngle ();
    int getRadius ();
};

#endif
