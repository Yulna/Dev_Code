#include "UiText.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1Fonts.h"


UiText::UiText(UItype type) : UI_element(type)
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



void UiText::SetSentence(const char* str)
{
	delete words;
	words = new p2SString(str);

	int w, h;
	App->font->CalcSize(words->GetString(), w, h);

	rect = new SDL_Rect{ 0,0,w,h };
}

