#include "UI_element.h"
#include "j1Render.h"


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


}

void UI_element::SetRect(int x, int y, int w, int h)
{
	rect = { x,y,w,h };
}

void UI_element::SetAnim(Animation * animation)
{
	anim = animation;
}
