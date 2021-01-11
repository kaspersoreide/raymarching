#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "constants.h"

using namespace glm;

class Raycaster {
public:
    Raycaster();
    void render(mat4 cam, mat4 VP);
    void setTime(float t);
    void setProjection(mat4 proj);
    GLuint vertexArray, program;
   
};