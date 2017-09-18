#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <vector>

class Paddle {
  private:
    float x;
    float y;
    int height;
    int width;
    float speed;
  public:
    Paddle (void) {};
    void set (float x, float y, int height, int width, float speed);
    void move (float y);
    int getWidth();
    int getHeight();
    float getX ();
    float getY ();
    float getSpeed ();
};

#endif
