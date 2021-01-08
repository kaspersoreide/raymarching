#pragma once
#include <GL/glew.h>
#include "framebuffer.h"

class Screen {
public:
    Screen(Framebuffer fb1, Framebuffer fb2);
    void render();
    GLuint vertexArray, program;
    Framebuffer fb1, fb2;
};