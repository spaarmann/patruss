#include <iostream>
#include <SDL.h>

#include "common.h"
#include "rendering/window.h"
#include "rendering/shader.h"

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		LOG_ERROR_SDL("Init");
		return EXIT_FAILURE;
	}

	try
	{
		rendering::Window window("Patruss", 640, 480);
		rendering::Shader shader("default");

		GLuint vertexArrayID;
		glGenVertexArrays(1, &vertexArrayID);
		glBindVertexArray(vertexArrayID);

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		
		const GLfloat triangleVertices[] = {
			-1.0f, -1.0f, 0.0f,
			1.0f, -1.0f, 0.0f,
			0.0f,  1.0f, 0.0f,
		};

		GLuint vertexBuffer;
		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

		SDL_Event e;
		auto running = true;
		while (running)
		{
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
				}
			}

			glClear(GL_COLOR_BUFFER_BIT);

			shader.Use();
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
			glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);

			glDrawArrays(GL_TRIANGLES, 0, 3);

			glDisableVertexAttribArray(0);

			window.Swap();
		}
	}
	catch (std::exception& e)
	{
		return EXIT_FAILURE;
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}