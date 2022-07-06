#pragma once

#include <glad/glad.h>


class ComputeShader {
public:
	ComputeShader();
};

static const char* vertexShaderSource = R"(
#version 450
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 coords;

out vec2 uv;

void main()
{
    gl_Position = vec4(position, 1.0f);
    uv = coords;
}
)";

static const char* fragmentShaderSource = R"(
#version 450
out vec4 FragColor;

uniform sampler2D screen;
in vec2 uv;

void main()
{
    FragColor = texture(screen, uv);
    //FragColor = vec4(0.2, 0.9f, 0.3f, 1.0f);
}
)";

static const char* computeShaderSource = R"(
#version 450

layout(local_size_x = 8, local_size_y = 4, local_size_z = 1) in;

layout(rgba32f, binding = 0) uniform image2D screen;

void main()
{
    vec4 pixel = vec4(0.8f, 0.2f, 0.2f, 1.0f);
    ivec2 pixel_coords = ivec2(gl_GlobalInvocationID.xy);
    ivec2 dim = imageSize(screen);

    imageStore(screen, pixel_coords, vec4(float(pixel_coords.x) / dim.x, float(pixel_coords.y) / dim.y, 0.1f, 1.0f));

}

)";