#pragma once
#include "object.h"
#include "loadObj.h"
#include "loadshaders.h"

class Cube : public Object {
public:
    Cube();
    void render(mat4 VP);
    GLuint program, vertexArray;
};