#include "main.h"

#ifndef MAG1_H
#define MAG1_H


class Mag1 {
public:
    Mag1() {}
    Mag1(float x, float y, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif // BALL_H
