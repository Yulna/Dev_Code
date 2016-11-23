#ifndef __UI_element_H__
#define __UI_element_H__

#include "j1Gui.h"
#include "animation.h"

class SDL_rect;

enum UItype {
	UI_ELEMENT,
	BUTTON,
	WORDSBOX,
	WRITABLEBOX
};

class UI_element
{
public:
	UI_element(UItype type, iPoint pos, int w, int h);
	~UI_element();



private:
	UItype type;
	SDL_Rect rect;
	Animation* anim;

};


#endif // !__UI_element_H__
