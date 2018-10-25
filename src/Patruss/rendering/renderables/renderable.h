#pragma once

namespace rendering
{
namespace renderable
{

	class Renderable
	{
	public:
		virtual void Bind() = 0;
		virtual void Render() = 0;
	};

}
}