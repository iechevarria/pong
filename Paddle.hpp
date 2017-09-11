#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <vector>

class Paddle {
  private:
    int x;
    int y;
    int height;
    int speed;
  public:
    Paddle (void) {};
    void set (int x, int y, int height, int speed);
    void move (int x);
    std::vector<int> getPosition()
};

#endif
