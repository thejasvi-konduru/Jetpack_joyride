#include "main.h"

#ifndef REC_H
#define REC_H


class Rec {
public:
    Rec() {}
    Rec(float x, float y, color_t color,float l,float b,float theta);
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
