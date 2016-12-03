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
	int x, y;
	GetGlobalPos(x, y);

	App->render->Blit( App->gui->GetAtlas(), x, y, rect);
}

bool UI_element::mouseIn(int x, int y)
{
	//A global_x global_y precalculation is needed so the mouseIn function corresponds to the
	//global frame, and their draw.
	//If the calculation is not done the mouseIn will take the relative pos as global and the
	//calculation will not match the representation (Draw())
	int global_x, global_y;
	GetGlobalPos(global_x,global_y);

	return ((x >= global_x && x <= rect->w + global_x) && (y >= global_y && y <= rect->h + global_y));
}

void UI_element::SetRect(int x, int y, int w, int h)
{
	rect = new SDL_Rect{ x,y,w,h };
}


//Position will be always relative to the one of the parent
void UI_element::SetPos(int x, int y)
{
	pos = iPoint(x, y);
}



void UI_element::Move(int x, int y)
{
	pos.x = pos.x + x;
	pos.y = pos.y + y;
}



void UI_element::GetGlobalPos(int & x, int & y)
{
	if (parent != nullptr)
	{
		x = pos.x + parent->pos.x;
		y = pos.y + parent->pos.y;
	}
	else
	{
		x = pos.x;
		y = pos.y;
	}
}

UItype UI_element::GetType()
{
	return type;
}
