#include "main.h"

#ifndef LINE_H
#define LINE_H


class Line {
public:
    Line() {}
    Line(float x, float y, color_t color);
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
