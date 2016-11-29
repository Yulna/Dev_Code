#ifndef __UI_element_H__
#define __UI_element_H__



#include "p2Log.h"
#include "p2Point.h"
#include "j1Input.h"


class SDL_Rect;

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
	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate) {};

	bool mouseIn(int x, int y);
	void SetRect(int x, int y, int w, int h);
	void SetPos(int x, int y);
    

	UItype GetType();

protected:
	UItype type;
	iPoint pos;
	SDL_Rect* rect;


};


#endif // !__UI_element_H__
