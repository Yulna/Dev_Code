#include "UiText.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1Fonts.h"
#include "UI_element.h"


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
	if (words != nullptr && parent->viewport == false)
	{
		int x, y;
		iPoint gpos = GetGlobalPos();

		App->render->Blit(App->font->Print(words->GetString(), { 255,255,255,255 }, nullptr), gpos.x, gpos.y, rect);
	}
	

	

	if (words != nullptr && parent->viewport == true)
	{
	
		SDL_Rect temp2;
		temp2.x = parent->GetGlobalPos().x;
		temp2.y = parent->GetGlobalPos().y;
		temp2.w = parent->rect->w;
		temp2.h = parent->rect->h;

		SDL_RenderSetViewport(App->render->renderer, &temp2);
		App->render->Blit(App->font->Print(words->GetString(), { 255,255,255,255 }, nullptr), pos.x, pos.y, rect);
		App->render->ResetViewPort();


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

