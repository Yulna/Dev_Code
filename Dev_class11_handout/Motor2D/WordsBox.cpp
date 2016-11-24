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
	App->render->Blit(App->font->Print(words->GetString(), {(255,255,255,255)}, App->font->default), rect.x, rect.y, &anim->GetCurrentFrame());

}



void WordsBox::SetSentence(p2SString * str)
{
	words = str;
}

