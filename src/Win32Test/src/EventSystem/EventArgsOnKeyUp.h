#pragma once

namespace Alex
{
	struct EventArgsOnKeyUp
	{
		UINT keyCode;
		EventArgsOnKeyUp(UINT keyCode)
			:keyCode(keyCode)
		{

		}
	};
}
