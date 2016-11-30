#include "UI_element.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"


UI_element::UI_element(UItype type, UI_element* parent) : type(type), parent(parent)
{
	rect = nullptr;

}

UI_element::~UI_element()
{
	if (rect != nullptr)
		delete rect;
}



void UI_element::Draw()
{

	App->render->Blit( App->gui->GetAtlas(), pos.x, pos.y, rect);
}

bool UI_element::mouseIn(int x, int y)
{
	return ((x >= pos.x && x <= rect->w+pos.x) && (y >= pos.y && y <= rect->h+pos.y));
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
