#pragma once

#include "../../common.h"
#include "renderable.h"

#include <GL/glew.h>

namespace rendering
{
namespace renderable
{
	class TestRenderable : Renderable
	{
	private:
		GLuint vao;
		GLuint vbo[2];
	public:
		TestRenderable();
		~TestRenderable();
		void Bind() override;
		void Render() override;
	};
}
}
