#include "UiButton.h"


UiButton::UiButton(UItype type) : UI_element(type)
{
	linkedText = nullptr;
}

UiButton::~UiButton()
{
	if (linkedText != nullptr)
		delete linkedText;
}



void UiButton::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	if (mouseIn(mousepos.x, mousepos.y))
	{
		if (key != NULL, keystate != NULL)
		{
			SetRect(412, 166, 229, 72);
		}
		else
			SetRect(643, 166, 229, 72);
	}
	else
		SetRect(1, 110, 229, 70);
}
