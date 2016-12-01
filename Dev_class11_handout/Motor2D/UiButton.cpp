#include "UiButton.h"
#include "j1App.h"
#include "j1Input.h"
#include "SDL/include/SDL.h"



UiButton::UiButton(UItype type, UI_element* parent) : UI_element(type, parent)
{

}

UiButton::~UiButton()
{

}



void UiButton::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	if (mouseIn(mousepos.x, mousepos.y))
	{
		//TODO: Try a state machine?
		if (key != NULL, keystate != NULL)
		{
			if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
			{
				
				int x, y;
				App->input->GetMouseDelta(x, y);
				Move(x, y);

				SetRect(643, 166, 229, 72);
			}
		}
		else
			SetRect(412, 166, 229, 72);
	}
	else
		SetRect(1, 110, 229, 70);
}
