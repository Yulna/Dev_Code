#ifndef __UIBUTTON_H__
#define __UIBUTTON_H__

#include "UI_element.h"

enum UiButtonState
{
	STANDBY = 0,		//Both standby and selected are just steps to take before actually doing 
	SELECTED,			//somtehing (ACTIVATED state)
	ACTIVATED			//The buttons will do what they are meant to do 
};

class UiButton : public UI_element
{
public:
	UiButton(UItype type, UI_element* parent);
	~UiButton();


	virtual void handle_input(iPoint mousepos, int key, j1KeyState keystate);

protected:
	UiButtonState bstate = STANDBY;

};


#endif // !__BUTTON_H__

