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
		//Make sure the sprite is the correct one and change it otherwise
		
			SetRect(412, 166, 229, 72); //TODO: compare rects or somoething but this is bad

		if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
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
		//In the activated state is where the actions will occur so a classification by buttons
		//is needed, in this case it is done with various if();

		if (key == SDL_BUTTON_LEFT)
		{
			int x, y;
			App->input->GetMouseMotion(x, y);
			Move(x, y);
			SetRect(643, 166, 229, 72);

			if (keystate == KEY_UP)
				bstate = SELECTED;
		}
	


	
		break;
	default:
		break;
	}

	/*
	if (mouseIn(mousepos.x, mousepos.y))
	{
		//TODO: Try a state machine?
		if (key != NULL, keystate != NULL)
		{
			if (key == SDL_BUTTON_LEFT && keystate == KEY_REPEAT)
			{
				
				int x, y;
				App->input->GetMouseMotion(x, y);
				Move(x, y);

				SetRect(643, 166, 229, 72);
			}

	}
	else
		SetRect(1, 110, 229, 70);
		*/
}
