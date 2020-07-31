#include "main.h"

#ifndef WALLOUT1_H
#define WALLOUT1_H


class Wallout1 {
public:
    Wallout1() {}
    Wallout1(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    //void tick();
    //double speed;
private:
    VAO *object;
};

#endif // BALL_H
