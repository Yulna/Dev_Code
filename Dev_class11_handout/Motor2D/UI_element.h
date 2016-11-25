#ifndef __UI_element_H__
#define __UI_element_H__


#include "animation.h"
#include "p2Log.h"


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
	virtual void PreUpdate() {};
	virtual void Update() { Draw(); };
	virtual void handle_input() {};


	void SetRect(int x, int y, int w, int h);
	void SetAnim(Animation* animation);

	UItype GetType();

protected:
	UItype type;
	SDL_Rect rect;
	Animation* anim;

};


#endif // !__UI_element_H__
