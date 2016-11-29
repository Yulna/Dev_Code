#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include "UI_element.h"
#include "UiText.h" 

class UiButton : public UI_element
{
public:
	UiButton(UItype type);
	~UiButton();

	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate);

private:
	
	UiText* linkedText;

};


#endif // !__BUTTON_H__

