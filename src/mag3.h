#include "main.h"

#ifndef MAG3_H
#define MAG3_H


class Mag3 {
public:
    Mag3() {}
    Mag3(float x, float y, color_t color);
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
