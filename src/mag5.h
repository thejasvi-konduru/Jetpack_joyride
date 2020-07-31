#include "main.h"

#ifndef MAG5_H
#define MAG5_H


class Mag5 {
public:
    Mag5() {}
    Mag5(float x, float y, color_t color);
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
