#pragma once

namespace Alex
{
	struct EventArgsOnKeyDown
	{
		UINT keyCode;
		EventArgsOnKeyDown(UINT keyCode)
			:keyCode(keyCode)
		{
			
		}
	};
}
