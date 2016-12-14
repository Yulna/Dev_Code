#include "UiText.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"
#include "j1Fonts.h"
#include "UI_element.h"


UiText::UiText(UItype type, UI_element* parent) : UI_element(type, parent)
{
	words = nullptr;
}

UiText::~UiText()
{
	if(words != nullptr)
	delete words;
}

void UiText::Draw()
{
	
	UI_element* tempviewport = nullptr;
	if (parent != nullptr)
		tempviewport = parent->IsViewPort();

	if (words != nullptr && tempviewport!=nullptr)
	{
	
		SDL_Rect temp2;
		temp2.x = tempviewport->GetGlobalPos().x;
		temp2.y = tempviewport->GetGlobalPos().y;
		temp2.w = tempviewport->rect->w;
		temp2.h = tempviewport->rect->h;

		SDL_RenderSetViewport(App->render->renderer, &temp2);
		App->render->Blit(App->font->Print(words->GetString(), { 255,255,255,255 }, nullptr),GetViewPortPos().x, GetViewPortPos().y, rect);  //TODO:Make a function to get the local pos respect the VIEWPORT
		App->render->ResetViewPort();
	}
	else if (words != nullptr)
	{
		int x, y;
		iPoint gpos = GetGlobalPos();

		App->render->Blit(App->font->Print(words->GetString()), gpos.x, gpos.y, rect);
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

