#pragma once

#include "../common.h"

#include <string>
#include <GL/glew.h>

namespace rendering
{

	class Shader
	{
	private:
		GLuint program;
	public:
		Shader(const std::string& name);
		~Shader();
		void Use() const;
	};

}
