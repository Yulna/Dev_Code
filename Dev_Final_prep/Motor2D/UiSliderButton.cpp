#include "UiSliderButton.h"
#include "j1Input.h"
#include "j1App.h"
#include "SDL/include/SDL.h"

UiSliderButton::UiSliderButton(UItype type, UI_element* parent) : UiButton(type, parent)
{

}

UiSliderButton::~UiSliderButton()
{
}

void UiSliderButton::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	switch (bstate)
	{
	case STANDBY:
		if (mouseIn(mousepos.x, mousepos.y))
		{
			bstate = SELECTED;
		}
		break;
	case SELECTED:
		//Make sure the sprite is the correct one and change it otherwise

		if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
		{
			bstate = ACTIVATED;
		}

		if (!mouseIn(mousepos.x, mousepos.y))
		{
			bstate = STANDBY;
		}

		break;

	case ACTIVATED:
		//In the activated state is where the actions will occur so a classification by buttons
		//is needed, in this case it is done with various if();

		if (key == SDL_BUTTON_LEFT)
		{
			int x, y;
			App->input->GetMouseMotion(x, y);
			if (pos.y > -100 && pos.y < 100)
			{
				Move(0, y);
				linkedobj->Move(0, -y);
			}
			else
				Move(0, -1);

			if (keystate == KEY_UP)
				bstate = SELECTED;
		}




		break;
	default:
		break;
	}
}
