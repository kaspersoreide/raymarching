#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "constants.h"

using namespace glm;

class Raycaster {
public:
    Raycaster();
    void render(glm::mat4 cam);
    void setResolution(unsigned int x, unsigned int y);
    void setTime(float t);
    void setProjection(mat4 proj);
    GLuint vertexArray, program;
   
};