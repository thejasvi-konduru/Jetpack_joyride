#include "main.h"

#ifndef WALLIN_H
#define WALLIN_H


class Wallin {
public:
    Wallin() {}
    Wallin(float x, float y, color_t color);
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
