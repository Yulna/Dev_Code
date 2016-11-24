#include "UI_element.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"


UI_element::UI_element(UItype type) : type(type)
{
	rect = { 0,0,0,0 };
	anim = nullptr;
}

UI_element::~UI_element()
{
}

void UI_element::Draw()
{
	App->render->Blit( App->gui->GetAtlas(), rect.x, rect.y, &anim->GetCurrentFrame());
}

void UI_element::SetRect(int x, int y, int w, int h)
{
	rect = { x,y,w,h };
}

void UI_element::SetAnim(Animation * animation)
{
	anim = animation;
}
