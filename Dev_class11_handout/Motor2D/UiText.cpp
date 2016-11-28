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
	App->render->Blit(App->font->Print(words->GetString(), {255,255,255,255}, nullptr), pos.x, pos.y);
}



void UiText::SetSentence(const char* str)
{
	delete words;
	words = new p2SString(str);
}

