#include "raycaster.h"
#include "loadshaders.h"
#include <iostream>

Raycaster::Raycaster() {
	//construct vertex array with 6 vertices: 2 triangles covering the screen
    GLuint vertexBuffer;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

	GLfloat vertices[] = {
		1.0,	-1.0,	0.0,	1.0,
		1.0,	1.0,	0.0,	1.0,
		-1.0,	1.0,	0.0,	1.0,
		1.0,	-1.0,	0.0,	1.0,
		-1.0,	-1.0,	0.0,	1.0,
		-1.0,	1.0,	0.0,	1.0
	};

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    program = loadShaders("shaders/raycaster/vert.glsl", "shaders/raycaster/frag.glsl");
}

void Raycaster::setTime(float t){
	glUniform1f(glGetUniformLocation(program, "time"), t);
}

void Raycaster::setProjection(mat4 proj) {
	glUseProgram(program);
	mat4 invProj = inverse(proj);
	GLuint locProj = glGetUniformLocation(program, "proj");
	glUniformMatrix4fv(locProj, 1, GL_FALSE, &invProj[0][0]);
}


void Raycaster::render(mat4 cam, mat4 VP) {
	//glDisable(GL_DEPTH_TEST);
	glUseProgram(program);
    GLuint locModel = glGetUniformLocation(program, "cam");
	glUniformMatrix4fv(locModel, 1, GL_FALSE, &cam[0][0]);
	GLuint locVP = glGetUniformLocation(program, "VP");
	glUniformMatrix4fv(locVP, 1, GL_FALSE, &VP[0][0]);
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	//glEnable(GL_DEPTH_TEST);
}