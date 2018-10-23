#pragma once

#include <GL/glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "../common.h"

namespace rendering {
	class Window
	{
	private:
		int width, height;
		std::string title;
		SDL_Window *windowHandle;
		SDL_GLContext glContext;

		void create();
	public:
		Window(std::string title, int width, int height);
		~Window();

		SDL_GLContext& GetContext();
		void Swap();
	};
}