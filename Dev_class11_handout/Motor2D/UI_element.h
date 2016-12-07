#ifndef __UI_element_H__
#define __UI_element_H__



#include "p2Log.h"
#include "p2Point.h"
#include "j1Input.h"


class SDL_Rect;

enum UItype {
	UI_ELEMENT,
	UI_BUTTON,
	UI_LABEL,
	UI_WRITABLE
};

class UI_element
{
public:
	UI_element(UItype type, UI_element* parent);
	~UI_element();

	virtual void Draw();
	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate) {};

	bool mouseIn(int x, int y);
	void SetRect(int x, int y, int w, int h);
	void SetPos(int x, int y);
	void Move(int x, int y);
	void Move2(int x, int y);

	//Gets Position in the window framework
	iPoint GetGlobalPos();

	UItype GetType();


	iPoint pos;

protected:
	UItype type;
	SDL_Rect* rect;
	UI_element* parent;
	int priority = 0;

};


#endif // !__UI_element_H__
