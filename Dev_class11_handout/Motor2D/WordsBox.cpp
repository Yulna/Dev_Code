#include "WordsBox.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1Fonts.h"


WordsBox::WordsBox(UItype type) : UI_element(type)
{
}

WordsBox::~WordsBox()
{
}

void WordsBox::Draw()
{
	App->render->Blit(App->font->Print(words->GetString(), {255,255,255,255}, nullptr), rect.x, rect.y);
}



void WordsBox::SetSentence(const char* str)
{
	delete words;
	words = new p2SString(str);
}

