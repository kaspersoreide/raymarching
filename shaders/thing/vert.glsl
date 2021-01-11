#version 430

layout(location = 0) in vec3 pos;
//layout(location = 1) in vec3 normal;

uniform mat4 MVP;

out float shade;

void main() {
    vec3 lightDir = normalize(vec3(1.0, 1.0, 1.0));
    shade = clamp(dot(lightDir, normalize(pos)), 0.1, 1.0);
	gl_Position = MVP * vec4(pos, 1.0);
}