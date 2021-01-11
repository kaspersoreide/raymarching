#version 430

in vec2 texCoords;

uniform sampler2D colorTexture1;
uniform sampler2D depthTexture1;
uniform sampler2D colorTexture2;
uniform sampler2D depthTexture2;

out vec4 FragColor;

void main() {
    FragColor = texture(colorTexture1, texCoords);
    //FragColor = vec4(texCoords, 0.0, 0.0);
}