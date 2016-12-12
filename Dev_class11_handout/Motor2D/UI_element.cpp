#include "UI_element.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"


UI_element::UI_element(UItype type, UI_element* parent) : type(type), parent(parent)
{
	rect = nullptr;
	priority;
}

UI_element::~UI_element()
{
	if (rect != nullptr)
		delete rect;
}



void UI_element::Draw()
{
	int x, y;
	iPoint gpos = GetGlobalPos();


	

	if (type == UI_BUTTON)
	{
		
		//Important to take the position of the parent or the viewport will start at the sprite pos in the texture (atlas)
		SDL_Rect temp2;
		temp2.x = parent->GetGlobalPos().x;
		temp2.y = parent->GetGlobalPos().y;
		temp2.w = parent->rect->w;
		temp2.h = parent->rect->h;

		SDL_RenderSetViewport(App->render->renderer, &temp2);
		App->render->Blit(App->gui->GetAtlas(), pos.x, pos.y, rect);
		App->render->ResetViewPort();

	}
	else
		App->render->Blit(App->gui->GetAtlas(), gpos.x, gpos.y, rect);

}

bool UI_element::mouseIn(int x, int y)
{
	//A global_x global_y precalculation is needed so the mouseIn function corresponds to the
	//global frame, and their draw.
	//If the calculation is not done the mouseIn will take the relative pos as global and the
	//calculation will not match the representation (Draw())
	int global_x, global_y;
	iPoint gpos = GetGlobalPos();

	return ((x >= gpos.x && x <= rect->w + gpos.x) && (y >= gpos.y && y <= rect->h + gpos.y));
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

void UI_element::Move2(int x, int y)
{
	pos.x = pos.x + x;
	pos.y = pos.y + y;

	rect->x = rect->x - x;
	rect->y = rect->y - y;
}



iPoint UI_element::GetGlobalPos()
{
	
	iPoint ret;
	if (parent != nullptr)
	{
		ret.x = pos.x + parent->GetGlobalPos().x;
		ret.y = pos.y + parent->GetGlobalPos().y;
	}
	else
	{
		ret.x = pos.x;
		ret.y = pos.y;
	}
	return ret;
}

UItype UI_element::GetType()
{
	return type;
}

bool UI_element::IsViewPort()
{
	if (viewport)
		return true;
	else
		return false;
}
