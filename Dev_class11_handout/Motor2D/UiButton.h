#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include "UI_element.h"

class UiButton : public UI_element
{
public:
	UiButton(UItype type, UI_element* parent);
	~UiButton();

	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate);

private:
	

};


#endif // !__BUTTON_H__

