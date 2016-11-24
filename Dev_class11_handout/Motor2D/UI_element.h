#ifndef __UI_element_H__
#define __UI_element_H__


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
	UI_element(UItype type, int x, int y, int w, int h);
	~UI_element();

	virtual void PreUpdate() {};
	virtual void Update() {};
	virtual void handle_input() {};
	virtual void Draw();

private:
	UItype type;
	SDL_Rect rect;
	Animation* anim;

};


#endif // !__UI_element_H__
