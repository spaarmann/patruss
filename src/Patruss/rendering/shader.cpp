#include "shader.h"

#include <vector>
#include <sstream>
#include <fstream>

rendering::Shader::Shader(const std::string& name)
{
	std::ifstream vertexIn("res/shaders/" + name + ".vert");
	std::stringstream vertexSourceBuffer;
	vertexSourceBuffer << vertexIn.rdbuf();
	const auto vertexSource = vertexSourceBuffer.str();

	std::ifstream fragmentIn("res/shaders/" + name + ".frag");
	std::stringstream fragmentSourceBuffer;
	fragmentSourceBuffer << fragmentIn.rdbuf();
	const auto fragmentSource = fragmentSourceBuffer.str();

	const auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
	const auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	GLint compileResult;
	int compileOutputLength;

	const auto vertexSourceC = vertexSource.c_str();
	glShaderSource(vertexShader, 1, &vertexSourceC, nullptr);
	glCompileShader(vertexShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compileResult);
	glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &compileOutputLength);

	if (compileOutputLength > 0)
	{
		std::vector<char> logOutput(compileOutputLength + 1);
		glGetShaderInfoLog(vertexShader, compileOutputLength, nullptr, &logOutput[0]);
		LOG_ERROR("Failed to compile vertex shader: ", std::string(logOutput.begin(), logOutput.end()));
		throw std::exception();
	}

	const auto fragmentSourceC = fragmentSource.c_str();
	glShaderSource(fragmentShader, 1, &fragmentSourceC, nullptr);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compileResult);
	glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &compileOutputLength);

	if (compileOutputLength > 0)
	{
		std::vector<char> logOutput(compileOutputLength + 1);
		glGetShaderInfoLog(fragmentShader, compileOutputLength, nullptr, &logOutput[0]);
		LOG_ERROR("Failed to compile fragment shader: ", std::string(logOutput.begin(), logOutput.end()));
		throw std::exception();
	}

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);

	glGetProgramiv(program, GL_COMPILE_STATUS, &compileResult);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &compileOutputLength);

	if (compileOutputLength > 0)
	{
		std::vector<char> logOutput(compileOutputLength + 1);
		glGetProgramInfoLog(program, compileOutputLength, nullptr, &logOutput[0]);
		LOG_ERROR("Failed to link program: ", std::string(logOutput.begin(), logOutput.end()));
		throw std::exception();
	}

	glDetachShader(program, vertexShader);
	glDetachShader(program, fragmentShader);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


rendering::Shader::~Shader()
{
	glDeleteProgram(program);
}

void rendering::Shader::Use() const
{
	glUseProgram(program);
}
