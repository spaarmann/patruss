#include "window.h"

rendering::Window::Window(const std::string title, const int width, const int height)
{
	this->title = title;
	this->width = width;
	this->height = height;

	create();
}

rendering::Window::~Window()
{
	if (windowHandle != nullptr) SDL_DestroyWindow(windowHandle);
}

SDL_GLContext& rendering::Window::GetContext()
{
	return glContext;
}

void rendering::Window::Swap()
{
	SDL_GL_SwapWindow(windowHandle);
}

void rendering::Window::create()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	windowHandle = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (windowHandle == nullptr)
	{
		LOG_ERROR_SDL("CreateWindow");
		throw std::exception();
	}

	glContext = SDL_GL_CreateContext(windowHandle);

	glewExperimental = true;
	const auto result = glewInit();
	if (result != GLEW_OK)
	{
		LOG_ERROR_GLEW("Init", result);
		throw std::exception();
	}

	SDL_GL_SetSwapInterval(1);
}
