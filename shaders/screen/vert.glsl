#version 430

layout(location = 0) in vec4 pos;

out vec2 texCoords;

void main() {
    //pos in range [-1, 1] but uv has to be [0, 1]
	texCoords = 0.5 * pos.xy + 0.5;
	gl_Position = pos;
}