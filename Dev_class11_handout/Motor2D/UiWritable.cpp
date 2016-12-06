#include "UiWritable.h"

UiWritable::UiWritable(UItype type, UI_element * parent) : UiText(type, parent)
{
	password = false;
}

UiWritable::UiWritable(UItype type, UI_element * parent, bool password) : UiText(type, parent), password(password)
{
}

UiWritable::~UiWritable()
{
}

void UiWritable::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	
	/*switch (wstate)
	{
	case STANDBY:


		break;
	case WRITING:


		break;
	default:
		break;
	}

	*/

}
