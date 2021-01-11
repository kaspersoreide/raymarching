#version 430

out vec4 color;

in float shade;

void main() {
    color = vec4(shade * vec3(1.0), 1.0);
}