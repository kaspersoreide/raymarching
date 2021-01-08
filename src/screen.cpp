#include "screen.h"
#include "loadshaders.h"

Screen::Screen(Framebuffer fb1, Framebuffer fb2) : fb1(fb1), fb2(fb2) { 

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
    program = loadShaders("shaders/screen/vert.glsl", "shaders/screen/frag.glsl");
	glUseProgram(program);
	glUniform1i(glGetUniformLocation(program, "colorTexture1"), 0);
	glUniform1i(glGetUniformLocation(program, "depthTexture1"), 1);
	glUniform1i(glGetUniformLocation(program, "colorTexture2"), 2);
	glUniform1i(glGetUniformLocation(program, "depthTexture2"), 3);
}

void Screen::render() {
	glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, fb1.colorTexture);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, fb1.depthTexture);
	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, fb2.colorTexture);
	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, fb2.depthTexture);
    glDisable(GL_DEPTH_TEST);
    glUseProgram(program);
	glBindVertexArray(vertexArray);
	glDrawArrays(GL_TRIANGLES, 0, 6);
    glEnable(GL_DEPTH_TEST);
}