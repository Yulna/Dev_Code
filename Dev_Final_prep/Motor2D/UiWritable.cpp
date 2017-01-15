#include "UiWritable.h"
#include "j1App.h"
#include "j1Input.h"
#include "SDL\include\SDL.h"	

UiWritable::UiWritable(UItype type, UI_element * parent) : UiLabel(type, parent)
{
	words = new p2SString;
	password = false;
	wstate = WRITE_OFF;

}

UiWritable::UiWritable(UItype type, UI_element * parent, bool password) : UiLabel(type, parent), password(password)
{
}

UiWritable::~UiWritable()
{
}

void UiWritable::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	
/*	switch (wstate)
	{
	case WRITE_OFF:
		if (mouseIn(mousepos.x, mousepos.y))
		{
			if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
			{
				wstate = WRITING;
			}
		}

		break;
	case WRITING:

		if (App->input->letter_printed == false && words != nullptr)
		{
			*words += App->input->input_text;
		}

		if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
		{
			if (mouseIn(mousepos.x, mousepos.y))
			{
				wstate = WRITE_OFF;
			}
		}


		break;
	default:
		break;
	}
	*/

	if (App->input->letter_printed == false && words != nullptr)
	{
		*words += App->input->input_text;
	}


}
