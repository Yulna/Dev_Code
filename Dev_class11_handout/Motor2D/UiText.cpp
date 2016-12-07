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
	if(words != nullptr)
	delete words;
}

void UiText::Draw()
{
	if (words != nullptr)
	{
		int x, y;
		iPoint gpos = GetGlobalPos();

		App->render->Blit(App->font->Print(words->GetString(), { 255,255,255,255 }, nullptr), gpos.x, gpos.y, rect);
	}
}

void UiText::handle_input(iPoint mousepos, int key, j1KeyState keystate)
{


}





void UiText::SetSentence(const char* str)
{
	if (words != nullptr)
	{
		delete words;
	}

	words = new p2SString(str);
	int w, h;
	App->font->CalcSize(words->GetString(), w, h);

	rect = new SDL_Rect{ 0,0,w,h };
}

void UiText::SetSentence2(const char* str)
{
	if (words != nullptr)
	{
		delete words;
	}

	words = new p2SString(str);
	int w, h;
	App->font->CalcSize(words->GetString(), w, h);

	rect = new SDL_Rect{ 0,0,w,h/2 };
}

