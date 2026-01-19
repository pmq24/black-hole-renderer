#version 410 core

in vec2 position;

out vec2 uv;

void main()
{
	vec2 pos;
	if (gl_VertexID == 0) {
		pos = vec2(-1.0, -1.0);
	} else if (gl_VertexID == 1) {
		pos = vec2(3.0, -1.0);
	} else {
		pos = vec2(-1.0, 3.0);
	}

	gl_Position = vec4(pos, 0.0, 1.0);
	uv = position * 0.5 + 0.5;
}
