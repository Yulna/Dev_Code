#include "UI_element.h"
#include "j1Render.h"


UI_element::UI_element(UItype type, int x, int y, int w, int h) : type(type), rect({x,y,w,h})
{

}

UI_element::~UI_element()
{
}

void UI_element::Draw()
{


}
