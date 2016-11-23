#include "UI_element.h"
#include "j1Render.h"


UI_element::UI_element(UItype type, iPoint pos, int w, int h)
{
	type = type;
	rect.x = pos.x;
	rect.y = pos.y;
	rect.w = w;
	rect.h = h;
}

UI_element::~UI_element()
{
}

void UI_element::Draw()
{


}
