#ifndef __UI_element_H__
#define __UI_element_H__


#include "animation.h"
#include "p2Log.h"
#include "p2Point.h"


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
	UI_element(UItype type);
	~UI_element();

	virtual void Draw();
	virtual void handle_input() {};


	void SetRect(int x, int y, int w, int h);
	void SetPos(int x, int y);


	UItype GetType();

protected:
	UItype type;
	iPoint pos;
	SDL_Rect* rect;


};


#endif // !__UI_element_H__
