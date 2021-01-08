#pragma once
#include <GL/glew.h>
#include "constants.h"

class Framebuffer {
public:
    Framebuffer(GLsizei width, GLsizei height);
    void bind();
    void unbind();
    GLuint fbo, depthTexture, colorTexture;
    GLsizei width, height;
};