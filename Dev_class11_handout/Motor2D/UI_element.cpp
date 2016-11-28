#include "UI_element.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"


UI_element::UI_element(UItype type) : type(type)
{
	rect = nullptr;

}

UI_element::~UI_element()
{
}



void UI_element::Draw()
{

	App->render->Blit( App->gui->GetAtlas(), pos.x, pos.y, rect);
}

void UI_element::SetRect(int x, int y, int w, int h)
{
	rect = new SDL_Rect{ x,y,w,h };
}

void UI_element::SetPos(int x, int y)
{
	pos = iPoint(x, y);
}



UItype UI_element::GetType()
{
	return type;
}
