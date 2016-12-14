#include "UiSelectBox.h"
#include "SDL/include/SDL.h"

UiSelectBox::UiSelectBox(UItype type, UI_element * parent) : UI_element(type, parent)
{
	slctstate = SLCT_STANDBY;
}

UiSelectBox::~UiSelectBox()
{
}

void UiSelectBox::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	switch (slctstate)
	{
	case SLCT_STANDBY:
		if (key == SDL_SCANCODE_TAB && keystate == KEY_DOWN)
		{
			slctstate = SLCT_ACTIVE;
		}
		break;
	case SLCT_ACTIVE:
		if (key == SDL_SCANCODE_UP && keystate == KEY_DOWN)
		{
			if (pos.y + (-rect->h + 14) > -14)
				Move(0, (-rect->h + 14));
		
		}

		if (key == SDL_SCANCODE_DOWN && keystate == KEY_DOWN)
		{
			if(pos.y + (rect->h - 14) < parent->rect->h - 14)
			Move(0, (rect->h-14));
		}
		if (key == SDL_SCANCODE_LEFT && keystate == KEY_DOWN)
		{
			if (pos.x + (-rect->w) >= 0)
				Move(-rect->w, 0);
		}

		if (key == SDL_SCANCODE_RIGHT && keystate == KEY_DOWN)
		{
			if (pos.x + (rect->w) < parent->rect->w)
				Move(rect->w, 0);
		}

		if (key == SDL_SCANCODE_TAB && keystate == KEY_DOWN)
		{
			slctstate = SLCT_STANDBY;
		}


		break;
	default:
		break;
	}


}
