#include <iostream>
#include <SDL.h>

#include "common.h"
#include "rendering/window.h"
#include "rendering/shader.h"
#include "rendering/renderables/TestRenderable.h"

#include <chrono>

#include "math/mat4.h"

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

		rendering::renderable::TestRenderable test{};

		SDL_Event e;
		auto running = true;
		while (running)
		{
			const auto frameStart = std::chrono::high_resolution_clock::now();

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

			test.Bind();
			test.Render();

			window.Swap();

			const auto frameEnd = std::chrono::high_resolution_clock::now();
			auto frameTime = std::chrono::duration_cast<std::chrono::microseconds>(frameEnd - frameStart);
			std::cout << "Frame time: " << frameTime.count() << "microseconds" << std::endl;
		}
	}
	catch (std::exception&)
	{
		return EXIT_FAILURE;
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
