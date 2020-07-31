#include "main.h"

#ifndef MAG2_H
#define MAG2_H


class Mag2 {
public:
    Mag2() {}
    Mag2(float x, float y, color_t color);
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
