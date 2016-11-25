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
	Uint8 test = 255;
	App->render->Blit(App->font->Print(words->GetString(), {(test, test, test, test)}, App->font->default), rect.x, rect.y, &anim->GetCurrentFrame());

}



void WordsBox::SetSentence(const char* str)
{
	p2SString stc = str;
	words = &stc;
}

