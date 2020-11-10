/*
#version 330 core
out vec4 FragColor;

void main()
{
    FragColor = vec4(0.9f, 0.8f, 0.2f, 1.0f);
}
/*/////
#version 330 core
out vec4 FragColor;

uniform vec4 ourColor; // we set this variable in the OpenGL code.

void main()
{
    FragColor = ourColor;
}


