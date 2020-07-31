#include "main.h"

#ifndef ENEMY2_H
#define ENEMY2_H


class Enemy2 {
public:
    Enemy2() {}
    Enemy2(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    int scoreen;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
    float dual;
private:
    VAO *object;
};

#endif // BALL_H
