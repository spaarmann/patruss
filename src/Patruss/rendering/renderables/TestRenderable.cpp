#include "TestRenderable.h"

using namespace rendering::renderable;

TestRenderable::TestRenderable()
{
	const GLfloat triangleVertices[] = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	};

	const GLfloat vertexColors[] = {
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,
	};
	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(2, vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexColors), vertexColors, GL_STATIC_DRAW);
}


TestRenderable::~TestRenderable()
{
	glDeleteBuffers(2, &vbo[0]);
	glDeleteVertexArrays(1, &vao);
}

void TestRenderable::Bind()
{
	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glVertexAttribPointer(0, 3, GL_FLOAT, false, 0, nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, false, 0, nullptr);
	glEnableVertexAttribArray(1);
}

void TestRenderable::Render()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
