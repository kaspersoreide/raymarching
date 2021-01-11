#include "cube.h"

Cube::Cube() {
    program = loadShaders("shaders/thing/vert.glsl", "shaders/thing/frag.glsl");
    vertexArray = loadObjectNoNormals("objects/cube.obj");
    pos = vec3(0.0, 0.0, -3.0);
}

void Cube::render(mat4 VP) {
    mat4 MVP = VP * Model;
    glUseProgram(program);
	GLuint l_M = glGetUniformLocation(program, "MVP");
	glUniformMatrix4fv(l_M, 1, GL_FALSE, &MVP[0][0]);
    glBindVertexArray(vertexArray);
    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
}