#include "UiButton.h"
#include "j1App.h"
#include "j1Input.h"
#include "SDL/include/SDL.h"



UiButton::UiButton(UItype type, UI_element* parent) : UI_element(type, parent)
{
	bstate = STANDBY;
}

UiButton::~UiButton()
{

}



void UiButton::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	//EXERCICE 1

	switch (bstate)
	{
	case STANDBY:
		if (mouseIn(mousepos.x, mousepos.y))
		{
			SetRect(412, 166, 229, 72);
			bstate = SELECTED;
		}
		break;
	case SELECTED:
		
		
		SetRect(412, 166, 229, 72); 

		if (key == SDL_BUTTON_LEFT && keystate == KEY_DOWN)
		{
			bstate = ACTIVATED;
		}

		if (!mouseIn(mousepos.x, mousepos.y))
		{
			SetRect(1, 110, 229, 70);
			bstate = STANDBY;
		}
		
		break;

	case ACTIVATED:


		if (key == SDL_BUTTON_LEFT)
		{
		
			SetRect(643, 166, 229, 72);

			if (keystate == KEY_UP)
				bstate = SELECTED;
		}
	

		if (!mouseIn(mousepos.x, mousepos.y))
		{
			SetRect(1, 110, 229, 70);
			bstate = STANDBY;
		}
	
		break;
	default:
		break;
	}


}
