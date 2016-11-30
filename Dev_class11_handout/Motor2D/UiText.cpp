#include "UiText.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1Fonts.h"


UiText::UiText(UItype type, UI_element* parent) : UI_element(type, parent)
{
}

UiText::~UiText()
{
	delete words;
}

void UiText::Draw()
{
	App->render->Blit(App->font->Print(words->GetString(), {255,255,255,255}, nullptr), pos.x, pos.y, rect);
}

void UiText::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{
	if (mouseIn(mousepos.x, mousepos.y))
	{
		if (key != NULL, keystate != NULL)
		{
			SetSentence("Some key pressed");  //TODO: Define the key states that could trigger UiText
		}
		else
			SetSentence("MouseInside");
	}
	else
		SetSentence("MouseOut");

}





void UiText::SetSentence(const char* str)
{
	delete words;
	words = new p2SString(str);

	int w, h;
	App->font->CalcSize(words->GetString(), w, h);

	rect = new SDL_Rect{ 0,0,w,h };
}

