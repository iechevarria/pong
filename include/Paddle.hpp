#ifndef PADDLE_HPP
#define PADDLE_HPP

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
    int getWidth (void);
    int getHeight (void);
    float getX (void);
    float getY (void);
    float getSpeed (void);
};

#endif
