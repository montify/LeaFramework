#pragma once

namespace Alex
{
	struct EventArgsOnWindowSizeChanged
	{
		int width;
		int height;

		EventArgsOnWindowSizeChanged(int width, int height)
			:width(width), height(height)
		{

		}
	};
}