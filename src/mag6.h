#include "main.h"

#ifndef MAG6_H
#define MAG6_H


class Mag6 {
public:
    Mag6() {}
    Mag6(float x, float y, color_t color);
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
