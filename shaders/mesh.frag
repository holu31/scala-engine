#version 460


in vec3 fPos;
in vec2 fUv;
in vec3 fNormal;
in vec3 fFragPos;

uniform mat4 projMat, viewMat, transMat;
uniform sampler2D textureSampler;
uniform vec3 color;

out vec4 fragmentColor;

void main() {
	vec3 result = color;

	fragmentColor = textureSize(textureSampler, 0) == ivec2(1, 1) ? vec4(result, 1.0) : vec4(result, 1.0) * texture(textureSampler, fUv);
}